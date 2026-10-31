---
# https://vitepress.dev/reference/default-theme-home-page
layout: home

hero:

  name: "RAXHTD"
  text: "zero to server"
  tagline: "- fen-lowcode -"

  image: 
    src: ./assets/raxhtd_2.png

  actions:
    
    - theme: brand
      text: Join My Journey
      link: /guide/introduction

    # - theme: alt
    #   text: markdown
    #   link: /markdown-examples


features:
  - title: What is glibc?
    details: understanding what it means to be a C standard library 
    link: /guide/how-raxhtd-is-built#What-is-glibc

  # - title: Raw syscalls
  #   details: socket, bind, accept, read and write go straight to the kernel.
  #   link: /internals/syscalls

  # - title: Event loop
  #   details: How connections are accepted and served.
  #   link: /internals/sockets

  # - title: HTTP parser
  #   details: A hand-written request parser, explained line by line.
  #   link: /internals/http-parser

  # - title: Memory
  #   details: Buffers and allocation without malloc.
  #   link: /internals/memory

  # - title: Build and run
  #   details: Compile flags, running the server, and testing it with curl.
  #   link: /guide/building
---