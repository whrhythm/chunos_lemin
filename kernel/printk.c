
#include <os/types.h>


#define PRINT_DEC  0x01
#define PRINT_HEX  0x02
#define PRINT_OCT  0x04
#define PRINT_BIN  0x08
#define PRINT_MASK 0x0f
#define PRINT_UNSIGNED 0x10
#define PRINT_SIGNED 0x20

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
	
	switch (flag & PRINT_MASK) {
		case PRINT_DEC:
		if(flag & PRINT_SIGNED)
			len = itoa(buf, (int)num);
		else
			len = uitoa(buf, num);
	}

}
