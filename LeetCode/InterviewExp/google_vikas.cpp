#include <bits/stdc++.h>
using namespace std;

class Iterator {

    private:
	vector<int>nums;
	vector<int>nextArray;
	int k;

    public:
	Iterator(vector<int>v) {
		nums = v;
		k = 0;
        int first = 1;
		
		for(int l = 0;l < nums.size();l+=2) {
			if(l + 1 >= nums.size()) continue;
			int freq = nums[l];
            if(freq == 0 && first == 1) {
                l = -2; first = 0; continue;
            }
			for(int j = 0;j < freq;j++) {
				nextArray.push_back(nums[l+1]);
			}
		}	
	}

	int next() { 
		if(k >= nextArray.size()) return -1;
		int ele = nextArray[k];
		k++;
		return ele;
	}
	
	bool hasNext() {
		return k < nextArray.size();
	}
};

int main() {
    vector<int>v = {1,4,2,3,0,1,3,5};
    Iterator it(v);
    cout << it.next() << endl; // 2
    cout << it.next() << endl; // 2
    cout << it.next() << endl; // 4
    cout << it.next() << endl; // 4
    cout << it.next() << endl; // 4
    cout << it.next() << endl; // 2
    cout << it.next() << endl; // 2
    cout << it.next() << endl; // 4
    cout << it.next() << endl; // 4
    cout << it.hasNext() << endl; // 0
    cout << it.next() << endl; // -1
    return 0;
}
