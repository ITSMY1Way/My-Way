**一维数组** 

> 数组名只有处于以下两种情况时才代表整个数组：①数组名**单独**在sizeof内时。②  &数组名（如&a）

```c
int a[] = {1,2,3,4};
printf("%d\n",sizeof(* a));//a是首元素地址，*a是首元素  4 
printf("%d\n",sizeof(&a));//数组的地址  4
printf("%d\n",sizeof(*&a));//&a是a的地址，那*&a就代表整个数组了，所以是16字节
printf("%d\n",sizeof(&a+1));//数组a尾元素后一位的那个元素地址 4 
printf("%d\n",sizeof(a));		//16，整个数组，大小为16个字节
printf("%d\n",sizeof(a+0));		//4，首元素的地址，地址即指针，指针大小为4个字节
printf("%d\n",sizeof(&a[0]));	//4，首元素的地址
printf("%d\n",sizeof(&a[0]+1));	//4，第二个元素的地址
```

## sizeof

 sizeof(...)是运算符，在头文件中typedef为unsigned int，结果类型是size_t。其值在编译时即计算好了，

参数可以是数组、指针、类型、对象、函数等。    

它的功能是：获得保证能容纳实现所建立的最大对象的字节大小。不关心里面存了多少数据。   

由于在编译时计算，因此sizeof不能用来返回动态分配的内存空间的大小。实际上，用sizeof来返回类型以及静态分配的对象、结构或数组所占的空间，返回值跟对象、结构、数组所存储的内容没有关系。   

>  具体而言，当参数分别如下时，sizeof返回的值表示的含义如下：   
>
>  数组——编译时分配的数组空间大小；   
>
>  指针——存储该指针所用的空间大小（存储该指针的地址的长度，是长整型，应该为4）；   
>
>  类型——该类型所占的空间大小；    
>
>  对象——对象的实际占用空间大小；  
>
>  函数——函数的返回类型所占的空间大小。函数的返回类型不能是void。

## strlen

strlen(...)是函数，要在运行时才能计算。参数必须是字符型指针（char*），且必须是以''\0''结尾的。 

当数组名作为参数传入时，实际上数组就退化成指针了。    

它的功能是：返回字符串的长度，以\0'为字符串结束标记，不区分是数组还是指针，就读到\0为止返回长度。而且strlen是不把\0计入字符串的长度的。

strlen只关心存储的数据内容，不关心空间的大小和类型。

该字符串可能是自己定义的，也可能是内存中随机的，该函数实际完成的功能是从代表该字符串的第一个地址开始遍历，直到遇到结束符NULL。返回的长度大小不包括NULL。

> 16位处理器可以一次性处理2个字节的数据量，指针即为2个字节；
>
> 32位处理器可以一次性处理4个字节的数据量，所以是4个字节；
>
> 64位处理器可以一次性处理8个字节的数据量，所以是8个字节。
>
> 指针是一个用来指示一个内存地址的计算机语言的变量或中央处理器(CPU)中寄存器(Register)。在使用一个指针时，一个程序既可以直接使用这个指针所储存的内存地址，又可以使用这个地址里储存的函数的值。且一个字节=8位。

### strlen计算字符串末尾自动加上'\0'的情况

> char test[4]={'t','e','s','t'}或char test[]={'t','e','s','t'}  这种情况下因为不管是数字长度缺省还是刚好填充字符个数，编译器都不会添加结尾符，所以这两种情况得到的结果不确定。
>
> char test[6]={'t','e','s','t'}  。当定义的数组长度大于字符串长度时，编译器会在字符串后面自动添加结尾符，所以结果为：4
>
> 如果不在字符数组后面加上‘\0’, 那么strlen就会一直计算下去，知道遇到内存中的'\0'，才停止计算。
>
> C风格的字符串给string类赋值的时候：char* test="test";string str(test);或string str=test时，str.size()的值也是4（string的末尾也有‘\0’）；
>
> const char *data()const;     //返回一个非null终止的c字符数组  
>
> const char *c_str()const;      //返回一个以null终止的c字符串
>
> 把string对象转换为C风格字符串的两个函数（c_str()和data()）得到的结果也能得到正确的结果，都为4

```cpp
const _Elem *c_str() const _NOEXCEPT
        {    // return pointer to null-terminated nonmutable array
        return (this->_Myptr());
        }
const _Elem *data() const _NOEXCEPT
        {    // return pointer to nonmutable array
        return (c_str());
        }
//data()函数最后也是调用c_str()函数。所以两者结果没有区别。
```

## 区别与联系

参考：https://blog.csdn.net/21aspnet/article/details/1539951



**字符数组**

```c
char arr[] = {'a','b','c','d','e','f'}; 
//字符数组初始化时为写入'\0'，所以不包括'\0'
printf("%d\n", strlen(arr));//6，整个数组
printf("%d\n", sizeof(arr + 0));//4，首元素的地址
printf("%d\n", sizeof(*arr));//第一个元素1
printf("%d\n", sizeof(arr[1]));//1，第二个元素
printf("%d\n", sizeof(&arr));//4，整个数组的地址
printf("%d\n", sizeof(&arr + 1));//4，下一个数组的地址
printf("%d\n", sizeof(&arr[0] + 1));//4，第二个元素的地址

//strlen() 直到遇到'\0'停止，所求字符串长度不包括'\0'
//strlen(const char*)
printf("%d\n", strlen(arr));		//随机值，19
printf("%d\n", strlen(arr + 0));	//随机值 19
printf("%d\n", strlen(*arr));		//ERROR，类型不匹配
printf("%d\n", strlen(arr[1]));		//ERROR，类型不匹配
printf("%d\n", strlen(&arr));		//随机值（此处为数组指针类型）  19
printf("%d\n", strlen(&arr + 1));	//随机值 13
printf("%d\n", strlen(&arr[0] + 1));//随机值 第二个元素             18
```

```c
char *p = "abcdef";
printf("%d\n", sizeof(p));			//4
printf("%d\n", sizeof(p + 1));		//4
printf("%d\n", sizeof(*p));			//1
printf("%d\n", sizeof(p[0]));		//1
printf("%d\n", sizeof(&p));			//4，p变量的地址
printf("%d\n", sizeof(&p + 1));		//4，下一个指针的地址
printf("%d\n", sizeof(&p[0] + 1));	//4

printf("%d\n", strlen(p));			//6
printf("%d\n", strlen(p + 1));		//5
printf("%d\n", strlen(*p));			//ERROR
printf("%d\n", strlen(p[0]));		//ERROR
printf("%d\n", strlen(&p));			//p的地址，为二级指针 随机
printf("%d\n", strlen(&p + 1));		//下一个指针的地址，为二级指针  随机
printf("%d\n", strlen(&p[0] + 1));	//5
```

**二维数组** 

```c
int a[3][4] = { 0 };
printf("%d\n", sizeof(a));			  //48
printf("%d\n", sizeof(a[0][0]));       //4，第一个int类型的变量
printf("%d\n", sizeof(a[0]));		  //16，可将a[0]类似看作数组名，a[0]中包括4个int类型的变量
printf("%d\n", sizeof(a[0] + 1));	  //4，a[0][1]的地址
printf("%d\n", sizeof(*(a[0] + 1)));   //4，a[0][1]的内容
printf("%d\n", sizeof(a + 1));		  //4，数组a里第一个元素的的地址
printf("%d\n", sizeof(*(a + 1)));      //16，a[1]的内容
printf("%d\n", sizeof(&a[0] + 1));	  //4，&a[0]为数组指针，加1为a[1]的地址
printf("%d\n", sizeof(*(&a[0] + 1)));  //16，a[1]的内容
printf("%d\n", sizeof(*a));			  //16，a[0]的内容
printf("%d\n", sizeof(a[3]));	      //16，虽然数组下标越界，但不会报错。
                                      //允许读取超出范围的下一个元素，但不允许写入。
```

