#include <string>
#include <cstring>
#include "dataMemory.hpp"
#include "machine.hpp"

using namespace std;

DataMemory::DataMemory() = default;

void DataMemory::executa(int address, int writeData, int memRead, int memWrite){
	if(memRead) readData = memory[address];
	if(memWrite) memory[address] = writeData;
}

int DataMemory::getReadData() {
    return readData;
}

const unsigned char *DataMemory::getMemory() const {
    return memory;
}