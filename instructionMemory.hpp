#ifndef INSTRUCTIONMEMORY_HPP
#define INSTRUCTIONMEMORY_HPP

// Unidade responsável por armazenas as instruções que serão executadas
class InstructionMemory {
private:
    // Vetor que armazena as instruções como inteiros
	unsigned int *memory;
    // Intrição a ser executada nesse ciclo
	int instruction;

public:
    // Construtor da classe
    InstructionMemory();
    // Define o valor da instrução com base no local da memória
    // Requer um endereço da memória
    void executa(int input);
    // Armazena todas as instruções na memória
    // Requer um vetor do conteúdo lido do arquivo
    void inicializa(unsigned int *memoryRef);
    // Retorna a instrução a ser executada
    int getInstruction();
};

#endif //INSTRUCTIONMEMORY_HPP