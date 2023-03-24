#ifndef ALUCONTROL_HPP
#define ALUCONTROL_HPP

#define IS_JR_MASK 0x08u

class ALUControl {
private:
  int output;

public:
  ALUControl();
  void executa(int instrucao, int aluop);
  int getOutput();
};


#endif //ALUCONTROL_HPP