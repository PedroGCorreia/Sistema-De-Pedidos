//Grupo: Pedro Enrico Barchi Nogueira e Pedro Gonçalves Correia
#include<stdlib.h>
#include"pedido.h"
#include"lista.h"

void CriaLista(lista *l, int (*igual)(T,T)){
    l->sentinela = (Node*)malloc(sizeof(Node));
    l->sentinela->prox = l->sentinela;
    l->sentinela->ant = l->sentinela;
    l->quantidade = 0;
    l->igual = igual;
}

int ListaVazia(lista *l){
    return l->sentinela->prox == l->sentinela; //Se o próximo elemento do sentinela, for o sentinela, quer dizer que a lista está vazia, com isso a função retorna verdadeiro
}

int TamanhoLista(lista *l){
    return l->quantidade; //Retorna a quantidade de elementos da lista
}

void InserirFim(lista *l, T p){
    Node *n = (Node*)malloc(sizeof(Node)); //Aloca o espaço do novo nó
    n->dados = p; //Entrada dos dados
    n->prox = l->sentinela; //Como é inserido antes do sentinela, o sucessor do nó é o sentinela
    n->ant = l->sentinela->ant; //O antecessor dele é o antigo anterior do sentinela
    l->sentinela->ant->prox = n; //O elemento que era o anterior do sentinela, agora tem o nó como sucessor
    l->sentinela->ant = n; //O anterior do sentinela agora é o nó
    l->quantidade++; //Aumenta a quantidade da lista em 1
}

void RemoverInicio(lista *l){
    if(ListaVazia(l)) return; //Se a lista estiver vazia, não pode remover
    Node *n = l->sentinela->prox; //Nó auxiliar que recebe o elemento que será removido
    l->sentinela->prox = n->prox; //O sentinela próximo agora aponta pra o sucessor do elemento que foi removido
    n->prox->ant = l->sentinela; //O elemento que era o sucessor do nó removido, agora recebe o sentinela como seu antecessor
    free(n); //Desaloca o elemento a ser removido
    l->quantidade--; //Decrementa a quantidade em 1
}

iterador PrimeiroLista(lista *l){
    iterador i;
    i.elemento = l->sentinela->prox; //O iterador pega o primeiro elemento da lista
    i.lista = l;
    return i; //Retorna o iterador com o primeiro elemento da lista
}

iterador ProximoLista(iterador i){
    iterador p;
    p.elemento = i.elemento->prox; //Coloca no iterador p o próximo elemento em relação ao iterador i
    p.lista = i.lista;
    return p; //Retorna o iterador com o próximo elemento
}

int ValidoLista(iterador i){
    return i.elemento != i.lista->sentinela; //Retorna verdadeiro se o elemento não for o sentinela, ou seja, contém algo
}

iterador BuscaLista(iterador i, T p){
    while(ValidoLista(i)){
        if(i.lista->igual(i.elemento->dados,p)){ //Utiliza um ponteiro de função para comparar um elemento da lista com base no iterador com o parâmetro p
        return i; //Retorna o elemento da lista que for igual
        }
        i = ProximoLista(i); //Incremento do iterador
    }
    return i; //Retorna o iterador com o elemento se ele foi encontrado na lista, se não retorna um iterador inválido
}

iterador RetiraLista(iterador i){
    if(ValidoLista(i)){ //Se o elemento for valido, irá fazer a remoção na posição desejada
        Node *p = i.elemento;
        i.elemento = i.elemento->prox; //Elemento do iterador recebe o próximo
        p->prox->ant = p->ant; //Ponteiro anterior do elemento seguinte deve ser mudado para ser o anterior do elemento atual, que será removido
        p->ant->prox = p->prox; //Ponteiro próximo do elemento anterior deve ser mudado para ser o próximo do elemento atual, que será removido
        free(p); //Desaloca o nó referente ao elemento
        i.lista->quantidade--; //Decrementa a quantidade de elementos da lista    
    }
    return i;
}

T ElementoLista(iterador i){
    return i.elemento->dados; //Retorna os dados de um elemento específico da lista
}

void DestroiLista(lista *l){
    while(!ListaVazia(l)) //Enquanto a lista não estiver vazia, faremos uma remoção até que ela fique sem elementos
        RemoverInicio(l);
    free(l->sentinela); //Desaloca o sentinela, pois ele não é removido da lista no while acima
}