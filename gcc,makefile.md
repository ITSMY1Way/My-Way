## Linux编译器-gcc/g++使用 

### 1.编译过程

<https://blog.csdn.net/weixin_41143631/article/details/81221777> 

> 1. 预处理（进行宏替换) 
> 2. 编译（生成汇编) 
> 3. 汇编（生成机器可识别代码） 
> 4. 连接（生成可执行文件/库文件)

`格式 gcc [选项] 要编译的文件[选项] [目标文件]`  

#### 预处理(进行宏替换) 

> - 预处理功能主要包括宏定义,文件包含,条件编译,去注释等。 
> - 预处理指令是以#号开头的代码行。 
> - 实例: gcc –E hello.c –o hello.i 
> - 选项“-E”,该选项的作用是让 gcc 在预处理结束后停止编译过程。 
> - 选项“-o”是指目标文件,“.i”文件为已经过预处理的C原始程序。 

#### 编译（生成汇编） 

> - 在这个阶段中,gcc 首先要检查代码的规范性、是否有语法错误等,以确定代码的实际要做的工作,在检查 
>
>   无误后,gcc 把代码翻译成汇编语言。 
>
> - 用户可以使用“-S”选项来进行查看,该选项只进行编译而不进行汇编,生成汇编代码。 
>
> - 实例: `gcc –S hello.i –o hello.s` 

#### 汇编（生成机器可识别代码） 

> - 汇编阶段是把编译阶段生成的“.s”文件转成目标文件 
> - 读者在此可使用选项“-c”就可看到汇编代码已转化为“.o”的二进制目标代码了 
> - 实例: `gcc –c hello.s –o hello.o`

#### 链接（生成可执行文件或库文件） 

> - 在成功编译之后,就进入了链接阶段。 
> - 实例: `gcc hello.o –o hello` 

#### 在这里涉及到一个重要的概念:函数库 

> 我们的C程序中，并没有定义“printf”的函数实现,且在预编译中包含的“stdio.h”中也只有该函数的声明,而没有定义函数的实现,那么,是在哪里实“printf”函数的呢? 
>
> 最后的答案是:系统把这些函数实现都被做到名为 libc.so.6 的库文件中去了,在没有特别指定时,gcc 会到 系统默认的搜索路径“/usr/lib”下进行查找,也就是链接到 libc.so.6 库函数中去,这样就能实现函 数“printf”了,而这也就是链接的作用 

#### 函数库一般分为静态库和动态库两种。 

> - 静态库是指编译链接时,把库文件的代码全部加入到可执行文件中,因此生成的文件比较大,但在运行时也 就不再需要库文件了。其后缀名一般为“.a” 
>
> - 动态库与之相反,在编译链接时并没有把库文件的代码加入到可执行文件中,而是在程序执行时由运行时 链接文件加载库,这样可以节省系统的开销。动态库一般后缀名为“.so”,如前面所述的 libc.so.6 就是动态 库。gcc 在编译时默认使用动态库。完成了链接之后,gcc 就可以生成可执行文件,如下所示。 
>
>   `gcc hello.o –o hello` 
>
> - gcc默认生成的二进制程序，是动态链接的，这点可以通过 file 命令验证。 

#### gcc选项 

> - -E 只激活预处理,这个不生成文件,你需要把它重定向到一个输出文件里面 
> - -S  编译到汇编语言不进行汇编和链接 
> - -c  编译到目标代码 
> - -o 文件输出到 文件 
> - -static 此选项对生成的文件采用静态链接 
> - -g 生成调试信息。GNU 调试器可利用该信息。 
> - -shared 此选项将尽量使用动态库，所以生成文件比较小，但是需要系统由动态库. 
> - -O0 
> - -O1 
> - -O2 
> - -O3 编译器的优化选项的4个级别，-O0表示没有优化,-O1为缺省值，-O3优化级别最高 
> - -w  不生成任何警告信息。 
> - -Wall 生存所有的警告信息

### Linux调试器-gdb使用

> - 程序的发布方式有两种，debug模式和release模式 
> - Linux gcc/g++出来的二进制程序，默认是release模式 
> - 要使用gdb调试，必须在源代码生成二进制程序的时候, 加上 -g 选项［重要］

`gdb binFile` 退出： `ctrl + d` 或 `quit` 调试命令： 

> list／l 行号：显示binFile源代码，接着上次的位置往下列，每次列10行。［重要］ 
>
> list／l 函数名：列出某个函数的源代码。 
>
> r或run：运行程序。［重要］ 
>
> n 或 next：单条执行。［重要］ 
>
> s或step：进入函数调用［重要］ 
>
> break(b) 行号：在某一行设置断点［重要］ 
>
> break 函数名：在某个函数开头设置断点 
>
> info break ：查看断点信息。 
>
> fifinish：执行到当前函数返回，然后挺下来等待命令 
>
> print(p)：打印表达式的值，通过表达式可以修改变量的值或者调用函数 
>
> p 变量：打印变量值。［重要］ 
>
> set var：修改变量的值 
>
> continue(或c)：从当前位置开始连续而非单步执行程序［重要］ 
>
> run(或r)：从开始连续而非单步执行程序 
>
> delete breakpoints：删除所有断点 
>
> delete breakpoints n：删除序号为n的断点［重要］ 
>
> disable breakpoints：禁用断点 
>
> enable breakpoints：启用断点 
>
> info(或i) breakpoints：参看当前设置了哪些断点 
>
> display 变量名：跟踪查看一个变量，每次停下来都显示它的值 
>
> undisplay：取消对先前设置的那些变量的跟踪 
>
> until X行号：跳至X行 
>
> breaktrace(或bt)：查看各级函数调用及参数 
>
> info（i) locals：查看当前栈帧局部变量的值 
>
> quit：退出gdb

## Linux项目自动化构建工具-make/Makefifile 

> - 一个工程中的源文件不计数，其按类型、功能、模块分别放在若干个目录中，makefifile定义了一系列的 规则来指定，哪些文件需要先编译，哪些文件需要后编译，哪些文件需要重新编译，甚至于进行更复杂 的功能操作 
> - makefifile带来的好处就是——“自动化编译”，一旦写好，只需要一个make命令，整个工程完全自动编 译，极大的提高了软件开发的效率。 
> - make是一个命令工具，是一个解释makefifile中指令的命令工具，一般来说，大多数的IDE都有这个命 令，比如：Delphi的make，Visual C++的nmake，Linux下GNU的make。可见，makefifile都成为了一 种在工程方面的编译方法。 
> - make是一条命令，makefifile是一个文件，两个搭配使用，完成项目自动化构建。

### 实例代码 

```c
//c代码
#include <stdio.h> 
int main() 
{ 
printf("hello Makefile!\n"); 
return 0; 
} 
```

**Makefifile文件** 

```makefile
hello:hello.o 
    gcc hello.o -o hello 
hello.o:hello.s 
    gcc -c hello.s -o hello.o 
hello.s:hello.i 
    gcc -S hello.i -o hello.s 
hello.i:hello.c 
    gcc -E hello.c -o hello.i 
```

```makefile
.PHONY:clean 
clean: 
    rm -f hello.i hello.s hello.o hello 
```

#### 依赖关系 

> - 上面的文件 hello ,它依赖 hell.o 
> - hello.o , 它依赖 hello.s hello.s , 它依赖 hello.i 
> - hello.i , 它依赖 hello.c 

#### 依赖方法 

> gcc hello.* -option hello.* ,就是与之对应的依赖关系 

#### 原理 

make是如何工作的,在默认的方式下，也就是我们只输入make命令。那么， 

> 1. make会在当前目录下找名字叫“Makefifile”或“makefifile”的文件。 
> 2. 如果找到，它会找文件中的第一个目标文件（target），在上面的例子中，他会找到“hello”这个文件， 并把这个文件作为最终的目标文件。
> 3. 如果hello文件不存在，或是hello所依赖的后面的hello.o文件的文件修改时间要比hello这个文件新（可 以用 touch 测试），那么，他就会执行后面所定义的命令来生成hello这个文件。 
> 4. 如果hello所依赖的hello.o文件不存在，那么make会在当前文件中找目标为hello.o文件的依赖性，如果 找到则再根据那一个规则生成hello.o文件。（这有点像一个堆栈的过程） 
> 5. 当然，你的C文件和H文件是存在的啦，于是make会生成 hello.o 文件，然后再用 hello.o 文件声明 make的终极任务，也就是执行文件hello了。 
> 6. 这就是整个make的依赖性，make会一层又一层地去找文件的依赖关系，直到最终编译出第一个目标文 件。 
> 7. 在找寻的过程中，如果出现错误，比如最后被依赖的文件找不到，那么make就会直接退出，并报错， 而对于所定义的命令的错误，或是编译不成功，make根本不理。 
> 8. make只管文件的依赖性，即，如果在我找了依赖关系之后，冒号后面的文件还是不在，那么对不起， 我就不工作啦。 

#### 项目清理 

> - 工程是需要被清理的 
> - 像clean这种，没有被第一个目标文件直接或间接关联，那么它后面所定义的命令将不会被自动执行， 不过，我们可以显示要make执行。即命令——“make clean”，以此来清除所有的目标文件，以便重编 译。 
> - 但是一般我们这种clean的目标文件，我们将它设置为伪目标,用 .PHONY 修饰,伪目标的特性是，总是被 执行的。 