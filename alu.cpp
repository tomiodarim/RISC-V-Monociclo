#include <cstring>
#include <iostream>
#include "alu.hpp"
#include "machine.hpp"

using namespace std;

ALU::ALU() = default;

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

int ALU::getOutput(){
    return output;
}

int ALU::getZero(){
    return zero;
}
