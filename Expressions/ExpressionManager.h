
#ifndef ExpressionManager_h
#define ExpressionManager_h

#include <stack>
#include <sstream>
#include <cctype>
#include <iomanip>
#include "ExpressionManagerInterface.h"

class ExpressionManager : public ExpressionManagerInterface {
public:
    ExpressionManager(string input){
        expression = input.substr(input.find(':') + 1, input.length());

    };
    virtual ~ExpressionManager(void){};
    
   /*************************************** This checks to see that all characters are valid for use **************************************/
    bool validOperators(void){
        
        for (int i = 0; i < expression.length(); i++){
            if ((expression[i] == '+') || (expression[i] == '-') || (expression[i] == '{') || (expression[i] == '}') || (expression[i] == '[') || (expression[i] == ']') || (expression[i] == '(') || (expression[i] == ')') || (expression[i] == ' ') || (expression[i] == '*') || (expression[i] == '/') || (expression[i] == '%') || (isdigit(expression[i]))){
                continue;
            }
            else {
                throw std::string("Illegal Operators");
            }
        }
        return true;
    }
    
    /*************************** This returns if the characters are closing parenthesis or not, used in balance function ******************************/
    bool areSimilar(char first, char second){
        
        if ((first == '(') && (second == ')')){
            return true;
        }
        else if ((first == '{') && (second == '}')){
            return true;
        }
        else if ((first == '[') && (second == ']')){
            return true;
        }
        else {
            return false;
        }
    }
    /*************************************** This returns the actual value when manipulating two numbers **************************************/
    int simpleEquation(char oper, int first, int second){
        switch (oper) {
            case '+':
                return first + second;
            case '-':
                return first - second;
            case '*':
                return first * second;
            case '/':
                return first / second;
            case '%':
                return first % second;
            default:
                return -1;
                break;
        }
    }
    
    /*************************************** This returns if the equation is balanced or not **************************************/
    bool areBalanced(void){
        
        for (int i = 0; i < expression.length(); i++){
            if (expression[i] == '(' || expression[i] == '{' || expression[i] == '['){
                balance.push(expression[i]);
            }
            else if (expression[i] == ')' || expression[i] == '}' || expression[i] == ']'){
                if((balance.empty()) || (!areSimilar(balance.top(), expression[i]))){
                    throw std::string("Paren Mis-match");
                }
                else{
                    balance.pop();
                }
            }
        }
        if (!balance.empty()){
            throw std::string("Unbalanced");
        }
        return true;
    }
    
    /******************************* This returns the priority of each symbol, asigning a number depending on precidence *******************************/
    int precedence (char symbol){
        if (symbol == '+' || symbol == '-'){
            return 1;
        }
        else if (symbol == '*' || symbol == '/' || symbol == '%'){
            return 2;
        }
        else if (symbol == ')' || symbol == '}' || symbol == ']' || symbol == '(' || symbol == '{' || symbol == '['){
            return 3;
        }
        else {
            return -1;
        }
    }
    
    /*************************************** Return the integer value of the infix expression **************************************/
    virtual int value(void){
        std::istringstream ISS(postfix());
        string equationPart;
        std::stack<int> numbers;
        int operand;
        
        while(ISS >> equationPart){
            std::istringstream subISS(equationPart);
            
            if (subISS >> operand){
                numbers.push(operand);
            }
            else{
                subISS.clear();
                int second = numbers.top();
                numbers.pop();
                int first = numbers.top();
                numbers.pop();
                numbers.push(simpleEquation(equationPart[0], first, second));
            }
        }
        return numbers.top();
    }
    
    /*************************************** Return the infix items from the expression *************************************/
    
    virtual string infix(void){
        std::ostringstream OS;
        
        OS << std::setw(11) << "Infix:";
        
        bool operand = false;
        bool lastOpenParen = false;
        bool lastCloParen = false;
        int numTest = 0;
        std::string equPart;
        std::istringstream ISS(expression);
        
        areBalanced();
        validOperators();
        
        while(ISS >> equPart){
            std::istringstream subISS(equPart);
            
            if (subISS >> numTest){
                if (operand == true){
                    throw std::string("Missing Operators");
                }
                else if (lastCloParen == true){
                    throw std::string("Missing Operands");
                }
                operand = true;
                lastOpenParen = false;
                lastCloParen = false;
            }
            else if (equPart == ")" || equPart == "}" || equPart == "]"){
                lastCloParen = true;
                lastOpenParen = false;
                continue;
            }
            else if (equPart == "(" || equPart == "{" || equPart == "["){
                lastOpenParen = true;
                lastCloParen = false;
                continue;
            }

            else {
                if (operand == false){
                    throw std::string("Missing Operands");
                }
                else if (lastOpenParen == true){
                    throw std::string("Missing Operands");
                }
                operand = false;
                lastOpenParen = false;
                lastCloParen = false;
                subISS.clear();
            }
        }
        if (operand == false){
            throw std::string("Missing Operators");
        }
        OS << expression;
        
        return OS.str();
    }
    
    /*************************************** Return a postfix representation of the infix expression **************************************/
    virtual string postfix(void){
        
        std::ostringstream OS;
        std::istringstream ISS(expression);
        std::string parsingString;
        int numberCheck;
                
        while(ISS >> parsingString){
            std::istringstream subISS(parsingString);
            
            if (subISS >> numberCheck){
                OS << numberCheck << " ";
            }
            else {
                while ((!postFix.empty()) && ((postFix.top() != '(') && (postFix.top() != '{') && (postFix.top() != '[')) && ((precedence(parsingString[0]) <= (precedence(postFix.top()))))){
                    OS << postFix.top() << " ";
                    postFix.pop();
                }
                
                if (parsingString == ")" || parsingString == "}" || parsingString == "]"){
                    while (!areSimilar(postFix.top(), parsingString[0])){
                        OS << postFix.top() << " ";
                        postFix.pop();
                    }
                    postFix.pop();
                }
                else {
                    postFix.push(parsingString[0]);
                    subISS.clear();
                }
            }
        }
        
        while(!postFix.empty()){
            OS << postFix.top() << " ";
            postFix.pop();
        }
        
        return OS.str();
    }
    
    /*************************************** (BONUS) Return a prefix representation of the infix expression **************************************/
    virtual string prefix(void){
        return "NOT IMPLEMENTED";
    }
    
    /*************************************** Return the infix vector'd expression items **************************************/
    virtual string toString() const{
        
        return "NOT IMPLEMENTED";
    }
    
private:
    string expression;
    std::stack<string> inFix;
    std::stack<char> postFix;
    std::stack<string> preFix;
    std::stack<char> balance;
    
};


#endif /* ExpressionManager_h */
