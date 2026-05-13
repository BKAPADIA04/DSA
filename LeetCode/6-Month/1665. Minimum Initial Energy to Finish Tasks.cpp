class Solution {
public:
    int minimumEffort(vector<vector<int>>& tasks) {
        sort(tasks.begin(),tasks.end(),[](vector<int>&a,vector<int>&b){
            return a[1]-a[0]<b[1]-b[0];
        });
        int high = 0, low = 0;
        int size = tasks.size();
        for(int i = size-1 ; i>=0;i--){
            low+= tasks[i][0];
            high+= tasks[i][1];
        }
        
        int ans = INT_MAX ;

        while(low<=high){
            bool can = true;
            int mid = low + (high-low)/2 ;
            int energy = mid;
            // cout<<energy<<endl;
            for(int i = size-1 ; i>=0 ;i--){
                if(energy < tasks[i][1]){
                    can = false;
                    break;
                }
                else{
                    energy-=tasks[i][0];
                }
            }
            if(can){
                ans = min(ans,mid);
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
    return ans;
    }
};
