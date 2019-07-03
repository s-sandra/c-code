/*
@author Sandra Shtabnaya

assignment: postfix calculator
purpose: defines functions for calculator and prompts user for input.
*/

#include <cctype>
#include <cmath>
#include <stack>
#include <iostream>
using namespace std;

void promptUser();
void toLower(string& line);
void trim(string& line);
void parse(string expression);
bool parseElement(stack<double>& operands, string element, string& expression);
void performOperation(double right, double left, string operation, stack<double>& operands);
bool isOperator(string op);
bool isOperand(string op);

int main () {
    promptUser();
    string expression;
    getline(cin, expression);
    toLower(expression);
    trim(expression);
    
    while (expression != "quit") {
        parse(expression);
        promptUser();
        getline(cin, expression);
        toLower(expression);
        trim(expression);
    }
    
    return 0;
}

/*
Prompts the user to enter a postfix expression or quit.
*/
void promptUser() {
    cout << "Enter a postfix expression or quit to exit:";
}

/*
Converts any letters to lowercase. Modifies passed line by 
reference.

@param line a reference to the user's input.
*/
void toLower(string& line) {
    for (int i = 0; i < line.length(); i++) {
        line.at(i) = tolower(line.at(i));
    }
}

/*
Removes any extra whitespace from input. Modifies passed
line by reference.

@param line a reference to the user's input.
*/
void trim(string& line) {
    int strLen = line.length();
    int findLoc = line.find("  ");
    while (findLoc != string::npos){ // while there is extra whitespace
        if(findLoc != strLen - 1){
            line.erase(findLoc, 1); // removes extra whitespace
        }
        findLoc = line.find("  ");
    }
}

/*
Divides a postfix expression into operators and operands.
Outputs "Invalid Expression!" if expression is not in postfix 
notation. Else, outputs the answer to the expression.

@param expression the postfix expression to parse.
*/
void parse(string expression) {
    stack<double> operands;
    int spaceIndex;
    string element;
    
    while (expression.size() != 0) {
        spaceIndex = expression.find(' '); // finds index of next space
        if (spaceIndex != string::npos) { // if space found
            element = expression.substr(0, spaceIndex); // extracts operator or operand
            if (!parseElement(operands, element, expression)) {
                cout << "Invalid Expression!" << endl;
                return;
            }
            expression.erase(0, spaceIndex + 1); // removes element from expression
            
        }
        else { // only one element left in expression
            element = expression;
            expression = "\n";
            if (!parseElement(operands, element, expression)) {
                cout << "Invalid Expression!" << endl;
                return;
            }
        }
   }
   
   cout << operands.top() << endl; // ouputs answer to expression
   operands.pop();
}


/*
Determines if an element in an expression is an operator or an
operand. Calls appropriate functions to handle operators or operands.

@param operands a reference to a stack of doubles containing parsed operands and answers to operations.
@param element the element to process.
@param expression a reference to the postfix expression. Is emptied if end of expression reached.
@return whether the passed element is valid.
*/
bool parseElement(stack<double>& operands, string element, string& expression){
    
    if (isOperator(element)) {
		if (element == "sqrt" && operands.size() >= 1) { // sqrt requires only one operand
			double op = operands.top();
			operands.pop();
			operands.push(sqrt(op));
			return true;
		}
        else if (operands.size() >= 2) { // ensures there are operands for operation
            double operator1 = operands.top();
            operands.pop();
            double operator2 = operands.top();
            operands.pop();
            performOperation(operator1, operator2, element, operands);
            return true;
        }
    }
    else if (isOperand(element)) {
        double operand = stod(element); // converts operand to double
        operands.push(operand);
        return true;
    }
    else {
        // if end of expression and operands left over.
        if (element == "\n" && operands.size() > 1) { 
            return false;
        }
        
        // if expression has stuff other than operators and operands
        else if (element != "\n") {
			if (element == "pi") { // supports pi constant
				operands.push(4 * atan(1));
				return true;
			}
			else if (element == "e") { // supports e constant
				operands.push(exp(1));
				return true;
			}
            return false;
        }
        expression = ""; // empties out expression
        return true;
    }
    return false;
}

/*
Performs an operation on two operands, pushing the answer onto a stack.

@param right the right operand.
@param left the left operand.
@param operation the operation to perform.
@param operands a reference to a stack of doubles where the answer will be pushed.
*/
void performOperation(double right, double left, string operation, stack<double>& operands) {
    if (operation == "+") {
        operands.push(right + left);
    }
    else if (operation == "/") {
        operands.push(left / right);
    }
    else if (operation == "*") {
        operands.push(left * right);
    }
    else if (operation == "-") {
        operands.push(left - right);
    }
    else if (operation == "^") {
        operands.push(pow(left, right));
    }
}

/*
Determines whether the passed string is an operator. This
includes sqrt.

@param whether the passed string is an operator.
*/
bool isOperator(string op) {
    if (op == "+") {
        return true;
    }
    else if (op == "/") {
        return true;
    }
    else if (op == "*") {
        return true;
    }
    else if (op == "-") {
        return true;
    }
    else if (op == "^") {
        return true;
    }
	else if (op == "sqrt") {
		return true;
	}
    
    return false;
}

/*
Determines whether the passed string is an operand. This includes
decimal numbers.

@param whether the passed string is an operand.
*/
bool isOperand(string op) {
    int i = 0;
    while (i < op.length()) {
        if (!isdigit(op.at(i)) && op.at(i) != '.') { // checks for decimal place
            return false;
        }
        i++;
    }
    return true;
}