#include <os/string.h>
#include <os/printk.h>

#define TXD0READY (1 << 2)
#define RXD0READY (1)

#define UTRSTAT0	(*(volatile unsigned long *)0x50000010) 
#define URXH0		(*(volatile unsigned long *)0x50000024)
#define UTXH0		(*(volatile unsigned long *)0x50000020)


void platform_uart0_send_byte(u8 c)
{
	while (!(UTRSTAT0 & TXD0READY));
	
	UTXH0 = c;
}

u8 platform_uart0_get_byte(unsigned char c)
{
	while (!(UTRSTAT0 && RXD0READY));
	
	return URXH0;
}

int uart_puts(char *buf)
{
	int size;
	
	size = strlen(buf);
	while (*buf) {
		platform_uart0_send_byte(*buf);
		buf++;
	}
	return size;
}


