#include <unistd.h>

int access (const char *name, int type);
off_t lseek (int fd, off_t offset, int whence);
off64_t lseek64 (int fd, off64_t offset, int whence);
int close (int fd);
ssize_t read (int fd, void *buf, size_t nbytes);
ssize_t write (int fd, const void *buf, size_t n)
ssize_t pread (int fd, void *buf, size_t nbytes, off_t offset);
ssize_t pwrite (int fd, const void *buf, size_t n, off_t offset)
ssize_t pread64 (int fd, void *buf, size_t nbytes,
			off64_t offset);
ssize_t pwrite64 (int fd, const void *buf, size_t n,
			 off64_t offset)
int pipe (int pipedes[2]);
int pipe2 (int pipedes[2], int flags);
unsigned int sleep (unsigned int seconds);
int chown (const char *file, uid_t owner, gid_t group);
int fchown (int fd, uid_t owner, gid_t group);
int lchown (const char *file, uid_t owner, gid_t group);
int chdir (const char *path);
int fchdir (int fd);
char *getcwd (char *buf, size_t size);
int dup (int fd);
int dup2 (int fd, int fd2);
int dup3 (int fd, int fd2, int flags);
int execve (const char *path, char *const argv[], char *const envp[]);
long int pathconf (const char *path, int name);
long int fpathconf (int fd, int name);
long int sysconf (int name);
size_t confstr (int name, char *buf, size_t len);
pid_t getpid (void);
pid_t getppid (void);
int setpgid (pid_t pid, pid_t pgid);
pid_t setsid (void);
uid_t getuid (void);
uid_t geteuid (void);
gid_t getgid (void);
gid_t getegid (void);
int getgroups (int size, gid_t list[]);
int group_member (gid_t gid);
int setuid (uid_t uid);
int setreuid (uid_t ruid, uid_t euid);
int setgid (gid_t gid);
int setregid (gid_t rgid, gid_t egid);
int setresuid (uid_t ruid, uid_t euid, uid_t suid);
int setresgid (gid_t rgid, gid_t egid, gid_t sgid);
pid_t fork (void);
pid_t vfork (void);
int ttyname_r (int fd, char *buf, size_t buflen);
int isatty (int fd);
int link (const char *from, const char *to);
int symlink (const char *from, const char *to);
ssize_t readlink (const char *restrict path, char *restrict buf, size_t len);
int unlink (const char *name);
int rmdir (const char *path);
int getlogin_r (char *name, size_t name_len);
int gethostname (char *name, size_t len);
int revoke (const char *file);
int profil (unsigned short int *sample_buffer, size_t size, size_t offset, unsigned int scale);
int getpagesize (void);
int getdtablesize (void);
int truncate64 (const char *file, off64_t length);
int ftruncate (int fd, off_t length);
int ftruncate64 (int fd, off64_t length);
int brk (void *addr);
void *sbrk (intptr_t delta);
int lockf64 (int fd, int cmd, off64_t len);

/* no  name*/
// alarm
// ualarm
// usleep
// pause -> libc_pause
// fchownat
// fexecve
// nice
// _exit
// getpgrp
// setpgrp
// getsid
// seteuid
// setegid
// getresuid
// getresgid
// ttyname
// linkat
// symlinkat
// readlinkat
// unlinkat
// tcgetpgrp
// tcsetpgrp
// getlogin
// setlogin
// sethostname
// sethostid
// getdomainname
// setdomainname
// vhangup
// acct
// getusershell
// endusershell
// setusershell
// daemon
// chroot
// getpass
// fsync
// syncfs
// gethostid
// sync
// truncate
// syscall
// lockf

// no reason
// execv execle execl execvp execlp execvpe

// ?
// getpgid