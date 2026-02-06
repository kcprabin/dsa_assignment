# Infix to Postfix - prog_2

converts normal math expressions (infix) to postfix and calculates the answer.

quick eg: `3+4*2` becomes `342*+` = 11

## data structures

two stacks here:
1. char stack - for operators during conversion
2. int stack (inside eval function) - for numbers while calculating

```c
char stack[MAX];
int top = -1;
```

## functions breakdown

**push, pop, peek, isEmpty** - usual stack operations

**precedence** - returns priority of operator. ^ is highest (3), then */  (2), then +- (1). needed to decide which op goes first.

**isOperator** - checks if char is +,-,*,/,^

**infixToPostfix** - the conversion logic:
- digit? add to output directly
- opening bracket? push to stack
- closing bracket? pop everything till you find opening bracket
- operator? pop higher/equal precedence ops first, then push current one
- finally empty the stack to output

**evaluatePostfix** - reads postfix left to right:
- number? push to stack
- operator? pop 2 numbers, do the math, push result back
- last number on stack is answer

## main

reads expression -> converts -> evaluates -> prints

**limitation**: only works with single digit numbers (0-9). didnt implement multi digit parsing.

## sample runs

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

why 342*+ = 11? coz 4*2=8 first (higher precedence), then 3+8=11
