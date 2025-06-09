#include <sys/syscall.h>  # include syscall number definitions

    .text                 # code section
    .globl _start         # declare _start as global symbol
_start:                   # program entry point
    mov     $12, %edx     # write: number of bytes to write
    mov     $message, %ecx# write: pointer to the message string
    mov     $1, %ebx      # write: file descriptor (1 = stdout)
    mov     $SYS_write, %eax # syscall number for write
    call    L_sys         # call common syscall wrapper (sysenter)

    xor     %ebx, %ebx    # exit: return code 0
    mov     $SYS_exit, %eax # syscall number for exit
                           # fall through to L_sys (no call needed)

L_sys:                    # common syscall wrapper using sysenter
    push    %ecx          # save ecx on stack
    push    %edx          # save edx on stack
    push    %ebp          # save ebp on stack
    mov     %esp, %ebp    # establish new stack frame
    sysenter              # perform system call
                           # does not return normally
message:
    .ascii  "Hello World\n"  # message string to output
