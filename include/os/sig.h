#ifndef _OS_SIG_H_
#define _OS_SIG_H_

typedef void (*sighandler_t)(int);

#define SIG_DFL ((sighandler_t)0L)  /* default signal handling */
#define SIG_IGN ((sighandler_t)1L)  /* ignore signal */
#define SIG_ERR ((sighandler_t)-1L) /* error return from signal */

struct signal_action {
	int action;
	void *arg;
	struct signal_action *next;
};

struct signal_entry {
	sighandler_t handler;
	int flag;
};

struct signal_struct {
	struct signal_action *pEnding;
	struct signal_action *pLast;
	struct signal_entry signal_table[MAX_SIGNAL];
	u16 signal_pEnding;
	u16 in_signal;
};




#endif
