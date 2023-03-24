#include <string>
#include <iostream>
#include "instructionMemory.hpp"
#include "machine.hpp"

using namespace std;

InstructionMemory::InstructionMemory(){
  this->memory = nullptr;
}

void InstructionMemory::inicializa(unsigned int *memoryRef){
    this->memory = memoryRef;
}

void InstructionMemory::executa(int input){
  this->instruction = this->memory[input/4];
	if(!this->instruction){
		cout << "\nPrograma finalizado!\n\n";
		exit(0);
	}
}

int InstructionMemory::getInstruction(){
    return instruction;
}
