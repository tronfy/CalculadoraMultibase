#ifndef CALCULADORAMULTIBASE_SOMADORAUNICA_H
#define CALCULADORAMULTIBASE_SOMADORAUNICA_H


class SomadoraUnica {
private:
    int base;
    char soma, carga;
public:
    void somar(char x, char y, char carga, int base);
    char getSoma();
    char getCarga();
};


#endif //CALCULADORAMULTIBASE_SOMADORAUNICA_H
