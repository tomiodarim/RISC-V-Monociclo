#include <string>
#include <iostream>
#include "immGen.hpp"

using namespace std;

ImmGen::ImmGen() = default; 

void ImmGen::executa(int input){
	int opcode = input & 127;
	switch(opcode){
		case 19:
			cout << "      Instrução ADDI" << endl;
			output = (input >> 20);
			if(output >> 11) output += 0xFFFFF000;
			break;
		
		case 3:
			cout << "      Instrução LW" << endl;
			output = (input >> 20);
			if(output >> 11) output += 0xFFFFF000;
			break;
		
		case 35:{
			cout << "      Instrução SW" << endl;
			int aux1 = (input >> 7) & 31;
			int aux2 = (input >> 20) & 4064;
			output = aux2 + aux1;
			if(output >> 11) output += 0xFFFFF000;
		} break;

		case 99: {
			cout << "      Instrução do Tipo B" << endl;
			int aux1 = (input >> 7) & 30;
			int aux2 = (input >> 20) & 2016;
			int aux3 = (input << 4) & 2048;
			int aux4 = (input >> 19) & 4096;
			output = aux4 | aux3 | aux2 | aux1;
			if(output >> 12) output += 0xFFFFE000;
		} break;
	}
}

int ImmGen::getOutput(){
  return output;
}
