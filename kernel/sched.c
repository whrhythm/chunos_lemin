
struct task_struct *current;
struct task_struct *idle;
struct task_struct *next_run;

static int schedule_running = 0;

struct pid_map {
	int nr_free;
	int current;
	int nr;
	struct mutex pid_map_mutex;
	u32 *addr;
};
struct pid_map pid_map;

static in init_pid_allocater(void)
{
	init_mutex(&pid_map.pid_map_mutex);
	pid_map.nr = (PID_MAP_PAGE_NR *PAGE_SIZE) / sizeof(void *);
	pid_map.nr_free = pid_map.nr;
	pid_map.current = 0;
	pid_map.addr = get_free_page(PID_MAP_PAGE_NR, GFP_KERNEL);
	if (pid_map.addr == NULL) {
		return -ENOMEM;
	}
	
	memset((char *)pid_map.addr, 0, PID_MAP_PAGE_NR * PAGE_SIZE);
	return 0;
}


static struct sched_list os_sched_table[16];
#define init_ched_list(name)  \
	do {
		init_list(&task__##name.list);
		task_##name.count = 0;
	}while(0)

int init_sched_struct(struct task_struct *task)
{
	task->prio = 0;
	task->pre_prio = 0;
	
	/* this value will be set to a default value later */
	get_task_run_time(task);
	task->wait_time = -1;
	task->time_out = 0;
	task->run_count = 0;
	task->state = PROCESS_STATE_UNKNOWN;
	
	init_list(&task->prio_running);
}

int sched_init(void)
{
	int i;
	
	for (i = 0; i < 16; i++) {
		init_list(&os_sched_table[i].list);
		os_sched_table[i].count = 0;
	}

	init_sched_list(sleep);
	init_sched_list(idle);
	init_sched_list(system);

	init_pid_allocater();

	current = NULL;
	next_run = NULL;
	schedule_running = 1;
	
	return 0;
}
