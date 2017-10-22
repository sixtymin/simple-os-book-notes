

1. Intel 80386加电后启动过程

当计算机加点后，一般不直接执行操作系统，而是一开始会到一个特定的地址开始执行指令，这个特定的地址存放了系统初始化软件，通过执行系统初始化软件（通常为固化在ROM或Flash中的firmware，即固件）完成基本I/O初始化和加载引导操作系统的代码段。

这个引导操作系统的代码段即后面看到的MBR，DBR(PBR)，bootloader等。BIOS实际上是被固化在计算机ROM（只读存储器）芯片上的特殊的软件，为上层软件提供了最底层的、最直接的硬件控制与支持。

<div align="center">
![图1 Intel80386加电后物理地址空间分布](D:\OS\ucoreOS\simple-os-book-notes\2017-10-22-tsinghua-os-course-ucore-bootloader-intel80386-poweron-address-space.jpg)
</div>

加电后CPU处于实模式状态，从物理地址0xFFFFFFF0开始执行。初始化状态CS和EIP确定了处理器的初始执行地址，CS中可见部分-选择子的值为0xF000，而其他不可见部分-基地址值为0xFFFF0000；EIP的值为0xFFF0，这样实际的线性地址（即物理地址）为CS.base + EIP=0xFFFFFFF0。在0xFFFFFFF0地址处放的是一条跳转指令，通过跳转指令跳转到BIOS程序的起始点。


#### 问题 ####

1. 参考文献1 第九章第一节讲述了为啥加电后从0xFFFFFFF0地址开始执行
