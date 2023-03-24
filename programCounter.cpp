#include "programCounter.hpp"

// Construtor da classe
ProgramCounter::ProgramCounter(){
	this->output = 0;
}


// Define o valor de output a partir do input
// Requer um valor de entrada
void ProgramCounter::executa(int input) {
	this->output = input;
}

// Retorna o valor de output
int ProgramCounter::getOutput() {
    return output;
}
