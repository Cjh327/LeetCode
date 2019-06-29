
	vector<string> letters{ " ","*","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz" };
	vector<string> letterCombinations(string digits) {
		vector<string> res;
		if (digits.empty()) {
			return res;
		}
 		letterCombinations(res, "", digits, 0);
		return res;
	}
	void letterCombinations(vector<string>& res, string str, string& digits, int k) {
		if (k == digits.size()) {
			res.push_back(str);
			return;
		}
		string letter = letters[digits[k] - '0'];
		for (char ch : letter) {
			str += ch;
			letterCombinations(res, str, digits, k + 1);
			str.pop_back();
		}
	}