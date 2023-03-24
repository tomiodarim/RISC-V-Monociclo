#include <string>
#include <iostream>
#include "adder.hpp"
#include "machine.hpp"

using namespace std;

Adder::Adder() = default;

void Adder::executa(int inputA, int inputB) {
	this->output = inputA + inputB;
}

int Adder::getOutput() {
    return output;
}
