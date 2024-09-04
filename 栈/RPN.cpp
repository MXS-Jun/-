#include <iostream>
#include <string>
#include <stack>

using namespace std;
bool isOperator(string elem);
void rpnFunc();

int main()
{
    while (true)
    {
        rpnFunc();
    }
    return 0;
}

bool isOperator(string elem)
{
    if (elem.length() == 1)
    {
        if (elem.compare("+") == 0 || elem.compare("-") == 0 || elem.compare("*") == 0 || elem.compare("/") == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
}

void rpnFunc()
{
    stack<double> rpnStack;
        string input;
        cout << "Enter an RPN expression: ";
        getline(cin, input);
        input.append(" ");

        unsigned front = 0;
        unsigned rear = -1;
        for (unsigned i = 0; i < input.length(); i++)
        {
            if (input.at(i) == ' ')
            {
                front = rear + 1;
                rear = i;
            }
            else
            {
                continue;
            }

            string elem = input.substr(front, rear - front);
            if (isOperator(elem))
            {
                double a, b;
                b = rpnStack.top();
                rpnStack.pop();
                a = rpnStack.top();
                rpnStack.pop();

                if (elem.compare("+") == 0)
                {
                    rpnStack.push(a + b);
                }
                if (elem.compare("-") == 0)
                {
                    rpnStack.push(a - b);
                }
                if (elem.compare("*") == 0)
                {
                    rpnStack.push(a * b);
                }
                if (elem.compare("/") == 0)
                {
                    rpnStack.push(a / b);
                }
            }
            else
            {
                rpnStack.push(stod(elem));
            }
        }

        cout << "The result is: " << rpnStack.top() << endl;
}