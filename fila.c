// Grupo: Pedro Enrico Barchi Nogueira e Pedro Gonçalves Correia
#include"fila.h"
#include"pedido.h"
#include<stdlib.h>

fila CriaFila(){
    fila f = (fila)malloc(sizeof(struct Fila)); //Alocação de memória para criação da fila
    f->inicio = 0;
    f->fim = 0;
    f->quantidade = 0;
    f->max = INICIAL; //Colocamos o max como sendo a quantidade máxima de elementos suportada pelo vetor naquele momento e ele recebe inicial, pois esse seria o tamanho base do vetor
    f->dados = (T*)malloc(f->max*sizeof(T)); //Alocamos um vetor para suportar uma quantidade base de elementos, sendo que esse será realocado ao longo do programa se necessário
    return f; //Retorno do endereço onde foi alocado a fila
}

int FilaVazia(fila f){
    return f->quantidade == 0; //Retorna verdadeiro se a fila estiver vazia
}

int FilaCheia(fila f){
    return f->quantidade == f->max; //Retorna verdadeiro se a fila estiver cheia, mostrando que o valor máximo suportado foi atingido
}

unsigned TamanhoFila(fila f){
    return f->quantidade; //Retorna a quantidade de elementos da fila
}

void InsercaoFila(fila f, T p){
    if (FilaCheia(f)) { //Se a fila estiver cheia, é necessário redimensionar o tamanho do vetor para alocar os novos elementos
        T *n = (T *)realloc(f->dados, 2 * f->max * sizeof(T)); //Redimensionamos o vetor com o dobro do tamanho atual, a fim de diminuir a quantidade de realocações
        f->dados = n; //Coloca o vetor realocado para o vetor original
        f->max = 2 * f->max; //Atualização do máximo de elementos suportado pelo vetor
    }
    f->dados[f->fim] = p; //Coloca as informações do pedido na posição final do vetor
    f->fim++; //O índice do último elemento agora é referente a posição do elemento que foi inserido
    f->quantidade++; //Incremento da quantidade de elementos da fila
}

void RemocaoFila(fila f){
    if (FilaVazia(f)) return; //Não pode fazer uma remoção na fila vazia
    f->inicio++; //O ínicio agora avança uma posição no vetor já que ele precisa tirar o elemento removido do alcance dos ponteiros do vetor
    f->quantidade--; //Decrementa a quantidade de elementos da fila
}

T Elemento(fila f, int i){
    return f->dados[i]; //Retorna os dados do primeiro elemento da fila
}

int Inicio(fila f){ 
    return f->inicio; //Retorna o índice da posição inicial do vetor
}

int Final(fila f){ 
    return f->fim; //Retorna o índice da posição do elemento final do vetor + 1
}

T PrimeiroElemento(fila f){
    return f->dados[f->inicio]; //Retorna os dados do primeiro elemento do vetor
}

void DestroiFila(fila f){
    free(f->dados); //Desaloca todo o vetor utilizado pela fila
    free(f); //Desaloca a memória usada pela estrutura da fila
}