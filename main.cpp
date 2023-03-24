#include <iostream>
#include "machine.hpp"

using namespace std;

int main(int argc, char *argv[]) {
	cout << "\nTrabalho de Organização e Arquitetura de Computadores\n";
	cout << "Máquina Virtual RISC-V Monociclo\n";
	cout << "Lucas Tomio Darim\n\n";

	if(argc < 1) {
		cout << "Modo de uso: \"./riscv instrucoes.txt\"\n";
		return 1;
	}

  Machine *machine = new Machine(argv[1]);
	char ch;

	cout << "Digite n para próximo ciclo ou q para sair.";
	cin >> ch;

	while(ch != 'q') {
		if(ch == 'n')
			machine->clock();
		cin >> ch;
	}

  return 0;
}
