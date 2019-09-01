### 只出现一次的数字

```cpp
//先排序，再双指针对比
int singleNumber(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    for(int i = 0, j = 1; j < nums.size(); i += 2, j += 2){
        if(nums[i] != nums[j])  return nums[i];
    }
    return nums[nums.size() - 1];
}
//异或   任何一个数字异或它自己都等于0，任何数与0异或为自身
int singleNumber(vector<int>& nums) {
    int result = 0;
    for(int e : nums)
        result ^=e;
    return result;
}
```

### 电话号码的字母组合

```cpp
vector<string> letterCombinations(string digits) {
    vector<string> a{"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    vector<string> c;
    if(digits.empty())
        return c;
    c.push_back("");//插入一个，size为1
    for (int i=0;i<digits.size();i++)
    {
        int res=digits[i]-'2';//当前按键对应的字符串索引
        int len=c.size();     //前一次处理好的字符串数
        for(int i = 0;i<len;i++)//遍历前一次处理好的字符串
        {
            for (auto m:a[res])//遍历按键对应字符
            {
                c.push_back(c[i]+m);//将每一种组合放到末端
            }
        }
        c.erase(c.begin(),c.begin()+len);//清除前一次的组合
    }
   return c;
}
```

### 杨辉三角OJ

```cpp
//杨辉三角即该位置的值为左上角与右上角的和
vector<vector<int>> generate(int numRows) {
    vector<vector<int>> a(numRows);
    if(numRows == 0)    
        return a; //若numRows为空，返回空数组
    for(int i = 0; i < numRows; ++ i ) //给数组一个个赋值
    {
        for(int j = 0; j <= i; ++ j)
        {
            if(j == 0 || j == i) //若是左右两边的边界，赋值为1
                a[i].push_back(1);
            else
                a[i].push_back(a[i-1][j-1] + a[i-1][j]); //否则赋值为该位置左上与右上的和
        }
    }
    return a;
}
```

### 删除排序数组中的重复项

```cpp
int removeDuplicates(vector<int>& nums) {
    int i = 0;
    for (int j = 0; j < nums.size(); ++j) {
        if (i == 0 || nums[i-1] != nums[j]) 
        nums[i++] = nums[j];
    }
    return i;
}
```

### 只出现一次的数字 II——331

```cpp
//1.统计每一位1的个数，和%3，若不为0，则则说明该位上只出现一次的元素，在该位上有1;
//通过移位操作和1做位与运算，则可求得当前元素在该位是否有1
int singleNumber(vector<int>& nums) {
    vector<int> bits(32);//统计nums中所有数转化成二进制后，每个位上1的个数
    int ans = 0;
    for (int i = 0; i < 32; i++) {
        for (int j = 0; j < nums.size(); j++)
            bits[i] += (nums[j] >> i) & 1;//将bits数组中能够整除3的值置0，不能整除3的值置1
        ans |= (bits[i] % 3) << i;//将bits转换成真的二进制数
    }
    return ans;
}
    
//2.状态机法，用2个数分别表示状态机的3个状态
//0 ^ x = x,
//x ^ x = 0；
//x & ~x = 0,
//x & ~0 =x;
//x第一次出现后，a = (a ^ x) & ~b。 a = x,b = (b ^ x) & ~a （此时a = x），所以b = 0。即 a = 0 ， b = 0；
//x第二次出现：a = (a ^ x) & ~b, a = (x ^ x) & ~0, a = 0;b = (b ^ x) & ~a 化简， b = (0 ^ x) & ~0 ,b = x;
//x第三次出现：a = (a ^ x) & ~b， a = (0 ^ x) & ~x ,a = 0;b = (b ^ x) & ~a 化简， b = (x ^ x) & ~0 , b = 0;
//出现三次同一个数，a和b最终都变回了0.
//只出现一次的数，按照上面x第一次出现的规律可知a = x, b = 0;因此最后返回a.
int singleNumber(vector<int>& nums) {
    int ones = 0, twos = 0;
    for(int i=0; i<nums.size(); ++i){
        ones = (ones^nums[i]) & ~twos;
        twos = (twos^nums[i]) & ~ones;
    }
    return ones;
}
```

### 只出现一次的数字 II——1，1，2，3

```cpp
    vector<int> singleNumber(vector<int>& nums) {
        int sum = 0,b = 1;
        for(auto num : nums)
            sum ^= num;//所有的数异或，即 x^y = sum
        while((sum&1) == 0){//若sum的这一位是1，则x与y在此位上不同
            sum >>= 1;//sum要右移，最后一位，倒数第二位以依此
            b <<= 1;//bit一直左移，代表的是x与y不同的位置
        }
        int num1 = 0,num2=0;//x和y
        for(auto i:nums){
            if((i&b) != 0)//区分这两个数，注意优先级
                num1 ^= i;
            else
                num2 ^= i;
        }
        return {num2,num1};//这里可以皮一下，输出顺序不重要
    }
```

### 数组中出现次数超过一半的数字 

```cpp
//先排序去中间数字，若它出现次数超过长度一般则存在
//时间O（nlogn） 空间 O（1）
int MoreThanHalfNum_Solution(vector<int> numbers) {
    sort(numbers.begin(),numbers.end());
    int key = numbers[numbers.size()/2];
    int count = 0;
    for (int i = 0; i < numbers.size(); ++i) {
        if(key == numbers[i])
            ++ count;
    }
    if (count>numbers.size()/2)
        return key;
    return 0;
}
```

### 连续子数组最大的和

```cpp
//给一个数组，返回它的最大连续子序列的和
//例如:{6,-3,-2,7,-15,1,2,2},连续子向量的最大和为8(从第0个开始,到第3个为止)
int FindGreatestSumOfSubArray(vector<int> array)
{
    // 鲁棒性
    if(array.empty())
        return 0;
    // 辅助变量
    int cur_sum = array[0];// cur_sum为当前和
    int max_sum = array[0];// max_sum为最大和
    // 遍历所有元素
    for(int i = 1; i < array.size(); ++i)
    {
        // 更新cur_sum
        if(cur_sum <= 0)
            cur_sum = array[i];
        else
            cur_sum += array[i];
        // 跟新max_sum
        if(cur_sum > max_sum)
            max_sum = cur_sum;
    }
    return max_sum;
}
```

