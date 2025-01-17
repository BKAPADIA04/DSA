class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int xorr = 0;
        for(int i = 0;i < derived.size();i++) {
            xorr ^= derived[i];
        }
        return xorr == 0;
    }
};
