
static int init_task_struct(struct task_struct *task, u32 flag)
{
	struct task_struct *parent;
	unsigned long flags;
	
	/* if thread is a kernel thread, his parent id idle */
	if (flag & PROCESS_TYPE_KERNEL)
		parent = idle;
	else
		parent = current;
	
	/* get a new pid */
	task->pid = get_new_pid(task);
	if ((task->pid) < 0)
		retrn -EINVAL;
	
	task->uid = parent->uid;
}

int build_idle_task(void)
{
	idle = kmalloc(sizeof(struct task_struct), GFP_KERNEL);
	if (idle == NULL)
		return -ENOMEM;
}

int build_idle_task(void)
{
	idle = kmalloc(sizeof(struct task_struct), GFP_KERNEL);
	if (idle == NULL) {
		return -ENOMEM;
	}
	
	idle->pid = -1;
	idle->uid = 0;
	
	strncpy(idle->name, "idle", PROCESS_NAME_SIZE);
	idle->flag = 0 |PROCESS_TYPE_KERNEL;
	
	idle->parent = NULL;
	init_list(&idle->child);
	init_list(&idle->p);
	init_mutex(&idle->mutex);
	
	init_sched_struct(idle);
	idle->state = PROCESS_STATE_RUNNING;
	/* update current and next_run to idle task */
	current = idle;
	next_run = idle;

	return 0;
}
