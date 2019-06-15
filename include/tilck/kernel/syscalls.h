/* SPDX-License-Identifier: BSD-2-Clause */

#pragma once
#include <tilck/common/basic_defs.h>
#include <tilck/common/string_util.h>
#include <tilck/common/syscalls.h>

#include <tilck/kernel/errno.h>
#include <tilck/kernel/datetime.h>
#include <tilck/kernel/sched.h>
#include <tilck/kernel/signal.h>
#include <tilck/kernel/sys_types.h>

#ifdef __SYSCALLS_C__

   #define CREATE_STUB_SYSCALL_IMPL(name)                  \
      int name()                                           \
      {                                                    \
         printk("[TID: %d] NOT IMPLEMENTED: %s()\n",       \
                get_curr_task_tid(), #name);               \
         return -ENOSYS;                                   \
      }

#else

   #define CREATE_STUB_SYSCALL_IMPL(name) sptr name();

#endif

CREATE_STUB_SYSCALL_IMPL(sys_restart_syscall)

int sys_exit(int code);
int sys_fork(void);
int sys_read(int fd, void *buf, size_t count);
int sys_write(int fd, const void *buf, size_t count);
int sys_open(const char *pathname, int flags, mode_t mode);
int sys_close(int fd);
int sys_waitpid(int pid, int *wstatus, int options);
int sys_creat(const char *pathname, mode_t mode);

CREATE_STUB_SYSCALL_IMPL(sys_link)

int sys_unlink(const char *pathname);

int sys_execve(const char *filename,
               const char *const *argv,
               const char *const *env);

int sys_chdir(const char *path);

CREATE_STUB_SYSCALL_IMPL(sys_time)
CREATE_STUB_SYSCALL_IMPL(sys_mknod)
CREATE_STUB_SYSCALL_IMPL(sys_chmod)
CREATE_STUB_SYSCALL_IMPL(sys_lchown16)
CREATE_STUB_SYSCALL_IMPL(sys_break)
CREATE_STUB_SYSCALL_IMPL(sys_oldstat)
CREATE_STUB_SYSCALL_IMPL(sys_lseek)

int sys_getpid();

int sys_mount(const char *user_source,
              const char *user_target,
              const char *user_filesystemtype,
              unsigned long mountflags,
              const void *user_data);

CREATE_STUB_SYSCALL_IMPL(sys_oldumount)

int sys_setuid16(uptr uid);
int sys_getuid16();

CREATE_STUB_SYSCALL_IMPL(sys_stime)
CREATE_STUB_SYSCALL_IMPL(sys_ptrace)
CREATE_STUB_SYSCALL_IMPL(sys_alarm)
CREATE_STUB_SYSCALL_IMPL(sys_oldfstat)

int sys_pause(); // TODO: update once signals are implemented

CREATE_STUB_SYSCALL_IMPL(sys_utime)

int sys_access(const char *pathname, int mode);

CREATE_STUB_SYSCALL_IMPL(sys_nice)
CREATE_STUB_SYSCALL_IMPL(sys_sync)

int sys_kill(int pid, int sig);

CREATE_STUB_SYSCALL_IMPL(sys_rename)

int sys_mkdir(const char *user_path, mode_t mode);
int sys_rmdir(const char *user_path);
int sys_dup(int oldfd);

CREATE_STUB_SYSCALL_IMPL(sys_pipe)

uptr sys_times(struct tms *user_buf);
void *sys_brk(void *vaddr);
int sys_setgid16(uptr gid);
int sys_getgid16();

CREATE_STUB_SYSCALL_IMPL(sys_signal)

int sys_geteuid16();
int sys_getegid16();

CREATE_STUB_SYSCALL_IMPL(sys_acct)

int sys_umount(const char *target, int flags);
int sys_ioctl(int fd, uptr request, void *argp);

CREATE_STUB_SYSCALL_IMPL(sys_fcntl)
CREATE_STUB_SYSCALL_IMPL(sys_setpgid)
CREATE_STUB_SYSCALL_IMPL(sys_olduname)

mode_t sys_umask(mode_t mask);

CREATE_STUB_SYSCALL_IMPL(sys_chroot)
CREATE_STUB_SYSCALL_IMPL(sys_ustat)

int sys_dup2(int oldfd, int newfd);
int sys_getppid();

CREATE_STUB_SYSCALL_IMPL(sys_getpgrp)

int sys_setsid(void);
int sys_sigaction(uptr a1, uptr a2, uptr a3); // deprecated interface

CREATE_STUB_SYSCALL_IMPL(sys_sgetmask)
CREATE_STUB_SYSCALL_IMPL(sys_ssetmask)
CREATE_STUB_SYSCALL_IMPL(sys_setreuid16)
CREATE_STUB_SYSCALL_IMPL(sys_setregid16)
CREATE_STUB_SYSCALL_IMPL(sys_sigsuspend)
CREATE_STUB_SYSCALL_IMPL(sys_sigpending)
CREATE_STUB_SYSCALL_IMPL(sys_sethostname)
CREATE_STUB_SYSCALL_IMPL(sys_setrlimit)
CREATE_STUB_SYSCALL_IMPL(sys_old_getrlimit)
CREATE_STUB_SYSCALL_IMPL(sys_getrusage)

int sys_gettimeofday(struct timeval *tv, struct timezone *tz);

CREATE_STUB_SYSCALL_IMPL(sys_settimeofday)
CREATE_STUB_SYSCALL_IMPL(sys_getgroups16)
CREATE_STUB_SYSCALL_IMPL(sys_setgroups16)
CREATE_STUB_SYSCALL_IMPL(sys_old_select)
CREATE_STUB_SYSCALL_IMPL(sys_symlink)
CREATE_STUB_SYSCALL_IMPL(sys_lstat)

int sys_readlink(const char *u_pathname, char *u_buf, size_t u_bufsize);

CREATE_STUB_SYSCALL_IMPL(sys_uselib)
CREATE_STUB_SYSCALL_IMPL(sys_swapon)
CREATE_STUB_SYSCALL_IMPL(sys_reboot)
CREATE_STUB_SYSCALL_IMPL(sys_old_readdir)
CREATE_STUB_SYSCALL_IMPL(sys_old_mmap)

int sys_munmap(void *vaddr, size_t len);

CREATE_STUB_SYSCALL_IMPL(sys_truncate)
CREATE_STUB_SYSCALL_IMPL(sys_ftruncate)
CREATE_STUB_SYSCALL_IMPL(sys_fchmod)
CREATE_STUB_SYSCALL_IMPL(sys_fchown16)
CREATE_STUB_SYSCALL_IMPL(sys_getpriority)
CREATE_STUB_SYSCALL_IMPL(sys_setpriority)
CREATE_STUB_SYSCALL_IMPL(sys_statfs)
CREATE_STUB_SYSCALL_IMPL(sys_fstatfs)
CREATE_STUB_SYSCALL_IMPL(sys_ioperm)
CREATE_STUB_SYSCALL_IMPL(sys_socketcall)
CREATE_STUB_SYSCALL_IMPL(sys_syslog)
CREATE_STUB_SYSCALL_IMPL(sys_setitimer)
CREATE_STUB_SYSCALL_IMPL(sys_getitimer)
CREATE_STUB_SYSCALL_IMPL(sys_newstat)
CREATE_STUB_SYSCALL_IMPL(sys_newlstat)
CREATE_STUB_SYSCALL_IMPL(sys_newfstat)
CREATE_STUB_SYSCALL_IMPL(sys_uname)
CREATE_STUB_SYSCALL_IMPL(sys_iopl)
CREATE_STUB_SYSCALL_IMPL(sys_vhangup)
CREATE_STUB_SYSCALL_IMPL(sys_vm86old)

int sys_wait4(int pid, int *wstatus, int options, void *user_rusage);

CREATE_STUB_SYSCALL_IMPL(sys_swapoff)
CREATE_STUB_SYSCALL_IMPL(sys_sysinfo)
CREATE_STUB_SYSCALL_IMPL(sys_ipc)
CREATE_STUB_SYSCALL_IMPL(sys_fsync)
CREATE_STUB_SYSCALL_IMPL(sys_sigreturn)
CREATE_STUB_SYSCALL_IMPL(sys_clone)
CREATE_STUB_SYSCALL_IMPL(sys_setsetdomainname)

int sys_newuname(struct utsname *buf);

CREATE_STUB_SYSCALL_IMPL(sys_modify_ldt)
CREATE_STUB_SYSCALL_IMPL(sys_adjtimex)
CREATE_STUB_SYSCALL_IMPL(sys_mprotect)

int sys_sigprocmask(uptr a1, uptr a2, uptr a3); // deprecated interface

CREATE_STUB_SYSCALL_IMPL(sys_init_module)
CREATE_STUB_SYSCALL_IMPL(sys_delete_module)
CREATE_STUB_SYSCALL_IMPL(sys_quotactl)
CREATE_STUB_SYSCALL_IMPL(sys_getpgid)
CREATE_STUB_SYSCALL_IMPL(sys_fchdir)
CREATE_STUB_SYSCALL_IMPL(sys_bdflush)
CREATE_STUB_SYSCALL_IMPL(sys_sysfs)
CREATE_STUB_SYSCALL_IMPL(sys_personality)
CREATE_STUB_SYSCALL_IMPL(sys_setfsuid16)
CREATE_STUB_SYSCALL_IMPL(sys_setfsgid16)

int sys_llseek(int fd, size_t off_hi, size_t off_low, u64 *result, u32 whence);

CREATE_STUB_SYSCALL_IMPL(sys_getdents)

int sys_select(int nfds, fd_set *readfds, fd_set *writefds,
               fd_set *exceptfds, struct timeval *timeout);

CREATE_STUB_SYSCALL_IMPL(sys_flock)
CREATE_STUB_SYSCALL_IMPL(sys_msync)

int sys_readv(int fd, const struct iovec *iov, int iovcnt);
int sys_writev(int fd, const struct iovec *iov, int iovcnt);
int sys_getsid(int pid);

CREATE_STUB_SYSCALL_IMPL(sys_fdatasync)
CREATE_STUB_SYSCALL_IMPL(sys_sysctl)
CREATE_STUB_SYSCALL_IMPL(sys_mlock)
CREATE_STUB_SYSCALL_IMPL(sys_munlock)
CREATE_STUB_SYSCALL_IMPL(sys_mlockall)
CREATE_STUB_SYSCALL_IMPL(sys_munlockall)
CREATE_STUB_SYSCALL_IMPL(sys_sched_setparam)
CREATE_STUB_SYSCALL_IMPL(sys_sched_getparam)
CREATE_STUB_SYSCALL_IMPL(sys_sched_setscheduler)
CREATE_STUB_SYSCALL_IMPL(sys_sched_getscheduler)
CREATE_STUB_SYSCALL_IMPL(sys_sched_yield)
CREATE_STUB_SYSCALL_IMPL(sys_sched_get_priority_max)
CREATE_STUB_SYSCALL_IMPL(sys_sched_set_priority_min)
CREATE_STUB_SYSCALL_IMPL(sys_sched_rr_get_interval)

int sys_nanosleep(const struct timespec *req, struct timespec *rem);

CREATE_STUB_SYSCALL_IMPL(sys_mremap)
CREATE_STUB_SYSCALL_IMPL(sys_setresuid16)
CREATE_STUB_SYSCALL_IMPL(sys_getresuid16)
CREATE_STUB_SYSCALL_IMPL(sys_vm86)

int sys_poll(struct pollfd *fds, nfds_t nfds, int timeout);

CREATE_STUB_SYSCALL_IMPL(sys_nfsservctl)
CREATE_STUB_SYSCALL_IMPL(sys_setresgid16)
CREATE_STUB_SYSCALL_IMPL(sys_getresgid16)

int sys_prctl(int option, uptr a2, uptr a3, uptr a4, uptr a5);

CREATE_STUB_SYSCALL_IMPL(sys_rt_sigreturn)

sptr
sys_rt_sigaction(int signum,
                 const struct k_sigaction *act,
                 struct k_sigaction *oldact,
                 size_t);

sptr
sys_rt_sigprocmask(int how, sigset_t *set,
                   sigset_t *oset, size_t sigsetsize);

CREATE_STUB_SYSCALL_IMPL(sys_rt_sigpending)
CREATE_STUB_SYSCALL_IMPL(sys_rt_sigtimedwait)
CREATE_STUB_SYSCALL_IMPL(sys_rt_sigqueueinfo)
CREATE_STUB_SYSCALL_IMPL(sys_rt_sigsuspend)
CREATE_STUB_SYSCALL_IMPL(sys_pread64)
CREATE_STUB_SYSCALL_IMPL(sys_pwrite64)
CREATE_STUB_SYSCALL_IMPL(sys_chown16)

int sys_getcwd(char *buf, size_t buf_size);

CREATE_STUB_SYSCALL_IMPL(sys_capget)
CREATE_STUB_SYSCALL_IMPL(sys_capset)
CREATE_STUB_SYSCALL_IMPL(sys_sigaltstack)
CREATE_STUB_SYSCALL_IMPL(sys_sendfile)

int sys_vfork();

CREATE_STUB_SYSCALL_IMPL(sys_getrlimit)

sptr sys_mmap_pgoff(void *addr, size_t length, int prot,
                    int flags, int fd, size_t pgoffset);

int sys_truncate64(const char *user_path, s64 length);

CREATE_STUB_SYSCALL_IMPL(sys_ftruncate64)

int sys_stat64(const char *user_path, struct stat64 *user_statbuf);
int sys_lstat64(const char *user_path, struct stat64 *user_statbuf);
int sys_fstat64(int fd, struct stat64 *user_statbuf);

CREATE_STUB_SYSCALL_IMPL(sys_lchown)

int sys_getuid();
int sys_getgid();
int sys_geteuid();
int sys_getegid();

CREATE_STUB_SYSCALL_IMPL(sys_setreuid)
CREATE_STUB_SYSCALL_IMPL(sys_setregid)
CREATE_STUB_SYSCALL_IMPL(sys_getgroups)
CREATE_STUB_SYSCALL_IMPL(sys_setgroups)
CREATE_STUB_SYSCALL_IMPL(sys_fchown)
CREATE_STUB_SYSCALL_IMPL(sys_setresuid)
CREATE_STUB_SYSCALL_IMPL(sys_getresuid)
CREATE_STUB_SYSCALL_IMPL(sys_setresgid)
CREATE_STUB_SYSCALL_IMPL(sys_getresgid)
CREATE_STUB_SYSCALL_IMPL(sys_chown)

int sys_setuid(uptr uid);
int sys_setgid(uptr gid);

CREATE_STUB_SYSCALL_IMPL(sys_setfsuid)
CREATE_STUB_SYSCALL_IMPL(sys_setfsgid)
CREATE_STUB_SYSCALL_IMPL(sys_pivot_root)
CREATE_STUB_SYSCALL_IMPL(sys_mincore)

int sys_madvise(void *addr, size_t len, int advice);

int sys_getdents64(int fd, struct linux_dirent64 *dirp, u32 buf_size);
int sys_fcntl64(int fd, int cmd, int arg);
int sys_gettid();

CREATE_STUB_SYSCALL_IMPL(sys_readahead)
CREATE_STUB_SYSCALL_IMPL(sys_setxattr)
CREATE_STUB_SYSCALL_IMPL(sys_lsetxattr)
CREATE_STUB_SYSCALL_IMPL(sys_fsetxattr)
CREATE_STUB_SYSCALL_IMPL(sys_getxattr)
CREATE_STUB_SYSCALL_IMPL(sys_lgetxattr)
CREATE_STUB_SYSCALL_IMPL(sys_fgetxattr)
CREATE_STUB_SYSCALL_IMPL(sys_listxattr)
CREATE_STUB_SYSCALL_IMPL(sys_llistxattr)
CREATE_STUB_SYSCALL_IMPL(sys_flistxattr)
CREATE_STUB_SYSCALL_IMPL(sys_removexattr)
CREATE_STUB_SYSCALL_IMPL(sys_lremovexattr)
CREATE_STUB_SYSCALL_IMPL(sys_fremovexattr)

int sys_tkill(int tid, int sig);

CREATE_STUB_SYSCALL_IMPL(sys_sendfile64)
CREATE_STUB_SYSCALL_IMPL(sys_futex)
CREATE_STUB_SYSCALL_IMPL(sys_sched_setaffinity)
CREATE_STUB_SYSCALL_IMPL(sys_sched_getaffinity)

int sys_set_thread_area(void *u_info);

CREATE_STUB_SYSCALL_IMPL(sys_get_thread_area)
CREATE_STUB_SYSCALL_IMPL(sys_io_setup)
CREATE_STUB_SYSCALL_IMPL(sys_io_destroy)
CREATE_STUB_SYSCALL_IMPL(sys_io_getevents)
CREATE_STUB_SYSCALL_IMPL(sys_io_submit)
CREATE_STUB_SYSCALL_IMPL(sys_io_cancel)
CREATE_STUB_SYSCALL_IMPL(sys_fadvise64)

NORETURN int sys_exit_group(int status);

CREATE_STUB_SYSCALL_IMPL(sys_lookup_dcookie)
CREATE_STUB_SYSCALL_IMPL(sys_epoll_create)
CREATE_STUB_SYSCALL_IMPL(sys_epoll_ctl)
CREATE_STUB_SYSCALL_IMPL(sys_epoll_wait)
CREATE_STUB_SYSCALL_IMPL(sys_remap_file_pages)

// TODO: complete the implementation when thread creation is implemented.
int sys_set_tid_address(int *tidptr);

CREATE_STUB_SYSCALL_IMPL(sys_timer_create)
CREATE_STUB_SYSCALL_IMPL(sys_timer_settime)
CREATE_STUB_SYSCALL_IMPL(sys_timer_gettime)
CREATE_STUB_SYSCALL_IMPL(sys_timer_getoverrun)
CREATE_STUB_SYSCALL_IMPL(sys_timer_delete)
CREATE_STUB_SYSCALL_IMPL(sys_clock_settime)

int sys_clock_gettime(clockid_t clk_id, struct timespec *tp);
int sys_clock_getres(clockid_t clk_id, struct timespec *res);

CREATE_STUB_SYSCALL_IMPL(sys_clock_nanosleep)
CREATE_STUB_SYSCALL_IMPL(sys_statfs64)
CREATE_STUB_SYSCALL_IMPL(sys_fstatfs64)

int sys_tgkill(int pid /* linux: tgid */, int tid, int sig);

CREATE_STUB_SYSCALL_IMPL(sys_utimes)
CREATE_STUB_SYSCALL_IMPL(sys_fadvise64_64)
CREATE_STUB_SYSCALL_IMPL(sys_mbind)
CREATE_STUB_SYSCALL_IMPL(sys_get_mempolicy)
CREATE_STUB_SYSCALL_IMPL(sys_set_mempolicy)
CREATE_STUB_SYSCALL_IMPL(sys_mq_open)
CREATE_STUB_SYSCALL_IMPL(sys_mq_unlink)
CREATE_STUB_SYSCALL_IMPL(sys_mq_timedsend)
CREATE_STUB_SYSCALL_IMPL(sys_mq_timedreceive)
CREATE_STUB_SYSCALL_IMPL(sys_mq_notify)
CREATE_STUB_SYSCALL_IMPL(sys_mq_getsetattr)
CREATE_STUB_SYSCALL_IMPL(sys_kexec_load)
CREATE_STUB_SYSCALL_IMPL(sys_waitid)
CREATE_STUB_SYSCALL_IMPL(sys_add_key)
CREATE_STUB_SYSCALL_IMPL(sys_request_key)
CREATE_STUB_SYSCALL_IMPL(sys_keyctl)
CREATE_STUB_SYSCALL_IMPL(sys_ioprio_set)
CREATE_STUB_SYSCALL_IMPL(sys_ioprio_get)
CREATE_STUB_SYSCALL_IMPL(sys_inotify_init)
CREATE_STUB_SYSCALL_IMPL(sys_inotify_add_watch)
CREATE_STUB_SYSCALL_IMPL(sys_inotify_rm_watch)
CREATE_STUB_SYSCALL_IMPL(sys_migrate_pages)
CREATE_STUB_SYSCALL_IMPL(sys_openat)
CREATE_STUB_SYSCALL_IMPL(sys_mkdirat)
CREATE_STUB_SYSCALL_IMPL(sys_mknodat)
CREATE_STUB_SYSCALL_IMPL(sys_fchownat)
CREATE_STUB_SYSCALL_IMPL(sys_futimesat)
CREATE_STUB_SYSCALL_IMPL(sys_fstatat64)
CREATE_STUB_SYSCALL_IMPL(sys_unlinkat)
CREATE_STUB_SYSCALL_IMPL(sys_renameat)
CREATE_STUB_SYSCALL_IMPL(sys_linkat)
CREATE_STUB_SYSCALL_IMPL(sys_symlinkat)
CREATE_STUB_SYSCALL_IMPL(sys_readlinkat)
CREATE_STUB_SYSCALL_IMPL(sys_fchmodat)
CREATE_STUB_SYSCALL_IMPL(sys_faccessat)
CREATE_STUB_SYSCALL_IMPL(sys_pselect6)
CREATE_STUB_SYSCALL_IMPL(sys_ppoll)
CREATE_STUB_SYSCALL_IMPL(sys_unshare)
CREATE_STUB_SYSCALL_IMPL(sys_set_robust_list)
CREATE_STUB_SYSCALL_IMPL(sys_get_robust_list)
CREATE_STUB_SYSCALL_IMPL(sys_splice)
CREATE_STUB_SYSCALL_IMPL(sys_sync_file_range)
CREATE_STUB_SYSCALL_IMPL(sys_tee)
CREATE_STUB_SYSCALL_IMPL(sys_vmsplice)
CREATE_STUB_SYSCALL_IMPL(sys_move_pages)
CREATE_STUB_SYSCALL_IMPL(sys_getcpu)
CREATE_STUB_SYSCALL_IMPL(sys_epoll_pwait)
CREATE_STUB_SYSCALL_IMPL(sys_utimensat)
CREATE_STUB_SYSCALL_IMPL(sys_signalfd)
CREATE_STUB_SYSCALL_IMPL(sys_timerfd_create)
CREATE_STUB_SYSCALL_IMPL(sys_eventfd)
CREATE_STUB_SYSCALL_IMPL(sys_fallocate)
CREATE_STUB_SYSCALL_IMPL(sys_timerfd_settime)
CREATE_STUB_SYSCALL_IMPL(sys_timerfd_gettime)
CREATE_STUB_SYSCALL_IMPL(sys_signalfd4)
CREATE_STUB_SYSCALL_IMPL(sys_eventfd2)
CREATE_STUB_SYSCALL_IMPL(sys_epoll_create1)
CREATE_STUB_SYSCALL_IMPL(sys_dup3)
CREATE_STUB_SYSCALL_IMPL(sys_pipe2)
CREATE_STUB_SYSCALL_IMPL(sys_inotify_init1)
CREATE_STUB_SYSCALL_IMPL(sys_preadv)
CREATE_STUB_SYSCALL_IMPL(sys_pwritev)
CREATE_STUB_SYSCALL_IMPL(sys_rt_tgsigqueueinfo)
CREATE_STUB_SYSCALL_IMPL(sys_perf_event_open)
CREATE_STUB_SYSCALL_IMPL(sys_recvmmsg)

int sys_tilck_cmd(enum tilck_testcmd_type cmd,
                  uptr a1, uptr a2, uptr a3, uptr a4);
