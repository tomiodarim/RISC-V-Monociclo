#ifndef MULTIPLEXER_HPP
#define MULTIPLEXER_HPP

// Unidade responsável por escolher entre dois inputs
class Multiplexer {
private:
    // Resultado da multiplexação
    int output;

public:
    // Construtor da classe
	Multiplexer();
    // Escolhe entre o inputA e o inputB com base no valor de inputControl
    // Requer dois valores de possíveis saidas e um de controle
	void executa(int inputA, int inputB, int inputContol);
    // Retorna o valor de output
	int getOutput();
};

#endif //MULTIPLEXER_HPP