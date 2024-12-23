/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    void print(vector<int>nums) {
        for(auto it:nums) cout << it << " ";
        cout << endl;
    }
    void print_m(map<int,int>nums) {
        for(auto it:nums) { cout << it.first << " " << it.second; cout << endl;}
        cout << endl;
    }

    int minSwaps(vector<int>nums) {
        int n = nums.size();
        int answer = 0;
        map<int,int>m;
        vector<int>temp = nums;
        sort(temp.begin(),temp.end());
        for(int i = 0;i < n;i++) {
            m[nums[i]] = i;
        }

        for(int i = 0;i < n;i++) {
            if(nums[i] != temp[i]) {
                answer++;
                int swap_index = m[temp[i]];
                m[nums[i]] = swap_index;
                m[temp[i]] = i;
                swap(nums[i],nums[swap_index]);

            }
        }
        return answer;
    }

    int minimumOperations(TreeNode* root) {
        if(root == nullptr) return 0;
        queue<TreeNode *>q;
        q.push(root);
        int ans = 0;
        while(!q.empty()) {
            int n = q.size();
            vector<int>tempo;
            for(int i = 0;i < n;i++) {
                TreeNode * temp = q.front();
                q.pop();
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
                tempo.push_back(temp->val);
            }
            ans += minSwaps(tempo);
            tempo.clear();
        }
        return ans;
    }   
};