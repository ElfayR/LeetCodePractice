class Solution {
public:
    int maxArea(vector<int>& height) {
		//短邊持續尋找更高的邊直到前後指標交會
        int res = 0; 
        int left = 0;
        int right = height.size() - 1;
        int min = 0;
        bool minIsLeft = true;
        int len = right - left;
        if (height.size() >= 2){
            while (left != right){
                if (height[left] >= height[right]){
                    minIsLeft = false;
                    min = height[right];
                }
                else{
                    minIsLeft = true;
                    min = height[left];
                }
                //calculate
                int temp = len * min;
                if (temp > res)
                    res = temp;
                if (minIsLeft)
                    left++;
                else
                    right--;
                len--;
            }                      
        }
        else{
            return 0;
        }
        return res;
    }
};