class Solution {
public:

    void print(map<char,int>m) {
        for(auto it:m) {
            cout << it.first << " " << it.second << endl;
        }
    }
    string repeatLimitedString(string s, int repeatLimit) {
        string answer = "";
        int n = s.size();
        map<char,int>freq_map;
        for(int i = 0;i < n;i++) {
            freq_map[s[i]]++;
        }

        while(freq_map.size() > 0) {
            auto it_last = freq_map.rbegin();
            if(it_last != freq_map.rend()) {
                int freq = it_last->second;
                if(freq <= repeatLimit) {
                    string temp(freq,it_last->first);
                    answer += temp;
                    freq_map.erase(it_last->first);
                }
                else {
                    string temp(repeatLimit,it_last->first);
                    answer += temp;
                    freq_map[it_last->first] -= repeatLimit;
                    it_last++;

                    if(it_last != freq_map.rend()) {
                        answer += it_last->first;
                        // cout << answer << endl;
                        freq_map[it_last->first] -= 1;
                        if(freq_map[it_last->first] == 0) freq_map.erase(it_last->first);
                    }
                    else break;
                }
            }
        // print(freq_map);
        }
        return answer;
    }
};

// better 
// class Solution {
// public:
//     string repeatLimitedString(string s, int repeatLimit) {
//         unordered_map<char, int> freq;
//         for (char ch : s) {
//             freq[ch]++;
//         }

//         priority_queue<char> maxHeap;
//         for (auto& [ch, count] : freq) {
//             maxHeap.push(ch);
//         }

//         string result;

//         while (!maxHeap.empty()) {
//             char ch = maxHeap.top();
//             maxHeap.pop();
//             int count = freq[ch];

//             int use = min(count, repeatLimit);
//             result.append(use, ch);

//             freq[ch] -= use;

//             if (freq[ch] > 0 && !maxHeap.empty()) {
//                 char nextCh = maxHeap.top();
//                 maxHeap.pop();

//                 result.push_back(nextCh);
//                 freq[nextCh]--;

//                 if (freq[nextCh] > 0) {
//                     maxHeap.push(nextCh);
//                 }

//                 maxHeap.push(ch);
//             }
//         }

//         return result;
//     }
// };