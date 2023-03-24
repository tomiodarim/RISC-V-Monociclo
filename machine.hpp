#ifndef MACHINE_HPP
#define MACHINE_HPP

// Classe que representa a máquina virtual
class Machine {
private:
    // Ponteiro para um processador
    class Processor *processor;

public:
    // Construtor da classe
    // Requer o nome do arquivo que contém as instruções
    Machine(char *nomeArq);
    // Executa o clock
    void clock();
    // Transforma uma string em inteiro equivalente aos bits da intrução
    // Requer um vetor de caracteres formados por 1s e 0s
    // Retorna o inteiro formado por esses mesmos bits
    static unsigned int lerInstrucao(const char str[255]);
};

#endif //MACHINE_HPP