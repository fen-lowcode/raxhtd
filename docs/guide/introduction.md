
# Intoduction
---
## What is raxhtd?

RAXHTD (RAX HyperText Daemon) is an ultra-light HTTP server written entirely from scratch in freestanding C and x86_64 Assembly. Bypassing the standard C library and entirely.

RAXHTD eliminates the overhead of functions like printf() and malloc(). Instead, it interacts directly with the Linux kernel via raw system calls and relies on custom engineered functions for memory management, string manipulation, socket management, multithreading functions specifically for itself.


---


## The Purpose <a name = "purpose"></a>

Writing a server in this way serves as an excercise for me to get used in writing in 
C in an enviroment where there is no operating system to catch mistakes, which such is called **freestanding C**.

In this way i can advance my skills beyond normal software development and go beyond in the world of bare-metal IoT and Operating System development.

And indulging in a deeper understanding of how computer memory and networking works, how each layers of the linux operating system work together under the hood as close as possible to the linux kernel by building an HTTP web server without any abstraction on the way, is one of the best piece of art.


## To be clear
**RAXHTD** is not designed to replace production-grade enterprise servers like Apache or Nginx. Instead, it stands as a pure, educational pursuit a challenge to reclaim the mastery over the machine, stripping away the magic boxes to appreciate the raw engineering of the technology behind modern abstractions.

---

So, let's begin.