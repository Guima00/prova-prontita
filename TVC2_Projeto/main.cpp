// ############################################################################
// TVC 2 -- ESTRUTURA DE DADOS e LABORATORIO DE PROGRAMACAO II
// DATA: 29/10/2018
// PREENCHER ESTE CABECALHO COM SUAS INFORMACOES
// ALUNO(A):
// MATRICULA:
// ############################################################################

#include <iostream>
#include <cstdlib>
#include <cmath>
#include "ListaDuplaCircular.h"
#include "PilhaCont.h"
#include "ListaEncad.h"
#include "MatrizEsparsa.h"
using namespace std;

// ----------------------------------------------------------------------------
//Q1

int fibonacci(int n)
{
    PilhaCont *pilha = new PilhaCont(100);
    if(n<0)
    {
        cout<<"erro"<<endl;
        exit(1);
    }
    int val=0;
    int fib=0;
    pilha->empilha(n);
    while(!pilha->vazia())
    {
        if(pilha->getTopo() != 1 && pilha->getTopo() != 0)
        {
            val=pilha->getTopo();
            pilha->desempilha();
            pilha->empilha(val-1);
            pilha->empilha(val-2);
            val=pilha->getTopo();
        }
        else if(pilha->getTopo()==1)
        {
            fib=fib+1;
            pilha->desempilha();
            if(pilha->vazia())
            {
                return fib;
            }
            val=pilha->getTopo();
        }
        else
            pilha->desempilha();
            if(pilha->vazia())
            {
                return fib;
            }
        val=pilha->getTopo();
    }
    return fib;
}

//-Q1
// ----------------------------------------------------------------------------

int main()
{
    cout << "TVC 2 -- ESTRUTURA DE DADOS e LAB. DE PROG. II" << endl;
    cout << "FAVOR PREENCHER OS SEUS DADOS" << endl;

    // TESTES PARA A QUESTAO 1 ------------------------------------------------
    cout << "TESTES PARA A QUESTAO 1" << endl;

    for(int i=1; i<11; i++)
    {
        cout << "fibonacci(" << i << "): " << fibonacci(i) << endl;
    }
    cout << endl;
    // ------------------------------------------------------------------------

    // TESTES PARA A QUESTAO 2 ------------------------------------------------
    cout << "TESTES PARA A QUESTAO 2" << endl;

    ListaEncad l1, *listaIntercalada, *l2 = new ListaEncad();

    for(int i=1; i<=7; i++)
    {
        l1.insereFinal(2*i+10);
        if(i <= 4)
            l2->insereFinal(3*i - 10);
    }

    cout << "Lista 1: ";
    l1.imprime();
    cout << "Lista 2: ";
    l2->imprime();

    cout << "Intercalacao de l1 com l2: ";
    listaIntercalada = l1.intercala(l2);
    if(listaIntercalada)
    {
        listaIntercalada->imprime();
        delete listaIntercalada;
    }
    else
        cout << "Erro na intercalacao ou operacao não implementada." << endl;

    cout << "Intercalacao de l2 com l1: ";
    listaIntercalada = l2->intercala(&l1);
    if(listaIntercalada)
    {
        listaIntercalada->imprime();
        delete listaIntercalada;
    }
    else
        cout << "Erro na intercalacao ou operacao não implementada." << endl;

    delete l2;

    cout << endl;
    // ------------------------------------------------------------------------

    // TESTES PARA A QUESTAO 3 ------------------------------------------------
    cout << "TESTES PARA A QUESTAO 3" << endl;

    ListaDuplaCircular* ld = new ListaDuplaCircular;
    for (int i = 1; i <=10; i++)
    {
        ld->insereFinal (i * 10);
    }
    cout << "Lista inicial: ";
    ld->imprime ();

    if (ld->josephus (3) != 70)
    {
        cout << "### ERRO Algoritmo de Josephus ERRO ###" << endl;
    }
    cout << "Lista apos Josephus: ";
    ld->imprime ();
    delete ld;

    cout << endl;
    // ------------------------------------------------------------------------

    // TESTES PARA A QUESTAO 4 ------------------------------------------------
    cout << "TESTES PARA A QUESTAO 4" << endl;
    cout << endl;
    cout << "Matriz esperada:" << endl;
    cout << "0\t-4\t0\t0\t0\n0\t3\t0\t0\t0\n0\t0\t0\t5\t0\n0\t0\t0\t0\t0\n2\t0\t0\t0\t0\n" << endl;
    MatrizEsparsa m(5);
    m.insere(2, 3, 5);
    m.insere(1, 1, 3);
    m.insere(0, 1, -4);
    m.insere(4, 0, 2);
    cout << "Matriz gerada pelo TAD:" << endl;
    m.imprime();
    // ------------------------------------------------------------------------

    return 0;
}
