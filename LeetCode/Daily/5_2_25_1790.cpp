class Solution {
public:

    void print(unordered_set<string>s) {
        for(auto it : s) {
            cout << it << endl;
        }
    }

    bool areAlmostEqual(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        unordered_set<string>s;
        for(int i = 0;i < n;i++) {
            for(int j = i;j < n;j++) {
                string temp = s1;
                swap(temp[i],temp[j]);
                s.insert(temp);
            }
        }
        auto it = s.find(s2);
        if(it == s.end()) return false;
        return true;
    }
};

/*
class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        if (s1 == s2) {
            return true;
        }
        int s1FrequencyMap[26] = {0};
        int s2FrequencyMap[26] = {0};
        int numDiffs = 0;

        for (int i = 0; i < s1.size(); i++) {
            char s1Char = s1[i];
            char s2Char = s2[i];

            if (s1Char != s2Char) {
                numDiffs++;
                // numDiffs is more than 2, one string swap will not make two
                // strings equal
                if (numDiffs > 2) return false;
            }

            // increment frequencies
            s1FrequencyMap[s1Char - 'a']++;
            s2FrequencyMap[s2Char - 'a']++;
        }

        // check if frequencies are equal
        for (int i = 0; i < 26; i++) {
            if (s1FrequencyMap[i] != s2FrequencyMap[i]) return false;
        }

        return true;
    }
};
*/
