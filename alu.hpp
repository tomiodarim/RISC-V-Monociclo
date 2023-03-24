#ifndef ALU_HPP
#define ALU_HPP

// Unidade responsável por executar a soma, subtração, and e or
class ALU {
private:
    // Armazena o resultado da operação
	int output;
    // Armazena se o resultado foi 0 ou não
    // 0 para output com valor diferente de zero
    // 1 para output com valor igual a zero
	int zero;

public:
    // Construtor da classe
	ALU();
    // Executa a operação informada por inputControl em inputA e inputB
    // Requer três inputs, sendo dois operandos e a operação
    // O resultado da operação é armazenado na variável output
	void executa(int inputA, int inputB, int inputControl);
    // Retorna o valor de output
	int getOutput();
    // Retorna o valor da flag zero
	int getZero();
};


#endif //ALU_HPP