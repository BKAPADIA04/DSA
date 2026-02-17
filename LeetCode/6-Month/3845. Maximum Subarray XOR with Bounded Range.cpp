struct Node{
    Node* child[2] = {};
    int count = 0;
};

struct Trie{
    Node* root;
    int bitSize;

    Trie() : root(new Node()), bitSize(15){}

    void insert(int num){
        Node* head = root;
        for(int i=bitSize-1; i>=0; --i){
            int bit = (num >> i) & 1;
            if(!head->child[bit])
                head->child[bit] = new Node();
            head = head->child[bit];
            ++head->count;
        }
    }

    void remove(int num){
        Node* head = root;
        for(int i=bitSize-1; i>=0; --i){
            int bit = (num >> i) & 1;
            head = head->child[bit];
            --head->count;
        }
    }

    int getMaxXor(int num){
        Node* head = root;
        int maxXor = 0;

        for(int i=bitSize-1; i>=0; --i){
            int bit = (num >> i) & 1;
            int oppBit = 1-bit;
            
            if(head->child[oppBit] && head->child[oppBit]->count){
                maxXor |= (1 << i);
                head = head->child[oppBit];
            }
            else
                head = head->child[bit];
        }

        return maxXor;
    }
};

class Solution {
public:
    int maxXor(vector<int>& nums, int k) {
        int n = nums.size(), maxVal = 0;
        vector<int> prefXor(n);

        prefXor[0] = nums[0];
        for(int i=1; i<n; ++i)
            prefXor[i] = prefXor[i-1] ^ nums[i];

        multiset<int> mst;

        Trie trie;
        trie.insert(0);

        for(int i=0, j=0; j<n; ++j){
            mst.insert(nums[j]);

            while(mst.size()){
                int cost = *mst.rbegin() - *mst.begin();
                if(cost <= k) break;

                int prevXor = (i<1 ? 0 : prefXor[i-1]);
                trie.remove(prevXor);

                mst.erase(mst.find(nums[i++]));
            }

            // for(int x=i; x<=j; ++x){
            //     int prevXor = (x<1 ? 0 : prefXor[x-1]);
            //     maxVal = max(maxVal, prefXor[j] ^ prevXor);
            // }

            maxVal = max(maxVal, trie.getMaxXor(prefXor[j]));
            trie.insert(prefXor[j]);
        }

        return maxVal;
    }
};


struct Node{
    Node* child[2] = {};
    int count = 0;
};

struct Trie{
    Node* root;
    int bitSize;

    Trie() : root(new Node()), bitSize(15){}

    void insert(int num){
        Node* head = root;
        for(int i=bitSize-1; i>=0; --i){
            int bit = (num >> i) & 1;
            if(!head->child[bit])
                head->child[bit] = new Node();
            head = head->child[bit];
            ++head->count;
        }
    }

    void remove(int num){
        Node* head = root;
        for(int i=bitSize-1; i>=0; --i){
            int bit = (num >> i) & 1;
            head = head->child[bit];
            --head->count;
        }
    }

    int getMaxXor(int num){
        Node* head = root;
        int maxXor = 0;

        for(int i=bitSize-1; i>=0; --i){
            int bit = (num >> i) & 1;
            int oppBit = 1-bit;
            
            if(head->child[oppBit] && head->child[oppBit]->count){
                maxXor |= (1 << i);
                head = head->child[oppBit];
            }
            else
                head = head->child[bit];
        }

        return maxXor;
    }
};

class Solution {
public:
    int maxXor(vector<int>& nums, int k) {
        int n = nums.size(), maxVal = 0;
        vector<int> prefXor(n);

        prefXor[0] = nums[0];
        for(int i=1; i<n; ++i)
            prefXor[i] = prefXor[i-1] ^ nums[i];

        deque<int> mx, mn;

        Trie trie;
        trie.insert(0);

        for(int i=0, j=0; j<n; ++j){
            while(mx.size() && nums[mx.back()] <= nums[j]) mx.pop_back();
            while(mn.size() && nums[mn.back()] >= nums[j]) mn.pop_back();

            mx.push_back(j);
            mn.push_back(j);
            
            while(mx.size() && mn.size()){
                int cost = nums[mx.front()] - nums[mn.front()];
                if(cost <= k) break;
                
                int prevXor = (i<1 ? 0 : prefXor[i-1]);
                trie.remove(prevXor);

                if(mx.front() <= i) mx.pop_front();
                if(mn.front() <= i) mn.pop_front();

                ++i;
            }

            // for(int x=i; x<=j; ++x){
            //     int prevXor = (x<1 ? 0 : prefXor[x-1]);
            //     maxVal = max(maxVal, prefXor[j] ^ prevXor);
            // }

            maxVal = max(maxVal, trie.getMaxXor(prefXor[j]));
            trie.insert(prefXor[j]);
        }

        return maxVal;
    }
};
