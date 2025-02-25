class Solution {
public:
    vector<bool>sieve(int n) {
        vector<bool>prime(n+1,true);
        prime[0] = prime[1] = false;
        for(int p = 2; p*p <= n;p++) {
            if(prime[p]) {
                for(int i = p*p;i <= n;i+=p) {
                    prime[i] = false;
                }
            }
        }
        return prime;
    }

    int minOperations(int n, int m) {
        vector<bool>prime = sieve(10000);

        if(n == 1 && m == 1) return 1;
        if(prime[n] || prime[m]) return -1;

        int answer = INT_MAX;
        vector<int>distance(1e5,1e9);
        distance[n] = 1;

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({n,n});

        while(!pq.empty()) {
            int node = pq.top().second;
            int dist = pq.top().first;
            pq.pop();

            if(node == m) return dist;

            string temp = to_string(node);
            for(int i = 0;i < temp.size();i++) {
                int digit = temp[i] - '0';

                if(digit == 0) {
                    string newnum = temp.substr(0,i) + to_string(digit+1) + temp.substr(i+1);
                    int newnumber = stoi(newnum);
                    if(!prime[newnumber] && dist + newnumber < distance[newnumber]) {
                        distance[newnumber] = dist + newnumber;
                        pq.push({distance[newnumber],newnumber});
                    }
                }
                else if(digit == 9) {
                    string newnum = temp.substr(0,i) + to_string(digit-1) + temp.substr(i+1);
                    int newnumber = stoi(newnum);
                    if(!prime[newnumber] && dist + newnumber < distance[newnumber]) {
                        distance[newnumber] = dist + newnumber;
                        pq.push({distance[newnumber],newnumber});
                    }
                }
                else {
                    string newnum = temp.substr(0,i) + to_string(digit+1) + temp.substr(i+1);
                    int newnumber = stoi(newnum);
                    if(!prime[newnumber] && dist + newnumber < distance[newnumber]) {
                        distance[newnumber] = dist + newnumber;
                        pq.push({distance[newnumber],newnumber});
                    }
                    newnum = temp.substr(0,i) + to_string(digit-1) + temp.substr(i+1);
                    newnumber = stoi(newnum);
                    if(!prime[newnumber] && dist + newnumber < distance[newnumber]) {
                        distance[newnumber] = dist + newnumber;
                        pq.push({distance[newnumber],newnumber});
                    }
                }
            }
        }

        return -1;
    }
};
