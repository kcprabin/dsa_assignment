
#include <stdio.h>
#include <string.h>

#define MAX 100

// using global stack - easier this way
char stack[MAX];
int top = -1;


void push(char ch) {
    stack[++top] = ch;
}

char pop() {
    return stack[top--];
}

int isMatching(char open, char close) {
    if (open == '(' && close == ')') return 1;
    if (open == '{' && close == '}') return 1;
    if (open == '[' && close == ']') return 1;
    return 0;
}

// main logic - go thru each char
int isBalanced(char exp[]) {
    for (int i = 0; i < strlen(exp); i++) {
        char ch = exp[i];
        // opening bracket - push it
        if (ch == '(' || ch == '{' || ch == '[') {
            push(ch);
        }
        else if (ch == ')' || ch == '}' || ch == ']') {
            if (top == -1) 
                return 0;

            char open = pop();
            if (!isMatching(open, ch))
                return 0;
        }
    }


    return (top == -1);
}

int main() {
    char exp[MAX];

    printf("Enter expression: ");
    gets(exp); 

    if (isBalanced(exp))
        printf("Expression is BALANCED\n");
    else
        printf("Expression is NOT BALANCED\n");

    return 0;
}
