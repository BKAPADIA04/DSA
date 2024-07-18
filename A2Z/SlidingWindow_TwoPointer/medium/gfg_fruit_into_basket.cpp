#include <bits/stdc++.h>
using namespace std;

int totalFruits(int n, vector<int> &nums) {
    map<int,int>freq_map;
    int maxlen = 0;
    int left = 0, right = 0;

    while(right < n) {
        freq_map[nums[right]]++;
        if(freq_map.size() > 2) {
            freq_map[nums[left]]--;
            if(freq_map[nums[left]] == 0) {
                freq_map.erase(nums[left]);
            }
            left++;
        }

        if(freq_map.size() <= 2) {
            maxlen = max(maxlen,right - left + 1);
        }
        right++;
    }    
    return maxlen;
}

int main() {
    vector<int>fruits = {0,1,0,2,2,2,3,4,4,4,5};
    cout << totalFruits(fruits.size(),fruits) << endl;
}