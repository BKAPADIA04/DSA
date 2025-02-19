class Solution {
public:

    void check(string &answer, string &temp, int &count,int index,int n,int k) {
        if(index > n) return;
        if(index == n) {
            count++;
            if(count == k) {
                answer = temp;
            }
            return;
        }

        for(int i = 0;i < 3;i++) {
            char ch = i + 'a';
            int si = temp.size();
            char ch_last = 'z';
            if(si > 0)
                ch_last = temp[si-1];

            if(ch_last == ch) continue;
            temp.push_back(ch);
            check(answer,temp,count,index+1,n,k);
            temp.pop_back();
        }
    }

    string getHappyString(int n, int k) {
        string answer = "";
        int count = 0;
        string temp = "";
        check(answer,temp,count,0,n,k);
        // for(int i = 0;i < 3;i++) {
        //     temp = i + 'a';
        //     check(answer,temp,count,1,n,k);
        //     temp = "";
        // }

        return answer;
    }
};

/*class Solution {
public:
    string getHappyString(int n, int k) {
        // Calculate the total number of happy strings of length n
        int total = 3 * (1 << (n - 1));

        // If k is greater than the total number of happy strings, return an
        // empty string
        if (k > total) return "";

        string result(n, 'a');

        // Define mappings for the next smallest and greatest valid characters
        unordered_map<char, char> nextSmallest = {
            {'a', 'b'}, {'b', 'a'}, {'c', 'a'}};
        unordered_map<char, char> nextGreatest = {
            {'a', 'c'}, {'b', 'c'}, {'c', 'b'}};

        // Calculate the starting indices for strings beginning with 'a', 'b',
        // and 'c'
        int startA = 1;
        int startB = startA + (1 << (n - 1));
        int startC = startB + (1 << (n - 1));

        // Determine the first character based on the value of k
        if (k < startB) {
            result[0] = 'a';
            k -= startA;
        } else if (k < startC) {
            result[0] = 'b';
            k -= startB;
        } else {
            result[0] = 'c';
            k -= startC;
        }

        // Iterate through the remaining positions in the result string
        for (int charIndex = 1; charIndex < n; charIndex++) {
            // Calculate the midpoint of the group for the current character
            // position
            int midpoint = (1 << (n - charIndex - 1));

            // Determine the next character based on the value of k
            if (k < midpoint) {
                result[charIndex] = nextSmallest[result[charIndex - 1]];
            } else {
                result[charIndex] = nextGreatest[result[charIndex - 1]];
                k -= midpoint;
            }
        }

        return result;
    }
};*/
