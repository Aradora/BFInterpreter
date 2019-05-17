#include "bfinterpreter.h"
#include <iostream>
#include <cstring>
#include <stdio.h>
#include <fstream>

BFInterpreter::BFInterpreter(){
	memory = nullptr;
	program = nullptr;
	outputPath = nullptr;
	memoryPointer = nullptr;
}

BFInterpreter::~BFInterpreter(){ delete[] memory; }
//there should be also internal function working as parser for input params and as courtyard for next actions. Currently main does that.

int BFInterpreter::ParseInput(int argc, char** argv){
	for(int i = 0 ; i < argc; i++){



	}



}


void BFInterpreter::ExecuteProgram(){
	memoryPointer = memory;
	while(*program){ //i'm evil person
		switch(*program){
			case '>':
				++memoryPointer;
				break;
			case '<':
				--memoryPointer;
				break;
			case '+':
				++*memoryPointer;
				break;
			case '-':
				--*memoryPointer;
				break;
			case '.':
				this->WriteToMemoryFromInput(); //puts char in *memoryPointer
				break;
			case ',':
				this->ReadFromMemoryToOutput(); //writes out char from *memoryPointer
				break;
			case '[':
				if(*memoryPointer == 0){
					while(*program == ']')
						++program;
				}
				break;
			case ']':
				if(*memoryPointer != 0){
					while(*program == '[')
						--program;
				}
				break;
			default:
				break;
		}			
		program++;
	}
}

void BFInterpreter::WriteToMemoryFromInput(){
	std::cout << ">";
	std::cin.ignore(std::cin.rdbuf()->in_avail(), '\n');//precise amount of ignoring
	*memoryPointer = static_cast<char>(std::getchar());
}

void BFInterpreter::ReadFromMemoryToOutput(){
	std::cout<< *memoryPointer;
}

bool BFInterpreter::ParseProgram(char* in){
	const unsigned programSize = 512;
	unsigned n = 1;
	unsigned cpyCntr = 0;
	program = new char[n*programSize];
	while(*in){
		if(*in == '>' || *in == '<' || *in=='+' || *in=='-' || *in == '.' || *in == ',' || *in == '[' || ']'){
			program[cpyCntr] = *in;
			cpyCntr++;
			if(cpyCntr == n*programSize){
				n++;
				char *tmpPtr = program;
				program = new char[n*programSize];
				std::strcpy(program,tmpPtr);
				delete []tmpPtr;
				//TODO check if enough memory to copy, return false if not
			}	
		}
		in++;
	}
	return true;
}
//public interface
//

bool BFInterpreter::ReadProgram(char* program){
	return (this->ParseProgram(program))?true : false ;
}


bool BFInterpreter::ReadProgramPath(char* path){
/*	std::ifstream file;
	file.open(program);	
	if(!file.is_open())
		return false;
	file.get
*/
	
	return (strcmp(path,"")==0)?false:true;
}

void BFInterpreter::Help(){
	std::cout<<"BF interpreter \n\r -i <code>  to interpret\n\r"
		"-if <file> to interpret file\n\r"
		" -o <file> to write output to file instead of console";

}
