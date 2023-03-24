#ifndef MULTIPLEXER_HPP
#define MULTIPLEXER_HPP

class Multiplexer {
private:
  int output;

public:
	Multiplexer();
	void executa(int inputA, int inputB, int inputContol);
	int getOutput();
};


#endif //MULTIPLEXER_HPP