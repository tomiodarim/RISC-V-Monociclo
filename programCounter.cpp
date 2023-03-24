#include <string>
#include <iostream>
#include "programCounter.hpp"
#include "machine.hpp"

using namespace std;

ProgramCounter::ProgramCounter(){
	this->output = 0;
}

void ProgramCounter::executa(int input) {
	this->output = input;
}

int ProgramCounter::getOutput() {
    return output;
}
