###  非类型模板参数 

> 模板参数分类类型形参与非类型形参。 
>
> 类型形参即：出现在模板参数列表中，跟在class或者typename之类的参数类型名称。 
>
> 非类型形参，就是用一个常量作为类(函数)模板的一个参数，在类(函数)模板中可将该参数当成常量来使用。 
>
> 注意： 
>
> 1. 浮点数、类对象以及字符串是不允许作为非类型模板参数的。 
> 2. 非类型的模板参数必须在编译期就能确认结果。 

### 模板的特化 

> 使用模板可以实现一些与类型无关的代码，但对于一些特殊类型的可能会得到一些错误的结果
>
> ```cpp
> template<class T>
> bool IsEqual(T& left, T& right) {
> return left == right; }
> void Test()
> {
> char* p1 = "hello";
> char* p2 = "world";
> if(IsEqual(p1, p2))
> cout<<p1<<endl;
> else
> cout<<p2<<endl; }
> ```
>
> 此时，就需要对模板进行特化。即：在原模板类的基础上，针对特殊类型所进行特殊化的实现方式。模板特 
>
> 化中分为函数模板特化与类模板特化。

### 函数模板特化 

> 函数模板的特化步骤： 
>
> 1. 必须要先有一个基础的函数模板 
> 2. 关键字template后面接一对空的尖括号<> 
> 3. 函数名后跟一对尖括号，尖括号中指定需要特化的类型 
> 4. 函数形参表: 必须要和模板函数的基础参数类型完全相同，如果不同编译器可能会报一些奇怪的错误。
>
> ```cpp
> template<>
> bool IsEqual<char*>(char*& left, char*& right) {
> if(strcmp(left, right) > 0)
> return true;
> return false; }
> //一般情况下如果函数模板遇到不能处理或者处理有误的类型，为了实现简单通常都是将该函数直接给出。
> bool IsEqual(char* left, char* right) {
> if(strcmp(left, right) > 0)
> return true;
> return false; }
> ```

### 类模板特化 

> ##### 全特化 
>
>  全特化即是将模板参数类表中所有的参数都确定化
>
> **偏特化**：任何针对模版参数进一步进行条件限制设计的特化版本。
>
> 偏特化有以下两种表现方式： 
>
> - 部分特化 ：将模板参数类表中的一部分参数特化
> - 参数更进一步的限制：偏特化并不仅仅是指特化部分参数，而是针对模板参数更进一步的条件限制所设计出来的一个特化版 本。 

### 如何实现一个通用的拷贝函数？

```cpp
// 使用memcpy拷贝
template<class T>
void Copy(T* dst, const T* src, size_t size) {
memcpy(dst, src, sizeof(T)*size);
}
int main()
{
string strarr1[3] = {"11", "22", "33"};
string strarr2[3];
Copy(strarr2, strarr1, 3);
}
//上述代码虽然对于任意类型的空间都可以进行拷贝，但是如果拷贝自定义类型对象就可能会出错，因为自定义类型对象有可能会涉及到深拷贝(比如string)，而memcpy属于浅拷贝。如果对象中涉及到资源管理，就只能用赋值。

//使用赋值方式拷贝
template<class T>
void Copy(T* dst, const T* src, size_t size) {
for(size_t i = 0; i < size; ++i)
 {
dst[i] = src[i];
 }
}//用循环赋值的方式虽然可以，但是代码的效率比较低，

//增加bool类型区分自定义与内置类型
template<class T>
void Copy(T* dst, const T* src, size_t size, bool IsPODType) {
if(IsPODType)
memcpy(dst, src, sizeof(T)*size);
else
 {
for(size_t i = 0; i < size; ++i)
dst[i] = src[i];
 }
}//通过多增加一个参数，就可将两种拷贝的优势体现结合起来。但缺陷是：用户需要根据所拷贝元素的类型去传递第三个参数，那出错的可能性就增加。

//使用函数区分内置于自定义类型
//因为内置类型的个数是确定的，可以将所有内置类型集合在一起，如果能够将所拷贝对象的类型确定下来，在内置类型集合中查找其是否存在即可确定所拷贝类型是否为内置类型
//
// POD: plain old data 平凡类型（无关痛痒的类型）--基本类型
// 指在C++ 中与 C兼容的类型，可以按照 C 的方式处理。
//
// 此处只是举例，只列出个别类型
bool IsPODType(const char* strType) {
const char* arrType[] = {"char", "short", "int", "long", "long long", "float", 
"double", "long double"};
for(size_t i = 0; i < sizeof(array)/sizeof(array[0]); ++i)
 {
if(0 == strcmp(strType, arrType[i]))
return true;
 }
return false; }
template<class T>
void Copy(T* dst, const T* src, size_t size) {
if(IsPODType(typeid(T).name()))
memcpy(dst, src, sizeof(T)*size);
else
 {
for(size_t i = 0; i < size; ++i)
dst[i] = src[i];
 }
}//通过typeid来确认所拷贝对象的实际类型，然后再在内置类型集合中枚举其是否出现过，既可确认所拷贝元素的类型为内置类型或者自定义类型。但缺陷是：枚举需要将所有类型遍历一遍，每次比较都是字符串的比较，效率比较低。
```

### 类型萃取 

https://blog.csdn.net/mxrrr_sunshine/article/details/81181958

### 模板总结 

【优点】 

> 1. 模板复用了代码，节省资源，更快的迭代开发，C++的标准模板库(STL)因此而产生比特科技 
> 2. 增强了代码的灵活性 

【缺陷】 

> 1. 模板会导致代码膨胀问题，也会导致编译时间变长 
> 2. 出现模板编译错误时，错误信息非常凌乱，不易定位错误 

https://blog.csdn.net/weixin_42678507/article/details/88658291