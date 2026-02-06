# Bracket Balancing - prog_1

checks if brackets are balanced in an expression. handles (), {}, []

## how the stack works

used a char array as stack with top variable. top=-1 means empty.

```c
char stack[MAX];  // holds opening brackets
int top = -1;     // stack pointer
```

kept it global coz its easier than passing around everywhere.

## functions

**push/pop** - basic stack stuff, nothing fancy

**isMatching** - takes two chars, returns 1 if they're a valid pair like ( and ), otherwise 0

**isBalanced** - this does the actual work:
- loop thru expression char by char
- opening bracket? push it
- closing bracket? pop and check if it matches
- if stack empty at end = balanced, else not

## main function

just takes input, calls isBalanced, prints result. used gets() for input (yeah its deprecated but works for this)

## output

```
Enter expression: {[a+b]*(c-d)}
Expression is BALANCED
```

```
Enter expression: {[a+b*(c-d}
Expression is NOT BALANCED
```

```
Enter expression: ([)]
Expression is NOT BALANCED
```

last one fails coz even tho all brackets have pairs, theyre not properly nested
