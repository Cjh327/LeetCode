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

### Problem 260. Single Number III
  1. xor operation on total array with result a.  
  2. choose a 1-bit of a, xor it with the whole array. This operation split the whole array into two parts, with a single number in it respectively.
### Problem 189. Rotate Array
  reverse 3 times
