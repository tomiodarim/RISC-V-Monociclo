#ifndef IMMGEN_HPP
#define IMMGEN_HPP

// Unidade responsável por decodificar o valor Immadiate
class ImmGen {
private:
    // Armazena o valor de Immediate
    int output;

public:
    // Construtor da classe
	ImmGen();
    // Gera o Immediate a partir da instrução
	// Requer a intrução
    void executa(int input);
    // Retorna o valor de output
    int getOutput();
};

#endif //IMMGEN_HPP