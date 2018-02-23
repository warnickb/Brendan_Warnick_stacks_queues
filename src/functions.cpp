#include "../include/functions.h"
#include <iostream>
#include <stack>
/**
 * perform check for matching items
 * used https://www.geeksforgeeks.org/check-for-balanced-parentheses-in-an-expression/ for refernce 
 */

bool balancedSymbols(std::string input){
	std::stack<char, std::deque<char> > testStack;
	//go through stack
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

std::string iToP(std::string input){
	std::stack<char, std::deque<char> > infixPostfix;
	std::string newString;
	for(int i = 0; i < input.length(); i++){
		if(input[i] == '(' || input[i] == '+' || input[i] == '-' || input[i] == '*' || input[i] == '/'){
			infixPostfix.push(input[i];





int main(int argc, char* argv[]){
	std::string testStuff = "({[test]}) [] () {()}";
	std::string testStuff2 = "([){}}";
	std::cout << balancedSymbols(testStuff) << std::endl;
	std::cout << balancedSymbols(testStuff2) << std::endl;
}


