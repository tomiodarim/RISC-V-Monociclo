#include <string>
#include <iostream>
#include "aluControl.hpp"
#include "machine.hpp"

using namespace std;

ALUControl::ALUControl() = default;

void ALUControl::executa(int instrucao, int aluop) {
	switch(aluop){
		case 0:
			output = 2;
			break;

		case 1:
			output = 6;
			break;

		case 2:
			if((instrucao >> 30) & 1) output = 6;
			else{
				switch((instrucao >> 12) & 7){
					case 0:
						output = 2;
						break;
				
					case 7:
						output = 0;
						break;

					case 6:
						output = 1;
						break;
				}
			}
			break;
	}
		
}

int ALUControl::getOutput(){
  return output;
}