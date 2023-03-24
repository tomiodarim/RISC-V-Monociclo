#ifndef CONTROL_HPP
#define CONTROL_HPP

// Unidade responsável por definir os sinais de controle
class Control {

private:
    // Cada variável armazena o valor do sinal de controle de mesmo nome
	int Branch;
	int MemRead;
	int MemToReg;
	int ALUOp;
	int MemWrite;
	int ALUSrc;
	int RegWrite;

public:
    // Construtor da classe
	Control();
    // Define o valor dos sinais com base na instrução que foi passada
	void executa(int input);
    // As funções abaixo retornam o valor das variáveis
	int getBranch();
	int getMemRead();
	int getMemToReg();
	int getAluOp();
	int getMemWrite();
	int getAluSrc();
	int getRegWrite();
};

#endif //CONTROL_HPP