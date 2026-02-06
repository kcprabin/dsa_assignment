# Program 2: Infix to Postfix Conversion and Evaluation

This program takes a mathematical expression in infix notation (the normal way we write, like `3+4*2`), converts it to postfix notation (also called Reverse Polish Notation), and then evaluates it to get the final answer.

---

## Data Structures Used

### Character Stack

For the infix to postfix conversion, I used a character stack:

```c
char stack[MAX];
int top = -1;
```

This stack temporarily holds operators and parentheses while we rearrange the expression.

### Integer Stack (inside evaluatePostfix)

For evaluation, I used a separate integer stack declared locally:

```c
int numStack[MAX];
int numTop = -1;
```

This one holds the operands (numbers) while we compute the result step by step.

---

## Functions

### `push(char ch)` and `pop()`

Standard stack operations. Push adds to top, pop removes from top.

### `peek()`

Returns the top element without removing it. Useful when we need to check what's on top before deciding what to do.

### `isEmpty()`

Returns 1 if stack is empty (top == -1), otherwise 0.

### `precedence(char op)`

Returns a number based on operator priority:
- `+` and `-` return 1 (lowest)
- `*` and `/` return 2
- `^` returns 3 (highest)

This helps decide which operator should come first in the postfix output.

### `isOperator(char ch)`

Simple check - returns 1 if the character is one of `+`, `-`, `*`, `/`, `^`.

### `infixToPostfix(char infix[], char postfix[])`

This is where the conversion happens. The algorithm goes like this:
- If we see a digit, directly add it to postfix output
- If we see `(`, push it to stack
- If we see `)`, keep popping and adding to output until we find the matching `(`
- If we see an operator, pop all operators with higher or equal precedence first, then push the current one
- At the end, pop everything remaining from stack to output

### `evaluatePostfix(char postfix[])`

Evaluates the postfix expression:
- If we see a digit, push it to the number stack
- If we see an operator, pop two numbers, apply the operator, push the result back
- The final answer is whatever's left on the stack

For power (`^`), I used a simple loop since we're only dealing with integers.

---

## How main() Works

1. Declares two character arrays - one for infix input, one for postfix output
2. Asks user to enter an infix expression
3. Reads it using `scanf`
4. Calls `infixToPostfix()` to convert
5. Prints the postfix expression
6. Calls `evaluatePostfix()` to compute the result
7. Prints the final answer

**Note:** This program works with single digit numbers only (0-9). For multi-digit support, we'd need to handle spacing or more complex parsing.

---

## Sample Output

```
Enter infix expression (single digit numbers only): 3+4*2
Postfix expression: 342*+
Result: 11
```

```
Enter infix expression (single digit numbers only): (5+3)*2
Postfix expression: 53+2*
Result: 16
```

```
Enter infix expression (single digit numbers only): 2^3+1
Postfix expression: 23^1+
Result: 9
```

```
Enter infix expression (single digit numbers only): ((4+2)*3)/(7-1)
Postfix expression: 42+3*71-/
Result: 3
```
