### 构造类型：

> \> 数组类型 
>
> \> 结构体类型 struct 
>
> \> 枚举类型 enum 
>
> \> 联合类型 union 

### 指针类型 空类型： 

> void 表示空类型（无类型） 通常应用于函数的返回类型、函数的参数 、指针类型

### 原码、反码、补码 

> 计算机中的符号数有三种表示方法，即原码、反码和补码。三种表示方法均有符号位和数值位两部分，符号 
>
> 位都是用0表示“正”，用1表示“负”，而数值位，三种表示方法各不相同。 
>
> **原码** 直接将二进制按照正负数的形式翻译成二进制就可以。 
>
> **反码** 将原码的符号位不变，其他位依次按位取反就可以得到了。 
>
> **补码** 反码+1就得到补码。 正数的原、反、补码都相同。 
>
> **对于整形来说：数据存放内存中其实存放的是补码。** 
>
> 为什么？ 
>
> 在计算机系统中，数值一律用补码来表示和存储。原因在于，使用补码，可以将符号位和数值域统一处理； 
>
> 同时，加法和减法也可以统一处理（**CPU只有加法器**）此外，补码与原码相互转换，其运算过程是相同的，不需要额外的硬件电路

`unsigned char c = -1;     `      输出c 为 255

> 当使用unsigned char 即无符号整数时，-1用补码表示即1111 1111，十六进制表示为0xff ，十进制表示即为255。
>
> -1，在c中将会默认为int类型，然后将int类型的-1强制转换为unsigned char类型， 相当于：(-1)%256=255

### 输出格式

> ％d整型输出，％ld长整型输出，
>
> ％o以八进制数形式输出整数，
>
> ％x以十六进制数形式输出整数，  
>
> ％u以十进制数输出unsigned型数据(无符号数)。
>
> ％c用来输出一个字符，
>
> ％s用来输出一个字符串，
>
> ％f用来输出实数，以小数形式输出，（备注：浮点数是不能定义如的精度的，所以“%6.2f”这种写法是“错误的”！！！）
>
> ％e以指数形式输出实数，
>
> ％g根据大小自动选f格式或e格式，且不输出无意义的零。

```c
short num = 32767;
short a = num + 1;
printf("%d\n", a);//-32768
//0111 1111 1111 1111 -> 1000 0000 0000 0000 
//(系统直接识别为最小值，不进行解码)
```

### 浮点型在内存中的存储 

包括 `float\ double\ long double`
