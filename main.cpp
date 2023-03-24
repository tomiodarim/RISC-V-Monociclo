#include <iostream>
#include "machine.hpp"

int main(int argc, char *argv[]) {
    std::cout << "\nTrabalho de Organização e Arquitetura de Computadores\n";
	std::cout << "Máquina Virtual RISC-V Monociclo\n";
	std::cout << "Lucas Tomio Darim\n\n";

    // Caso não tenha sido passado o arquivo de instruções
	if(argc < 1) {
		std::cout << "Modo de uso: \"./riscv instrucoes.txt\"\n";
		return 1;
	}

    // Cria a máquina virtual
    Machine *machine = new Machine(argv[1]);
	char ch;

	std::cout << "Digite n para próximo ciclo ou q para sair.";
	std::cin >> ch;

    // Executa as instruções quando o usuário inseri 'n' até que o arquivo acabe ou este insira 'q'
	while(ch != 'q') {
		if(ch == 'n')
			machine->clock();
		std::cin >> ch;
	}

  return 0;
}
