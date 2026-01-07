/*
Sys Calls is how a user-space program asks kernel to do something privileged 
eg:
  Acessing hardware
  create processes
  allocate mem
  I/O
  for c they r in <unistd.h>, they are not however not simple functions but asks CPU to do processes
  typical flow :-
                your C code
                    ↓
                glibc wrapper
                    ↓
                syscall instruction
                    ↓ 
                kernel
-----------------------------------------------------------------------------------------------------------------------
File Descriptor 
an integer that the kernel uses to handle an open resources
can represet:
  Regular Files
  Terminals
  Pipes
  Sockets
  Devices
std FDs(always open):-
  0->stdin
  1->stdout
  2->stderr
can be checked via :printf("%d %d %d\n", STDIN_FILENO, STDOUT_FILENO, STDERR_FILENO);
for the kernel
Process
 ├── FD table (per process)
 │     fd 0 → open file object
 │     fd 1 → open file object
 │     fd 2 → open file object                                                                      ─One FD per process
 │                                                                                -> implications:─│─Mutiple FDs can point to the same obj
Open file object                                                                                   └─File Offsets are shared on duplication
 ├── file offset
 ├── access mode
 └── pointer to inode
--------------------------------------------------------------------------------------------------------------------------------------
Certain Sys calls
open()
    int open(const char *path,int flags, mode_t mode);
    for modes common flags:-
                O_RDONLY
                O_WRONLY
                O_RDWR
                O_CREAT
                O_TRUNC
                O_APPEND
    failure:- if(fd < 0) perror("open")
read()
    ssize_t(int fd, void *buf,size_t count)
        returns >0 -> bytes read 
        0 -> EOF
        -1 -> error
    char buf[sizededo]
    ssize_t n = read(fd, buf, sizeof(buf))
write()
    ssize_t write(int fd, const void *buf, size_t count);
    May write fewer bytes than required, looping req for robustness
close()
    int close(int fd); however can be reused
-------------------------------------------------------------------------------------------------------------------------------------------
stdio(fopen,fgets,printf) is buffered and higher-level, thus for kernel level work we use syscalls 
--------------------------------------------------------------------------------------------------------------------------------------
the duplication command is cricitcal for shell making
int newfd = dup(fd)
dup2(fd,newfd);
--------------------------------------------------------------------------------------------------------------------------------------------
fork()
- child gets copy of FD table
- same open file objects
- shared offsets
fork()
write(1,"x",1)   output may vary and this later on matters for pipes, shell, schedular sim
---------------------------------------------------------------------------------------------------------------------------------------------
error handling utilizes perror thru errno.h
----------------------------------------------------------------------------------------------------------------------------------------------
lseek()
off_t lseek(int fd, off_t,int whence)
where whence cane be :-
    SEEK_SET   // absolute
    SEEK_CUR   // relative
    SEEK_END   // from end
however not supported by lseek()
-----------------------------------------------------------------------------------------------------------------------------------------------
write() for regular files may interleave across processes, for pipes(pip_buf all caps), they are atomic
-----------------------------------------------------------------------------------------------------------------------------------------------
read() blocks until data availalbe, this can be changed in FD - 
-----------------------------------------------------------------------------------------------------------------------------------------------
fcntl - FD control.
fcntl(fd, F_SETFL,O_NONBLOCK)
this forces read() to return 01 and errno = EAGAIN if no dat
fcntl(fd,F_GETFL) or fcntl(fd,F_SETFL,flags) - dubplicate df with flags and makes it non blocking
-----------------------------------------------------------------------------------------------------------------------------------------------
a file descriptor's life cycle: open -> read/write -> dup or fork or oth such optional -> close 
-----------------------------------------------------------------------------------------------------------------------------------------------
start("path/file.extension", &st)                            <---alt--->                           fstat(fd, &st)
fd is better as it will work regardless of renaming of file, safe against race conditions
-----------------------------------------------------------------------------------------------------------------------------------------------
syscalls to be utilized 
open
read 
write 
close 
dup/dup2
lseek
fork
execve(latr)
pipe(latr)

the program will, copy a file -> skip first 10 bytes -> apppend to output -> handle errors ->use only syscalss
*/
#include <stdio.h>
#include <fcntl.h>
#include <stdio.h>
#include <errno.h>

int main(int argc, char *argv[]){
    if(argc<3){
        write(2, "usage: copy src dst\n", 20);
    }
    //opening src file
    int src = open(argv[1], O_RDONLY);             
    if(src < 0){
        perror("OPEN SRC"); return 1;
    }
    //opening destination file
    int dest = open(argv[2], O_WRONLY|O_CREAT|O_APPEND, 0644);
    if(dest < 0){
        perror("OPEN DEST"); return 1; 
    }
    //using lseek to change first ten bytes
    if((src, 10, SEEK_SET) < 0){
        perror("lseek");
        close(src);close(dest);
        return 1;
    }

    char buf[512]; ssize_t n;
    while(1) {
        n = read(src, buf, sizeof(buf)); //allows us to read only 
        if(n == 0) break;
        if (n < 0){
            if(errno == EINTR) continue;
            perror("read");break;
        }
    
        ssize_t written = 0;
        while(written < n){
            ssize_t w = write(dest, buf + written, n - written);
            if(w < 0){
                perror("write");
                goto cleanup;
            }
            written += w;
        }
    }
    cleanup:
        close(src);
        close(dest);
        return 0;
}
/* 
for compiling 
gcc copy.c -o copy
./copy src dest              -> these files need to exist 
*/
