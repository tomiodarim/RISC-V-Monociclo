#include <iostream>
#include <cstring>
#include "machine.hpp"
#include "processor.hpp"

using namespace std;

Machine::Machine(char *nomeArq) {
  this->processor = new Processor();
	FILE *f = fopen(nomeArq, "r");
	
	if (!f) exit(1);

	int i;
	auto *instrucoes = (unsigned int *) (malloc(255 * sizeof(unsigned int)));
	char buff[255];
	int aux;

	for (i = 0; !feof(f); i++) {
		fgets(buff, 255, f);
		instrucoes[i] = lerInstrucao(buff);
	}

	processor->inicializa(instrucoes);
}

void Machine::clock() {
  cout << "================================================\n";
  processor->executa();
  cout << "------------------Registradores-----------------\n";
  processor->printRegistradores();
  cout << "---------------------Memoria-------------------\n";
  processor->printMemoria();
	cout << "-----------------------------------------------\n";
}

unsigned int Machine::lerInstrucao(const char *str) {
  unsigned int res = 0, aux = 1u;
  int i;

  for (i = 31; i >= 0; --i, aux <<= 1u) {
    res |= (str[i] - '0') ? aux : 0;
  }

  return res;
}