#include <os/spin_lock.h>


void spin_lock_init(spin_lock_t *lock)
{
	lock_flags = 0;
}
