#include <iostream>
#include "machine.hpp"
#include "processor.hpp"

// Construtor da classe
Machine::Machine(char *nomeArq) {
    // Cria o processador
    this->processor = new Processor();

    // Abre o arquivo com as instruções
    FILE *f = fopen(nomeArq, "r");
    if (!f) exit(1);

    int i;
    auto *instrucoes = (unsigned int *) (malloc(255 * sizeof(unsigned int)));
    char buff[255];
    int aux;

    // Lê e decodifica cada instrução
    for (i = 0; !feof(f); i++) {
        fgets(buff, 255, f);
        instrucoes[i] = lerInstrucao(buff);
    }

    // Passa as instruções para o processador
    processor->inicializa(instrucoes);
}

// Executa o clock
void Machine::clock() {
    std::cout << "================================================\n";
    processor->executa();
    std::cout << "------------------Registradores-----------------\n";
    processor->printRegistradores();
    std::cout << "---------------------Memoria-------------------\n";
    processor->printMemoria();
    std::cout << "-----------------------------------------------\n";
}

// Transforma uma string em inteiro equivalente aos bits da intrução
// Requer um vetor de caracteres formados por 1s e 0s
// Retorna o inteiro formado por esses mesmos bits
unsigned int Machine::lerInstrucao(const char *str) {
    unsigned int res = 0, aux = 1u;
    int i;

    for (i = 31; i >= 0; --i, aux <<= 1u) {
        res |= (str[i] - '0') ? aux : 0;
    }

    return res;
}