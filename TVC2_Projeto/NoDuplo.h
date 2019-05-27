#ifndef NO_DUPLO_H
#define NO_DUPLO_H

class NoDuplo
{
public:
    NoDuplo  () {}
    ~NoDuplo () {}
    
    int      getInfo () { return info; }
    NoDuplo* getProx () { return prox; }
    NoDuplo* getAnt  () { return ant; }

    void setInfo (float val)  { info = val; }
    void setProx (NoDuplo *p) { prox = p; }
    void setAnt  (NoDuplo *p) { ant = p; }

private:
    int     info;
    NoDuplo *prox;
    NoDuplo *ant;
};

#endif // NO_DUPLO_H
