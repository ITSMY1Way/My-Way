## 概述

readelf命令用来显示一个或者多个ELF格式的目标文件的信息，可以通过选项来控制显示哪些信息。可支持32位，64位的ELF格式文件，也支持包含ELF文件的文档（这里一般指的是使用ar命令将一些elf文件打包之后生成的例如lib*.a之类的“静态库”文件）。常见的文件如在Linux上的可执行文件，动态库(*.so)或者静态库(*.a) 等包含ELF格式的文件。以下命令的使用是基于android编译出来的so文件上面去运行。

## readelf常用命令

#### **语法**：readelf (选项)(参数:文件)

​              除了-v和-H之外，其它的选项必须有一个被指定参数

#### 选项

1.  -l test(program headers),segments 显示程序头（段头）信息(如果有数据的话)。
2. -I,histogram 显示符号的时候，显示bucket list长度的柱状图
3. -x,hex-dump=<number or name> 以16进制方式显示指定段内内容。number指定段表中段的索引,或字符串指定文件中的段名
4. -g  (section groups),显示节组信息(如果有数据的话)
5. -t,section-details 显示节的详细信息(-S的)
6. -n ,notes 显示note段（内核注释）的信息
7. -r  ,relocs 显示可重定位段的信息
8. -u,unwind 显示unwind段信息。当前只支持IA64 ELF的unwind段信息
9. -d ,dynamic 显示动态段的信息
10. -D,use-dynamic 使用动态段中的符号表显示符号，而不是使用符号段
11. -v，version 显示readelf的版本信息
12. -V ,version-info 显示版本段的信息
13. -a ，all 显示test的全部信息,**等价于 -h -l -S -s -r -d -V -A -I**
14. -A,arch-specific 显示CPU构架信息
15. -h (elf header)，显示testd的elf header的文件头信息（也就是ELF文件开始的52个字节）
16. -H，help 显示readelf所支持的命令行选项
17. -s ,symbols 显示符号表段中的项（如果有数据的话）
18.  -S (section headers),sections 显示节头信息(如果有数据的话)
19. -e ,headers 显示全部头信息，**等价于: -h -l -S test**











