// DP


// #include <bits/stdc++.h>
// using namespace std;

// string minWindow(string str1, string str2) {
//     int m = str1.size(); int n = str2.size();
//     map<char,int>freq_map;

//     int left = 0; int right = 0; int j = 0;
//     int count = 0; int start_index = -1; int minlen = INT_MAX;

//     while(right < m) {
        
//         if(freq_map.find(str1[right]) != freq_map.end() && freq_map[str1[right]] > 0) {
//             count += 1;
//             j++;
//         }
//         freq_map[str1[right]]--;
//         while(count == n) {
//             if(right - left + 1 < minlen) {
//                 minlen = right-left+1;
//                 start_index = left;
//             }
//             freq_map[str1[left]]++;
//             if(freq_map[str1[left]] > 0) {
//                 count -= 1;
//             }
//             left++;
//         }
//         right++;
//    }
// }