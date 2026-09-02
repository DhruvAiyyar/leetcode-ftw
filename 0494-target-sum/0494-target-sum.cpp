class Solution {
public:
    int solve(vector<int>& nums, int i, int sum, int target) {
        
        // Base case
        if (i == nums.size()) {
            if (sum == target) {
                return 1;
            }
            return 0;
        }

        // Choose +
        int plus = solve(nums, i + 1, sum + nums[i], target);

        // Choose -
        int minus = solve(nums, i + 1, sum - nums[i], target);

        return plus + minus;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        return solve(nums, 0, 0, target);
    }
};