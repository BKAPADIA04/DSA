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

    void print(vector<int>nums) 
    {
        for(auto it:nums) cout << it << " ";
    }
    vector<int> getBinary(int num) {
        vector<int>bin(32,0);
        int temp = num; int i = 31;
        while(temp > 0) {
            int put = temp % 2;
            bin[i] = put;
            i--;
            temp /= 2;
        }
        return bin;
    }

    int maxXor(Node * root,int num) {
        Node * node = root;
        int maxi = 0;
        for(int i = 31;i >= 0;i--) {
            int num_bit = ((1 << i) & num) == 0 ? 0 : 1;
            if(node->contains(1 - num_bit)) {
                maxi |= (1 << i);
                node = node->next(1 - num_bit);
            }
            else {
                node = node->next(num_bit);
            }
        }
        return maxi;
    }


    int findMaximumXOR(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0;i < n;i++) {
            vector<int>bin = getBinary(nums[i]);
            Node * node = root;
            for(int j = 0;j < 32;j++) {
                if(!(node->contains(bin[j]))) {
                    node->insert(new Node(),bin[j]);
                }
                node = node->next(bin[j]);
            }
        }

        // insertion completed
        int answer = 0;
        for(int i = 0;i < n;i++) {
            answer = max(answer,maxXor(root,nums[i]));
            // cout << answer << endl;
        }
        return answer;
    }
};


/*                            
#include <iostream>
#include <vector>

using namespace std;

// Node structure 
// for the Trie
struct Node {
    // Array to store links
    // to child nodes (0 and 1)
    Node* links[2]; 
    
    // Method to check if a specific
    // bit key is present in the child nodes
    bool containsKey(int bit) {
        
        // Returns true if the link at
        // index 'bit' is not NULL
        return (links[bit] != NULL); 
    }
    
    // Method to get the child node
    // corresponding to a specific bit
    Node* get(int bit) {
        
        // Returns the child
        // node at index 'bit'
        return links[bit]; 
    }
    
    // Method to set a child node at a
    // specific index in the links array
    void put(int bit, Node* node) {
        
        // Sets the child node at index
        // 'bit' to the provided node
        links[bit] = node; 
    }
};

// Trie class
class Trie {
private:
    // Root node of the Trie
    Node* root;
public:
    // Constructor to initialize
    // the Trie with a root node
    Trie() {
         // Creates a new root
         // node for the Trie
        root = new Node();
    }
    
    // Method to insert a number into the Trie
    void insert(int num) {
        // Start from the root node
        Node* node = root; 
        // Iterate through each bit of the
        // number (from left to right)
        for (int i = 31; i >= 0; i--) { 
            // Extract the i-th bit of the number
            int bit = (num >> i) & 1; 
            
            // If the current node doesn't have a
            // child node with the current bit
            if (!node->containsKey(bit)) { 
                
                // Create a new child node
                // with the current bit
                node->put(bit, new Node()); 
            }
            
            // Move to the child node
            // corresponding to the current bit
            node = node->get(bit); 
        }
    }
    
    // Method to find the maximum
    // XOR value for a given number
    int getMax(int num) {
         // Start from the root node
        Node* node = root;
        
        // Initialize the maximum XOR value
        int maxNum = 0; 
        
        // Iterate through each bit of
        // the number (from left to right)
        for (int i = 31; i >= 0; i--) { 
            
            // Extract the i-th
            // bit of the number
            int bit = (num >> i) & 1; 
            
            // If the complement of the current
            // bit exists in the Trie
            if (node->containsKey(1 - bit)) { 
                
                // Update the maximum XOR
                // value with the current bit
                maxNum |= (1 << i); 
                
                 // Move to the child node corresponding
                 // to the complement of the current bit
                node = node->get(1 - bit);
            } else {
                
                 // Move to the child node
                 // corresponding to the current bit
                node = node->get(bit);
            }
        }
        
        // Return the maximum XOR value
        return maxNum; 
    }
};

// Function to find the maximum XOR
// value between two sets of numbers
int maxXOR(int n, int m, vector<int>& arr1, vector<int>& arr2) {
    // Create a Trie object
    Trie trie; 
    // Insert each number from
    // the first set into the Trie
    for (auto& it : arr1) { 
        trie.insert(it);
    }
    
    // Initialize the maximum XOR value
    int maxi = 0; 
    
    // Iterate through each
    // number in the second set
    for (auto& it : arr2) { 
         // Update the maximum XOR value
         // with the result from the Trie
        maxi = max(maxi, trie.getMax(it));
    }
     // Return the
     // maximum XOR value
    return maxi;
}

// Function to print the 
// Input Arrays
void printArr(vector<int> arr){
    for(auto it: arr){
        cout << it << " ";
    }
    cout << endl;
}

int main() {
    vector<int> arr1 = {3, 10, 5, 25, 2};
    vector<int> arr2 = {8, 1, 2, 12, 7};
    int n = arr1.size();
    int m = arr2.size();
    
    cout << "Arr1: ";
    printArr(arr1);
    cout << "Arr2: ";
    printArr(arr2);
    

    int result = maxXOR(n, m, arr1, arr2);
    cout << "Maximum XOR value: " << result << endl;

    return 0;
}*/