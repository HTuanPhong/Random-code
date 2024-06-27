#include <fstream>
#include <iostream>
#include <sstream>
#include <stack>
#include <string>
using namespace std;

double evaluate(istream &in)
{
    stack<string> ops;
    stack<double> vals;
    string        tok;
    while (in >> tok)
    {
        if (tok == "(")
            ;
        else if (tok == "+" || tok == "*" || tok == "-" || tok == "/")
            ops.push(tok);
        else if (tok == ")")
        {
            string op = ops.top();
            ops.pop();
            double val2 = vals.top();
            vals.pop();
            double val1 = vals.top();
            vals.pop();
            if (op == "+")
                vals.push(val1 + val2);
            else if (op == "*")
                vals.push(val1 * val2);
            else if (op == "-")
                vals.push(val1 - val2);
            else if (op == "/")
                vals.push(val1 / val2);
        }
        else
            vals.push(stod(tok));
    }
    return vals.top();
}

int main()
{
    string buffer;
    getline(cin, buffer);
    stringstream ss(buffer);
    std::cout << evaluate(ss);
    return 0;
}