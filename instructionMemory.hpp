#ifndef INSTRUCTIONMEMORY_HPP
#define INSTRUCTIONMEMORY_HPP

class InstructionMemory {
private:
	unsigned int *memory;
	int instruction;

public:
  InstructionMemory();
  void executa(int input);
  void inicializa(unsigned int *memoryRef);
  int getInstruction();
};


#endif //INSTRUCTIONMEMORY_HPP