#include <iostream>
#include <cstdio>
#include <cstring>
#include "processor.hpp"

using namespace std;

Processor::Processor() = default;

void Processor::inicializa(unsigned int *instrucoes) {
	this->instructionMemory->inicializa(instrucoes);

}

void Processor::executa() {
	pc->executa(mux3->getOutput());
	cout << "ProgramCounter: " << pc->getOutput() << endl;

	instructionMemory->executa(pc->getOutput());
	cout << "InstructionMemory: " << instructionMemory->getInstruction() << endl;
	
	adder1->executa(pc->getOutput(), 4);
	cout << "Adder1: " << adder1->getOutput() << endl;

	int instrucao = instructionMemory->getInstruction();
	
	cout << "Control: " << endl;
	control->executa(instrucao & 127);
	cout << "      Branch  : " << control->getBranch() << endl;
	cout << "      MemRead : " << control->getMemRead() << endl;
	cout << "      MemToReg: " << control->getMemToReg() << endl;
	cout << "      ALUOP   : " << control->getAluOp() << endl;
	cout << "      MemWrite: " << control->getMemWrite() << endl;
	cout << "      ALUSrc  : " << control->getAluSrc() << endl;
	cout << "      RegWrite: " << control->getRegWrite() << endl;

	registers->executa((instrucao >> 15) & 31, (instrucao >> 20) & 31);
	cout << "Registers Read: " << endl;
	cout << "      ReadData1: "  << registers->getReadData1() << endl;
	cout << "      ReadData2: " << registers->getReadData2() << endl;

	cout << "ImmGen: " << endl;
	immgen->executa(instrucao);
  cout << "      Output: " << immgen->getOutput() << endl;

	mux1->executa(registers->getReadData2(), immgen->getOutput(), control->getAluSrc());
	cout << "Mux1: " << mux1->getOutput() << endl;

	aluControl->executa(instrucao, control->getAluOp());
	cout << "ALUControl: " << aluControl->getOutput() << endl;

	alu->executa(registers->getReadData1(), mux1->getOutput(), aluControl->getOutput());
	cout << "ALU: " << endl;
	cout << "      Output: " << alu->getOutput() << endl;
	cout << "      Zero  : " << alu->getZero() << endl;

	adder2->executa(pc->getOutput(), immgen->getOutput());
	cout << "Adder2: " << adder2->getOutput() << endl;

	mux2->executa(alu->getZero(), (!alu->getZero()), ((instrucao >> 12) & 1));
	cout << "Mux2: " << mux2->getOutput() << endl;
	
	mux3->executa(adder1->getOutput(), adder2->getOutput(), (control->getBranch() & mux2->getOutput()));
	cout << "Mux3: " << mux3->getOutput() << endl;

	dataMemory->executa(alu->getOutput(), registers->getReadData2(), control->getMemRead(), control->getMemWrite());
	cout << "DataMemory: " << endl;
	if(control->getMemRead()){
		cout << "      Read operation " << endl;
		cout << "      Address: " << alu->getOutput() << endl;
		cout << "      Data   : " << dataMemory->getReadData() << endl;
	}
	if(control->getMemWrite()){
		cout << "      Write operation " << endl;
		cout << "      Address: " << alu->getOutput() << endl;
		cout << "      Data   : " << registers->getReadData2() << endl;
	}

	mux4->executa(alu->getOutput(), dataMemory->getReadData(), control->getMemToReg());
	cout << "Mux4: " << mux4->getOutput() << endl;

	registers->executa((instrucao >> 7) & 31, mux4->getOutput(), control->getRegWrite());
	cout << "Registers Write: " << endl;
	cout << "      Register: " << ((instrucao >> 7) & 32) << endl;
	cout << "      Data    : " << mux4->getOutput() << endl;
	
}

void Processor::printRegistradores() {
  unsigned int const *registers = this->registers->getMemory();

  for (int i = 0; i < 32; ++i) {
    if (registers[i])
    	cout << "reg(" << i << ") = " << (int) registers[i] << endl;
  }
}

void Processor::printMemoria() {
  unsigned char const *dataMem = this->dataMemory->getMemory();
  int val;

  for (int i = 0; i < 65536; ++i) {
    memcpy(&val, &dataMem[i], sizeof(int));
    if (dataMem[i])
			cout << "Mem[" << i << "] = " << val << endl;
    }
}