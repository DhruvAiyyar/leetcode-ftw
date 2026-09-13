class Solution {
public:
    bool rotateString(string s, string goal) {
        if (s.size() != goal.size()) {
            return false;
        }

        int n = s.size();

        for (int i = 0; i < n; i++) {
            char last = s.back();
            s.pop_back();
            s.insert(s.begin(), last);

            if (s == goal) {
                return true;
            }
        }

        return false;
    }
};