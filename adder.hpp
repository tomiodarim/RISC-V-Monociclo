#ifndef ADDER_HPP
#define ADDER_HPP

class Adder {
private:
	int output;

public:
	Adder();
	void executa(int inputA, int inputB);
	int getOutput();
};

#endif //ADDER_HPP