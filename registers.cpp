#include "registers.hpp"

// Contrutor padrão da classe
Registers::Registers() = default;

// Envia para os ReadData o valor armazenado nos registradores informados
// Requer como entrada quais registradores serão lidos
void Registers::executa(int ReadReg1, int ReadReg2) {
	this->readData1 = this->memory[ReadReg1];
	this->readData2 = this->memory[ReadReg2];
}

// Escreve um dado a um regitrado se a flag for 1
// Requer o registrador a ser escritor, o dado e a flag
void Registers::executa(int WriteReg, int WriteData, int RegWrite) {
	if(RegWrite){
		this->memory[WriteReg] = WriteData;
	}
}

// Retorna o valor de readData1
int Registers::getReadData1(){
  return readData1;
}

// Retorna o valor de readData2
int Registers::getReadData2(){
  return readData2;
}

// Retorna o vetor com todos os registradores
const unsigned int *Registers::getMemory() const {
  return memory;
}