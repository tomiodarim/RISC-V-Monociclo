#include <string>
#include <iostream>
#include "multiplexer.hpp"
#include "machine.hpp"

using namespace std;

Multiplexer::Multiplexer() = default;

void Multiplexer::executa(int inputA, int inputB, int inputContol){
	this->output = inputContol ? inputB : inputA;
}

int Multiplexer::getOutput(){
    return output;
}