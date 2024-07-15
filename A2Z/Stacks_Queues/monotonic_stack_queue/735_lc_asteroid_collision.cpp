#include <bits/stdc++.h>
using namespace std;

vector<int> asteroidCollision(vector<int>& asteroids) {
    vector<int>answer;
    stack<int>st;
    int i = 0;
    while(i < asteroids.size() && asteroids[i] < 0) {
        answer.push_back(asteroids[i++]);
    }  
    for(;i < asteroids.size();i++) {
        if(st.empty()) st.push(asteroids[i]);
        else {
            if(asteroids[i] > 0) st.push(asteroids[i]);
            else {
                while(!st.empty() && st.top() > 0 && (abs(asteroids[i]) > st.top())) {
                    st.pop();
                }
                if(!st.empty() && st.top() == abs(asteroids[i])) st.pop();
                else if(st.empty() || st.top() < 0) st.push(asteroids[i]);
            }
        }
    }
    stack<int>temp = st;
    vector<int>tempo;
    while(!temp.empty()) {
        tempo.push_back(temp.top());
        temp.pop();
    }
    reverse(tempo.begin(),tempo.end());
    if(answer.size() == 0) return tempo;
    for(int j = 0 ; j < tempo.size();j++) {
        answer.push_back(tempo[j]);
    } 
    return answer;
}

int main() {
    vector<int>asteroids = {10,2,-5,-11};
    vector<int>ans = asteroidCollision(asteroids);
    for(int i:ans) cout << i << endl; 
}