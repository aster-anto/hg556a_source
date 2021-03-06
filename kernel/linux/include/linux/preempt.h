#ifndef __LINUX_PREEMPT_H
#define __LINUX_PREEMPT_H

/*
 * include/linux/preempt.h - macros for accessing and manipulating
 * preempt_count (used for kernel preemption, interrupt count, etc.)
 */

#include <linux/config.h>
#include <linux/linkage.h>

#ifdef __KERNEL__

#define preempt_count()	(current_thread_info()->preempt_count)

#define inc_preempt_count() \
do { \
	preempt_count()++; \
} while (0)

#define dec_preempt_count() \
do { \
	preempt_count()--; \
} while (0)

#ifdef CONFIG_PREEMPT

asmlinkage void preempt_schedule(void);

#define preempt_disable() \
do { \
	inc_preempt_count(); \
	barrier(); \
} while (0)

#define preempt_enable_no_resched() \
do { \
	barrier(); \
	dec_preempt_count(); \
} while (0)

#define preempt_check_resched() \
do { \
	if (unlikely(test_thread_flag(TIF_NEED_RESCHED))) \
		preempt_schedule(); \
} while (0)

#define preempt_enable() \
do { \
	preempt_enable_no_resched(); \
	preempt_check_resched(); \
} while (0)

#else

#define preempt_disable()		do { } while (0)
#define preempt_enable_no_resched()	do { } while (0)
#define preempt_enable()		do { } while (0)
#define preempt_check_resched()		do { } while (0)

#endif

#else  /* __KERNEL__ */

/* We need to disable much of the above in order to build iptables.
 * Create unresolvable references so there are no surprises. */
asmlinkage void preempt_disable(void);
asmlinkage void preempt_enable(void);
asmlinkage int preempt_count(void);

#endif /* __KERNEL__ */

#endif /* __LINUX_PREEMPT_H */
