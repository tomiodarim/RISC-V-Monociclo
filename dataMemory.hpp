#ifndef DATAMEMORY_HPP
#define DATAMEMORY_HPP

// Unidade responsável por armazenar dados
class DataMemory {
private:
    // Vetor onde são armazenados os dados
    unsigned char memory[65536] = {0};
    // Variável que armazena o valor da memória que foi lido
	int readData;

public:
    // Construtor da classe
	DataMemory();
    // Executa a leitura e escrita na memória
    // Requer o endereço da memória, o dado para ser escrito e duas flags quer determinam se vai escrever ou ler
	void executa(int address, int writeData, int memRead, int memWrite);
	// Retorna o valor de ReadData
    int getReadData();
    // Retorna toda a memória
	const unsigned char *getMemory() const;
};

#endif //DATAMEMORY_HPP