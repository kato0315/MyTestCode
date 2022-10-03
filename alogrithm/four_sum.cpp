#include <iostream>
#include <vector>
#include <unordered_map>

using std::vector;

class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        std::unordered_map<int, int> umap;
        for (int a : nums1) {
            for (int b : nums2) {
                umap[a + b]++;
            }
        }
        int count = 0;

        for (int c : nums3) {
            for (int d : nums4) {
                if (umap.find(0 - (c + d)) != umap.end()) {
                    count += umap[0 - (c +d)];
                }
            }
        }

        return count;
    }
};

int main()
{
    vector<int> nums1{1, 2};
    vector<int> nums2{-2, -1};
    vector<int> nums3{-1, 2};
    vector<int> nums4{0 ,2};
    Solution solution;
    std::cout << solution.fourSumCount(nums1, nums2,nums3, nums4) << std::endl;
    return 0;
}
