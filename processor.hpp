#ifndef PROCESSOR_HPP
#define PROCESSOR_HPP


#include "programCounter.hpp"
#include "adder.hpp"
#include "instructionMemory.hpp"
#include "control.hpp"
#include "multiplexer.hpp"
#include "registers.hpp"
#include "immGen.hpp"
#include "aluControl.hpp"
#include "alu.hpp"
#include "dataMemory.hpp"

// Classe que simulara o processador da máquina virtual
// Essa classe posuirá cada uma das unidades necessárias
class Processor{
public:
    /* Todas as unidades presentes na arquitetura RISC-V monociclo
     *
     * adder1 é o adder que soma o valor de pc com 4
     * adder2 soma pc com o immediate
     *
     * mux1 é o que está entre registers e a alu, escolhe a fonte dos dados da alu
     * mux2 é o que utiliza o valor de zero e escolhe se vai fazer branch
     * mux3 é o que escolhe qual dos somadores será retornado para o pc
     * mux4 é o que está após a memória de dados, escolhe entre dados da memória ou da alu
     */
	ProgramCounter *pc = new ProgramCounter();
	Adder *adder1 = new Adder();
	InstructionMemory *instructionMemory = new InstructionMemory();
	Control *control = new Control();
	Registers *registers = new Registers();
	ImmGen *immgen = new ImmGen();
	Multiplexer *mux1 = new Multiplexer();
	Adder *adder2 = new Adder();
	ALU *alu = new ALU();
	ALUControl *aluControl = new ALUControl();
	Multiplexer *mux2 = new Multiplexer();
	Multiplexer *mux3 = new Multiplexer();
	DataMemory *dataMemory = new DataMemory();
	Multiplexer *mux4 = new Multiplexer();

public:
    // Construtor da classe
	Processor();
    // Passa para a InstructionMemory as instruções lidas do arquivo
    // Requer um vetor de inteiros com as instruções
	void inicializa(unsigned int *instructionMemoryRef);
    // Executa um clock
	void executa();
    // Imprime o valor dos registradores com contrúdos diferentes de zero
	void printRegistradores();
    // Imprime o valor de memória de dados com conteúdos diferentes de zero
	void printMemoria();
};

#endif //PROCESSOR_HPP