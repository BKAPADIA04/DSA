#define ll long long
class Solution {
public:
    
    int counter;
    unordered_map<ll,int>umap;
    priority_queue<ll,vector<ll>,greater<ll>>minHeap;

    int nthUglyNumber(int n) {
        counter = 1;
        minHeap.push(1);
        umap[1] = 1;
        while(!minHeap.empty()) {
            ll num = minHeap.top();
            minHeap.pop();
            if(counter == n) return (int)num;
            counter++;
            if(umap.find(2 * num) == umap.end()) { minHeap.push(2 * num); umap[2 * num] = 1; }
            if(umap.find(3 * num) == umap.end()) { minHeap.push(3 * num); umap[3 * num] = 1; }
            if(umap.find(5 * num) == umap.end()) { minHeap.push(5 * num); umap[5 * num] = 1; }
        }
        return -1;
    }
};

/*
class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> uglyNumbers(n);  // DP array to store ugly numbers
        uglyNumbers[0] = 1;          // The first ugly number is 1

        // Three pointers for the multiples of 2, 3, and 5
        int indexMultipleOf2 = 0, indexMultipleOf3 = 0, indexMultipleOf5 = 0;
        int nextMultipleOf2 = 2, nextMultipleOf3 = 3, nextMultipleOf5 = 5;

        // Generate ugly numbers until we reach the nth one
        for (int i = 1; i < n; i++) {
            // Find the next ugly number as the minimum of the next multiples
            int nextUglyNumber =
                min(nextMultipleOf2, min(nextMultipleOf3, nextMultipleOf5));
            uglyNumbers[i] = nextUglyNumber;

            // Update the corresponding pointer and next multiple
            if (nextUglyNumber == nextMultipleOf2) {
                indexMultipleOf2++;
                nextMultipleOf2 = uglyNumbers[indexMultipleOf2] * 2;
            }
            if (nextUglyNumber == nextMultipleOf3) {
                indexMultipleOf3++;
                nextMultipleOf3 = uglyNumbers[indexMultipleOf3] * 3;
            }
            if (nextUglyNumber == nextMultipleOf5) {
                indexMultipleOf5++;
                nextMultipleOf5 = uglyNumbers[indexMultipleOf5] * 5;
            }
        }

        return uglyNumbers[n - 1];  // Return the nth ugly number
    }
};*/
