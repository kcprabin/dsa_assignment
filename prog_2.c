#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char ch) {
    stack[++top] = ch;
}

char pop() {
    return stack[top--];
}

char peek() {
    return stack[top];
}

int isEmpty() {
    return top == -1;
}

int precedence(char op) {
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    if (op == '^')
        return 3;
    return 0;
}

int isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
}

void infixToPostfix(char infix[], char postfix[]) {
    int j = 0;

    for (int i = 0; i < strlen(infix); i++) {
        char ch = infix[i];

        if (isdigit(ch)) {
            postfix[j++] = ch;
        }
        else if (ch == '(') {
            push(ch);
        }
        else if (ch == ')') {
            while (!isEmpty() && peek() != '(') {
                postfix[j++] = pop();
            }
            pop(); // removes '(' 
        }
        else if (isOperator(ch)) {
            while (!isEmpty() && peek() != '(' && precedence(peek()) >= precedence(ch)) {
                postfix[j++] = pop();
            }
            push(ch);
        }
    }

    while (!isEmpty()) {
        postfix[j++] = pop();
    }

    postfix[j] = '\0';
}

int evaluatePostfix(char postfix[]) {
    int numStack[MAX];
    int numTop = -1;

    for (int i = 0; i < strlen(postfix); i++) {
        char ch = postfix[i];

        if (isdigit(ch)) {
            numStack[++numTop] = ch - '0';
        }
        else if (isOperator(ch)) {
            int b = numStack[numTop--];
            int a = numStack[numTop--];
            int result;

            switch (ch) {
                case '+': result = a + b; break;
                case '-': result = a - b; break;
                case '*': result = a * b; break;
                case '/': result = a / b; break;
                case '^': 
                    result = 1;
                    for (int p = 0; p < b; p++)
                        result *= a;
                    break;
            }

            numStack[++numTop] = result;
        }
    }

    return numStack[numTop];
}

int main() {
    char infix[MAX], postfix[MAX];

    printf("Enter infix expression (single digit numbers only): ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);
    printf("Postfix expression: %s\n", postfix);

    int result = evaluatePostfix(postfix);
    printf("Result: %d\n", result);

    return 0;
}
