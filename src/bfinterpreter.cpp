#include "bfinterpreter.h"
#include <iostream>
#include <cstring>

BFInterpreter::BFInterpreter(unsigned int howMuchMemory){
	memory = new unsigned char[howMuchMemory]();
	program = nullptr;
	outputPath = nullptr;
	memoryPointer = memory;

}

BFInterpreter::BFInterpreter():BFInterpreter(30000){};


void BFInterpreter::ExecuteProgram(){
	memoryPointer = memory;
	while(*program){ //im evil person
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




void BFInterpreter::Help(){
	std::cout<<"BF interpreter \n\r -i <code>  to interpret\n\r"
		"-if <file> to interpret file\n\r"
		" -o <file> to write output to file instead of console";

}

void BFInterpreter::ParseInput(char* input){
	bool wasInput=false,wasOutput=false; //to eliminate possibility of multiple arguments of the same type
	char *inputDash = std::strtok(input, "-if");
	if(inputDash != nullptr){
		//TODO parsing file;
		wasInput = true;
		std::cout << "idk how to parse yet";
		return;
	
	}
	else{
		inputDash = std::strtok(input,"-i");
		if(inputDash == nullptr){
			std::cout<< "No input parameter \r\n";
			this->Help();
			return;
		}
		else{
		//parsing program given in cli
		this->ParseProgram(inputDash);
		}
	}
	if(std::strtok(input,"-o")){
		//TODO getting path to output file
		std::cout << "idk how to output file yet";
		wasOutput = true;
		return;

	}

}


