class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(); int n2 = nums2.size();
        int xor1 = 0; int xor2 = 0;
        for(int i = 0;i < n1;i++) {
            xor1 ^= nums1[i];
        }
        for(int i = 0;i < n2;i++) {
            xor2 ^= nums2[i];
        } 

        bool odd1 = (n1 & 1) == 1; bool odd2 = (n2 & 1) == 1;
        cout << odd1 << " " << odd2 << endl;
        if(odd1 && odd2) return xor1 ^ xor2;
        else if (odd1 && !odd2) return xor2;
        else if(!odd1 && odd2) return xor1;
        return 0;
    }
};
