#include "../leetcode.h"

class Solution
{
public:
    int eva(int a, int b, string op)
    {
        if (op == "+")
        {
            return a + b;
        }
        else if (op == "-")
        {

            return a - b;
        }
        else if (op == "/")
        {
            return a / b;
        }
        else if (op == "*")
        {
            return a * b;
        }
        throw invalid_argument("unknown op");
    }
    bool isOP(string s)
    {
        return s == "+" || s == "*" || s == "/" || s == "-";
    }
    int evalRPN(vector<string> &tokens)
    {
        stack<int> opValues;

        for (int i = 0; i < tokens.size(); i++)
        {
            if (isOP(tokens[i]))
            {
                int b = opValues.top();
                opValues.pop();

                int a = opValues.top();
                opValues.pop();
                int res = eva(a, b, tokens[i]);

                opValues.push(res);
            }
            else
            {
                opValues.push((stoi(tokens[i])));
            }
        }

        return opValues.top();
    }
};

int main()
{
    Solution s;
    vector<string> d = {"2", "1", "+", "3", "*"};
    int res = s.evalRPN(d);
    cout << res;
}