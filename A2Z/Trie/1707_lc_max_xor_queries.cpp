struct Node {
    Node * links[2];

    bool contains(int bit) {
        return links[bit] != nullptr;
    }

    void insert(Node * node,int bit) {
        links[bit] = node;
    }
    
    Node * next(int bit) {
        return links[bit];
    }
};

class Solution {
public:

    Node * root = new Node();

    void print(vector<vector<int>>v) {
        for(auto it:v) {
            for(auto it1:it) cout << it1 << " ";
            cout << endl;
        }
    }
    bool static compare(vector<int>p1,vector<int>p2) {
        return p1[1] < p2[1];
    }

    void insertIntoTrie(int ele) {
        Node * node = root;
        for(int j = 31; j >= 0;j--) {
            int bit = ((1 << j) & ele) == 0 ? 0 : 1;
            if(!node->contains(bit)) {
                node->insert(new Node(),bit);
            }
            node = node->next(bit);
        }
    }

    int maxXor(Node * root,int num) {
        Node * node = root;
        if(node == nullptr) return -1;
        int maxi = 0;
        for(int i = 31;i >= 0;i--) {
            int num_bit = ((1 << i) & num) == 0 ? 0 : 1;
            if(node && node->contains(1 - num_bit)) {
                maxi |= (1 << i);
                node = node->next(1 - num_bit);
            }
            else {
                if(node)
                    node = node->next(num_bit);
            }
        }
        return maxi;
    }

    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        sort(nums.begin(),nums.end());
        for(int i = 0;i < queries.size();i++) queries[i].push_back(i);
        sort(queries.begin(),queries.end(),compare);
        vector<int>answer(queries.size(),-1); int j = 0;
        for(int i = 0;i < queries.size();i++) {
            int check = queries[i][1];
            while(j < nums.size() && nums[j] <= check) {
                insertIntoTrie(nums[j]);
                j++;
            }
            if(j == 0) answer[queries[i][2]] = -1;
            else {
                int ans = maxXor(root,queries[i][0]);
                answer[queries[i][2]] = ans;
            }
        }
        return answer;
    }
};