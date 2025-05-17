class Solution {
public:

    char evaluate(char operation, vector<char>&values) {
        if(operation == '!') {
            if(values[0] == 't') return 'f';
            return 't';
        }

        if(operation == '&') {
            for(char ch : values) {
                if(ch == 'f') return 'f';
            }
            return 't';
        }

        if(operation == '|') {
            for(char ch : values) {
                if(ch == 't') return 't';
            }
            return 'f';
        }

        return 'f';
    }

    bool parseBoolExpr(string expression) {
        stack<char>st;
        int n = expression.size();
        for(int i = 0;i < n;i++) {
            char ch = expression[i];
            if(ch == ')') {
                vector<char>values;
                while(st.top() != '(') {
                    values.push_back(st.top());
                    st.pop();
                }
                st.pop(); // remove (
                char op = st.top();
                st.pop(); // remove operation


                // evaluate
                char res = evaluate(op,values);
                st.push(res);
            }
            else if(ch != ','){
                st.push(ch);
            }
        }
        return st.top() == 't';
    }
};
