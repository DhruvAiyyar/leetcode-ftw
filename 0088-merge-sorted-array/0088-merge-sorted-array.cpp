class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

        vector<int> v1;

        int i = 0;
        int j = 0;

        while(i < m && j < n) {

            if(nums1[i] == nums2[j]) {
                v1.push_back(nums1[i]);
                v1.push_back(nums2[j]);
                i++;
                j++;
            }
            else if(nums1[i] > nums2[j]) {
                v1.push_back(nums2[j]);
                j++;
            }
            else {
                v1.push_back(nums1[i]);
                i++;
            }
        }

        while(i < m) {
            v1.push_back(nums1[i]);
            i++;
        }

        while(j < n) {
            v1.push_back(nums2[j]);
            j++;
        }

        for(int k = 0; k < m + n; k++) {
            nums1[k] = v1[k];
        }
    }
};