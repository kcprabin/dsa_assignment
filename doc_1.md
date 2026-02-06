# Program 1: Bracket Balancing Checker

This program checks whether the brackets in a given expression are properly balanced or not. It supports three types of brackets: `()`, `{}`, and `[]`.

---

## Data Structures Used

### Stack (Array-based)

I used a simple character array `stack[MAX]` to implement the stack where MAX is set to 100. The variable `top` keeps track of the current position in the stack, and it starts at -1 (meaning the stack is empty).

```c
char stack[MAX];
int top = -1;
```

The stack is global here so all the functions can access it directly without passing it around as a parameter.

---

## Functions

### `push(char ch)`

Adds a character to the top of the stack. First increments `top`, then puts the character there.

### `pop()`

Removes and returns the character at the top of the stack. Returns the character at current `top` position and then decrements `top`.

### `isMatching(char open, char close)`

This helper function checks if a pair of brackets match each other. For example, `(` matches with `)`, `{` with `}`, and `[` with `]`. Returns 1 if they match, 0 otherwise.

### `isBalanced(char exp[])`

The main logic sits here. It goes through each character in the expression:
- If it finds an opening bracket (`(`, `{`, `[`), it pushes it onto the stack
- If it finds a closing bracket (`)`, `}`, `]`), it pops the stack and checks if the popped bracket matches the closing one
- If at any point there's no matching bracket or the stack is empty when trying to pop, returns 0 (not balanced)
- At the end, if the stack is empty, expression is balanced (return 1), otherwise not balanced (return 0)

---

## How main() Works

The main function is pretty straightforward:

1. Declares a character array `exp` to store the input expression
2. Asks the user to enter an expression using `printf`
3. Reads the expression using `gets()` 
4. Calls `isBalanced()` with the expression
5. Based on the return value, prints whether the expression is balanced or not

---

## Sample Output

```
Enter expression: {[a+b]*(c-d)}
Expression is BALANCED
```

```
Enter expression: {[a+b]*(c-d}
Expression is NOT BALANCED
```

```
Enter expression: ((()))
Expression is BALANCED
```

```
Enter expression: ([)]
Expression is NOT BALANCED
```
