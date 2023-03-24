#ifndef ADDER_HPP
#define ADDER_HPP

// Unidade responsável por somar
class Adder {
private:
    // Armazena o resultado da soma
	int output;

public:
    // Construtor da classe
	Adder();
    // Função que executa a soma
    // Requer duas entradas que serão utilizadas na soma
    // O resultado é armazenado na variável output
	void executa(int inputA, int inputB);
    // Retorna o valor de output
	int getOutput();
};

#endif //ADDER_HPP