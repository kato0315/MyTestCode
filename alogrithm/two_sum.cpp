#include <iostream>
#include <vector>
#include <unordered_map>

using std::vector;

//需要查询一个元素是否出现过，或者一个元素是否在集合里的时候
//我们不仅要知道元素有没有遍历过，还有知道这个元素对应的下标，需要使用 key value结构来存放，key来存元素，value来存下标，那么使用map正合适
//这道题目中并不需要key有序，选择std::unordered_map 效率更高
//key：数据元素，value：数组元素对应的下表

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> map;

        for (int i = 0; i < nums.size(); i++) {     //O(n)
            auto iter = map.find(target - nums[i]); //O(1)
            if (iter != map.end()) {
                return {iter->second, i};
            }
            map.insert(std::pair<int, int>(nums[i], i));
        }

        return {};
    }
};

int main()
{
    int target = 10;
    vector<int> nums{1,2,3,4,5,6};
    Solution solution;

    vector<int> result = solution.twoSum(nums, target);
    
    for (auto iter = result.begin(); iter != result.end(); iter++) {
        std::cout << (*iter) << std::endl;
    }
    
    return 0;
}