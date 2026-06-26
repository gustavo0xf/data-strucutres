#include <iostream>
#include <stack>

using namespace std;

void printStack(stack<int> cpStack) {
    cout << "[top] -> "; 
    if (cpStack.empty()) {
        cout << "[!] call stack is empty";
    }
    while (!cpStack.empty()) {
        cout << "|" << cpStack.top() << "| ";
        cpStack.pop();
    }
    cout << "\n";
}

int fact(int n) {
    stack<int> stack;
    int res = 1;

    while (n > 1) {
        stack.push(n);
        cout << "[*] pushed: " << n << " -> ";
        printStack(stack);
        n--;
    }

    cout << "\n[!] base case reached.\n";

    while (!stack.empty()) {
        int top = stack.top();
        res *= top;
        
        cout << "[*] popped: " << top << " | " << (res / top) << " * " << top << " = " << res << "\n";
        stack.pop();
        
        cout << "[+] stack: " << endl;
        printStack(stack);
    }

    return res;
}

int main() {
    int num = 5;
    int res = fact(num);
    cout << "\n" << num << "! = " << res << endl;
    return 0;
}