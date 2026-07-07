class Solution {
public:
    bool isPalindrome(string s) {
        string a = "";
        
        for(char ch : s){
            if(isalnum(ch)){
                a+=tolower(ch);
            }
        }
        int left = 0,right = a.size()-1,temp;
        while(left<right){
            if(a[left]!=a[right]) return false;
            left++;
            right--;
        }
        


        
        return true;
    }
};