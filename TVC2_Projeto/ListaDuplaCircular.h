#ifndef LISTA_DUPLA_CIRCULAR_H
#define LISTA_DUPLA_CIRCULAR_H

class NoDuplo;

class ListaDuplaCircular
{
public:
    ListaDuplaCircular ();
    ~ListaDuplaCircular ();

    void insereFinal (int val);
    void imprime ();
    bool vazia ();

    // Questão 3
    int  josephus (int k);

private:
    // Questão 3
    void     remover (NoDuplo *p);
    NoDuplo* voltar  (NoDuplo *p, int n);

    NoDuplo *primeiro;
    NoDuplo *ultimo;
};

#endif // LISTA_DUPLA_CIRCULAR_H
