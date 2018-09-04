The characteristics of C++ reference is an outstanding tool for backtracking algorithm!

let us use [1,2,3,4] as an example to explain my solution:

subsets([1,2,3,4]) = []
                     // push(1)
                     [1, subsets([2,3,4])] // if push N times in subsets([2,3,4]), the pop times is also N, so vec is also [1] after backtrack.
                     // pop(), push(2)
                     [2, subsets([3,4])]
                     // pop(), push(3)
                     [3, subsets([4])]
                     // pop(), push(4)
                     [4, subsets([])]
                     // pop()
                     
class Solution {
public:
	vector<vector<int>> subsetsWithDup(vector<int>& nums) {
		for (vector<int>::size_type i = 1; i < nums.size(); i++) {
			//sort
      int key = nums[i];
			int j = i - 1;
			while (key < nums[j] && j >= 0) {
				nums[j + 1] = nums[j];
				j--;
			}
			nums[j + 1] = key;
		}
    
		vector<vector<int>> res;
		vector<int> vec;
		subsetsWithDup(res, vec, nums, 0);
		return res;
	}
private:
	void subsetsWithDup(vector<vector<int>> &res, vector<int> &vec, vector<int>& nums, int begin)
	{
		res.push_back(vec);
		for (vector<int>::size_type i = begin; i < nums.size(); i++)
		{
			if (i == begin || nums[i] != nums[i - 1])
			{
				vec.push_back(nums[i]);
				subsetsWithDup(res, vec, nums, i + 1);
				vec.pop_back();
			}
		}
	}
};
