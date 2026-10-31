# How is it built?

---

### What should i know first?

raxhtd is possible by knowing multiple things about how an operating system work.
we need to first understand what a lib c (C Standard Library) is and the [**glibc library**](https://www.baeldung.com/linux/gnu-c-library).
Also we will look deeper inside the linux kernel and look upon to it's [**System Calls**](https://www.baeldung.com/linux/system-calls-vs-library-calls).



<br>
<br>
<br>

---

<br>
<br>
<br>

### What is glibc?

"glibc stands for **GNU C Library**, and it is a fundamental part of most Linux distributions. It’s a Collection of C library functions that provide low-level functionality to the operating system and other system software. 

The primary goal of glibc is to provide a consistent interface to system resources, such as files, networks, and memory, to make it easier for us to write software that runs on different platforms."

Basically glibc is a C standard library, one from many others. but glibc is the standard that most
linux mainstream distros use

glibc can be a wrapper to a system call** to avoid invoking them manually and unsafely thru assembly or 
it can be also either a set of functions that performs byte level manipulation to save developers time, 

for example is strcpy() which simply copies an array or char to another memory address.


<br>
<br>
<br>

---

<br>
<br>
<br>


### Libc (C standard Libraries)

There's also other multiple C libraries like glibc which are and not limited to: 


- **musl libc**: 
    Designed for lightweight systems and containers (it's what Alpine Linux uses). It’s extremely clean, standards-compliant, and built to handle static linking effortlessly.

- **libSystem**(Apple libc): 
    The standard library for macOS and iOS. It actually combines several libraries under the hood (math, pthread, info, and core C) into one system umbrella library.

- **Bionic**: 
    Google's custom libc built specifically for Android. It uses its own linker, is optimized for low memory usage on mobile, and bypasses some traditional UNIX behaviors.

- **UCRT** (Universal C Runtime / ucrtbase.dll): 
    Microsoft’s C library for Windows. While Windows programs usually talk directly to the Win32 API (kernel32.dll), MSVC compiles standard C code against this runtime.



<br>
<br>
<br>

---

<br>
<br>
<br>


### System Calls

User programs cannot directly access hardware or critical OS resources because it would make the system unstable and insecure. To maintain safety, the operating system provides system calls controlled interfaces that allow user programs to request services from the kernel. These calls act as a gateway between user mode and kernel mode. 

**System Calls are**:

* A way for programs to interact with the operating system.
* Provide the services of the operating system to the user programs.
* Only entry points into the kernel are executed in kernel mode.

For example:

| Syscall | Description |
| --- | --- |
| [open](https://manpages.debian.org/unstable/manpages-dev/open.2.en.html) | Open and possibly create a file |
| [socket](https://manpages.debian.org/unstable/manpages-dev/socket.2.en.html) | Create an endpoint for communication |
| [mmap](https://manpages.debian.org/unstable/manpages-dev/mmap.2.en.html) | Map or unmap files or devices into memory (memory allocation) |
| [brk](https://manpages.debian.org/unstable/manpages-dev/brk.2.en.html) | Change data segment size (heap memory allocation) |
| [clone](https://manpages.debian.org/unstable/manpages-dev/clone.2.en.html) | Create a child process with fine-grained control |

You can more available syscalls by exporing https://filippo.io/linux-syscall-table/