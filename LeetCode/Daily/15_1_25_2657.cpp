class Solution {
public:
    void print(vector<int>m) {
        for(auto it:m) {
            cout << it << " ";
        }
        cout << endl;
    }

    void print_m(map<int,int>m) {
        for(auto it:m) {
            cout << it.first << " " << it.second << endl;
        }
    }

    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        map<int,int>m;
        for(int i = 0;i < A.size();i++) {
            m[A[i]] = i;
        }
        // print_m(m);
        for(int i = 0;i < B.size();i++) {
            if(m[B[i]] < i) m[B[i]] = i;
        }
        // print_m(m);
        vector<int>temp(A.size());
        for(auto it:m) {
            temp[it.second]++;
        }
        vector<int>pre(A.size());
        pre[0] = temp[0];
        for(int i = 1;i < A.size();i++) {
            pre[i] = pre[i-1] + temp[i];
        }
        print(pre);
        
        return pre;
    }
};

/*class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        
        int n = A.size();
        vector<int> freq(n+1, 0), res(n);
        int cnt = 0;

        for (int i = 0; i < n; i++) {
            
            freq[A[i]]++;
            if (freq[A[i]] == 2) cnt++;

            freq[B[i]]++;
            if (freq[B[i]] == 2) cnt++;

            res[i] = cnt;
        }

        return res;
    }
};*/
