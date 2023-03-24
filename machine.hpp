#ifndef MACHINE_HPP
#define MACHINE_HPP

class Machine {
private:
  class Processor *processor;

public:
  Machine(char *nomeArq);
  void clock();
  static unsigned int lerInstrucao(const char str[255]);
};

#endif //MACHINE_HPP