#ifndef PROGRAMCOUNTER_HPP
#define PROGRAMCOUNTER_HPP

// Unidade responsável por informar qual instrução será executada no ciclo
class ProgramCounter {
private:
    // Endereço da memória que contém a instrução
    int output;

public:
    // Construtor da classe
	ProgramCounter();
    // Define o valor de output a partir do input
    // Requer um valor de entrada
	void executa(int input);
    // Retorna o valor de output
	int getOutput();
};

#endif //PROGRAMCOUNTER_HPP