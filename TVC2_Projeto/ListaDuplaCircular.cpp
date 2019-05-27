#include <iostream>
#include <cstdlib>
#include "NoDuplo.h"
#include "ListaDuplaCircular.h"

using namespace std;

// ----------------------------------------------------------------------------
//Q3

void ListaDuplaCircular::remover (NoDuplo *p)
{
    if(primeiro==NULL)
    {
        cout<<"nao pode remover"<<endl;
        exit(1);
    }
    else if(p==primeiro)
    {
        primeiro=p->getProx();
        (primeiro)->setAnt(ultimo);
        (ultimo)->setProx(primeiro);
    }
    else if(p==ultimo)
    {
        ultimo=p->getAnt();
        (ultimo)->setProx(primeiro);
        (primeiro)->setAnt(ultimo);
    }
    else
    {
        (p->getProx()->setAnt(p->getAnt()));
        (p->getAnt()->setProx(p->getProx()));
    }
    delete p;
}

NoDuplo* ListaDuplaCircular::voltar(NoDuplo *p, int n)
{
    NoDuplo*aux;
    int cont=0;
    if(primeiro==NULL)
    {
        cout<<"nao ha nos"<<endl;
        exit(1);
    }
    else
    {
        aux=p;
        while(cont<n)
        {
            aux=aux->getAnt();
            cont++;
        }
    }
    return aux;
}

int ListaDuplaCircular::josephus (int k)
{
    int j;
    if(primeiro==NULL)
    {
        cout<<"impossivel porra"<<endl;
        exit(1);
    }
    else
    {
        NoDuplo*p;
        NoDuplo*aux;
        p=primeiro;
        while(primeiro!=ultimo)
        {
            aux=voltar(p,3);
            p=aux->getProx();
            remover(aux);

        }
        j=p->getInfo();
    }

    return j;
}

//-Q3
// ----------------------------------------------------------------------------
//
// Execução passo a passo do algoritmo de Josephus para o caso de teste desta
// questão, com lista inicial "10 20 30 40 50 60 70 80 90 100" e k = 3.
//
// Lista inicial: 10 20 30 40 50 60 70 80 90 100
// Inicia a partir do primeiro nó: 10
// Volta 3 posições na lista: 10 -> 100 -> 90 -> 80
// Remove o elemento desta posição: 80
//
// Lista atual: 10 20 30 40 50 60 70 90 100
// Reinicia a partir do nó à direita do último removido: 90
// Volta 3 posições na lista: 90 -> 70 -> 60 -> 50
// Remove o elemento desta posição: 50
//
// Lista atual: 10 20 30 40 60 70 90 100
// Reinicia a partir do nó à direita do último removido: 60
// Volta 3 posições na lista: 60 -> 40 -> 30 -> 20
// Remove o elemento desta posição: 20
//
// Lista atual: 10 30 40 60 70 90 100
// Reinicia a partir do nó à direita do último removido: 30
// Volta 3 posições na lista: 30 -> 10 -> 100 -> 90
// Remove o elemento desta posição: 90
//
// Lista atual: 10 30 40 60 70 100
// Reinicia a partir do nó à direita do último removido: 100
// Volta 3 posições na lista: 100 -> 70 -> 60 -> 40
// Remove o elemento desta posição: 40
//
// Lista atual: 10 30 60 70 100
// Reinicia a partir do nó à direita do último removido: 60
// Volta 3 posições na lista: 60 -> 30 -> 10 -> 100
// Remove o elemento desta posição: 100
//
// Lista atual: 10 30 60 70
// Reinicia a partir do nó à direita do último removido: 10
// Volta 3 posições na lista: 10 -> 70 -> 60 -> 30
// Remove o elemento desta posição: 30
//
// Lista atual: 10 60 70
// Reinicia a partir do nó à direita do último removido: 60
// Volta 3 posições na lista: 60 -> 10 -> 70 -> 60
// Remove o elemento desta posição: 60
//
// Lista atual: 10 70
// Reinicia a partir do nó à direita do último removido: 70
// Volta 3 posições na lista: 70 -> 10 -> 70 -> 10
// Remove o elemento desta posição: 10
//
// Lista final: 70

ListaDuplaCircular::ListaDuplaCircular ()
{
    primeiro = NULL;
    ultimo = NULL;
}

ListaDuplaCircular::~ListaDuplaCircular ()
{
    if (!vazia ())
    {
        NoDuplo *prox = primeiro;
        NoDuplo *este;
        do
        {
            este = prox;
            prox = este->getProx ();
            delete (este);
        }
        while (prox != primeiro);
        primeiro = NULL;
        ultimo = NULL;
    }
}

void ListaDuplaCircular::insereFinal (int val)
{
    NoDuplo *novo = new NoDuplo ();
    novo->setInfo (val);

    if (vazia ())
    {
        primeiro = novo;
        ultimo = novo;
    }

    primeiro->setAnt (novo);
    ultimo->setProx (novo);
    novo->setAnt (ultimo);
    novo->setProx (primeiro);
    ultimo = novo;
}

void ListaDuplaCircular::imprime ()
{
    if (vazia ())
    {
        cout << "vazia!" << endl;
        return;
    }

    NoDuplo *prox = primeiro;
    do
    {
        cout << prox->getInfo () << " ";
        prox = prox->getProx ();
    }
    while (prox != primeiro);
    cout << endl;
}

bool ListaDuplaCircular::vazia ()
{
    return (primeiro == NULL && ultimo == NULL);
}
