#include <iostream>
using namespace std;

struct Nodo {
    int info;
    Nodo* sgte;
};

void Push (Nodo* &pila, int x) {
    Nodo* p = new Nodo();
    p ->info = x;
    p ->sgte = pila;
    pila = p;
    return;
}

int Pop(Nodo* &pila){
    Nodo* p = pila;
    int x = p ->info;
    pila = p ->sgte;
    delete p;
    return x;
}

void encolar (Nodo* &fte, Nodo* &fin, int x){
    Nodo* p = new Nodo();
    p ->info = x;
    p ->sgte = NULL;
    if (fte==NULL) {
        fte = p;
    } else {
            fin ->sgte=p;
    }
    fin=p;
    return;
}

int desencolar (Nodo* &fte, Nodo* &fin){
    Nodo* p = fte;
    int x = p->info;
    fte = p->sgte;
    if (fte==NULL){
        fin==NULL;
    }
    delete p;
    return x;
}

int main()
{
    cout << "-------------------------------------------------------------------" << endl;
    cout << "-------------------------------------------------------------------" << endl;
    //punteros
    cout << "PUNTEROS: " << endl;
    int a = 10;
    int *p = &a;

    cout << a << endl;   //muestra el valor de a, es decir, un entero que almacena el valor 10.
    cout << p << endl;   // muestra el valor de p, es decir, un puntero, una direccion de memoria.
    cout << &a << endl;   // muestra la direccion de memoria
    cout << *p << endl;  // muestra el valor que almacena en la direccion de memoria.


    cout << "-------------------------------------------------------------------" << endl;
    cout << "-------------------------------------------------------------------" << endl;

    //pilas
    cout << "PILAS: " << endl;
    Nodo* Pila = NULL;
    for (int i=1;i<11;i++){
        Push(Pila,i);
    }

    while(Pila !=NULL){
        cout << Pila->info<< endl;
        Pop(Pila);
    }


    cout << "-------------------------------------------------------------------" << endl;
    cout << "-------------------------------------------------------------------" << endl;
    //colas
    cout << "COLAS: " << endl;
    Nodo* fte1 = NULL;
    Nodo* fin1 = NULL;

    for (int i=0;i<5;i++) {
        encolar(fte1,fin1,i);
    }

    while (fte1 && fin1 != NULL) {
        cout << desencolar(fte1,fin1) << endl;
    }

    cout << "-------------------------------------------------------------------" << endl;
    cout << "-------------------------------------------------------------------" << endl;


    return 0;
}
