#include "alu.hpp"

// Construtor da classe
ALU::ALU() = default;

// Executa a operação informada por inputControl em inputA e inputB
// Requer três inputs, sendo dois operandos e a operação
// O resultado da operação é armazenado na variável output
void ALU::executa(int inputA, int inputB, int inputControl) {
	switch(inputControl){
		case 0:
			this->output = inputA & inputB;
			break;

		case 1:
			this->output = inputA | inputB;
			break;
		
		case 2:
			this->output = inputA + inputB;
			break;
		
		case 6:
			this->output = inputA - inputB;
			break;
	}
	zero = (!output);
}

// Retorna o valor de output
int ALU::getOutput(){
    return output;
}
// Retorna o valor da flag zero
int ALU::getZero(){
    return zero;
}
