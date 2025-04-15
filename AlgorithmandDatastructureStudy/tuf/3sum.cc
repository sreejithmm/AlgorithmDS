#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <cmath>
#include <string>

/*
Given an integer array nums. Return all triplets such that:

i != j, i != k, and j != k
nums[i] + nums[j] + nums[k] == 0.


Notice that the solution set must not contain duplicate triplets. One element can be a part of multiple triplets. The output and the triplets can be returned in any order.


*/
using namespace std;
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        auto size = nums.size();
        for(auto i=0; i < size ; i++)
        {
          auto sum = nums[i];
          auto left = i+1;
          auto right = size-1;  
          if(i> 0 && (left > right || nums[i] == nums[i - 1])) { continue;}
          while (left < right) 
          {

            sum = nums[i]+ nums[left]+nums[right];
            if(sum == 0)
            {
                result.push_back({nums[i],nums[left],nums[right]});
                while (left < right && nums[left] == nums[left + 1]) left++; // skip duplicates
                while (left < right && nums[right] == nums[right - 1]) right--;                
                left++;
                right--;
            }
            else if (sum < 0)
            {
                left++;
            }
            else
            {
                right--;
            }
            
          }
        }
        return result;
    }
};
int main() {
    Solution solution;
    vector<int> nums = {-2,-2,2,0,5,5};
    vector<vector<int>> result = solution.threeSum(nums);
    for (const auto& triplet : result) {
        cout << "[";
        for (const auto& num : triplet) {
            cout << num << " ";
        }
        cout << "]" << endl;
    }
    return 0;
}