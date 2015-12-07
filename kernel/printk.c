
#include <os/types.h>

#define LOG_BUFFER_SIZE (8192)

struct log_buffer {
	spin_lock_t buffer_lock;
	int head;
	int tail;
	char buf[LOG_BUFFER_SIZE];
}

static struct log_buffer lbuffer;

int log_buffer_init(void)
{
	spin_lock_init(&lbuffer_lock);
	log_buffer.head = 0;
	log_buffer.tail = 0;
	log_buffer.total = 0;

	return 0;
}

int numbric(char *buf, unsigned int num, int flag)
{
	int len = 0;

}
