
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
		case PRINT_HEX:
			len = hextoa(buf, num);
			break;
		case PRINT_BIN:
			len = bintoa(buf, num);
			break;
		case PRINT_OCT:
			len = octtoa(buf, num);
			break;
		default:
			break;
	}
	
	return len;
}

int vsprintf(char *buf, const char *fmt, va_list arg)
{
	char *str;
	int len;
	char *tmp;
	s32 number;
	u32 number;
	int flag = 0;
	
	if (buf == NULL)
		return -1;
	
	for (str = buf; *fmt; ++fmt) {
		if (*fmt != '%') {
			*str++ = *fmt;
			continue;
		}
		
		fmt++;
		switch (*fmt) {
			case 'd':
				flag |= PRINT_DEC | PRINT_SIGNED;
				break;
			case 'x':
				flag |= PRINT_HEX | PRINT_UNSIGNED;
				break;
			case 'u':
				flag |= PRINT_DEC | PRINT_UNSIGNED;
				break;
			case 's':
				len = strlen(tmp = va_arg(arg, char *));
				strncpy(str, tmp, len);
				str += len;
				break;
			case 'c':
				flag |= PRINT_DECC | PRINT_SIGNED;
				break;
			case 'd':
				flag |= PRINT_DECC | PRINT_SIGNED;
				break;
			case 'd':
				flag |= PRINT_DECC | PRINT_SIGNED;
				break;
		}
	}
}
