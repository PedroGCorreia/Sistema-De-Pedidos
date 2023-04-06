//Grupo: Pedro Enrico Barchi Nogueira e Pedro Gonçalves Correia
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"interface.h"

void horario(){ //Função criada com base no site linguagemc.com.br
    //Define o fuso horário
    setenv("TZ", "UTC+3", 1);
    tzset();

    // Obtém o horário atual
    time_t horario;
    struct tm *info_horario;
    char hora_formatada[20];
    time(&horario);
    info_horario = localtime(&horario);

    // Formata a hora para exibição
    strftime(hora_formatada, 20, "%H:%M:%S", info_horario);
    printf("Horario: %s\n", hora_formatada);
}

void cabecalho(){
    printf("ABERTURA DO SISTEMA\n");
    horario();
    printf("=====================\n");
}

void opcoes(){
    printf("Codigo das operacoes validas:\n");
    printf("1 - adicionar pedido\n");
    printf("2 - verificar historico de pedidos\n");
    printf("3 - iniciar proximo pedido\n");
    printf("4 - verificar pedidos em andamento\n");
    printf("5 - marcar pedido como concluido\n");
    printf("6 - verificar pedidos concluidos\n");
    printf("0 - fechar sistema\n");
}

void delimitador(){
    printf("=====================\n");
}

void divisor(){
    printf("========\n");
}

void encerrar(float valor, int NaoIniciados, int EmAndamento, int Concluidos){
    printf("=====================\n");
    printf("Quantidade de pedidos nao iniciados: %d\n", NaoIniciados);
    printf("Quantidade de pedidos em andamento: %d\n", EmAndamento);
    printf("Quantidade de pedidos concluidos: %d\n", Concluidos);
    printf("Receita do dia: R$%.2f\n", valor);
    printf("=====================\n");
    printf("FECHAMENTO DO SISTEMA\n");
    horario();
}