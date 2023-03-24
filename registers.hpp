#ifndef REGISTERS_HPP
#define REGISTERS_HPP

// Unidade responsável por armazenar os registradores
class Registers {
private:
    // Vetor para armazenar os 32 registradores
	unsigned int memory[32] = {0};

    // Saida com o valor armazenado nos registradores
	int readData1;
	int readData2;

public:
    // Contrutor da classe
	Registers();
    // Envia para os ReadData o valor armazenado nos registradores informados
	// Requer como entrada quais registradores serão lidos
    void executa(int ReadReg1, int ReadReg2);
    // Escreve um dado a um regitrado se a flag for 1
    // Requer o registrador a ser escritor, o dado e a flag
	void executa(int WriteReg, int WriteData, int RegWrite);
    // Retorna o vetor com todos os registradores
	const unsigned int *getMemory() const;
    // Retorna o valor de readData1
	int getReadData1();
    // Retorna o valor de readData2
	int getReadData2();
};

#endif //REGISTERS_HPP