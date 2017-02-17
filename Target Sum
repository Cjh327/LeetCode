The recursive solution is very slow, because its runtime is exponential

The original problem statement is equivalent to:
Find a subset of nums that need to be positive, and the rest of them negative, such that the sum is equal to target

Let P be the positive subset and N be the negative subset
For example:
Given nums = [1, 2, 3, 4, 5] and target = 3 then one possible solution is +1-2+3-4+5 = 3
Here positive subset is P = [1, 3, 5] and negative subset is N = [2, 4]

Then let's see how this can be converted to a subset sum problem:

                  sum(P) - sum(N) = target
sum(P) + sum(N) + sum(P) - sum(N) = target + sum(P) + sum(N)
                       2 * sum(P) = target + sum(nums)
So the original problem has been converted to a subset sum problem as follows:
Find a subset P of nums such that sum(P) = (target + sum(nums)) / 2

Note that the above formula has proved that target + sum(nums) must be even
We can use that fact to quickly identify inputs that do not have a solution (Thanks to @BrunoDeNadaiSarnaglia for the suggestion)
For detailed explanation on how to solve subset sum problem, you may refer to Partition Equal Subset Sum


class Solution {
public:
	int findTargetSumWays(vector<int>& nums, int S) {
		int sum = 0;
		for (int i : nums)
		{
			sum += i;
		}
		if ((S + sum) % 2 != 0 || sum < S)
		{
			return 0;
		}
		int sumP = (S + sum) / 2;
    
		int *dp = new int[sumP + 1];
		for (int i = 0; i < sumP + 1; i++)
		{
			dp[i] = 0;
		}
		dp[0] = 1;
		for (int n : nums)
		{
			for (int i = sumP; i >= n; i--)
			{
				dp[i] += dp[i - n];
			}
		}
		return dp[sumP];
	}
};
