#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <sstream>
#include <stack>
#include <limits>
using namespace std;

int precedence(char optr)
{
    if (optr == '+' || optr == '-')
    {
        return 1;
    }
    else if (optr == '*' || optr == '/')
    {
        return 2;
    }
    else
    {
        throw "Invalid operator\n";
    }
}

double result(double num1, char optr, double num2)
{
    switch (optr)
    {
    case '+':
        return num1 + num2;
    case '-':
        return num1 - num2;
    case '*':
        return num1 * num2;
    case '/':
        if (num2 == 0)
        {
            throw "Can't divide by 0\n";
        }
        return num1 / num2;
    default:
        throw "Invalid Operator\n";
    }
}

double solve_expression(string expression)
{
    stack<double> nums;
    stack<char> optr;
    for (int i = 0; i < expression.size(); i++)
    {
        char elem = expression[i];

        if (elem == '+' || elem == '-' || elem == '*' || elem == '/')
        {
            if (optr.empty() || optr.top() == '(')
            {
                optr.push(elem);
            }
            else if (precedence(optr.top()) < precedence(elem))
            {
                optr.push(elem);
            }
            else
            {
                while (!optr.empty() && optr.top() != '(' && (precedence(optr.top()) >= precedence(elem)))
                {
                    double num2 = nums.top();
                    nums.pop();
                    double num1 = nums.top();
                    nums.pop();
                    char symbol = optr.top();
                    optr.pop();
                    double partial_res = result(num1, symbol, num2);
                    nums.push(partial_res);
                }
                optr.push(elem);
            }
        }
        else if (elem == '(' || elem == ')')
        {
            if (elem == '(')
            {
                optr.push(elem);
            }
            else
            {
                while (!optr.empty() && optr.top() != '(')
                {
                    double num2 = nums.top();
                    nums.pop();
                    double num1 = nums.top();
                    nums.pop();
                    char symbol = optr.top();
                    optr.pop();
                    double partial_res = result(num1, symbol, num2);
                    nums.push(partial_res);
                }
                optr.pop();
            }
        }
        else if (elem == ' ')
        {
            continue;
        }
        else
        {
            double current_num = 0;
            while (i < expression.size() && (expression[i] >= '0' && expression[i] <= '9'))
            {
                current_num = 10 * current_num + (expression[i] - '0');
                i++;
            }
            i--; // When the loop will exit then the i value will get increased by one which will skip one character for the outer loop.
            nums.push(current_num);
        }
    }

    while (!optr.empty())
    {
        double num2 = nums.top();
        nums.pop();
        double num1 = nums.top();
        nums.pop();
        char symbol = optr.top();
        optr.pop();
        double partial_res = result(num1, symbol, num2);
        nums.push(partial_res);
    }

    return nums.top();
}

int main()
{
    vector<string> history;
    string expression;
    int history_count = 0;
    while (true)
    {
        int key;
        cout << "Press 1 for Calculation\n"
                "Press 2 to show History\n"
                "Press 3 to clean History\n"
                "Press 0 to Exit\n";
        cin >> key;

        switch (key)
        {
        case 1:
            cout << "Enter expression: ";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            getline(cin, expression);
            try
            {
                double res = solve_expression(expression);
                cout << fixed << setprecision(2) << res << endl;

                // Something new we learnt today
                ostringstream oss;
                oss << fixed << setprecision(2);
                oss << ++history_count << ". " << expression << " = " << res;

                history.push_back(oss.str());
                break;
            }
            catch (const char *msg)
            {
                cout << msg << endl;
            }
            break;
        case 2:
            cout << "History: \n";
            if (history.empty())
            {
                cout << "No History yet.\n";
            }
            else
            {
                for (int i = 0; i < history.size(); i++)
                {
                    cout << history[i] << "\n";
                }
            }
            cout << "\n";
            break;
        case 3:
            cout << "History Deleted" << endl;
            history_count = 0;
            history.clear();
            break;
        case 0:
            cout << "Exiting...\n";
            return 0;
        default:
            cout << "Invalid Key";
            break;
        }
    }
    return 0;
}