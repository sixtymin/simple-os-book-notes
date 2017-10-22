
操作系统的重要性没什么可说，它是现代计算机软件的基石，很多软件问题的解决最终都依赖于对操作系统某个机制的深刻理解。

一直想要自己写个“操作系统”，但是它要求的内容太多了。一部分内容之前本科学习中就遇到过，但是很多细节内容教学的书本中根本了解不到，对于这一部分内容又不知道该从何学起，从哪里可以查找到相应资料（计算机科学博大精深，绝非一朝一夕资料查询就可以获取到想要内容，尤其编写操作系统这种冷门资料）。一些写过的人给出了很多资料，或者他们直接省略了很多边角细节，看了这些人写的资料或代码后只是知其然，而不知其所以然（这也是很痛苦的事情）。

始终在寻找一个“官方的”，权威的，正式的资料，能够从头到尾解惑整个过程。无意中看到清华大学一门在线的操作系统公开课中涉及到操作系统的编写，尽管比较简单，但是它会介绍从无到有，从有到全的整个过程。而这种资料正式我想要寻找的“权威资料”，看了两节觉得内容不错，决定看完整篇。

从视频课程前两节的内容来看，操作系统课作为本科的教学内容，清华大学能有如此务实的教学方法，也不得不说清华大学果然名不虚传，确实有料。清华大学的计算机操作系统课程是理论加实践的方式来进行讲授，一个老师负责讲解操作系统的原理；另外一个老师负责操作系统的实验，而实验的结果就是一个“相对完整”的操作系统（其实就是将操作系统涉及到的几大部分添加完毕）。

看陈渝老师总结的国内外计算机方面比较牛掰的大学的教学中都使用了类似的方法，如下图所示。

<div align="center">
![图1 国外部分大学操作系统课程实践部分](D:\OS\ucoreOS\simple-os-book-notes\2017-10-21-tsinghua-os-course-ucore-precourse-out-university.jpg)
</div>

国内的大学貌似只有清华大学有自己的教学操作系统即ucore，而其他的几个对操作系统比较重视的大学没有自己独有的教学操作系统，而是引进的国外一些著名大学的教学操作系统。

<div align="center">
![图2 国内部分大学操作系统课程实践部分](D:\OS\ucoreOS\simple-os-book-notes\2017-10-21-tsinghua-os-course-ucore-precourse-in-university.jpg)
</div>

所以当那个人说上学无用时，说非名校一样可以成功时，一定不能上当！要读书，要读名校，并非虚荣而是到了名校之后有不一样的眼界，看到且接触到普通高校无法接触到的东西。

操作系统设计很多内容，要编写操作系统也会涉及很多工具，如下是课程中给出的一些工具（在这里抄一下，以备之后的不时之需）。`apt-get`作为Ubuntu中软件包管理程序，需要熟悉一下，否则在Ubuntu中无法安装下面的工具。git是版本管理工具，程序开发的很多人应该都熟悉。gcc是Linux系统的上的编译工具集。gdb是程序调试工具，可以调试应用程序，同时对于基于GDB stub的虚拟机或模拟器也可以用GDB远程调试器中的操作系统，所以它是必须的工具。make是方便编译的工具，像我这种Windows平台上的开发很难用到。shell就不用说了，Linux上做开发必备技能。understand是Linux平台上类似于Windows上的Source Insight的一款工具，方便代码阅读，必备。vim是Linux平台上的编辑软件，强大但是使用门槛极高。meld和diff是类似的工具，不过meld有图形界面用起来更加方便。qemu是一款模拟器，功能类似于虚拟机，但是所有指令模拟执行，做到对内部操作系统的完全控制。Eclipse-CDT是Linux上`C/C++`开发的IDE环境的代表，当然还有一些其他IDE工具比如kdevelop，anjuta，geany，codeblocks等。

* apt-get
    * http://wiki.ubuntu.org.cn/Apt-get%E4%BD%BF%E7%94%A8%E6%8C%87%E5%8D%97
* git
    * http://www.cnblogs.com/cspku/articles/Git_cmds.html
* gcc
    * http://wiki.ubuntu.org.cn/Gcchowto
    * http://wiki.ubuntu.org.cn/Compiling_Cpp
    * http://wiki.ubuntu.org.cn/C_Cpp_IDE
    * http://wiki.ubuntu.org.cn/C%E8%AF%AD%E8%A8%80%E7%AE%80%E8%A6%81%E8%AF%AD%E6%B3%95%E6%8C%87%E5%8D%97
* gdb
    * http://wiki.ubuntu.org.cn/%E7%94%A8GDB%E8%B0%83%E8%AF%95%E7%A8%8B%E5%BA%8F
* make & makefile
    * http://wiki.ubuntu.com.cn/index.php?title=%E8%B7%9F%E6%88%91%E4%B8%80%E8%B5%B7%E5%86%99Makefile&variant=zh-cn
    * http://blog.csdn.net/a_ran/article/details/43937041
* shell
    * http://wiki.ubuntu.org.cn/Shell%E7%BC%96%E7%A8%8B%E5%9F%BA%E7%A1%80
    * http://wiki.ubuntu.org.cn/%E9%AB%98%E7%BA%A7Bash%E8%84%9A%E6%9C%AC%E7%BC%96%E7%A8%8B%E6%8C%87%E5%8D%97
* understand
    * http://blog.csdn.net/qwang24/article/details/4064975
* vim
    * http://www.httpy.com/html/wangluobiancheng/Perljiaocheng/2014/0613/93894.html
    * http://wenku.baidu.com/view/4b004dd5360cba1aa811da77.html
    * http://blog.csdn.net/wooin/article/details/1858917
* meld
    * https://linuxtoy.org/archives/meld-2.html
* qemu
    * http://wenku.baidu.com/view/04c0116aa45177232f60a2eb.html
* Eclipse-CDT
    * http://blog.csdn.net/anzhu_111/article/details/5946634

自身作为Windows平台上的开发人员，看到这些工具列表还是感觉亚历山大啊！除了上述的内容，还有一个内容就是汇编。看到源码中用了C语言嵌入汇编，而用gcc编译的就是gcc汇编了，这个汇编形式区别于Windows上的x86汇编形式。不过想要挖到“真金白银”需要付出一些努力，没有白来的技能。

这一小节作为听操作系统这么公开课的起始，后面每一节做一些笔记。一方面记录听课过程中感触比较深的点，以及感觉比较重要的细节；另外一方面记录自己在编写ucore操作系统中的一些问题。

** 修改历史 **

* 2017-10-22 10:55:23 完成博客


By Andy @2017-10-22