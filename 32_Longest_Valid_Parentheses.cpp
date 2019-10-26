class Solution {
public:
    int longestValidParentheses(string s) {
        int sz = s.size();
        int maxlen = 0;
        int curhigh = 0;
        int lastreset = -1;
        int lastresetr = sz;
        for(int i = 0; i < sz; ++i)
        {
            if(s[i] == '(')
                ++curhigh;
            else
                --curhigh;
            if(curhigh == 0)
            {
                if(i - lastreset > maxlen)
                    maxlen = i - lastreset;
            }
            if(curhigh < 0)
            {
                lastreset = i;
                curhigh = 0;
            }
        }
        curhigh = 0;
        if(lastreset == -1)
            lastreset = 0;
        for(int i= sz - 1; i >= lastreset; --i)
        {
            if(s[i] == '(')
                --curhigh;
            else
                ++curhigh;
            if(curhigh == 0)
            {
                if(lastresetr - i > maxlen)
                    maxlen = lastresetr - i;
            }
            if(curhigh < 0)
            {
                lastresetr = i;
                curhigh = 0;
            }
        }
        return maxlen;
    }
};