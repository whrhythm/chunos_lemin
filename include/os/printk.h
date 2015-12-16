#ifndef _OS_PRINTK_H_
#define _OS_PRINTK_H_

int uart_puts(char *buf);
int level_printk(const char *fmt, ...);

#endif
