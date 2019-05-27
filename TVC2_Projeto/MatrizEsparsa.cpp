#include <cstdlib>
#include <iostream>
#include "MatrizEsparsa.h"

using namespace std;

MatrizEsparsa::MatrizEsparsa(int d)
{
    dim = d;
    nmax = dim * dim / 4;
    n = 0;
    linha = new int[nmax];
    coluna = new int[nmax];
    vet = new int[nmax];
}

MatrizEsparsa::~MatrizEsparsa()
{
    delete [] linha;
    delete [] coluna;
    delete [] vet;
}

// ----------------------------------------------------------------------------
//Q4

void MatrizEsparsa::insere(int lin, int col, int val)
{
    int k=busca(lin,col);
    if(k!=-1)
    {
        if(val!=0)
        {
            for(int i=n-1;i>=k;i--){
                linha[i+1]=linha[i];
                coluna[i+1]=coluna[i];
                vet[i+1]=vet[i];
            }
            linha[k]=lin;
            coluna[k]=col;
            vet[k]=val;
            n++;
        }
    }
}

//-Q4
// ----------------------------------------------------------------------------

int MatrizEsparsa::busca(int lin, int col)
{
    int i = 0;

    while(i < n)
    {
        if(lin == linha[i] && col == coluna[i])
            return -1;

        if(lin < linha[i] || (lin == coluna[i] && col < coluna[i]))
            break;

        i++;
    }

    return i;
}

void MatrizEsparsa::imprime()
{
    int k = 0;
    for(int i = 0; i < dim; i++)
    {
        for(int j = 0; j < dim; j++)
        {
            if(i == linha[k] && j == coluna[k])
            {
                cout << vet[k] << '\t';
                k++;
            }
            else
                cout << 0 << '\t';
        }
        cout << endl;
    }
    cout << endl;
}
