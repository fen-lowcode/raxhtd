# What is raxhtd?

RAXHTD (RAX HyperText Daemon) is an ultra-light HTTP server written entirely from scratch in freestanding C and x86_64 Assembly. Bypassing the standard C library and entirely.

RAXHTD eliminates the overhead of functions like printf() and malloc(). Instead, it interacts directly with the Linux kernel via raw system calls and relies on custom engineered functions for memory management, string manipulation, socket management, multithreading functions specifically for itself.


---


# The Purpose <a name = "purpose"></a>

In a modern development landscape dominated by high-level abstractions, bloated libraries, and "black box" APIs that blurs the mechanics behind the scenes, building software from the ground up has become a lost art form. 

**RAXHTD** is not designed to replace production-grade enterprise servers like Apache or Nginx. Instead, it stands as a pure, educational pursuit a challenge to reclaim mastery over the machine, stripping away the magic boxes to appreciate the raw engineering of the technology behind the web.

---
