## 1.输入

- #### 预先不输入数据的数组，处理方式：读到文件结尾 

  ```cpp
  //C 语言
  while(scanf("%d%d",&a,&b)!=EOF) {
  printf("%d\n",a+b);
  }
  //C++
  while (cin>>a>>b)
  { 
  cout<<a + b<< endl; 
  }
  ```

- #### 预先输入数据的数组，处理方式：读数组然后进行循环

  ```cpp
  //C 语言
  scanf("%d",&n)
  for(int i=0;i<n;i++) {
  int a,b;
  scanf("%d%d",&a,&b);
  printf("%d\n",a+b);
  }
  //C++
  cin>>n; 
  for (int i = 0; i < n; i++) 
  {
      int a, b; 
      cin>>a>>b; 
      cout<<a + b<<endl; 
  }
  ```

- #### 只有一组数据，处理方式：直接读取 

  ```cpp
  //C 语言
  scanf("%d%d",&a,&b);
  printf("%d\n",a+b);
  //C++
  cin>>a>>b;
  cout<<a+b<<endl;
  ```

## 2.输出

- 不需要输出 case 数 

  ```cpp
  cin>>n; 
  for (int i = 0; i < n; i++)
  { 
      int a, b; 
      cin>>a>>b; 
      cout<<a + b<<endl; 
  }
  ```

- 需要输出 case 数

  ```cpp
  cin>>n; 
  for (int i = 0; i < n; i++)
  { 
      int a, b; 
      cin>>a>>b;
      cout<<"Case"<<i+1<<a + b<<endl; 
  }
  ```

-  每个 case 之后有空行

  ```cpp
  cin<<n; 
  for (int i = 0; i < n; i++)
  { 
      int a, b; 
      cin>>a>>b; 
      cout<<"Case"<<i + 1<<a + b<<endl<<endl; 
  }
  ```

- 两个 case 之间有空行 

  ```cpp
  cin>>n; 
  for (int i = 0; i < n; i++)
  { 
      int a, b; 
      cin>>a>>b; 
      if (i > 0){ 
          cout<<endl; 
      } 
      cout<<"Case"<<i + 1<<a + b<<endl<<endl; 
  }
  ```

## 3.行末空格

> 比如：输出需要打印多个数需要使用空格分隔的时候，我们循环使用 printf("%d ",x); 这种会 很方便，但是这样会导致行末多一个空格，后台系统会严格比对你 的输出和.out 文件，这 样也会被判错误

## 4.换行问题

> 对于每个样例，建议输出完全之后都换行一下。对于一些题目，可能就是不换行就导致了后 面输入数据错位，那就肯定不可能过了。 

## 处理细节和技巧

> - ### 输入
>
>   #### 不用保存所有组的输入，读一组算一组
>
>   **“可恶”的字符串——带空白**
>
>   - scanf, cin之类都读到**空白结束**
>   - gets, cin.getline。再自己parse
>   - **用scanf, gets代替cin**。
>
> - ### 输出
>
>   #### 注意格式
>
>   - 字母大小写
>   - 什么时候换行
>   - 输出“case”后面有没有“#”或者“：”之类。
>   - 每行末尾有\n，但一般没有空白
>   - 用printf代替cout。

 