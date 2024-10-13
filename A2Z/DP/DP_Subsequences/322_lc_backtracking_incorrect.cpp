#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int check(vector<int>& coins, int amount, vector<int>& answer, int no_coins, bool &change) {
    if (amount < 0) return -1;
    if (amount == 0) {
        change = true;
        return answer.size();
    }
    
    for (int i = 0; i < coins.size(); i++) {
        if (amount >= coins[i]) {
            answer.push_back(coins[i]);
            int num = check(coins, amount - coins[i], answer, no_coins, change);
            
            if(change) {
                return num;
            }
            answer.pop_back(); // Backtracking
        }
    }
    return 0;
}

int main() {
    vector<int> coins = {1, 2, 5}; // Example coin set
    int amount = 0;
    vector<int> answer;
    int no_coins = amount + 1;
    bool change = false;
    sort(coins.begin(),coins.end(),greater<int>());
    int result = check(coins, amount, answer, no_coins, change);
    if (change) cout << "Minimum coins required: " << result << endl;
    else cout << "No solution exists." << endl;
    return 0;
}
