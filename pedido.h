#ifndef PEDIDO_H
#define PEDIDO_H

struct pedidos{
    int numero;
    float valor;
    char tipo[100];
};
typedef struct pedidos pedido;

#endif