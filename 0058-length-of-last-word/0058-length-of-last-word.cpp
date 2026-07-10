class Solution {
public:
    int lengthOfLastWord(string s) {
        int count =0;
        int last = s.length()-1;
        while (last >= 0 && s[last] == ' ') {
            last--;
        }
        for(int i = last;i>=0;i--){
            if(s[i]== ' '){
                break;
            }
            count++;
            
        }
        return count;
    }
};