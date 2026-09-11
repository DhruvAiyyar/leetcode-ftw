class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n = heights.size();
        int low = 0, high= n-1;
        int maxArea = 0;
        while(low<high){
            int height = min(heights[high],heights[low]);
            int width = high-low;
            int area = height * width;

            maxArea = max(maxArea, area);
            

        if(heights[low]<heights[high]){
            low++;
        }
        else{
            high--;
        }

        }
        return maxArea;

    }
};
