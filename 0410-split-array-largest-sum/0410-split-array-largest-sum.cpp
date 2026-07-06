class Solution {
public:
    int Count_partitions(vector<int>& nums, int maxSum){
        int partitions = 1;
        long subarraysum = 0;
        for(int i : nums){
            if(subarraysum+i<=maxSum){
                subarraysum+=i;
            }
            else{
                partitions++;
                subarraysum = i;
            }
        }
        return partitions;

    }
        int splitArray(vector<int>& nums, int k) {
            int low = *max_element(nums.begin(),nums.end());
            int high = accumulate(nums.begin(),nums.end(),0);
            while(low<=high){
                int mid = low + (high - low)/2;
                if(Count_partitions(nums , mid)>k){
                    low = mid +1;
                }
                else{
                    high = mid -1;
                }
            }
            return low;


        }
};