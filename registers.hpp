#ifndef REGISTERS_HPP
#define REGISTERS_HPP

class Registers {
private:
	unsigned int memory[32] = {0};

	int readData1;
	int readData2;

public:
	Registers();
	void executa(int ReadReg1, int ReadReg2);
	void executa(int WriteReg, int WriteData, int RegWrite);
	const unsigned int *getMemory() const;
	int getReadData1();
	int getReadData2();
};

#endif //REGISTERS_HPP