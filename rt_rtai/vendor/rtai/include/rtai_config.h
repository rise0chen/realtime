/* rtai_config.h.  Generated from rtai_config.h.in by configure.  */
/* rtai_config.h.in.  Generated from configure.ac by autoheader.  */

/* Kconfig */
#define CONFIG_KBUILD 1

/* Legacy */
#define CONFIG_RTAI 1

/* Kconfig */
#define CONFIG_RTAI_16550A_ANY 1

/* Kconfig */
/* #undef CONFIG_RTAI_16550A_MMIO */

/* Kconfig */
/* #undef CONFIG_RTAI_16550A_PIO */

/* Kconfig */
/* #undef CONFIG_RTAI_ADEOS */

/* Kconfig */
/* #undef CONFIG_RTAI_ALIGN_LINUX_PRIORITY */

/* Kconfig */
#define CONFIG_RTAI_ALLOW_RR 1

/* Kconfig */
#define CONFIG_RTAI_BITS 1

/* Kconfig */
/* #undef CONFIG_RTAI_BITS_BUILTIN */

/* Build system alias */
#define CONFIG_RTAI_BUILD_STRING "x86_64-unknown-linux-gnu"

/* Kconfig */
#define CONFIG_RTAI_CAL_FREQS_FACT 0

/* Kconfig */
#define CONFIG_RTAI_CLOCK_REALTIME 1

/* Compiler */
#define CONFIG_RTAI_COMPILER "gcc version 4.9.2 (Debian 4.9.2-10) "

/* Kconfig */
#define CONFIG_RTAI_CPUS 4

/* Kconfig */
#define CONFIG_RTAI_DEBUG_RTDM 1

/* Kconfig */
/* #undef CONFIG_RTAI_DIAG_TSC_SYNC */

/* Kconfig */
#define CONFIG_RTAI_DONT_DISPATCH_CORE_IRQS 0

/* Kconfig */
#define CONFIG_RTAI_DRIVERS_16550A 1

/* Kconfig */
#define CONFIG_RTAI_DRIVERS_SERIAL 1

/* Kconfig */
#define CONFIG_RTAI_FIFOS 1

/* Kconfig */
/* #undef CONFIG_RTAI_FIFOS_BUILTIN */

/* Kconfig */
#define CONFIG_RTAI_FIFOS_TEMPLATE "/dev/rtf%d"

/* Kconfig */
#define CONFIG_RTAI_FPU_SUPPORT 1

/* Kconfig */
/* #undef CONFIG_RTAI_FULL_PRINHER */

/* Kconfig */
/* #undef CONFIG_RTAI_HAL_PREEMPT */

/* have libsensors */
/* #undef CONFIG_RTAI_HAVE_SENSORS */

/* Host system alias */
#define CONFIG_RTAI_HOST_STRING "x86_64-unknown-linux-gnu"

/* Kconfig */
#define CONFIG_RTAI_IMMEDIATE_LINUX_SYSCALL 0

/* Kconfig */
#define CONFIG_RTAI_INTERNAL_LXRT_INLINE 1

/* Kconfig */
#define CONFIG_RTAI_INTERNAL_LXRT_SUPPORT 1

/* Use RTAI Adeos-newgen HAL */
#define CONFIG_RTAI_IPIPE 1

/* Kconfig */
#define CONFIG_RTAI_KERN_BUSY_ALIGN_RET_DELAY 0

/* Kconfig */
#define CONFIG_RTAI_KSTACK_HEAPSZ 512

/* Kconfig */
#define CONFIG_RTAI_LATENCY_SELF_CALIBRATION_CYCLES 10000

/* Kconfig */
#define CONFIG_RTAI_LATENCY_SELF_CALIBRATION_FREQ 10000

/* Kconfig */
#define CONFIG_RTAI_LATENCY_SELF_CALIBRATION_METRICS 1

/* Kconfig */
/* #undef CONFIG_RTAI_LONG_TIMED_LIST */


#ifndef CONFIG_RTAI_LXRT_INLINE
#define CONFIG_RTAI_LXRT_INLINE CONFIG_RTAI_INTERNAL_LXRT_INLINE
#endif /* !CONFIG_RTAI_LXRT_INLINE */
#define __hidefun(name) name ## _hidden_inline
#if CONFIG_RTAI_LXRT_INLINE == 1
#define RTAI_PROTO(type,name,arglist) static inline type name arglist
#elif CONFIG_RTAI_LXRT_INLINE == 2
#define RTAI_PROTO(type,name,arglist) extern inline type name arglist
#elif CONFIG_RTAI_LXRT_INLINE == 3
#define RTAI_PROTO(type,name,arglist) type name arglist; static inline type __hidefun(name) arglist
#else
#define RTAI_PROTO(type,name,arglist) type name arglist
#endif /* CONFIG_RTAI_LXRT_INLINE */
#define RTAI_PROTO_ALWAYS_INLINE(type,name,arglist) static inline type name arglist
#define RTAI_PROTO_NEVER_INLINE(type,name,arglist) type name arglist; static inline type __hidefun(name) arglist


/* Kconfig */
/* #undef CONFIG_RTAI_LXRT_USE_LINUX_SYSCALL */

/* Kconfig */
/* #undef CONFIG_RTAI_MAINTAINER */

/* Kconfig */
/* #undef CONFIG_RTAI_MAINTAINER_PGM */

/* Kconfig */
/* #undef CONFIG_RTAI_MAINTAINER_PMA */

/* Kconfig */
#define CONFIG_RTAI_MALLOC 1

/* Kconfig */
#define CONFIG_RTAI_MALLOC_BUILTIN 1

/* Kconfig */
#define CONFIG_RTAI_MALLOC_HEAPSZ 2048

/* Kconfig */
#define CONFIG_RTAI_MALLOC_VMALLOC 1

/* Kconfig */
/* #undef CONFIG_RTAI_MASTER_TSC_CPU */

/* Kconfig */
/* #undef CONFIG_RTAI_MATH */

/* Kconfig */
/* #undef CONFIG_RTAI_MATH_BUILTIN */

/* Kconfig */
/* #undef CONFIG_RTAI_MATH_C99 */

/* Kconfig */
/* #undef CONFIG_RTAI_MATH_KCOMPLEX */

/* Kconfig */
#define CONFIG_RTAI_MATH_LIBM_TO_USE 

/* Kconfig */
#define CONFIG_RTAI_MBX 1

/* Kconfig */
/* #undef CONFIG_RTAI_MBX_BUILTIN */

/* Kconfig */
#define CONFIG_RTAI_MONITOR_EXECTIME 1

/* Legacy */
#define CONFIG_RTAI_MOUNT_ON_LOAD 1

/* Kconfig */
#define CONFIG_RTAI_MQ 1

/* Kconfig */
/* #undef CONFIG_RTAI_MQ_BUILTIN */

/* Kconfig */
#define CONFIG_RTAI_MSG 1

/* Kconfig */
/* #undef CONFIG_RTAI_MSG_BUILTIN */

/* Kconfig */
#define CONFIG_RTAI_NETRPC 1

/* Kconfig */
/* #undef CONFIG_RTAI_NETRPC_BUILTIN */

/* Kconfig */
/* #undef CONFIG_RTAI_NETRPC_RTNET */

/* Kconfig */
#define CONFIG_RTAI_ONE_SHOT 0

/* Kconfig */
#define CONFIG_RTAI_REVISION_LEVEL 0

/* Kconfig */
#define CONFIG_RTAI_RTC_FREQ 0

/* Kconfig */
#define CONFIG_RTAI_RTDM 1

/* Kconfig */
#define CONFIG_RTAI_RTDM_FD_MAX 128

/* Kconfig */
#define CONFIG_RTAI_RTDM_SELECT 1

/* Kconfig */
#define CONFIG_RTAI_RTDM_SHIRQ 1

/* Kconfig */
/* #undef CONFIG_RTAI_RT_POLL */

/* Kconfig */
/* #undef CONFIG_RTAI_RT_POLL_ON_STACK */

/* Kconfig */
#define CONFIG_RTAI_SCHED_8254_LATENCY 

/* Kconfig */
/* #undef CONFIG_RTAI_SCHED_ISR_LOCK */

/* Kconfig */
#define CONFIG_RTAI_SCHED_LXRT_NUMSLOTS 150

/* Kconfig */
#define CONFIG_RTAI_SEM 1

/* Kconfig */
/* #undef CONFIG_RTAI_SEM_BUILTIN */

/* Kconfig */
#define CONFIG_RTAI_SHM 1

/* Kconfig */
/* #undef CONFIG_RTAI_SHM_BUILTIN */

/* Kconfig */
#define CONFIG_RTAI_TASKLETS 1

/* Kconfig */
/* #undef CONFIG_RTAI_TASKLETS_BUILTIN */

/* Kconfig */
/* #undef CONFIG_RTAI_TASK_SWITCH_SIGNAL */

/* Kconfig */
#define CONFIG_RTAI_TBX 1

/* Kconfig */
/* #undef CONFIG_RTAI_TBX_BUILTIN */

/* Kconfig */
/* #undef CONFIG_RTAI_TRACE */

/* Use TSC in user space */
#define CONFIG_RTAI_TSC 1

/* Kconfig */
/* #undef CONFIG_RTAI_TUNE_TSC_SYNC */

/* Kconfig */
#define CONFIG_RTAI_USER_BUSY_ALIGN_RET_DELAY 0

/* Kconfig */
/* #undef CONFIG_RTAI_USE_COMEDI_LOCK */

/* Kconfig */
/* #undef CONFIG_RTAI_USE_LINUX_COMEDI */

/* Kconfig */
#define CONFIG_RTAI_USE_NEWERR 1

/* Kconfig */
/* #undef CONFIG_RTAI_USE_STACK_ARGS */

/* Kconfig */
/* #undef CONFIG_RTAI_USE_TLSF */

/* Kconfig */
/* #undef CONFIG_RTAI_USI */

/* Kconfig */
/* #undef CONFIG_RTAI_USI_BUILTIN */

/* Kconfig */
#define CONFIG_RTAI_VERSION_MAJOR 5

/* Kconfig */
#define CONFIG_RTAI_VERSION_MINOR 1

/* Kconfig */
#define CONFIG_RTAI_WD 1

#ifdef __IN_RTAI__

/* Define to 1 if you have the <dlfcn.h> header file. */
#define HAVE_DLFCN_H 1

/* Define to 1 if you have the <inttypes.h> header file. */
#define HAVE_INTTYPES_H 1

/* Define to 1 if you have the <memory.h> header file. */
#define HAVE_MEMORY_H 1

/* have libpci */
/* #undef HAVE_PCI */

/* Define to 1 if you have the <stdint.h> header file. */
#define HAVE_STDINT_H 1

/* Define to 1 if you have the <stdlib.h> header file. */
#define HAVE_STDLIB_H 1

/* Define to 1 if you have the <strings.h> header file. */
#define HAVE_STRINGS_H 1

/* Define to 1 if you have the <string.h> header file. */
#define HAVE_STRING_H 1

/* Define to 1 if you have the <sys/stat.h> header file. */
#define HAVE_SYS_STAT_H 1

/* Define to 1 if you have the <sys/types.h> header file. */
#define HAVE_SYS_TYPES_H 1

/* Define to 1 if you have the <unistd.h> header file. */
#define HAVE_UNISTD_H 1

/* Define to the sub-directory in which libtool stores uninstalled libraries.
   */
#define LT_OBJDIR ".libs/"

/* Name of package */
#define PACKAGE "rtai"

/* Define to the address where bug reports for this package should be sent. */
#define PACKAGE_BUGREPORT "rtai@rtai.org"

/* Define to the full name of this package. */
#define PACKAGE_NAME "rtai"

/* Define to the full name and version of this package. */
#define PACKAGE_STRING "rtai 5.1"

/* Define to the one symbol short name of this package. */
#define PACKAGE_TARNAME "rtai"

/* Define to the home page for this package. */
#define PACKAGE_URL ""

/* Define to the version of this package. */
#define PACKAGE_VERSION "5.1"

/* Define to 1 if you have the ANSI C header files. */
#define STDC_HEADERS 1

/* Version number of package */
#define VERSION "5.1"

/* Define to 1 if the X Window System is missing or not being used. */
/* #undef X_DISPLAY_MISSING */

#endif /* __IN_RTAI__ */
