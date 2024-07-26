#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> p;

int leastInterval(vector<char>& tasks, int n) {
    vector<int>freq(26,0);
    priority_queue<p>pq; // store freq 
    queue<p> q; // store cooldown time

    for(int i = 0;i < tasks.size();i++) {
        freq[tasks[i] - 'A']++;
    }

    for(int i = 0;i < 26;i++) {
        if(freq[i] >= 1) pq.push({freq[i],0});
    }
    int time = 0;

    while(!pq.empty() || !q.empty()) {
        if(!q.empty() && time - q.front().second > n) {
            pq.push(q.front());
            q.pop();
        }
        if(!pq.empty()) {
            pair<int,int>maxi = pq.top();
            pq.pop();
            maxi.first -= 1;
            maxi.second = time;

            if(maxi.first > 0) q.push(maxi);
        }
        time++;
    }
    return time;
}

int main() {
    vector<char>tasks = {'A','A','A','B','B','B'};
    cout << leastInterval(tasks,3) << endl;
}