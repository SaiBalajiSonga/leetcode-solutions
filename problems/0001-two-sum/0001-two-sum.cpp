#include <unordered_map>
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> Map; 
        for(int i=0;i<nums.size();i++){
            int complement = target - nums[i];
            if (Map.find(complement) != Map.end()) {
                return {Map[complement], i};
            }
            Map[nums[i]] = i;
        } 
        return{};
    }
};