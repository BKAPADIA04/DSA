#include <bits/stdc++.h>
using namespace std;

int coinChange(vector<int>& coins, int amount) {
    sort(coins.begin(),coins.end(),greater<int>());
    int answer = 0;
    int i = 0;
    while(i < coins.size()) {
        while(amount >= coins[coins.size()-1]) {
            amount -= coins[i];
            answer += 1;
        }
        i++;
    }   
    return (amount == 0) ? answer : -1;
}

int main() {
    vector<int>coins = {186,419,83,408};
    int amount = 6249;
    cout << coinChange(coins,amount) << endl;
}