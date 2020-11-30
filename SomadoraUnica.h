#ifndef CALCULADORAMULTIBASE_SOMADORAUNICA_H
#define CALCULADORAMULTIBASE_SOMADORAUNICA_H


class SomadoraUnica {
private:
    int fatorX, fatorY, base, soma, carga;
    void somar();
public:
    void setValores(int x, int y, int base);
    int getSoma();
    int getCarga();
};


#endif //CALCULADORAMULTIBASE_SOMADORAUNICA_H
