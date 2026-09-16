class Solution {
public:
    void recurPermute(int index, vector<int>& nums, vector<vector<int>>& ans){
        int n = nums.size();
        if(n == index){
            ans.push_back(nums);
            return;
        }
        for(int i = index;i<n;i++){
            swap(nums[index],nums[i]);
            recurPermute(index+1, nums, ans);
            swap(nums[index], nums[i]);

        }


        
    }
    
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        int index;
        recurPermute(0,nums,ans);
        return ans;
    }
};