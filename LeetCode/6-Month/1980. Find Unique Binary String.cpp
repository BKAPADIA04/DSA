class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums[0].size();
        unordered_set<int>s;
        for(int i = 0;i < nums.size();i++) {
            s.insert(stoi(nums[i],0,2));
        }

        int rand_index = rand() % (nums.size());
        int ans = stoi(nums[rand_index],0,2);
        

        while(s.find(ans) != s.end()) {
            ans = rand() % (int)pow(2,n);
        }
        return bitset<16>(ans).to_string().substr(16 - n);
    }
};

/*class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        string ans;
        for (int i = 0; i < nums.size(); i++) {
            char curr = nums[i][i];
            ans += curr == '0' ? '1' : '0';
        }
        
        return ans;
    }
};*/
