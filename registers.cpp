#include <string>
#include <iostream>
#include "registers.hpp"
#include "machine.hpp"

using namespace std;

Registers::Registers() = default;

void Registers::executa(int ReadReg1, int ReadReg2) {
	this->readData1 = this->memory[ReadReg1];
	this->readData2 = this->memory[ReadReg2];
}

void Registers::executa(int WriteReg, int WriteData, int RegWrite) {
	if(RegWrite){
		this->memory[WriteReg] = WriteData;
	}
}

int Registers::getReadData1(){
  return readData1;
}

int Registers::getReadData2(){
  return readData2;
}

const unsigned int *Registers::getMemory() const {
  return memory;
}