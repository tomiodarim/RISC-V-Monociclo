#ifndef CONTROL_HPP
#define CONTROL_HPP

class Control {

private:
	int Branch;
	int MemRead;
	int MemToReg;
	int ALUOp;
	int MemWrite;
	int ALUSrc;
	int RegWrite;

public:
	Control();
	void executa(int input);
	int getBranch();
	int getMemRead();
	int getMemToReg();
	int getAluOp();
	int getMemWrite();
	int getAluSrc();
	int getRegWrite();
};


#endif //CONTROL_HPP