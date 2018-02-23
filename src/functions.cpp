#include "../include/functions.h"
#include <iostream>
#include <stack>
/**
 * @author Brendan Warnick
 * @version Winter 2018
 * stack and queue hw
 */

/**
 * perform check for matching items
 * used https://www.geeksforgeeks.org/check-for-balanced-parentheses-in-an-expression/ for refernce 
 */

bool balancedSymbols(std::string input){
	std::stack<char, std::deque<char> > testStack;
	for(int i = 0; i < input.length(); i++){
		//push starting characters
		if(input[i] == '(' || input[i] == '[' || input[i] == '{'){
			testStack.push(input[i]);
		}
		//push ending characters
		if(input[i] == ')' || input[i] == ']' || input[i] == '}'){ 
			//pop when there is a match
			if(testStack.top() == '(' && input[i] == ')')
				testStack.pop();
			else if(testStack.top() == '[' && input[i] == ']')
				testStack.pop();
			else if(testStack.top() == '{' && input[i] == '}')
				testStack.pop();
		}
	}
	//return 1 if empty, 0 if not empty
	if(testStack.empty()){
		return true;
	}
	else return false;
}
/** 
 * converts infix to postfix
 */
std::string iToP(std::string input){
	//create stack and new string
	std::stack<char, std::deque<char> > infixPostfix;
	std::string newString;
	for(int i = 0; i < input.length(); i++){
		//add operators to start of queue
		if(input[i] == '(' || input[i] == '+' || input[i] == '-' || input[i] == '*' || input[i] == '/'){
			infixPostfix.push(input[i]);
		}
		//add everything else to the queue
		else newString += input[i];
	}
	//form new string with queue
	while(!infixPostfix.empty()){
		newString += infixPostfix.top();
		infixPostfix.pop();
	}
	return newString;
}

/**
 * main for testing a few samples
 */

int main(int argc, char* argv[]){
	std::string testStuff = "({[test]}) [] () {()}";
	std::string testStuff2 = "([){}}";
	std::string testStuff3 = "a + b - c * d / e";
	std::cout << balancedSymbols(testStuff) << std::endl;
	std::cout << balancedSymbols(testStuff2) << std::endl;
	std::cout << iToP(testStuff3) << std::endl;
}


