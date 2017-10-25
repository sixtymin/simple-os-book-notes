

#### Intel 80386加电后启动过程 ####

当计算机加电后，一般不直接执行操作系统，而是到一个特定地址开始执行指令，这个特定地址存放了系统初始化软件，通过执行系统初始化软件（通常为固化在ROM或Flash中的firmware，即固件）完成基本I/O初始化和加载引导操作系统的代码段。

这个特定地址是什么呢？对于不同的CPU这个地址值不同，80286以前（不是特别准确，想了解准确内容参考Intel的文档）的CPU中为0xFFFF0，而之后的CPU这个值为0xFFFFFFF0。即加电后CS/EIP值被重置为0xF000和0xFFF0，32位CPU中CS的Base值为0xFFFF0000，根据CPU加电后的地址计算方法，80386之后的CPU第一条访问地址为Base+EIP=0xFFFFFFF0。使用Bochs调试一下，如下图结果。

<div align="center">
![图1 Intel80386加电后第一条指令](D:\OS\ucoreOS\simple-os-book-notes\2017-10-22-tsinghua-os-course-ucore-bootloader-pc-init-instruction.jpg)
</div>

从调试的内容可以看到，起始执行地址为CS:IP=0xF000:FFF0，但是其物理地址显示的为0x0000FFFFFFF0，同时在0xFFFF0物理地址处也有相同的内容。根据陈渝老师的解释，在32位CPU上BIOS被映射到4G空间最高64K的地址空间内，但是在1M向下的64K被CPU映射了和4G最高64K相同内容，但是这块64K其实是RAM而非4G空间最高64K的EPROM（这个内容待考证）。

用Bochs模拟硬件来调试看一下4G和1M中第二条要执行指令对应位置的内容，如下图所示。它们的内容完全一致，也印证了上面的说法，但是至于真机中低1M处的64K是RAM还是ROM就无从验证了。

<div align="center">
![图2 4G和1M内存空间处BIOS内容对比](D:\OS\ucoreOS\simple-os-book-notes\2017-10-22-tsinghua-os-course-ucore-bootloader-4G-1M-BIOS-Compare.jpg)
</div>

在CPU加电后准备执行第一条指令时，这时候系统的物理内存映射情况如下图3所示。从图上可以看到在1M内存以下比较“热闹”，最低的640K是空闲内存，然后是VGA显存，再然后是设备的BIOS，再是系统BIOS，再之后就是可用的物理内存直到物理内存大小。

<div align="center">
![图3 Intel80386加电后物理地址空间分布](D:\OS\ucoreOS\simple-os-book-notes\2017-10-22-tsinghua-os-course-ucore-bootloader-intel80386-poweron-address-space.jpg)
</div>

其实看到这个内存图内心还是有很多疑问：前面根据陈渝老师的说法，这里的BIOS其实是RAM，那VGA部分占用的内存呢？其他的设备BIOS的内存段呢？

正常理解，硬件RAM提供的内存应该被编址为连续物理地址块，即从0到物理条大小，比如1G，或者从1G到2G。那这低1M里面这么热闹怎么回子事？后面纯属猜测内容，需要求证：就是物理内存1G没有问题，那就编址为0-1G；对于系统BIOS，设备BIOS，VGA缓存等则由北桥芯片强制将对应物理地址块映射给了ROM或VGA物理内存了，而RAM中对应的这些物理内存块就被屏蔽了（其实就是闲置了，从CPU中访问不到了，毕竟CPU也受制于北桥芯片的地址映射）。这些内容有待进一步考证，后面也有统计物理内存的需要，到时看统计出来的物理内存分布，再看实际的RAM就大概知道这块内容了。

> 注：这里的低1M的物理地址空间要和Windows编程中用到的低1M的内存空间区分。

下面列举几个参考文档，对于上述的内容可能还是有很多问题，那只能自己去探索了。

1. [主板和内存映射](http://liaoph.com/motherboard-and-memory-map/)
2. [计算机如何引导](http://liaoph.com/how-computers-boot-up/)
3. [CPU加电后第一条指令](http://blog.csdn.net/u011523762/article/details/52972572)
4. [基于Intel 80×86 CPU的IBM PC及其兼容计算机的启动流程](https://yq.aliyun.com/articles/15221)
5. [BIOS启动过程](https://github.com/chyyuu/ucore_os_docs/blob/master/lab1/lab1_3_1_bios_booting.md)

#### BIOS自检与MBR加载 ####

根据上一节加电后指令执行并不是按照实模式的地址计算方法，当然它也不可能按照保护模式的地址计算，所以这第一条指令即非保护模式，也非实模式。从上面可以看到CPU加电后的第一条指令是`jmpf 0xF000:0xE05B`，这条指令不单纯是跳转，它会更新CS内容，如上一节的图所示，更新后CS的Base段被修改为0x000F0000，该条指令执行后，就跳入1M内存空间执行，并且开始进入CPU实模式，用实模式的CS左移4位加上IP的形式进行地址计算。

跳入的代码段即BIOS。BIOS是被固化在计算机ROM（只读存储器）芯片上的特殊的软件，为上层软件提供了最底层的、最直接的硬件控制与支持。接下来要执行的BIOS代码主要完成了系统自检和MBR加载，详细说就是检测必要硬件是否可用，对于存在BIOS的设备（如显示器）则调用这些设备的BIOS进行设备初始化；硬件初始化完毕后，则加载引导设备中的MBR。

这块的引导设备就比较丰富了，如软盘，CDROM，硬盘，USB设备等。

视频第三节 BIOS开始


// 英文资料，普及
http://duartes.org/gustavo/blog/archives/

// 阮一峰 系统引导过程
http://www.ruanyifeng.com/blog/2013/02/booting.html


#### 问题 ####

1. 参考文献1 第九章第一节讲述了为啥加电后从0xFFFFFFF0地址开始执行
