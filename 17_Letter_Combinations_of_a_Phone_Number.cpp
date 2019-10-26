class Solution {
public:
    vector<string> letterCombinations(string digits) {
        int num[8] = {3,3,3,3,3,4,3,4};
        char alpha[8][5] = {"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        vector<string> res;
        int sz = digits.size();
        if(sz == 0)
            return res;
        int* multi = new int[sz];
        char* cur = new char[sz + 1];
        cur[sz] = 0;
        int sum = 1;
        for(int i = sz - 1; i >= 0; i--)
        {
            multi[i] = sum;
            if(digits[i] == '7' || digits[i] == '9')
                sum *= 4;
            else
                sum *= 3;
        }
        res.resize(sum);
        for(int i = 0; i < sum; i++)
        {
            for(int j = 0; j < sz; j++)
                cur[j] = alpha[digits[j] -'2'][i / multi[j] % num[digits[j] -'2']];
            res[i] = move(cur);
        }
        delete []multi;
        delete []cur;
        return res;       
    }
};