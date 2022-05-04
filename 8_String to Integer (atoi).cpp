#include <stack>
#include <limits>

using namespace std;

class Solution {
public:
    const int intMax = INT_MAX;
    const int intMin = INT_MIN;
    
    bool isNum(char input){
        if ((input >= 48) && (input <= 57)){
            return true;
        }
        else{
            return false;
        }
    }
    
    long pow(int x){
        long res = 1;
        if (x > 11){
            x = 11;
        }
            
        while(x > 0){
            res *= 10;
            x--;
        }
        return res;
    }    
    
    int myAtoi(string s) {
        stack<char>number;
        int result = 0;
        bool startCountNum = false;
        bool isNagative = false;
        int badCount = 0;
        
        for(auto it = s.begin(); it!= s.end(); it++){
            if (!startCountNum){
                if (isNum(*it)){
                    startCountNum = true;
                    number.push(*it);
                }
                else{
                    if (badCount > 0)
                        break;
                    if (*it == '-'){
                        isNagative = true;
                        badCount++;
                    }
                    else if (*it == ' '){
                        continue;
                    }
                    else if (*it == '+'){
                        badCount++;
                        continue;
                    }
                    else{
                        break;
                    }
                }
            }
            else{
               if (isNum(*it)){
                    number.push(*it);
                }
                else{
                    break;
                }           
            }
        }
        
        if (startCountNum){
            long tempRes = 0;
            int count = 0;
            while(!number.empty()){
                int value = (int)number.top() - 48;
                tempRes += value * pow(count);
                count++;
                number.pop();
            }
            
            if (isNagative){
                tempRes = tempRes * -1;
                if (tempRes < intMin)
                    tempRes = intMin;
            }
            else{
                if (tempRes >intMax)
                    tempRes = intMax;
            }
            result = (int)tempRes;
        }
        return result;
    }
};