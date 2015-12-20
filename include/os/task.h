#ifndef _OS_TASK_H_
#define _OS_TASK_H_

struct mm_struct {
	int elf_size;
	int stack_size;
	struct list_head *stack_curr;
	struct list_head *elf_curr;
	struct list_head stack_list;
	struct list_head elf_list;
	struct list_head elf_stack_list;
	struct list_head elf_elf_image_list;
	
	struct list_head mmap_page_list;
	struct list_head mmap_mem_list;
	DECLEAR_BITMAP(mmap, PROCESS_USER_MMAP_SIZE >> PAGE_SHIFT);
	int free_pos;
	int mmap_nr;
};

struct task_struct {
	void *stack_base;
	void *stack_origin;
	
	char name[PROCESS_NAME_SIZE + 1];
	u32 flag;
	
	pid_t pid;
	u32 uid;
	state_t state;
	
	struct signal_struct signal;
	struct mm_struct mm_struct;
	
	
}

#endif
