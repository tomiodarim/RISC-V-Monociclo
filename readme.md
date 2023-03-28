# RISC-V Monociclo

Esse projeto foi um trabalho para a disciplina de Organização e Arquitetura de Computadores do curso de Ciência da Computação. Sendo desenvolvido para consolidar os conhecimentos adquiridos sobre a arquitetura RISC-V Monociclo.

Essa implementação é capaz de realizar as instruções add, sub, and, or, lw, sw, beq e bne. Para mais detalhes ver o PDF do relatório.

### Instalação

Primeiramente clone o repositório no local em que achar adequado com o comando:

```bash
git clone https://github.com/tomiodarim/RISC-V-Monociclo.git
```

Em seguida, execute o comando "make" no diretório clonado:

```bash
cd RISC-V-Monociclo
make
```

### Uso 

Para iniciar o programa, execute o arquivo "riscv" seguido do caminho para o arquivo contendo as instruções:

```bash
./riscv <arquivo/de/instruções>
```

Para executar um ciclo na máquina, digite "n". Para sair do programa, digite "q".

### Saída

A cada ciclo da máquina, será impresso na tela o output de cada uma das unidades do processador na sequência em que são executadas, seguidos pelos registradores e memória com conteúdo diferente de zero.
