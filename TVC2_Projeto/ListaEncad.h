#ifndef LISTAENCAD_H_INCLUDED
#define LISTAENCAD_H_INCLUDED
#include "NoSimples.h"

class ListaEncad
{
public:
    ListaEncad(){primeiro = ultimo = NULL; n = 0;};
    ~ListaEncad();
    void insereFinal(int val);  /// insere um novo No contendo val no final da lista
    void imprime();

    ListaEncad* intercala(ListaEncad *lista);

private:
    NoSimples *primeiro;  /// ponteiro para o primeiro No da lista
    NoSimples *ultimo;    /// ponteiro para o ultimo No da lista
    int n;                /// numero de nos na lista
};
#endif
