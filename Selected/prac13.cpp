#include<iostream>
#include<stack>
using namespace std;

bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

int precedence(char c) {
    if (c == '^') return 3;
    else if (c == '*' || c == '/') return 2;
    else if (c == '+' || c == '-') return 1;
    else return -1;
}

string InfixToPostfix(stack<char> s, string infix) {
    string postfix;
    for (int i = 0; i < infix.length(); i++) {
        if ((infix[i] >= 'a' && infix[i] <= 'z') || (infix[i] >= 'A' && infix[i] <= 'Z')) {
            postfix += infix[i];
        }
        else if (infix[i] == '(') {
            s.push(infix[i]);
        }
        else if (infix[i] == ')') {
            while (s.top() != '(' && !s.empty()) {
                char temp = s.top();
                postfix += temp;
                s.pop();
            }
            if (s.top() == '(') {
                s.pop();
            }
        }
        else if (isOperator(infix[i])) {
            if (s.empty()) {
                s.push(infix[i]);
            }
            else {
                if (precedence(infix[i]) > precedence(s.top())) {
                    s.push(infix[i]);
                }
                else if ((precedence(infix[i]) == precedence(s.top())) && (infix[i] == '^')) {
                    s.push(infix[i]);
                }
                else {
                    while (!s.empty() && precedence(infix[i]) <= precedence(s.top())) {
                        postfix += s.top();
                        s.pop();
                    }
                    s.push(infix[i]);
                }
            }
        }
    }
    while (!s.empty()) {
        postfix += s.top();
        s.pop();
    }
    return postfix;
}

int main() {
    string infix_exp, postfix_exp;
    cout << "Enter an Infix Expression:" << endl;
    cin >> infix_exp;
    stack<char> stack;
    cout << "INFIX EXPRESSION: " << infix_exp << endl;
    postfix_exp = InfixToPostfix(stack, infix_exp);
    cout << endl << "POSTFIX EXPRESSION: " << postfix_exp;

    return 0;
}



// Infix and postfix expressions are two different ways to represent mathematical expressions. The difference lies in the placement of operators and operands within the expression.

// 1. **Infix Expression:**
//    - In an infix expression, operators are placed between their operands, and parentheses are used to indicate the order of operations.
//    - For example: `a + b * c`
//    - In this expression, the addition operator (`+`) is placed between the operands `a` and `b`, and the multiplication operator (`*`) is placed between `b` and `c`.
//    - The infix notation is the standard mathematical notation that we use in everyday arithmetic.

// 2. **Postfix Expression (also known as Reverse Polish Notation - RPN):**
//    - In a postfix expression, also known as reverse Polish notation (RPN), operators are placed after their operands, and there is no need for parentheses to indicate the order of operations.
//    - For example: `a b c * +`
//    - In this expression, the multiplication operator (`*`) is applied to the operands `b` and `c` first, and then the addition operator (`+`) is applied to the result and the operand `a`.
//    - Postfix notation is often used in computer science and calculators because it eliminates the need for parentheses and follows a clear and unambiguous order of operations.

// Here's a brief comparison between infix and postfix expressions using the example `a + b * c`:

// - **Infix:** `a + b * c`
// - **Postfix:** `a b c * +`

// In postfix notation, the order of operations is determined solely by the position of the operators relative to their operands, making it easier to evaluate programmatically. It's also useful in stack-based algorithms for expression evaluation.

// Certainly! Let's go through the provided C++ code step by step:

// 1. **Include Header Files:**
//     ```cpp
//     #include<iostream>
//     #include<stack>
//     using namespace std;
//     ```
//     - The code includes necessary header files for input-output operations (`iostream`) and to use the `stack` data structure.

// 2. **Define Function to Check if a Character is an Operator:**
//     ```cpp
//     bool isOperator(char c)
//     {
//         if(c=='+'||c=='-'||c=='*'||c=='/'||c=='^')
//         {
//             return true;
//         }
//         else
//         {
//             return false;
//         }
//     }
//     ```
//     - This function `isOperator` takes a character as input and checks if it is one of the specified operators (`+`, `-`, `*`, `/`, `^`). It returns `true` if the character is an operator, and `false` otherwise.

// 3. **Define Function to Assign Precedence to Operators:**
//     ```cpp
//     int precedence(char c)
//     {
//         if(c == '^')
//             return 3;
//         else if(c == '*' || c == '/')
//             return 2;
//         else if(c == '+' || c == '-')
//             return 1;
//         else
//             return -1;
//     }
//     ```
//     - The `precedence` function assigns precedence values to operators. It returns an integer representing the precedence of the operator, with higher values indicating higher precedence. For example, `^` has the highest precedence, followed by `*` and `/`, and then `+` and `-`. The function returns -1 for characters that are not operators.

// 4. **Infix to Postfix Conversion Function:**
//     ```cpp
//     string InfixToPostfix(stack<char> s, string infix)
//     {
//         string postfix;
//         for(int i=0;i<infix.length();i++)
//         {
//             // ... (see next explanation)
//         }
//         while(!s.empty())
//         {
//             postfix+=s.top();
//             s.pop();
//         }
//         return postfix;
//     }
//     ```
//     - The `InfixToPostfix` function converts an infix expression to a postfix expression. It takes a stack (`s`) and an infix expression (`infix`) as input.

//     - It iterates through each character in the infix expression.
//     - If the character is an operand (a letter), it is directly appended to the postfix expression.
//     - If the character is an opening parenthesis `'('`, it is pushed onto the stack.
//     - If the character is a closing parenthesis `')'`, the function pops operators from the stack and appends them to the postfix expression until an opening parenthesis is encountered. The opening parenthesis is also popped from the stack.
//     - If the character is an operator, the function compares its precedence with the operator at the top of the stack. If the stack is empty or the current operator has higher precedence, it is pushed onto the stack. Otherwise, operators are popped from the stack and appended to the postfix expression until the stack is empty or the top operator has lower precedence.
//     - After processing all characters in the infix expression, any remaining operators in the stack are popped and appended to the postfix expression.
//     - The function returns the resulting postfix expression.

// 5. **Main Function:**
//     ```cpp
//     int main()
//     {
//         string infix_exp, postfix_exp;
//         cout << "Enter an Infix Expression:" << endl;
//         cin >> infix_exp;
//         stack<char> stack;
//         cout << "INFIX EXPRESSION: " << infix_exp << endl;
//         postfix_exp = InfixToPostfix(stack, infix_exp);
//         cout << endl << "POSTFIX EXPRESSION: " << postfix_exp;

//         return 0;
//     }
//     ```
//     - The `main` function is the entry point of the program.
//     - It prompts the user to enter an infix expression, reads the input, and then calls the `InfixToPostfix` function to convert the infix expression to postfix.
//     - Finally, it prints both the original infix expression and the resulting postfix expression.

// This program demonstrates a simple implementation of converting infix expressions to postfix using a stack in C++.