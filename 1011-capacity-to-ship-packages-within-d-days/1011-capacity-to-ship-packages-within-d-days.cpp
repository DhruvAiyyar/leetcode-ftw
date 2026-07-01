class Solution {
public:
    // Helper: given a capacity, how many days do we need?
    int daysNeeded(vector<int>& weights, int capacity){
        int days         = 1;
        int current_load = 0;

        for(int i = 0; i < weights.size(); i++){
            if(current_load + weights[i] <= capacity){
                current_load += weights[i];
            }
            else{
                days++;
                current_load = weights[i];
            }
        }
        return days;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int low  = *max_element(weights.begin(), weights.end());
        int high = accumulate(weights.begin(), weights.end(), 0);
        int ans  = high;

        while(low <= high){
            int mid = low + (high - low) / 2;

            if(daysNeeded(weights, mid) > days){
                low = mid + 1;
            }
            else{
                ans  = mid;
                high = mid - 1;
            }
        }
        return ans;
    }
};