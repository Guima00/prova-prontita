#ifndef NO_H_INCLUDED
#define NO_H_INCLUDED

class NoSimples
{
private:
    int info; /// valor armazenado no No
    NoSimples *prox; /// ponteiro para o proximo No
public:
    NoSimples()                  { };
    ~NoSimples()                 { };
    int getInfo()                { return info; };
    NoSimples* getProx()         { return prox; };
    void setInfo(int val)        { info = val; };
    void setProx(NoSimples *p)   { prox = p; };
};
#endif // NO_H_INCLUDED
