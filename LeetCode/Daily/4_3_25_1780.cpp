class Solution {
public:

    bool check(int n,int power,unordered_map<int,bool>&umap) {
        if(n == 0) return true;
        if(pow(3,power) > n) return false;
        if(umap.find(n) != umap.end()) {
            return umap[n];
        }

        bool ans1 = check(n,power+1,umap);
        bool ans2 = check(n - pow(3,power),power+1,umap);
        
        return umap[n] = ans1 || ans2;
    }

    bool checkPowersOfThree(int n) {
        unordered_map<int,bool>umap;
        return check(n,0,umap);
    }
};

// class Solution {
// public:
//     bool checkPowersOfThree(int n) {
//         while (n > 0) {
//             // Check if this power should be used twice
//             if (n % 3 == 2) return false;

//             // Divide n by 3 to move to the next greater power
//             n /= 3;
//         }

//         // The ternary representation of n consists only of 0s and 1s
//         return true;
//     }
// };
