/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

// @lc code=start
#include <map>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> arr;
        vector<int> res;
        for (int i = 0; i < nums.size(); i++) {
            if(arr.find(target - nums[i]) != arr.end()) {
                res.push_back(arr[target - nums[i]]);
                res.push_back(i);
                break;
            }
            arr[nums[i]] = i;
        }
        return res;
    }
};
// @lc code=end

