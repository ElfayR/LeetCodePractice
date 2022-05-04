class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
		//使用Map找到對應的另一半以及idx
        vector<int> res;
        unordered_map <int, int> bucketmap;
        int tempData = 0;
        for(int i = 0; i <nums.size(); i++){
            tempData = target-nums[i];
            if (bucketmap.count(tempData)){
                res.insert(res.end(), bucketmap.find(tempData)->second);
                res.insert(res.end(),i);
                return res;
            }
            else{
                bucketmap[nums[i]] = i;
            }
        }
        return res;
    }
};