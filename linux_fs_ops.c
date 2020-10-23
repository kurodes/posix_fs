// https://pubs.opengroup.org/onlinepubs/009695399/basedefs/fcntl.h.html
// POSIX Standard: 6.5 File Control Operations (statement from fcntl.h file)
#include <fcntl.h> //fcntl=file control
// https://pubs.opengroup.org/onlinepubs/009695399/functions/open.html
// ret fd
extern int open(const char *path, int oflag, ... );
// https://pubs.opengroup.org/onlinepubs/009695399/functions/creat.html
// ret fd
extern int creat(const char *path, mode_t mode);

extern int fcntl(int fildes, int cmd, ...); //fildes=file descriptor



// https://pubs.opengroup.org/onlinepubs/009695399/basedefs/sys/stat.h.html
// POSIX Standard: 5.6 File Characteristics
#include <sys/stat.h>
// https://pubs.opengroup.org/onlinepubs/009695399/functions/chmod.html
// ret 0/-1
extern int chmod(const char *path, mode_t mode);
extern int fchmod(int fildes, mode_t mode); // equivalent to chmod(), but with file descriptor
// https://pubs.opengroup.org/onlinepubs/009695399/functions/stat.html
// ret 0/-1
extern int stat(const char *restrict path, struct stat *restrict buf);
extern int fstat(int fildes, struct stat *buf); // equivalent to stat(), but with file descriptor
extern int lstat(const char *restrict path, struct stat *restrict buf); // equivalent to stat(), but path refers to a symbolic link
/**
 * umask - set and get the file mode creation mask
 * https://pubs.opengroup.org/onlinepubs/009695399/functions/umask.html
 * The process' file mode creation mask is used to turn off permission bits in the mode argument
 */
extern mode_t umask(mode_t cmask);
/**
 * mknod - make a directory, a special file, or a regular file
 * https://pubs.opengroup.org/onlinepubs/009695399/functions/mknod.html
 * 'The file type for path' and 'the permissions for the new file' are OR'ed into the mode argument
 * permission bits:
 *     The user ID of the file shall be initialized to the effective user ID of the process.
 *     Implementations shall provide a way to initialize the file's group ID to the group ID of the parent directory. 
 *     The owner, group, and other permission bits of mode shall be modified by the file mode creation mask of the process.(clear each bit who is set in the mask)
 * the st_ctime and st_mtime fields of the directory that contains the new entry shall be marked for update.
 */
extern int mknod(const char *path, mode_t mode, dev_t dev);
/**
 * mkfifo - make a FIFO special file
 * https://pubs.opengroup.org/onlinepubs/009695399/functions/mkfifo.html
 * permission bits:
 *     mknod()
 * the st_ctime and st_mtime fields of the directory that contains the new entry shall be marked for update.
 * ret 0/-1
 */
extern int mkfifo(const char *path, mode_t mode);
/**
 * https://pubs.opengroup.org/onlinepubs/009695399/functions/mkdir.html
 * permission bits:
 *     mknod()
 * the st_ctime and st_mtime fields of the directory that contains the new entry shall be marked for update.
 * ret 0/-1
 */
extern int mkdir(const char *path, mode_t mode);



// https://pubs.opengroup.org/onlinepubs/009695399/basedefs/unistd.h.html
// POSIX Standard: 2.10 Symbolic Constants
#include <unistd.h> //unistd=unix standard

/** 
 * https://pubs.opengroup.org/onlinepubs/009695399/functions/access.html
 * access - test accessibility of a file
 * amode:
 *      OR of the access permissions to be checked (R_OK, W_OK, X_OK) or the existence test (F_OK).
 * an implementation may indicate success for X_OK even if none of the execute file permission bits are set.
 * ret 0/-1
 */
extern int access(const char *path, int amode);
/**
 * https://pubs.opengroup.org/onlinepubs/009695399/functions/chdir.html
 * chdir - change working directory
 * ret 0/-1
 */
extern int chdir(const char *path);
/**
 * https://pubs.opengroup.org/onlinepubs/009695399/functions/chown.html
 * ret 0/-1
 */
extern int chown(const char *path, uid_t owner, gid_t group);

/**
 * https://pubs.opengroup.org/onlinepubs/009695399/functions/close.html
 * close - close a file descriptor
 * 
 */