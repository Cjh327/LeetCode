//Problem 476: Number Coplement
    
    //My solution:
    class Solution {
    public:
    	int power(int n, int k)
    	{
    		int product = 1;
    		for (int i = 0; i < k; i++)
    		{
    			product *= n;
    		}
    		return product;
    	}
    	int findComplement(int num) {
    		int tmp = 0;
    		int i = 0;
    		int copynum = num;
    		while (copynum)
    		{
    			copynum /= 2;
    			tmp += power(2, i);
    			i++;
    		}
    		return tmp^num;
    	}
    };
    
//a more concise solution
class Solution {
public:
	int findComplement(int num) {
		unsigned mask = ~0;
		while (num & mask) mask <<= 1;
		return ~mask & ~num;
	}
};
