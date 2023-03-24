#ifndef ALU_HPP
#define ALU_HPP

#define AND 0
#define OR 1
#define SUM 2
#define SUB 6

class ALU {
private:
	int output;
	int zero;

public:
	ALU();
	void executa(int inputA, int inputB, int inputControl);
	int getOutput();
	int getZero();
};


#endif //ALU_HPP