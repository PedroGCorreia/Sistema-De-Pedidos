//Grupo: Pedro Enrico Barchi Nogueira e Pedro Gonçalves Correia
#ifndef INTERFACE_H
#define INTERFACE_H

//Função que printa a mensagem de abertura do sistema
void cabecalho();
//Função que printa o menu de opções disponíveis para execução do programa
void opcoes();
//Função que printa o horário atual do computador do usuário
void horario();
//Função que printa um separador grande no terminal
void delimitador();
//Função que printa um separador pequeno no terminal
void divisor();
//Função que printa a mensagem de encerramento do sistema com a receita total do dia e quantidade de pedidos não iniciados, em andamento e concluídos
void encerrar(float valor, int NaoIniciados, int EmAndamento, int Concluidos);

#endif