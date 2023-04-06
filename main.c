//Grupo: Pedro Enrico Barchi Nogueira e Pedro Gonçalves Correia
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"pedido.h"
#include"interface.h"
#include"fila.h"
#include"lista.h"

int igual(pedido p1, pedido p2);
void FecharSistema(float receita, fila i, lista *a, fila c);
int AdicionarPedido(fila i, pedido p, float receita, int ContPedidos);
void HistoricoDePedidos(fila i, lista *a, fila c, pedido p);
void AdicionarListaEmAndamento(fila i, lista *a, fila c, pedido p);
void MostrarPedidosEmAndamento(lista *a, pedido p);
void MarcarComoConcluido(lista *a, fila c, pedido p);
void MostrarPedidosConcluidos(fila c, pedido p);

int main() {
    int pedidos=0; //Variável pedidos conta a quantidade de pedidos concluídos
    int NaoIniciados=0; //Variável NaoIniciados conta a quantidade de pedidos não iniciados
    int Andamento=0; //Variável Andamento conta a quantidade de pedidos em andamento
    int operacao=0;//Variável operação recebe qual será a ação a ser executada
    int ContPedidos=1; //Contador que gera o número de pedidos automaticamente
    float receita=0; //Variável que calcula o total arrecadado no dia
    pedido p; //Estrutura do tipo pedido que será usada para receber e passar dados
    fila i = CriaFila(); //Inicialização da fila i para colocar os pedidos não iniciados
    fila c = CriaFila(); //Inicialização da fila c para colocar os pedidos concluídos
    lista a; //Variável a é usada para lista com os pedidos em andamento
    CriaLista(&a,igual); //Inicializa a lista de pedidos em andamento
    
    cabecalho(); //Printa a abertura do sistema
    opcoes(); //Printa as opções disponíveis para utilização no sistema

    do {

        delimitador();
        printf("Digite o codigo da operacao desejada: ");
        scanf("%d", &operacao); //Entrada da operação a ser realizada
        
        switch(operacao){
        case 0: //Caso em que a primeira operacao é para fechar o sistema
            break;
        case 1: //Caso para adicionar um pedido
            receita = AdicionarPedido(i,p,receita,ContPedidos++); //Receita recebe a função, pois ela realiza a entrada do pedido e retorna o total em caixa com a adição desse novo pedido
            break;
        case 2: //Caso para verificar o histórico de pedidos
            HistoricoDePedidos(i,&a,c,p);
            break;
        case 3: //Caso para adicionar pedido na lista em andamento
            AdicionarListaEmAndamento(i,&a,c,p);
            break;
        case 4: //Caso para verificar os pedidos em andamento
            MostrarPedidosEmAndamento(&a,p);
            break;
        case 5: //Caso para marcar pedido como concluído
            MarcarComoConcluido(&a,c,p);
            break;
        case 6: //Caso para verificar os pedidos concluídos
            MostrarPedidosConcluidos(c,p);
            break;
        default: //Caso das operações não abrangidas pelo sistema
            printf("Operacao invalida!\n");
            break;
        }
        
    } while(operacao != 0);

    //Caso da operação igual a 0, ou seja, o sistema é fechado
    if(operacao == 0){
        FecharSistema(receita,i,&a,c);
    }

    DestroiFila(i); //Destrói fila dos pedidos não iniciados
    DestroiLista(&a); //Destrói lista dos pedidos em andamento
    DestroiFila(c); //Destrói fila dos pedidos concluídos
    
    return(0);
}

int igual(pedido p1, pedido p2){ //Função que será passada para lista com o intuito de manter o encapsulamento da estrutura
  return p1.numero == p2.numero;  
}

void FecharSistema(float receita, fila i, lista *a, fila c){
    int NaoIniciados = TamanhoFila(i); //Naoiniciados recebe o total de pedidos não iniciados
    int Andamento = TamanhoLista(a); //Andamento recebe o total de pedidos em andamento
    int pedidos = TamanhoFila(c); //Pedidos recebe o total de pedidos concluídos 
    encerrar(receita,NaoIniciados,Andamento,pedidos); //Printa o fechamento do sistema com o valor arrecadado e o total de pedidos realizados no dia e seus estados
}

int AdicionarPedido(fila i, pedido p, float receita, int ContPedidos){
    delimitador();
    p.numero = ContPedidos; //Marca qual será o número do pedido automaticamente
    printf("Pedido #%d\n", p.numero);
    printf("Insira o tipo do pedido: ");
    scanf("\n%100[^\n]", p.tipo); //Entrada do tipo de pedido
    printf("Insira o preco do pedido: ");
    scanf("%f", &p.valor); //Entrada do preço do pedido
    receita += p.valor; //Adiciona o valor para sabermos o total arrecadado no dia
    InsercaoFila(i,p); //Insere na fila de pedidos não iniciados
    printf("O pedido foi realizado com sucesso!\n");
    return receita; //Retorna a variavel receita para verificar o total arrecadado ao fim do programa
}

void HistoricoDePedidos(fila i, lista *a, fila c, pedido p){
    printf("\nHISTORICO DE PEDIDOS\n\n");
    printf("1. Pedidos nao iniciados:\n");
    //Loop para imprimir a fila de pedidos não iniciados
    for(int j=Inicio(i); j != Final(i); j++){
        p = Elemento(i,j);
        divisor();
        printf("Pedido: %d\n", p.numero);
        printf("Preco: %.2f\n", p.valor);
        printf("Descricao: %s\n", p.tipo);  
    }
    divisor();
    printf("\n");
    printf("2. Pedidos em andamento:\n");
    //Loop para imprimir a lista de pedidos em andamento com o uso do iterador
    for(iterador it = PrimeiroLista(a); ValidoLista(it); it = ProximoLista(it)){
        p = ElementoLista(it);
        divisor();
        printf("Pedido: %d\n", p.numero);
        printf("Preco: %.2f\n", p.valor);
        printf("Descricao: %s\n", p.tipo);  
    }
    divisor();
    printf("\n");
    printf("3. Pedidos concluidos:\n");
    //Loop para imprimir a fila de pedidos concluídos
    for(int j=Inicio(c); j != Final(c); j++){
        p = Elemento(c,j);
        divisor();
        printf("Pedido: %d\n", p.numero);
        printf("Preco: %.2f\n", p.valor);
        printf("Descricao: %s\n", p.tipo);  
    }
    divisor();
    printf("\n");
}

void AdicionarListaEmAndamento(fila i, lista *a, fila c, pedido p){
    if(FilaVazia(i) && ListaVazia(a) && FilaVazia(c)){ //Se todas as filas forem vazias, não foi realizado nenhum pedido
        printf("Nenhum pedido foi realizado.\n");
        printf("Por favor, selecione a tecla 1 para adicionar novos pedidos.\n");
    } else if(FilaVazia(i) && (!ListaVazia(a) || !FilaVazia(c))){ //Se as fila de pedidos não iniciados for vazia e uma das demais não for, temos pedidos, porém nenhum pode ser iniciado
        printf("Todos os pedidos ja estao em andamento ou foram concluidos.\n");
        printf("Por favor, selecione a tecla 1 para adicionar novos pedidos.\n");
    } else { //Caso em que o pedido pode ser iniciado
        p = PrimeiroElemento(i); //Pega o primeiro elemento não iniciado, pois ele será o primeiro que deve ser preparado com base na ordem de chegada dos pedidos
        RemocaoFila(i); //Remove esse elemento da fila de pedidos não iniciados
        InserirFim(a,p); //Insere o elemento que foi removido da fila na lista de pedidos em andamento
        printf("O pedido #%d foi iniciado!\n", p.numero);
    }
}

void MostrarPedidosEmAndamento(lista *a, pedido p){
    if(ListaVazia(a)){ //Se a fila for vazia, não existem pedidos em andamento
        printf("Ainda nao temos pedidos em andamento.\n");
    } else {
        printf("\nPEDIDOS EM ANDAMENTO\n");
        //Loop para imprimir a lista de pedidos em andamento com o uso do iterador
        for(iterador it = PrimeiroLista(a); ValidoLista(it); it = ProximoLista(it)){
        p = ElementoLista(it);
        divisor();
        printf("Pedido: %d\n", p.numero);
        printf("Preco: %.2f\n", p.valor);
        printf("Descricao: %s\n", p.tipo);  
        }
        divisor();
        printf("\n");
    }
}

void MarcarComoConcluido(lista *a, fila c, pedido p){
    printf("Pedido que foi concluido: ");
    scanf("%d", &p.numero); //Elemento que será concluído
    iterador b = BuscaLista(PrimeiroLista(a),p); //Busca o pedido que será concluído na lista da pedidos em andamento
    if(ValidoLista(b)){ //Se o pedido realmente estiver em andamento
        p = ElementoLista(b); //Busca as informações do pedido concluído na lista
        InsercaoFila(c, p); //Insere esse pedido na fila de pedidos concluídos
        RetiraLista(b); //Remove da lista de pedidos em andamento
        printf("O pedido #%d foi concluido com sucesso!\n", p.numero);
    } else { //Caso em que o elemento não foi iniciado ou encontrado
        printf("O pedido desejado, nao esta em andamento.\nPor favor, verifique os pedidos em andamento, utilizando a tecla 4 e tente novamente.\n");
    }
}

void MostrarPedidosConcluidos(fila c, pedido p){
    if(FilaVazia(c)){ //Verifica se a fila contendo os pedidos concluídos contém algo
        printf("Ainda nao temos pedidos concluidos.\n");
    } else {
        printf("\nPEDIDOS CONCLUIDOS\n");
        //Loop para imprimir a fila de pedidos concluídos
        for(int j=Inicio(c); j != Final(c); j++){
          p = Elemento(c,j);
          divisor();
          printf("Pedido: %d\n", p.numero);
          printf("Preco: %.2f\n", p.valor);
          printf("Descricao: %s\n", p.tipo);  
        }
        divisor();
        printf("\n");
    }
}