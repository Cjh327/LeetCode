# LeetCode
### Problem 5. 最长回文子串（Longest Palindromic Substring）

$$
\begin{align}
dp[i,j]=\left\{\begin{matrix}
dp[i+1,j-1],\quad &str[i]=str[j]\\ 
0&o.w.
\end{matrix}\right.
\end{align}
$$

$dp[i,j]=1$表示 `str[i,...,j]` 为回文子串

### Problem 53. 最大子序和（Maximum Subarray）

从第一个大于0的数开始找

```C++
 int maxSubArray(vector<int> &nums) {
     int maxSum = nums[0];
     int curSum = 0;
     for (int num : nums) {
         if (curSum > 0) curSum += num;
         else curSum = num;
         if (curSum > maxSum) {
             maxSum = curSum;
         }
     }
     return maxSum;
 }
```

### Problem 62. Unique Paths

组合数，用递推关系计算，注意乘法溢出

### Problem 63. Unique Paths II

有障碍物，障碍物点无法到达，注意初始化边界时，障碍物后面的点也无法到达。

### Problem 69. Sqrt(x)

Implement int sqrt(int x).  

**Notice:**  

Divide and Conquer: mid * mid may overflow. Convert int to long long.  

Newton's method is another way to solve it.

### Problem 141. Linked List Cycle
  Use a slow pointer and a fast pointer. If the fast pointer catch up the slow one, there is a cycle.  
###  x=2^n
  x>0 && ((x-1) & x == 0)
### Problem 137. Single Number II
  Use two variables a and b to implement state transition 00->01->10->00

### Problem 139. Word Break

dynamic programming

`isBreak[i]` means that `s[0...i]` is word break

### Problem 213. House Robber II

分情况，分为**可以偷第一家**和**绝不偷第一家**

**可以偷第一家**：这种情况下第一家可能被偷也可能不被偷，但最后一家一定不会被偷

**绝不偷第一家**：这种情况下第一家绝不被偷，因此最后一家可能被偷

两种情况中的最大值为答案

### Problem 260. Single Number III
  1. xor operation on total array with result a.  
  2. choose a 1-bit of a, xor it with the whole array. This operation split the whole array into two parts, with a single number in it respectively.
### Problem 189. Rotate Array
  reverse 3 times

### Problem 103. Binary Tree Zigzag Level Order Traversal

翻转vector

```C++
#include <algorithm>
reverse(v.begin(), v.end());
```

### Problem 559. Maximum Depth of N-ary Tree

层序遍历，每层最后一个节点后面入队NULL，注意后一层最后一个节点额外判断，直接返回。

### Problem26. RemoveDuplicatesfromSortedArray

在一个有序数组中删除重复元素。

两个索引 i, j，分别指向不重复位置和搜索位置

注意输入为空数组的情况

```C++
// vector 删除一段元素
v.erase(v.begin()+i+1, v.end())
```

### Problem771. JewelsandStones

频繁在同一个集合中查找注意使用map

### Problem500. KeyboardRow

string中判断某一个字符或字符串是否包含其中：

```C++
if (str.find('c') == str.npos) {
	// 未找到
}
```

### Problem28. ImplementstrStr

KMP算法，先计算next数组，再进行匹配

```C++
int KMP(string haystack, string needle) {
	vector<int> next(needle.size(), -1);
	int i = 0, j = -1;
	while (i < (int)next.size() - 1) {
		if (j == -1 || needle[i] == needle[j]) {
			next[++i] = ++j;
		}
		else {
			j = next[j];
		}
	}
	i = 0, j = 0;
	while (i < (int)haystack.size() && j < (int)needle.size()) {
		if (j == -1 || haystack[i] == needle[j]) {
			++i;
			++j;
		}
		else {
			j = next[j];
		}
	}
	if (j == needle.size()) {
		return i - j;
	}
	return -1;
}
```

