#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> answer;
    string digits;
    long long target;

    void recurse(int index, long long previousOperand, long long currentOperand, long long value, vector<string>& ops) {
        string nums = digits;

        if (index == nums.length()) {
            if (value == target && currentOperand == 0) {
                string expr;
                for (int i = 1; i < ops.size(); ++i) {
                    expr += ops[i];
                }
                answer.push_back(expr);
            }
            return;
        }

        currentOperand = currentOperand * 10 + (nums[index] - '0');
        string current_val_rep = to_string(currentOperand);

        if (currentOperand > 0) {
            // NO OP recursion
            recurse(index + 1, previousOperand, currentOperand, value, ops);
        }

        // ADDITION
        ops.push_back("+");
        ops.push_back(current_val_rep);
        recurse(index + 1, currentOperand, 0, value + currentOperand, ops);
        ops.pop_back();
        ops.pop_back();

        if (!ops.empty()) {
            // SUBTRACTION
            ops.push_back("-");
            ops.push_back(current_val_rep);
            recurse(index + 1, -currentOperand, 0, value - currentOperand, ops);
            ops.pop_back();
            ops.pop_back();

            // MULTIPLICATION
            ops.push_back("*");
            ops.push_back(current_val_rep);
            recurse(index + 1, previousOperand * currentOperand, 0, value - previousOperand + (previousOperand * currentOperand), ops);
            ops.pop_back();
            ops.pop_back();
        }
    }

    vector<string> addOperators(string num, int target) {
        if (num.empty()) return {};

        this->digits = num;
        this->target = target;
        this->answer.clear();

        vector<string> ops;
        recurse(0, 0, 0, 0, ops);

        return answer;
    }
};
