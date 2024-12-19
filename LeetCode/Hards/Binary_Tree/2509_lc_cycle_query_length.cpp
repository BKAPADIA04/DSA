class Solution {
public:

    int dist(int a,int b,int lca) {
        int d1 = log(a)/log(2);
        int d2 = log(b)/log(2);
        int dl = log(lca)/log(2);
        return 1 + d1 + d2 - 2 * dl;
    }
    
    vector<int> cycleLengthQueries(int n, vector<vector<int>>& queries) {
        vector<int>answer;
        for(int i = 0;i < queries.size();i++) {
            int node1 = queries[i][0];
            int node2 = queries[i][1];

            // int temp1 = node1; int temp2 = node2; int lca = 1;
            // while(temp1 != temp2) {
            //     if(temp1 == 1 || temp2 == 1) {
            //         lca = 1; break;
            //     }
            //     if(temp1 > temp2)
            //         temp1 = temp1/2;
            //     else if(temp1 < temp2)
            //         temp2 = temp2/2;
            // }
            // if(temp1 != 1 && temp2 != 1 && temp1 == temp2) lca = temp1;
            // cout << lca << endl;
            // int ans = dist(node1,node2,lca);


            // better
            int ans = 1;
            while(node1 != node2) {
                if(node1 > node2) node1 /= 2;
                else node2 /= 2;
                ans += 1;
            }

            answer.push_back(ans);
        }
        return answer;
    }
};