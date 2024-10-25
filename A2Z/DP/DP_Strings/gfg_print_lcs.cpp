// #include <bits/stdc++.h>
// using namespace std;
// vector<string> all_longest_common_subsequences(string str1, string str2) {
//     // Code here
//     vector<string>answer;
//     int n = str1.size(); int m = str2.size();
//     vector<vector<int> >dp(n+1,vector<int>(m+1,0));
//     // vector<int>prev(m+1),curr(m+1);
//     for(int i = 1;i <= n;i++) {
//         for(int j = 1;j <= m;j++) {
//             if(str1[i-1] == str2[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
//             else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
//         }
//     }

//     int i = n; int j = m;
//     int index = dp[n][m] - 1;
//     string str = "";
//     for (int k = 1; k <= dp[n][m]; k++) {
//         str += "$"; // dummy string
//     }
//     while(i > 0 && j > 0) {
//         if(str1[i-1] == str2[j-1]) {
//             str[index] = str1[i - 1];
//             index--;
//             i = i - 1; j = j - 1;
//         }
//         else if(dp[i-1][j] > dp[i][j-1]) {
//             i = i - 1;
//         }
//         else {
//             j = j - 1;
//         }
//         answer.push_back(str);
//     }
//     return answer;
// }

// int main() {
//     vector<string>answer = all_longest_common_subsequences("abaaac","baabac");
//     cout << answer[0] << endl;
// }

#include <bits/stdc++.h>
using namespace std;

void findAllLCS(int i, int j, string &str1, string &str2, vector<string> &lcs, string &current, vector<vector<int> > &dp, vector<vector<int> > &dp_temp) {
    if (i == 0 || j == 0) {
        reverse(current.begin(), current.end());
        lcs.push_back(current);
        reverse(current.begin(), current.end());
        return;
    }

    if (str1[i - 1] == str2[j - 1]) {
        current += str1[i - 1];
        if(i-1 >= 0 && j-1 >= 0 && dp_temp[i-1][j-1] != -1) {
            dp_temp[i-1][j-1] = 1;
            findAllLCS(i - 1, j - 1, str1, str2, lcs, current, dp,dp_temp);
        }
        current.pop_back();
    } else {
        if (dp[i - 1][j] >= dp[i][j - 1]) {
            if(i-1 >= 0 && dp_temp[i-1][j] != -1) {
                dp_temp[i-1][j] = 1;
                findAllLCS(i - 1, j, str1, str2, lcs, current, dp,dp_temp);
            }
        }
        if (dp[i][j - 1] >= dp[i - 1][j]) {
            if(dp_temp[i][j-1] != -1) {
                dp_temp[i][j-1] = 1;
                findAllLCS(i, j - 1, str1, str2, lcs, current, dp,dp_temp);
            }
        }
    }
}

vector<string> all_longest_common_subsequences(string str1, string str2) {
    vector<string> answer;
    int n = str1.size(), m = str2.size();
    vector<vector<int> > dp(n + 1, vector<int>(m + 1, 0));

    // Fill the DP table
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (str1[i - 1] == str2[j - 1]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    // Use a temporary string to find all LCS
    string current = "";
    vector<vector<int> > dp_temp(n+1, vector<int>(m+1, 0));
    findAllLCS(n, m, str1, str2, answer, current, dp,dp_temp);

    // // Remove duplicates and sort the result
    set<string> uniqueLCS(answer.begin(), answer.end());
    answer.assign(uniqueLCS.begin(), uniqueLCS.end());
    return answer;
}

int main() {
    vector<string> answer = all_longest_common_subsequences("abaaa", "baabaca");
    for (string lcs : answer) {
        cout << lcs << " ";
    }
    cout << endl;
    return 0;
}
