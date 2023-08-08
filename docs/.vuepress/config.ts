import { defineUserConfig } from 'vuepress'
import { defaultTheme } from '@vuepress/theme-default'
import { MarkdownOptions } from '@vuepress/markdown'

const markdownOptions: MarkdownOptions = {
  headers: {
    level: [2, 3, 4, 5],
  },
}

export default defineUserConfig({
  lang: 'zh-CN',
  title: 'Interview Preparation',
  description: 'Interview Preparation',
  base: '/Interview-Preparation/',


  markdown: markdownOptions,
  theme: defaultTheme({
    // 在这里进行配置
    repo: 'https://github.com/HenryZhuHR/Interview-Preparation',
    sidebarDepth: 4, // 设置根据页面标题自动生成的侧边栏的最大深度

    navbar: [
      // NavbarItem
      {
        text: '🧮 算法',
        link: '/algorithm.md',
        children: [
          {
            text: '🏊 回溯算法',
            link: '/algorithm.md/#-回溯算法',
          },
          {
            text: '🍪 贪心算法',
            link: '/algorithm.md/#-贪心算法',
          },
          {
            text: '🎒 动态规划',
            link: '/algorithm.md/#-动态规划',
          },
        ]
      },
      {
        text: '💻 语法基础',
        link: '/cppBasics.md',
        children: [
          {
            text: '🧱 C++ 基础',
            link: '/cppBasics.md/#-c-基础',
          },
          {
            text: '🧬 C++ 面向对象',
            link: '/cppBasics.md/#-c-面向对象',
          },
          {
            text: '🚚 C++ 内存管理',
            link: '/cppBasics.md/#-c-内存管理',
          },
        ]
      },

    ],

  }),
})