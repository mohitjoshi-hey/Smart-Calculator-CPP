#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <sstream>
#include <stack>
#include <limits>
#include <cmath>
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
    else if (optr == '^')
    {
        return 3;
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
    case '^':
        if(num1 < 0 && floor(num2) != num2){ // Throw error if num2 is not an integer.
            throw "Output can't be Imaginary\n";
        }
        return pow(num1, num2);
    default:
        throw "Invalid Operator\n";
    }
}

void do_single_operation(stack<double> &nums, stack<char> &optr)
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

double solve_expression(string expression)
{
    stack<double> nums;
    stack<char> optr;
    int sign = 1;

    for (int i = 0; i < expression.size(); i++)
    {
        char elem = expression[i];

        int j = i - 1;
        char prev_elem = '\0';
        while(j >= 0 && expression[j] == ' '){ // Searching for an operator which exist just before the unary operator: if YES, then its a unary & if NO then its not
            j--;
        }

        if(j >= 0){
            prev_elem = expression[j];
        }

        if((elem == '-' || elem == '+') &&
            (i == 0 || j < 0 || prev_elem == '(' ||
            prev_elem == '+' || prev_elem == '-' ||
            prev_elem == '*' || prev_elem == '/' || prev_elem == '^')){

                sign *= (elem == '+' ? 1 : -1); // For multiunary operation like --- then sign at final becomes = -1 an then after finding a num it will get multiplied to it and later it gets equal to 1.
                continue;
        }


        if (elem == '+' || elem == '-' || elem == '*' || elem == '/' || elem == '^')
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
                while (!optr.empty() && optr.top() != '(' &&
                      ((precedence(optr.top()) > precedence(elem)) ||
                      (precedence(optr.top()) == precedence(elem) && elem != '^'))) // Because exponent has a right associativity i.e. 3^2^2 = 3^4 = 81 which is unlike other operators like * etc.
                { // Once you are outside the bracket then this thing will take place.
                    do_single_operation(nums, optr);
                }
                optr.push(elem);
            }
        }
        else if (elem == '(' || elem == ')') // Jab tak bracket ke andar ho tab tak aapka ye chlega
        {
            if (elem == '(')
            {
                optr.push(elem);
            }
            else
            {
                while (!optr.empty() && optr.top() != '(')
                {
                    do_single_operation(nums, optr);
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
            if (i < expression.size() && expression[i] == '.') // Checking for decimal values.
            {
                double decimal_num = 0;
                int k = 0;
                i++;
                while (i < expression.size() && (expression[i] >= '0' && expression[i] <= '9'))
                {
                    decimal_num = decimal_num * 10 + (expression[i] - '0');
                    i++, k++;
                }
                current_num += decimal_num / pow(10, k);
            }

            i--; // When the loop will exit then the i value will get increased by one which will skip one character for the outer loop.
            current_num *= sign;
            nums.push(current_num);
            sign = 1;
        }
    }

    while (!optr.empty()) // If the expression is all parsed now and the optr stack is still unempty then do this thing.
    {
        do_single_operation(nums, optr);
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