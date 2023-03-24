#ifndef ALUCONTROL_HPP
#define ALUCONTROL_HPP

// Unidade responsável por definir a operação que será executada pela ALU
class ALUControl {
private:
    // Armazena o código da operação
    int output;

public:
    // Construtor da classe
    ALUControl();
    // Define o código da operação a partir da instrução e do ALUOp
    void executa(int instrucao, int aluop);
    // Retorna o valor de output
    int getOutput();
};

#endif //ALUCONTROL_HPP