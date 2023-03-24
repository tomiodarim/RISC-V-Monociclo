#include "multiplexer.hpp"

// Construtor da classe
Multiplexer::Multiplexer() = default;

// Escolhe entre o inputA e o inputB com base no valor de inputControl
// Requer dois valores de possíveis saidas e um de controle
void Multiplexer::executa(int inputA, int inputB, int inputContol){
	this->output = inputContol ? inputB : inputA;
}

// Retorna o valor de output
int Multiplexer::getOutput(){
    return output;
}