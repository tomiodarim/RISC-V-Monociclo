#ifndef PROCESSOR_HPP
#define PROCESSOR_HPP

#include "programCounter.hpp"
#include "adder.hpp"
#include "instructionMemory.hpp"
#include "control.hpp"
#include "multiplexer.hpp"
#include "registers.hpp"
#include "immGen.hpp"
#include "aluControl.hpp"
#include "alu.hpp"
#include "dataMemory.hpp"

class Processor{
public:
	ProgramCounter *pc = new ProgramCounter();
	Adder *adder1 = new Adder();
	InstructionMemory *instructionMemory = new InstructionMemory();
	Control *control = new Control();
	Registers *registers = new Registers();
	ImmGen *immgen = new ImmGen();
	Multiplexer *mux1 = new Multiplexer();
	Adder *adder2 = new Adder();
	ALU *alu = new ALU();
	ALUControl *aluControl = new ALUControl();
	Multiplexer *mux2 = new Multiplexer();
	Multiplexer *mux3 = new Multiplexer();
	DataMemory *dataMemory = new DataMemory();
	Multiplexer *mux4 = new Multiplexer();

public:
	Processor();
	void inicializa(unsigned int *instructionMemoryRef);
	void executa();
	void printRegistradores();
	void printMemoria();
};

#endif //PROCESSOR_HPP