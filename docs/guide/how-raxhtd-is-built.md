# How is it built?

---

### What should i know first?

raxhtd is possible by knowing multiple things about how an operating system work.

we need to first understand what a **lib c (C Standard Library)** is and the [**glibc library**](https://www.baeldung.com/linux/gnu-c-library).

Also we will look deeper inside the linux kernel and look upon to it's [**System Calls**](https://www.baeldung.com/linux/system-calls-vs-library-calls).

---

### What is glibc?

"glibc stands for **GNU C Library**, and it is a fundamental part of most Linux distributions. It’s a Collection of C library functions that provide low-level functionality to the operating system and other system software. 

The primary goal of glibc is to provide a consistent interface to system resources, such as files, networks, and memory, to make it easier for us to write software that runs on different platforms."

**Basically glibc is a C standard library, one from many others. but glibc is the standard that most
linux mainstream distros use**

glibc can be **a wrapper to a system call** to avoid invoking them manually and unsafely thru assembly or 
it can be also either a **set of functions that performs byte level manipulation** to save developers time, 

for example is strcpy() which simply copies an array or char to another memory address.

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

---

### System Calls