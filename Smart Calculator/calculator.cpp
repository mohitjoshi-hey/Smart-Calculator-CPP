#include<iostream>
#include<iomanip>
#include<vector>
#include<string>
#include<sstream>
using namespace std;

int precedence(char optr){
    if(optr == '+' || optr == '-'){
        return 1;
    }
    else if(optr == '*' || optr == '/'){
        return 2;
    }
}

double result(char optr, double num1, double num2){
    switch(optr){
        case '+': return num1 + num2;
        case '-': return num1 - num2;
        case '*': return num1 * num2;
        case '/':
            if(num2 == 0){
                throw "Can't divide by 0\n";
            }
            return num1 / num2;
        default: throw "Invalid Operator\n";
    }
}

void precedence(){
    
}

int main(){
    vector <string> history;

    double num1, num2;
    char optr;
    while(true){
        int key;
        cout << "Press 1 for Calculation\n"
                "Press 2 to show History\n"
                "Press 0 to Exit\n";
        cin >> key;

        switch(key){
            case 1:
                cout << "Enter expression: ";
                cin >> num1 >> optr >> num2;
                try{
                    double res = result(optr, num1, num2);
                    cout << fixed << setprecision(2) << res << endl;

                    // Something new we learnt today
                    ostringstream oss;
                    oss << fixed << setprecision(2);
                    oss << num1 << " " << optr << " " << num2 << " = " << res;

                    history.push_back(oss.str());
                    break;
                }
                catch(const char *msg){
                    cout << msg << endl;
                }
                break;
            case 2:
                cout << "History: \n";
                for(int i = 0; i < history.size(); i++){
                    cout << history[i] << "\n";
                }
                cout << "\n";
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