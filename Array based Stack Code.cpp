#include <iostream>
#include <cstring>
using namespace std;

#define MAX 100

struct Stack {
    char stk[MAX];
    int top;
} s = { .top = -1 };


bool isEmpty() {
    return s.top == -1;
}


bool isFull() {
    return s.top == MAX - 1;
}

void push(char c) {
    if (isFull()) {
        cout << "Stack is Full\n";
        return;
    }
    s.stk[++s.top] = c;
   
}


char pop() {
    if (isEmpty()) {
        cout << "Stack is Empty\n";
        return '\0';
    }
    char popped = s.stk[s.top--];
    return popped;
}

// Display operation 
void display() {
    if (isEmpty()) {
        cout << "Stack is empty\n";
        return;
    }
    cout << "Current Stack (Top to Bottom): ";
    for (int i = s.top; i >= 0; i--)
        cout << s.stk[i] << " ";
    cout << "\n";
}

void peek() {
    if (isEmpty()) {
        cout << "Stack is empty\n";
        return;
    }
    cout << "Top element: " << s.stk[s.top] << "\n";
}



// Reverse Word Function
string reverseWord(string str) {
    string reversedWord;
    s.top = -1;  
    
    for (int i = 0; i < str.length(); i++) {
        push(str[i]);
    }
  
    while (!isEmpty()) {
        reversedWord += pop();
    }
    return reversedWord;
}


// Palindrome Checker Function
bool isPalindrome(string str) {
    s.top = -1;  
    for (int i = 0; i < str.length(); i++) {
        push(str[i]);
    }

    for (int i = 0; i < str.length(); i++) {
        if (str[i] != pop()) {
            return false;
        }
    }
    return true;
}


// Braces Balancer Function
bool isBalanced(string expr) {
    s.top = -1;

    for (int i = 0; i < expr.length(); i++) {
        char c = expr[i];
        
        if (c == '(' || c == '{' || c == '[') {
            push(c);
        } else if (c == ')' || c == '}' || c == ']') {
            if (isEmpty()) {
                return false;
            }
            char topChar = pop();
            // Check for matching pairs
            if ((c == ')' && topChar != '(') ||
                (c == '}' && topChar != '{') ||
                (c == ']' && topChar != '[')) {
                return false;
            }
        }
    }
    return isEmpty();
}

int main() {
    int choice;
    cout << "\n*** Data Structure Practicing Project ***\n";
    while (true) {
         cout <<"\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Display\n";
        cout << "4. Peek\n";
        cout << "5. IsEmpty\n";
        cout << "6. IsFull\n";
        cout << "7. Reverse Word\n";
        cout << "8. Palindrome Check\n";
        cout << "9. Braces Balancer\n";
        cout << "10. Exit\n";
        cout << "------------------------------------------------------------------------------------\n";
        cout << "Please enter the number of the required operation (1-10) from the above menu: ";
        cin >> choice;
        cout << "------------------------------------------------------------------------------------\n";
        switch (choice) {
            case 1: {
                char c;
                cout << "Please enter a character to push: ";
                cin >> c;
                push(c);
                break;
            }
            case 2: {
                
                  cout << "Popped character: " << pop() << "\n";
                break;
            }
            case 3: {
                display();
                break;
            }
            case 4: {
                peek();
                break;
            }
            case 5: {
                cout << (isEmpty() ? "Stack is empty\n" : "Stack is not empty\n");
                break;
            }
            case 6: {
                cout << (isFull() ? "Stack is full\n" : "Stack is not full\n");
                break;
            }
            case 7: {
                string word;
                cout << "Please enter a word to reverse: ";
                cin >> word;
                string reversed = reverseWord(word);
                cout << "Reversed word: " << reversed << "\n";
                break;
            }

            case 8: {
                string str;
                cout << "Please enter a string to check if it is a palindrome or not: ";
                cin >> str;
                bool result = isPalindrome(str);
                if (result)
                    cout << str << " is a palindrome string.\n";
                else
                    cout << str << " is not a palindrome string.\n";
                break;
            }
            case 9: {
                string expr;
                cout << "Please enter an expression to check braces balance: ";
                cin >> expr;
                bool balanced = isBalanced(expr);
                if (balanced)
                    cout << "The expression is balanced.\n";
                else
                    cout << "The expression is not balanced.\n";
                break;
            }

            case 10: {
                cout << "Exiting program.\n";
                return 0;
            }

            default: {
                cout << "Invalid choice. Please try again.\n";
                break;
            }
        }

       
        cout << "Operation executed successfully.\n";
    }

    return 0;
}
