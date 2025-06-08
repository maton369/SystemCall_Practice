#include <sys/syscall.h>  
# include syscall number definitions

    .section .text        # code section
    .globl _start         # declare _start as global
_start:
    movl $12, %edx        # write: third argument = 12 bytes
    movl $message, %ecx   # write: second argument = address of message
    movl $1, %ebx         # write: first argument = file descriptor 1 (stdout)
    movl $SYS_write, %eax # syscall number for write
    int $0x80             # invoke syscall

    xorl %ebx, %ebx       # exit: status code 0
    movl $SYS_exit, %eax  # syscall number for exit
    int $0x80             # invoke syscall

    # we do not return from _start

.section .data
message:
    .ascii "Hello World\n"  # message to output
