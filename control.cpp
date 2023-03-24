#include "control.hpp"
#include "machine.hpp"
#include <iostream>
#include <string>

using namespace std;

Control::Control() = default;

void Control::executa(int input) {
  switch (input) {
  case 51:
    cout << "      Instrução do Tipo R" << endl;
		this->Branch = 0;
		this->MemRead = 0;
		this->MemToReg = 0;
		this->ALUOp = 2;
		this->MemWrite = 0;
		this->ALUSrc = 0;
		this->RegWrite = 1;
    break;

  case 19:
    cout << "      Instrução ADDI" << endl;
		this->Branch = 0;
		this->MemRead = 0;
		this->MemToReg = 0;
		this->ALUOp = 0;
		this->MemWrite = 0;
		this->ALUSrc = 1;
		this->RegWrite = 1;
    break;

  case 3:
    cout << "      Instrução LW" << endl;
		this->Branch = 0;
		this->MemRead = 1;
		this->MemToReg = 1;
		this->ALUOp = 0;
		this->MemWrite = 0;
		this->ALUSrc = 1;
		this->RegWrite = 1;
    break;

  case 35:
    cout << "      Instrução SW" << endl;
		this->Branch = 0;
		this->MemRead = 0;
		this->MemToReg = 0;
		this->ALUOp = 0;
		this->MemWrite = 1;
		this->ALUSrc = 1;
		this->RegWrite = 0;
    break;

  case 99:
    cout << "      Instrução do Tipo B" << endl;
		this->Branch = 1;
		this->MemRead = 0;
		this->MemToReg = 0;
		this->ALUOp = 1;
		this->MemWrite = 0;
		this->ALUSrc = 0;
		this->RegWrite = 0;
    break;
  }
}

int Control::getBranch(){ return Branch; }

int Control::getMemRead(){ return MemRead; }

int Control::getMemToReg(){ return MemToReg; }

int Control::getAluOp(){ return ALUOp; }

int Control::getMemWrite(){ return MemWrite; }

int Control::getAluSrc(){ return ALUSrc; }

int Control::getRegWrite(){ return RegWrite; }