#ifndef LISTA_CONT
#define LISTA_CONT

class MatrizEsparsa
{
    private:
        int *linha;
        int *coluna;
        int *vet;
        int nmax;
        int n;
        int dim;
    
    public:
        MatrizEsparsa(int d);
        ~MatrizEsparsa();
        int busca(int lin, int col);
        void insere(int lin, int col, int val);
        void imprime();
};

#endif