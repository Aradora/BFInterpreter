//prototype

class BFInterpreter{
	private:
		unsigned char *memoryPointer;
		unsigned char *memory;
		char *program;
		char *outputPath;

		bool ParseProgram(char* in);		
		void ExecuteProgram();

		void WriteToMemoryFromInput();
		void ReadFromMemoryToOutput();


	public:
		void Help(); //prints help to CLI
		void ParseInput(char* input); //commands to run(-i <file> -o <output>)

		BFInterpreter(); //default constructor with 30k bytes memory
		BFInterpreter(unsigned int howMuchMemory); //custom constructor with custom amount of memory

		~BFInterpreter(); //destructor which releases memory

};
