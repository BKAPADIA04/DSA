class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0;i < n;i++) nums[i] %= 2;
        vector<int>even,odd;
        for(int i = 0;i < n;i++) {
            if(nums[i] == 0) even.push_back(i);
            else odd.push_back(i);
        }

        // for(auto it : even) cout << it << " ";
        // cout << endl;

        // for(auto it : odd) cout << it << " ";
        // cout << endl;

        int e = even.size(); int o = odd.size();

        if(abs(e - o) > 1) return -1;
        

        // even first
        int index = 1;
        int temp1 = 0;
        for(int i = 0;i < odd.size();i++) {
            temp1 += abs(odd[i] - index);
            index += 2;
            if(index >= n) {
                if(i < odd.size() - 1) temp1 = INT_MAX;
                break;
            }
        }

        // odd first
        index = 1;
        int temp2 = 0;
        for(int i = 0;i < even.size();i++) {
            temp2 += abs(even[i] - index);
            index += 2;
            if(index >= n) {
                if(i < even.size() - 1) temp2 = INT_MAX;
                break;
            }
        }

        // cout << temp1 << " " << temp2 << endl;
        return min(temp1,temp2);
    }
};
