# Postfix Calculator
## Description

This program calculates the value of an expression in postfix (reverse polish) notation using a stack. It supports subtraction, addition, 
multiplication, exponentiation and square roots (SQRT), as well as the constants PI and E. Although it can evaluate a series of operations,
it does not recognize parenthesis. If the expression is not postfix or contains an invalid operator, the calculation is aborted. 

## Use Case
The calculator accepts numerical operands, which can be integers or doubles. Operators and operands must be separated by at least one 
space. The calculator continues to prompt for expressions until the user enters “quit.”

```
Enter a postfix expression or quit to exit:7.5   2.1 +
9.6
Enter a postfix expression or quit to exit:2 3 * 1 +
7
Enter a postfix expression or quit to exit:1 2 3 4 *
Invalid Expression!
Enter a postfix expression or quit to exit:1 A +
Invalid Expression!
Enter a postfix expression or quit to exit:64 sqrt
8
Enter a postfix expression or quit to exit:5 PI + E *
22.1311
Enter a postfix expression or quit to exit:quit
```
