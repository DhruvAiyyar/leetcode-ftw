class Solution {
public:
    int CanWePlace(vector<int>& position , int m , int d){
        int count = 1;
        int lastposition = position[0];
        for(int i = 1;i<position.size();i++){
            if (position[i] - lastposition >= d) {
                count++;
                lastposition = position[i];
            }
            if(count>=m){
                return true;
            }

            

        }
        return false;



    }
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(),position.end());
        int n = position.size(),ans = 0;
        int low  = 1, high = (position[n-1]) - (position[0]);
        while(low<=high){
            int mid = low + (high-low)/2;
            if(CanWePlace(position,m,mid)== true){
                ans = mid;
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        return ans;
         
    }
};