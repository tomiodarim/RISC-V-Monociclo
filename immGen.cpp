#include <string>
#include <iostream>
#include "immGen.hpp"

// Construtor padrão da classe
ImmGen::ImmGen() = default;

// Gera o Immediate a partir da instrução
// Requer a intrução
void ImmGen::executa(int input){
    // Obtem os primeiros 7 bits da instrução, equivalentes ao Opcode
	int opcode = input & 127;
    // Dependendo o tipo da intrução há formas diferentes de gerar o Opcode
	switch(opcode){
        // Caso seja ADDI, apenas faz um shift
		case 19:
			std::cout << "      Instrução ADDI" << std::endl;
			output = (input >> 20);
			if(output >> 11) output += 0xFFFFF000;
			break;

        // Caso seja LW, apenas faz um shift
		case 3:
			std::cout << "      Instrução LW" << std::endl;
			output = (input >> 20);
			if(output >> 11) output += 0xFFFFF000;
			break;

        // Caso seja SW, o immediate está separado em duas partes
        // Obtem cada uma delas e soma para uní-las
		case 35:{
			std::cout << "      Instrução SW" << std::endl;
			int aux1 = (input >> 7) & 31;
			int aux2 = (input >> 20) & 4064;
			output = aux2 + aux1;
			if(output >> 11) output += 0xFFFFF000;
		} break;

        // Caso seja Tipo B, precisa reordenar pois o Immediate está separado em 4 partes
		case 99: {
			std::cout << "      Instrução do Tipo B" << std::endl;
			int aux1 = (input >> 7) & 30;
			int aux2 = (input >> 20) & 2016;
			int aux3 = (input << 4) & 2048;
			int aux4 = (input >> 19) & 4096;
			output = aux4 | aux3 | aux2 | aux1;
			if(output >> 12) output += 0xFFFFE000;
		} break;
	}
}

// Retorna o valor de output
int ImmGen::getOutput(){
    return output;
}
