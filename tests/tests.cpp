#include "bfinterpreter.h"
#include <iostream>



void test_simpleCliProgram(){

	BFInterpreter testsubject;
	char *program = "-i ++++++++[>++++[>++>+++>+++>+<<<<-]>+>+>->>+[<]<-]>>.>---.+++++++..+++.>>.<-.<.+++.------.--------.>>+.>++.";
	std::cout<<"below should be Hello World\n\r";
	testsubject.ParseInput(program);
	
}













int main(){

	test_simpleCliProgram();


	return 0;
}
