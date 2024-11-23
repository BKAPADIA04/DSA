/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string str = "";
        if(root == nullptr) return str;

        queue<TreeNode*>q;
        q.push(root);

        while(!q.empty()) {
            TreeNode * node = q.front();
            q.pop();
            // if(node->val == 1001) continue;
            // cout << "hi" << endl;
            
            str += to_string(node->val) + ",";

            if(node->left) {
                q.push(node->left);
            }
            else {
                if(node->val != 1001) {
                    TreeNode * dump = new TreeNode(1001);
                    q.push(dump);
                }
            }

            if(node->right) {
                q.push(node->right);
            }
            else {
                if(node->val != 1001) {
                    TreeNode * dump = new TreeNode(1001);
                    q.push(dump);
                }
            }
        }
        str = str.substr(0,str.size()-1);
        str += ".";
        cout << str << endl;
        return str;
    }

    TreeNode * build(vector<int>&level) {
        if(level.size() == 0) return nullptr;
        queue<TreeNode *>q;
        TreeNode * root = new TreeNode(level[0]);
        q.push(root);
        int i = 0;
        while(i < level.size() && !q.empty()) {
            TreeNode * node = q.front();
            q.pop();
            if(2*i + 1 < level.size()) {
                TreeNode * left = new TreeNode(level[2*i+1]);
                if(level[2*i+1] == 1001) node->left = nullptr;
                else {
                    node->left = left;
                    q.push(left);
                }
            }
            if(2*i + 2 < level.size()) {
                TreeNode * right = new TreeNode(level[2*i+2]);
                if(level[2*i+2] == 1001) node->right = nullptr;
                else {
                    node->right = right;
                    q.push(right);
                }
            }
            i++;
        }
        return root;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string str) {
        if(str.size() == 0) return nullptr;
        int i = 0; int n = str.size();
        vector<int>level;
        string temp = "";
        while(i < n) {
            if(str[i] == '.') break;
            while(i < n && str[i] != ',') temp += str[i++];
            if(temp[temp.size()-1] == '.') temp = temp.substr(0,temp.size()-1);
            int int_temp = stoi(temp);
            level.push_back(int_temp);
            temp = "";
            i++;
        }
        // cout << endl;
        for(auto it:level) cout << it << " ";
        cout << endl;  

        TreeNode * root = build(level);
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));