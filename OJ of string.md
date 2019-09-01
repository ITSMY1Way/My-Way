

### 把字符串转成整数

```cpp
//实现Integer.valueOf(string)的功能
class Solution {
    public:    
    int StrToInt(string str) {        
        int n = str.size(), s = 1;        
        long long res = 0;        
        if(!n) 
            return 0;        
        if(str[0] == '-')   s = -1;       
        for(int i = (str[0] ==  '-' || str[0] == '+') ? 1 : 0; i < n; ++i){            
            if(!('0' <= str[i] && str[i] <= '9')) 
                return 0;//过滤非合法字符           
            res = (res << 1) + (res << 3) + (str[i] & 0xf);//res=res*10+str[i]-'0';        
        }          
        return res * s;    
    }
};
```

### 字符串相加

```cpp
//分析：给定两个字符串形式的非负整数，返回他们的和，也是个字符串
//从后往前取单个字符，若有，转为数字；若无+0；
string addStrings(string num1, string num2) {
string res ;
int c = 0,i = num1.size() -1,j = num2.size()-1;
    while(i >= 0 || j >= 0 || c > 0){
        c += (i >= 0) ? num1[i--] -'0' : 0;//从后往前取字符，转为数字
        c += (j >= 0) ? num2[j--] -'0' : 0;//对应位置相加
        res.push_back(c%10 + '0');//转为字符插入res后，
        c /= 10 ;//进位
    }
    reverse(res.begin(),res.end());  //从后往前取的，所以需要反转
    return res;
}
```

### 反转字

```

```

### 符串

```cpp
//位运算
void reverseString(vector<char>& s) {
    const int half = s.size() / 2;
    int end = s.size() - 1;
    for (int i = 0 ; i < half; ++i, --end) {
        s[i] = s[i] ^ s[end];
        s[end] = s[end] ^ s[i];
        s[i] = s[i]^s[end];
    }
}
//双指针转换
void reverseString(vector<char>& s) 
{
    int k=0,i=s.size()-1;
    while(k<i) swap(s[k++],s[i--]);
}
```

### 字符串的第一个唯一字符

```cpp
int firstUniqChar(string s) {
    int a[26] = {0};
    for(int i = 0; i < s.size(); i++){
        a[s[i]- 'a']++;
    }
    for(int i = 0; i < s.size(); i++){
        if(a[s[i]- 'a'] == 1)
        return i;
    }
    return -1;
}
```

### 字符串里最后一个单词的长度

```cpp
//方法一：
int lengthOfLastWord(string s) {
    if(s.empty())
        return 0;//不存在最后一个单词
    int size = s.size() - 1;
    while(size>=0 && s[size]==' '){//可能会在末尾处包含多余的空格，先将这些多余处理掉。
        s.erase(size);
        --size;
    }
    int pos = s.find_last_of(' ');//找到最后一个空格
    return s.length() - pos - 1;
}
//方法二：
int lengthOfLastWord(string s)
{
    string word;
    stringstream ss(s);//字符串输入输出流自动过滤空格
    while(ss>>word){}//读取到最后一个单词
    return word.size();
}
```

### 验证回文串

```cpp
// 双指针
//isalnum(char c):判断字符变量c是否为字母或数字，若是则返回非零，否则返回零。
//tolower(char c):把字母字符转换成小写,非字母字符不做出处理。
bool isPalindrome(string s) {
    if(s.size() <= 1)
        return true;
    int i = 0, j = s.size() - 1;
while(i < j)
     {
        while(i < j && !isalnum(s[i]))// 排除所有非字母或数字的字符
            i++;
        while(i < j && !isalnum(s[j]))
            j--;
        if(tolower(s[i++]) != tolower(s[j--]))//统一转换成小写字母再比较
            return false; 
     }
     return true;
}
```

### 翻转字符串II：区间部分翻转

```cpp
//解法1：暴力啊
string reverseStr(string s, int k) {
    for (int i = 0; i < s.size(); i += 2 * k)
    {
        if (i + k <= s.size())
            reverse(s.begin() + i, s.begin() + i + k);
        else
            reverse(s.begin() + i, s.end());
    }
    return s;
}
//解法2：迭代器实现
string reverseStr(string s, int k) {    
    string::iterator it=s.begin();
    while(it+k<=s.end())
    {
        reverse(it,it+k);
        it += 2*k;
    }
    reverse(it,s.end());//it跑出去和没有出去都不影响的。         
    return s;        
}   
```

### 翻转字符串III：翻转字符串中的单词

```cpp
//使用stack存储每一个单词
//pos指向第一个不是' '的位置，即单词的首字母
//将pos所指的单词保存到stack中
//最后将stack中的单词保存到字符串中
string reverseWords(string s) {
    stack<string> st;
    int pos = 0;
    while (true) {  //whiie(1)
        pos = s.find_first_not_of(' ', pos);    // 指向单词首字母
        if (pos == string::npos)//未匹配
            break;
        st.push(s.substr(pos, s.find(' ', pos) - pos));    // 储存单词
        pos = s.find(' ', pos);    // 找到单词后的位置
    }
    string out;//定义一个out
    while (!st.empty()) {
        out += st.top() + " ";
        st.pop();
    }
    out.pop_back();    //删除字符串的最后一个空格——>多余空格
    return out;
}
```

### 字符串相乘

```cpp
//两个一位数字相乘最多为两位，对10求模得低位，对10求商得高位
//时间复杂度: O(m∗n)
//空间复杂度: O(m+n)
string multiply(string num1, string num2) {
    int n1=num1.size()， n2=num2.size();
    string res(n1+n2,'0');// 所有的进位初始化为 '0'
    for(int i=n2-1;i>=0;i--){
        for(int j=n1-1;j>=0;j--){// 进位和乘积的和，当前要加上上一步计算的进位
            int temp=(res[i+j+1]-'0')+(num1[j]-'0')*(num2[i]-'0');
            res[i+j+1]=temp%10+'0';// 保存当前计算的数字(低位)
            res[i+j]+=temp/10; //更新当前进位(高位)，前一位加上进位，res[i+j]已经初始化为'0'，加上int类型自动转化为char，所以此处不加'0'
        }
    }
//去除首位'0'    从第一个不为 '0' 的字符开始是有效结果或者结果是个位数
    for(int i=0;i<n1+n2;i++){
        if(res[i]!='0')
            return res.substr(i); // 从 i 到最后的子字符串
    }
    return "0";
}
```

