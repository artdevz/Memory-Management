# Trabalho 2 - Sistemas Operacionais

## Assunto
Este trabalho aborda a simulação de algoritmos de substituição de páginas em memória virtual. O objetivo é comparar o comportamento e desempenho dos algoritmos FIFO (First-In-First-Out) e Aging (Envelhecimento) frente a diferentes sequências de referências e quantidades de molduras de páginas disponíveis.

## Professor
Prof. Daniel Silva Ferreira

## Equipe
- Arthur Dantas Lacerda Silva Patrício
- Bruno Costa Diniz Leandro
- Guilherme Amaro Clarindo
- Rafael Jorge Cabral Cardoso

## Questão – Comparação de Algoritmos de Substituição de Página

### Objetivo
Comparar o número de faltas de página dos algoritmos FIFO e Aging em diferentes cenários de execução, considerando conjuntos de trabalho de processos distintos.

### Detalhes da Simulação
- Implementação modular com classes separadas para os algoritmos.
- Entrada: número de molduras de páginas (via linha de comando).
- Sequência de referências simulando diferentes processos, gerada automaticamente e salva em references.txt.
- Para cada algoritmo e número de molduras:
  - Cálculo do número total de faltas de página.
  - Relatório com faltas por 1000 acessos.

### Componentes

- FIFO.cpp / FIFO.hpp: implementação do algoritmo FIFO.
- Aging.cpp / Aging.hpp: implementação do algoritmo de envelhecimento.
- ReferenceGenerator.cpp / ReferenceGenerator.hpp: geração de sequências de referência com base em conjuntos de trabalho.
- main.cpp: orquestra a execução da simulação, comparando os algoritmos.
- Makefile: compila automaticamente o projeto e organiza os binários.

### Execução
Para compilar e rodar o projeto:
```bash
make
./bin/MemoryManagement
``` 

---
