class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int res = 0;
        int startPtr = 0, endPtr = 0;
        int checkArray[256] = {0};
        
        while(endPtr < s.size()){           
            char rightValue = s[endPtr];
            checkArray[rightValue]++;
            
            while(checkArray[rightValue] > 1){
                char value = s[startPtr];
                checkArray[value]--;
                startPtr++;            
            }
            res = max(res, (endPtr-startPtr+1));
            endPtr++;
        }

        
        return res;
    }
};