#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> p;
class KthLargest {
public:
    vector<int>nums;
    int size;
    priority_queue<int,vector<int>,greater<int>>pq;
    KthLargest(int K, vector<int>& NUMS) {
        size = K;
        nums = NUMS;

        for(int i = 0;i < nums.size();i++) {
            pq.push(nums[i]);
            if(pq.size() > size) pq.pop();
        }
    }
    
    int add(int val) {
        pq.push(val);
        if(pq.size() > size) pq.pop();
        return pq.top();
    }
};

int main() {
    vector<int>nums = {4,5,8,2};
    int k = 3;
    KthLargest* obj = new KthLargest(k, nums);
    cout << obj->add(3) << endl;
    cout << obj->add(5) << endl;
    cout << obj->add(10) << endl;
    cout << obj->add(9) << endl;
    cout << obj->add(4) << endl;
}