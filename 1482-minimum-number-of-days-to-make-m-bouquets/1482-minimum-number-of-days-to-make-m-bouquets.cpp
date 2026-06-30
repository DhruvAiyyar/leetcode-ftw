class Solution {
public:
    // Plain-English contract: 
    // "If 'days' days have passed, can we make at least m bouquets, 
    //  where each bouquet needs k ADJACENT bloomed flowers?"
    bool canMakeBouquets(vector<int>& bloomDay, int days, int m, int k){
        int bouquets = 0;
        int adjacentBloomed = 0;  // count of consecutive bloomed flowers

        for(int i = 0; i < bloomDay.size(); i++){
            if(bloomDay[i] <= days){
                adjacentBloomed++;          // this flower has bloomed
                if(adjacentBloomed == k){   // enough adjacent flowers for one bouquet
                    bouquets++;
                    adjacentBloomed = 0;    // reset and start counting next group
                }
            } else {
                adjacentBloomed = 0;        // streak broken, flower hasn't bloomed
            }
        }
        return bouquets >= m;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        // Step 1: impossibility check
        if ((long long)m * k > bloomDay.size()) return -1;

        int low = *min_element(bloomDay.begin(), bloomDay.end());
        int high = *max_element(bloomDay.begin(), bloomDay.end());
        int ans = -1;

        // Step 2: binary search on the answer (days)
        while(low <= high){
            int mid = low + (high - low) / 2;  // avoids overflow, same as (low+high)/2

            if(canMakeBouquets(bloomDay, mid, m, k)){
                ans = mid;        // mid works, but try to find a smaller valid day
                high = mid - 1;
            } else {
                low = mid + 1;    // mid too small, need more days
            }
        }
        return ans;
    }
};