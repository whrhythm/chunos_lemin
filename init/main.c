
extern unsigned long init_call_end;
extern unsigned long init_call_start;

int main(void)
{
	sched_init();
	
	/* to be continue */	
	size = (init_call_end - init_call_start) / sizeof(unsigned long);
	fn = (init_call *)init_call_start;
	for (i = 0; i < size; i++) {
		
	}
	
	build_idle_task();
}
