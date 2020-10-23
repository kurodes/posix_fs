// POSIX Standard: 6.5 File Control Operations
// https://pubs.opengroup.org/onlinepubs/009695399/basedefs/fcntl.h.html
#include <fcntl.h>
// https://pubs.opengroup.org/onlinepubs/009695399/functions/open.html
// ret fd
extern int open(const char *path, int oflag, ... );
// https://pubs.opengroup.org/onlinepubs/009695399/functions/creat.html
// ret fd
extern int creat(const char *path, mode_t mode);

extern int fcntl(int fildes, int cmd, ...); //fildes=file descriptor



// POSIX Standard: 5.6 File Characteristics
// https://pubs.opengroup.org/onlinepubs/009695399/basedefs/sys/stat.h.html
#include <sys/stat.h>
// https://pubs.opengroup.org/onlinepubs/009695399/functions/chmod.html
// ret is_succeed
extern int chmod(const char *path, mode_t mode);
// https://pubs.opengroup.org/onlinepubs/009695399/functions/fchmod.html
// ret is_succeed
extern int fchmod(int fildes, mode_t mode); 
// https://pubs.opengroup.org/onlinepubs/009695399/functions/stat.html
// ret is_succeed
extern int stat(const char *restrict path, struct stat *restrict buf);

