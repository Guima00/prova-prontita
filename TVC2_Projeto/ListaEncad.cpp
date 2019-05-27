#include <iostream>
#include <cstdlib>
#include "ListaEncad.h"
#include "NoSimples.h"

using namespace std;

// ----------------------------------------------------------------------------
//Q2

ListaEncad* ListaEncad::intercala(ListaEncad *lista)
{
    ListaEncad *listanova = new ListaEncad();
    NoSimples*p=primeiro;
    NoSimples*p2=lista->primeiro;
    int cont1=0,cont2=0;
    while((cont1+cont2)<(lista->n+n))
    {
        if((cont1==cont2 && p!=NULL) ||p2==NULL)
        {
            listanova->insereFinal(p->getInfo());
            p=p->getProx();
            cont1++;
        }
        else if((cont1>cont2 && p2!=NULL)||p==NULL)
        {
            listanova->insereFinal(p2->getInfo());
            p2=p2->getProx();
            cont2++;

        }
        listanova->n=listanova->n+1;

    }

    return listanova;
}

//-Q2
// ----------------------------------------------------------------------------

ListaEncad::~ListaEncad()
{
    NoSimples *p = primeiro;
    while(p != NULL)
    {
        NoSimples *t = p->getProx();
        delete p;
        p = t;
    }
}

void ListaEncad::imprime ()
{
    cout << endl;

    NoSimples *noAtual = primeiro;
    if (noAtual == NULL) {
        cout << "Lista simplesmente encadeada vazia!" << endl;
        return;
    }

    while(noAtual != NULL)
    {
        cout << noAtual->getInfo () << " ";
        noAtual = noAtual->getProx ();
    }
    cout << endl;
}

void ListaEncad::insereFinal(int val)
{
    NoSimples* p = new NoSimples();
    p->setInfo(val);
    p->setProx(NULL);

    if(ultimo != NULL)
        ultimo->setProx(p);
    ultimo = p;

    n++;
    if(n == 1)
        primeiro = p;
}
