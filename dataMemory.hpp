#ifndef DATAMEMORY_HPP
#define DATAMEMORY_HPP

class DataMemory {

private:
  unsigned char memory[65536] = {0};
	int readData;

public:
	DataMemory();
	void executa(int address, int writeData, int memRead, int memWrite);
	int getReadData();
	const unsigned char *getMemory() const;
};


#endif //DATAMEMORY_HPP