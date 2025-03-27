/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution {
public:
    NestedInteger deserialize(string s) {
        stack<NestedInteger>st;
        int n = s.size();
        if(s[0] != '[') return NestedInteger(stoi(s));
        int num = 0;
        bool negative = false;
        for(int i = 0;i < n;i++) {
            if(s[i] == '-') negative = true;
            else if(s[i] == '[') {
                st.push(NestedInteger());
            }
            else if(isdigit(s[i])) {
                num = num * 10 + (s[i] - '0');
            }
            else if(s[i] == ']' || s[i] == ',') {
                if(isdigit(s[i-1])) {
                    if(negative) num = -num;
                    st.top().add(NestedInteger(num)); 
                }
                num = 0;
                negative = false;

                if(s[i] == ']' && st.size() > 1) {
                    NestedInteger temp = st.top();
                    st.pop();
                    st.top().add(temp);
                }
            }
        }
        return st.top();
    }
};
