#include "dataMemory.hpp"

// Construtor padrão da classe
DataMemory::DataMemory() = default;

// Executa a leitura e escrita na memória
// Requer o endereço da memória, o dado para ser escrito e duas flags quer determinam se vai escrever ou ler
void DataMemory::executa(int address, int writeData, int memRead, int memWrite){
	if(memRead) readData = memory[address];
	if(memWrite) memory[address] = writeData;
}

// Retorna o valor de ReadData
int DataMemory::getReadData() {
    return readData;
}

// Retorna toda a memória
const unsigned char *DataMemory::getMemory() const {
    return memory;
}