#ifndef _ELF_STRUCTS_H_
#define _ELF_STRUCTS_H_



typedef unsigned long	Elf32_Addr;
typedef unsigned short	Elf32_Half;
typedef unsigned long	Elf32_Off;
typedef unsigned int	Elf32_Word;
typedef int				Elf32_SWord;

////
#define		ELF_SIGN	0x464C457F
#define		EV_CURRENT  1
enum ELFCLASS
{
	ELFCLASSNONE = 0,	// 非法目标文件
	ELFCLASS32,			// 32位目标文件
	ELFCLASS64,			// 64位目标文件
};

enum ELFDATA
{
	ELFDATANONE = 0,	// 非法编码格式
	ELFDATA2LSB,		// LSB编码（小字节序）
	ELFDATA2MSB,		// MSB编码（大字节序）
};

typedef struct  
{
	unsigned int ei_sign;	// 'FLE0x7f' = '464C457F'
	unsigned char ei_class;	// ELFCLASS32
	unsigned char ei_data;	// ELFDATA2LSB 小字节序编码
	unsigned char ei_ver;	// EV_CURRENT = 1
	unsigned char ei_pad[7];// 扩展字节，填充为0
}Inner_Ident;

// 
enum ElfType
{
	ET_NONE = 0,		// 未知文件类型
	ET_REL,				// 可重定位文件
	ET_EXEC,			// 可执行文件
	ET_DYN,				// 动态链接库文件
	ET_CORE,			// Core文件
	ET_LOPROC,			// 特定处理器文件扩展下边界
	ET_HIPROC,			// 特定处理器文件扩展上边界
};

enum ElfMachine
{
	EM_NONE = 0,		// 未知体系结构
	EM_M32,				// AT&T WE32100
	EM_SPARC,			// Sparc
	EM_386,				// Intel Arch
	EM_68K,				// Motorola 68000
	EM_88K,				// Motorola 88000
	EM_860,				// Intel 80860 (IA64?)
	EM_MIPS,			// Mips RS3000 Big-Endian
	EM_MIPS_RS4_BE,		// Mips RS4000 Big-Endian
	RESERVED,			// 11 ~ 16保留未用
};

#define		EI_NIDENT	16
typedef struct  
{
	unsigned char e_ident[EI_NIDENT];		// 统一标识，见后面解析
	Elf32_Half e_type;			// ELF文件的类型
	Elf32_Half e_machine;		// 处理器体系结构
	Elf32_Word e_version;		// 版本号 EV_CURRENT
	Elf32_Addr e_entry;			// 程序入口的虚拟地址，非可执行程序该字段为0
	Elf32_Off  e_phoff;			// program header table文件中偏移
	Elf32_Off  e_shoff;			// section header table文件中偏移
	Elf32_Word e_flags;			// 处理器特定标志位，对于Intel架构为0
	Elf32_Half e_ehsize;		// ELF文件头的大小，字节为单位
	Elf32_Half e_phentsize;		// 程序头表中每一项大小，字节为单位
	Elf32_Half e_phnum;			// 程序头表中表项数
	Elf32_Half e_shentsize;		// 节头表每一个表项大小，字节为单位
	Elf32_Half e_shnum;			// 节头表中表项数
	Elf32_Half e_shstrndx;		// 节头表中与节名表项对应的表项的索引，可能为SHN_UNDEF
}Elf32_Ehdr;

enum SectionHeaderIndex
{
	SHN_UNDEF = 0,				// 未定义，不存在节索引
	
	SHN_LORESERVE = 0xFF00,		// 被保留索引号区间下限 
	//SHN_LOPROC = 0xFF00		// 为处理器定制节保留索引号区间下限
	SHN_HIPROC = 0xFF1F,		// 为处理器定制节保留索引号区间上限
	SHN_ABS = 0xFFF1,			// 节区中定义符号有绝对值，不会因重定位改变
	SHN_COMMON = 0xFFF2,		// 节中定义公共符号，如未分配的C外部变量等
	SHN_HIRESERVE = 0xFFFF,		// 保留索引号区间的上限
};

enum SectionType
{
	SHT_NULL = 0,				// 表示无效的节头
	SHT_PROGBITS = 1,			// 本节信息由程序定义，格式和含义有程序决定
	SHT_SYMTAB = 2,				// 符号表，用于创建目标文件时编辑链接，完整的符号表
	SHT_STRTAB = 3,				// 字符串表，一个ELF中可以包含多个
	SHT_RELA = 4, 				// 重定位节，含有带明确加数的重定位项
	SHT_HASH = 5,				// 包含一张哈希表，动态链接中使用的符号哈希表
	SHT_DYNAMIC = 6,			// 本节包含动态链接信息
	SHT_NOTE = 7,				// 本节包含信息用于以某种方式来标记本文件
	SHT_NOBITS = 8,				// 表明该节内容为空，节并不占用实际空间
	SHT_REL = 9,				// 一个重定位节，带明确加数的重定位项，可能包含多个。
	SHT_SHLIB = 10,				// 保留值，暂未使用
	SHT_DYNSYM = 11,			// 符号表，存储运行期间（动态链接）使用符号
	SHT_LOPROC = 0x70000000,	// 为特殊处理器保留节类型索引值下边界
	SHT_HIPROC = 0x7FFFFFFF,	// 为特殊处理器保留节类型索引值上边界
	SHT_LOUSER = 0x80000000,	// 为应用程序保留节类型下边界
	SHT_HIUSER = 0xFFFFFFFF,	// 为应用程序保留节类型上边界 
};

#define	SHF_WRITE			0x1			// 进程运行过程中可写
#define	SHF_ALLOC			0x2			// 本节内容在进程运行中要占用内存
#define	SHF_EXECINSTR		0x4			// 此节内容是指令代码
#define	SHF_MASHPROC		0xF0000000	// 所有被此值所覆盖位为保留位


typedef struct  
{
	Elf32_Word sh_name;			// 本节的名字，"字符串表"节中的索引值
	Elf32_Word sh_type;			// 本节的类型
	Elf32_Word sh_flags;		// 本节的一些属性，由一系列比特位组成
	Elf32_Addr sh_addr;			// 映射到进程空间中，指定映射的起始地址
	Elf32_Off  sh_offset;		// 本节所在位置，即该节第一个字节在文件中位置
	Elf32_Word sh_size;			// 指明节的大小，单位为字节
	Elf32_Word sh_link;			// 索引值，执向节头表中本节所对应位置
	Elf32_Word sh_info;			// 节的附加信息，不同类型节，此字段意义不同
	Elf32_Word sh_addralign;	// 本节如何对齐，即sh_addr必须整除sh_addralign
	Elf32_Word sh_entsize;		// 有些节内容为表，每张表大小固定，该成员指定表项大小
}Elf32_Shdr;

/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
	   sh_type			sh_link			        sh_info
	SHT_DYNAMIC   本节中项目的字符串表             0
				  在节头表中相应的索引
	SHT_HASH      本节中Hash表的符号表             0
				  在节头表中相应索引

	SHT_REL/	  相应符号表在节头表中的   本重定位节所应用到
	SHT_RELA      索引值                   目标节在表头表中索引

	SHT_SYMTAB/   相关字符串表的街头索引	符号表中最后一个本地符号
	SHT_DYNSYM								的索引值加 1
	
		其他       SHN_UNDEF						0
 --------------------------------------------------------------*/

/*
 对于索引值为0的节头表，它并不表达实际内容，只是一个空白表项，值如下：
	sh_type 值为SHT_NULL
	sh_link 值为SHN_UNDEF
	
	其他成员值全为0
 */

typedef struct  
{
	Elf32_Word st_name;		// 符号名字，字符串表索引值
	Elf32_Addr st_value;	// 符号的值
	Elf32_Word st_size;		// 符号的大小
	unsigned char st_info;	// 符号的类型和属性，一系列比特位构成
	unsigned char st_other;	// 暂未使用，值为0
	Elf32_Half st_shndx;	// 指明相关联节
}Elf32_Sym;

typedef struct  
{
	Elf32_Addr r_offset;	// 本数据成员给出重定位所作用位置
	Elf32_Word r_info;		// 重定位所作用的符号表索引
}Elf32_Rel;

typedef struct  
{
	Elf32_Addr r_offset;
	Elf32_Word r_info;
	Elf32_SWord r_addend;	// 指定一个加数，用于计算需要重定位的域的值
}Elf32_Rela;


//////////////////////////////////////////////////////////////////////////

// 
enum SegmentType
{
	PT_NULL = 0,				// 表示本程序头未使用
	PT_LOAD = 1,				// 执行一个可装载段
	PT_DYNAMIC = 2,				// 本段为动态链接信息
	PT_INTERP = 3,				// ELF解析器路径，以null结尾的字符串
	PT_NOTE = 4,				// 附加信息的段，以null结尾字符串
	PT_SHLIB = 5,				// 保留，未定义
	PT_PHDR = 6,				// 程序头表在文件或内存中的位置和大小
	PT_LOPROC = 0x70000000,		// 为特定处理器保留
	PT_HIPROC = 0x7FFFFFFF,		// 
};

enum SegmentPermissions
{
	PF_NONE = 0,		// 无任何权限
	PF_X = 1,			// 可执行权限，实际为可读，可执行
	PF_W = 2,			// 可写
	PF_R = 4,			// 可读
};

// 可读和可执行是通用的，即可读就可以执行，同时可执行必然可读
// 可写权限是最高权限，可以覆盖另外两个，有了可写权限，所有权限就都有了

// 可执行文件或共享目标文件的程序头表，每一项称为程序头
// 每一个程序头描述了一个段，或一块用于准备执行程序的信息
// 程序头只对可执行文件或共享目标文件有意义，即可执行的ELF
typedef struct  
{
	Elf32_Word p_type;		// 本程序头所描述段类型
	Elf32_Off  p_offset;	// 本段内容在文件中位置，相对文件开头偏移量
	Elf32_Addr p_vaddr;		// 本段在进程空间中起始虚拟地址
	Elf32_Addr p_paddr;		// 在进程空间中的起始物理地址，一般不用
	Elf32_Word p_filesz;	// 文件中所占空间
	Elf32_Word p_memsz;		// 内存中所占空间，一般大于p_filesz
	Elf32_Word p_flags;		// 段内容属性
	Elf32_Word p_align;		// 内存对齐值
}Elf32_Phdr;

// 段 Segment
// 一个段由若干个节组成，不过程序头并不关心节的问题，程序装载和节并没有太大关系
// .text 为代码段，一般包括.text/.rodata/.hash/.dynsym/.dynstr/.plt/.rel.got等
// 数据段则典型包括.data / .dynamic / .got / .bss等

enum DynamicType
{							//       EXE    SO
	DT_NULL = 0,			// 忽略  必需   必需   作为数组结束标记
	DT_NEEDED = 1,			// d_val 可选   可选   指明所需的库名字，可以包含若干项
	DT_PLTRELSZ = 2,		// d_val 可选   可选   函数连接表相关重定位项总大小，字节为单位
	DT_PLTGOT = 3,			// d_ptr 可选   可选   函数连接表或全局偏移量表相应的地址
	DT_HASH = 4,			// d_ptr 必需   必需   符号哈希表的地址
	DT_STRTAB = 5,			// d_ptr 必需   必需   字符串表的地址，符号名和库名称
	DT_SYMTAB = 6,			// d_ptr 必需   必需   符号表的地址
	DT_RELA = 7,			// d_ptr 必需   可选   重定位表的地址，存储显示的加数
	DT_RELASZ = 8,			// d_val 必需   可选   DT_RELA重定位表的大小，字节为单位
	DT_RELAENT = 9,			// d_val 必需   可选   DT_RELA对应重定位表项大小
	DT_STRSZ = 10,			// d_val 必需   必需   字符串表的大小
	DT_SYMENT = 11,			// d_val 必需   必需   符号表项的大小，字节为单位
	DT_INIT = 12,			// d_ptr 可选   可选   初始化函数地址
	DT_FINI = 13,			// d_ptr 可选   可选   终止函数的地址
	DT_SONAME = 14,			// d_val 忽略   可选   字符串表中的偏移量，共享目标名字
	DT_RPATH = 15,			// d_val 可选   忽略   字符串表中的偏移量，用于搜索库文件路径名
	DT_SYMBOLIC = 16,		// 忽略  忽略   可选   决定动态链接其解析符号时算法
	DT_REL = 17,			// d_ptr 必需   可选   与DT_RELA相似，指向重定位表
	DT_RELSZ = 18,			// d_val 必需   可选   DT_REL相应重定位表的大小
	DT_RELENT = 19,			// d_val 必需   可选   DT_REL相应重定位表项的大小
	DT_PLTREL = 20,			// d_val 可选   可选   函数连接表所引用的重定位项的类型
	DT_DEBUG = 21,			// d_ptr 可选   忽略   用于调试
	DT_TEXTREL = 22,		// 忽略  可选   可选   是否可以修改只读段
	DT_JMPREL = 23,			// d_ptr 可选   可选   指向与函数连接表单独关联的重定位项地址
	DT_BIND_NOW = 24,		// 忽略  可选   可选   该项出现，则在程序开始执行前，完成所有重定位工作
	DT_LOPROC = 0x70000000,	// 未定义未定义 未定义 为处理器保留
	DT_HIPROC = 0x7FFFFFFF,	// 未定义未定义 未定义 为处理器保留
};

typedef struct  
{
	Elf32_SWord d_tag;		// d_tag控制着d_un的解析
	union {
		Elf32_Word d_val;	// 代表整型数
		Elf32_Addr d_ptr;	// 代表进程空间里的地址
	}d_un;	
}Elf32_Dyn;

//extern Elf32_Dyn _DYNAMIC[];

#endif