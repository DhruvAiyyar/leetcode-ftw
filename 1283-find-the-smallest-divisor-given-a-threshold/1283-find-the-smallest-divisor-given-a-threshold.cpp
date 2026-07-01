class Solution {
public:
    int divide_and_sum(vector<int>& nums,int m){
        int sum = 0; 
        for(int i = 0;i<nums.size();i++){
            int a  = (nums[i]+m-1)/m;
            sum += a;
        }
        return sum;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low = 1, high  = *max_element(nums.begin(),nums.end());
        int ans  = INT_MAX ;
        while(low<=high){
            int mid = low + (high - low)/2;
            if(divide_and_sum(nums,mid)>threshold){
                low = mid + 1;

            }
            else{
                ans = min(ans,mid);
                high = mid - 1;
            }
        }
        return ans;
    }
};