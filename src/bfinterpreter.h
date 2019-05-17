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

	protected:	
		bool ReadProgramPath(char* path);
		bool ReadOutputPath(char* path);
		bool ReadProgram(char* program);
		bool Prepare(); //initiliazes resources(memory) based on set members
	public:
		BFInterpreter(); //default constructor with every member initialized to NULL
		~BFInterpreter(); //destructor which releases memory

		int ParseInput(int argc,char** argv); //parses params and decides which actions should be taken maybe seperate class in the future?
		void Help(); //prints help to CLI

};
