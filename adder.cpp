#include "adder.hpp"

// Construtor padrão para a classe
Adder::Adder() = default;

// Função que executa a soma
// Requer duas entradas que serão utilizadas na soma
// O resultado é armazenado na variável output
void Adder::executa(int inputA, int inputB) {
	this->output = inputA + inputB;
}

// Retorna o valor de output
int Adder::getOutput() {
    return output;
}
