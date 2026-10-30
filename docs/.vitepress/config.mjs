import { defineConfig } from 'vitepress'

export default defineConfig({
  base: '/raxhtd/',
  title: 'raxhtd',
  description: 'A glibc-free HTTP server in C',
  appearance: false,

  themeConfig: {
    nav: [
      // { text: '', link: '/guide/introduction' },
      // { text: 'markdown', link: '/guide/markdown-examples.md' },
    ],

    sidebar: [
      {
        text: 'Guide',
        items: [
          { text: 'Introduction', link: '/guide/introduction' },
          // { text: 'Getting started', link: '/guide/getting-started' },
          { text: 'How raxhtd is built', link: '/guide/how-raxhtd-is-built' },
          // { text: 'Using the server', link: '/guide/usage' },
        ],
      },
      // {
      //   text: 'How it works',
      //   items: [
      //     { text: 'Going without glibc', link: '/internals/no-libc' },
      //     { text: 'Entry point and syscalls', link: '/internals/syscalls' },
      //     { text: 'Sockets and the event loop', link: '/internals/sockets' },
      //     { text: 'Parsing HTTP', link: '/internals/http-parser' },
      //     { text: 'Memory and buffers', link: '/internals/memory' },
      //   ],
      // },
    ],

    outline: { level: [2, 3] },
    search: { provider: 'local' },

    socialLinks: [
      { icon: 'github', link: 'https://github.com/fen-lowcode/raxhtd' }
    ]
  },

})