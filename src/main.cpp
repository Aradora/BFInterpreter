#include <iostream>
#include <cstring>
#include <string.h>
#include <stdio.h>
#include "bfinterpreter.h"


int main(int argc, char** argv){ //main function in program. Gets parameters from cmd and starts needed function of bfI

	BFInterpreter bfI;
	return bfI.ParseInput(argc,argv);
}
