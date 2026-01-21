class Solution {
public:
    int minimumLines(vector<vector<int>>& nums) {
        sort(nums.begin(),nums.end());
        int ans = 0; 
        int n = nums.size(); long double slope; bool flag = false;
        for(int i = 1;i < n;i++) {
            long double currSlope = (long double)(((long double)nums[i][1] - (long double)nums[i-1][1]) * 1.0) / (long double)(((long double)nums[i][0] - (long double)nums[i-1][0]) * 1.0);
            if(!flag) {
                ans++;
                slope = currSlope;
                flag = !flag;
                continue;
            }
            if(currSlope != slope) {
                ans++;
                slope = currSlope;
            }
        }
        return ans;
    }
};

/*class Solution {
public:
    int minimumLines(vector<vector<int>>& stockPrices) {


        sort(stockPrices.begin(),stockPrices.end(),[](vector<int> &a,vector<int>&b){
            return a[0]<b[0];
        });
        int n=stockPrices.size();
        if(n==1)return 0;
        int result=1;
        int x1=stockPrices[0][0],x2=stockPrices[1][0],y1=stockPrices[0][1],y2=stockPrices[1][1];
        
        for(int i=1;i<n;i++){
            long long check=long(stockPrices[i][1]-y1)*(x2-x1);
            long long check1=long(stockPrices[i][0]-x1)*(y2-y1);
            if(check!=check1){
                result++;
                x1=stockPrices[i-1][0];
                x2=stockPrices[i][0];
                y1=stockPrices[i-1][1];
                y2=stockPrices[i][1];
            }


        }
        return result;
    }
};*/
