// HASH.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Diretorio.h"
#include "utils.h"

int numeroBytes;
void randomB(int N,Diretorio* dir,int max){
    srand(max);
    for (int i = 0; i < N; i++)
    {
        
        int k=random(0, max);
        std::string insert=integerToByte(k,numeroBytes);
        dir->insere(insert);


    }
    
}
void randomsB(int N, Diretorio* dir, int max,int ti,std::string inicial) {
    int size;

    for (int i = 0; i < N; i++)
    {
        int k = random(0, max);
        std::string aux=(integerToByte(k,numeroBytes-ti));
        
        std::string inserte =inicial.substr(0, ti); 
        inserte+=aux;
       
        dir->insere(inserte);
    }
}
int main()
{
    int op, n,m,b;
    {
    std::cout << "Digite N para o numero de chaves aleatorias" << std::endl;
    scanf_s("%d", &n);
    while (n < 1) {
        std::cout << "Digite N >= 1" << std::endl;
        scanf_s("%d", &n);
    }
    std::cout << "Digite M para o numero de chaves em um balde" << std::endl;
    scanf_s("%d", &m);
    while (m < 1) {
        std::cout << "Digite M >= 1" << std::endl;
        scanf_s("%d", &m);
    }
    std::cout << "Digite B para o numero de bytes" << std::endl;
    scanf_s("%d", &b);
    while (b < 1) {
        std::cout << "Digite B >= 1" << std::endl;
        scanf_s("%d", &b);
    }
    numeroBytes = b;
    do {
        std::cout << "Digite 1 para N numeros aleatorios e 2 para N numeros aleatorios com mesma sequencia inicial" << std::endl;
        scanf_s("%d", &op);
    } while (op != 1 && op != 2);
    }
    Diretorio dir = Diretorio(numeroBytes,m);
    if(op==1)
    randomB(n, &dir, pow(2, numeroBytes)-1);
    else if (op == 2) {
        int tI = numeroBytes / 3; 
        std::cout << "Digite T para o numero de bytes na sequencia inicial " << std::endl;
        scanf_s("%d", &tI);
        while (tI > numeroBytes ||tI <0) {
            std::cout << "Digite T > 0 e T< B" << std::endl;
            scanf_s("%d", &tI);
        }
        int k = random(0, pow(2, tI) - 1);
        std::string inicial = integerToByte(k,tI);
        randomsB(n, &dir, pow(2, numeroBytes-tI) - 1, tI,inicial);
    }
    dir.printdir();
    std::cout <<"FATOR DE CARGA"<< dir.getFatorCarga()<<" com "<<Balde::idgenerator<<" baldes";
    }


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
