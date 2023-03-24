#include <iostream>
#include <cstring>
#include "processor.hpp"

using namespace std;

// Construtor da classe
Processor::Processor() = default;

// Passa para a InstructionMemory as instruções lidas do arquivo
// Requer um vetor de inteiros com as instruções
void Processor::inicializa(unsigned int *instrucoes) {
	this->instructionMemory->inicializa(instrucoes);
}

// Executa um clock
void Processor::executa() {
    // Executa o Program Couter com o valor do mux3
	pc->executa(mux3->getOutput());
	cout << "ProgramCounter: " << pc->getOutput() << endl;

    // Define a instrução a ser executada
	instructionMemory->executa(pc->getOutput());
	cout << "InstructionMemory: " << instructionMemory->getInstruction() << endl;

    // Incrementa o PC em 4 para ir para a próxima instrução
	adder1->executa(pc->getOutput(), 4);
	cout << "Adder1: " << adder1->getOutput() << endl;

	int instrucao = instructionMemory->getInstruction();

    // Define os sinais de controle
	cout << "Control: " << endl;
	control->executa(instrucao & 127);
	cout << "      Branch  : " << control->getBranch() << endl;
	cout << "      MemRead : " << control->getMemRead() << endl;
	cout << "      MemToReg: " << control->getMemToReg() << endl;
	cout << "      ALUOP   : " << control->getAluOp() << endl;
	cout << "      MemWrite: " << control->getMemWrite() << endl;
	cout << "      ALUSrc  : " << control->getAluSrc() << endl;
	cout << "      RegWrite: " << control->getRegWrite() << endl;

    // Coloca os dados dos registradores definidos no ReadData
	registers->executa((instrucao >> 15) & 31, (instrucao >> 20) & 31);
	cout << "Registers Read: " << endl;
	cout << "      ReadData1: "  << registers->getReadData1() << endl;
	cout << "      ReadData2: " << registers->getReadData2() << endl;

    // Gera o Immediate
	cout << "ImmGen: " << endl;
	immgen->executa(instrucao);
    cout << "      Output: " << immgen->getOutput() << endl;

    // Determina a entrada da ale entre o registrador 2 e o Immediate
	mux1->executa(registers->getReadData2(), immgen->getOutput(), control->getAluSrc());
	cout << "Mux1: " << mux1->getOutput() << endl;

    // Define a operação a ser executada pela alu
	aluControl->executa(instrucao, control->getAluOp());
	cout << "ALUControl: " << aluControl->getOutput() << endl;

    // Executa a operação
	alu->executa(registers->getReadData1(), mux1->getOutput(), aluControl->getOutput());
	cout << "ALU: " << endl;
	cout << "      Output: " << alu->getOutput() << endl;
	cout << "      Zero  : " << alu->getZero() << endl;

    // Soma o valor de PC com o Immediate
	adder2->executa(pc->getOutput(), immgen->getOutput());
	cout << "Adder2: " << adder2->getOutput() << endl;

    // Escolhe se inverte ou não a flag zero
	mux2->executa(alu->getZero(), (!alu->getZero()), ((instrucao >> 12) & 1));
	cout << "Mux2: " << mux2->getOutput() << endl;

    // Escolhe entre a saida dos dois somadores para pc
	mux3->executa(adder1->getOutput(), adder2->getOutput(), (control->getBranch() & mux2->getOutput()));
	cout << "Mux3: " << mux3->getOutput() << endl;

    // Lê ou escreve na memória de dados
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

    // Define qual dado será escrito nos registradores
	mux4->executa(alu->getOutput(), dataMemory->getReadData(), control->getMemToReg());
	cout << "Mux4: " << mux4->getOutput() << endl;

    // Escreve o output da alu ou da memória em um registrador se a flag for 1
	registers->executa((instrucao >> 7) & 31, mux4->getOutput(), control->getRegWrite());
	cout << "Registers Write: " << endl;
	cout << "      Register: " << ((instrucao >> 7) & 32) << endl;
	cout << "      Data    : " << mux4->getOutput() << endl;
	
}

// Imprime o valor dos registradores com contrúdos diferentes de zero
void Processor::printRegistradores() {
  unsigned int const *registers = this->registers->getMemory();

  for (int i = 0; i < 32; ++i) {
    if (registers[i])
    	cout << "reg(" << i << ") = " << (int) registers[i] << endl;
  }
}

// Imprime o valor dos registradores com contrúdos diferentes de zero
void Processor::printMemoria() {
  unsigned char const *dataMem = this->dataMemory->getMemory();
  int val;

  for (int i = 0; i < 65536; ++i) {
    memcpy(&val, &dataMem[i], sizeof(int));
    if (dataMem[i])
			cout << "Mem[" << i << "] = " << val << endl;
    }
}