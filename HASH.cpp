// HASH.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Diretorio.h"
#include "utils.h"
#include <cmath>
#include "stdio.h"

int numeroBytes;
void randomB(int N,Diretorio* dir,int max){
    srand((int) &dir);
    for (int i = 0; i < N; i++)
    {
        
        std::string insert;
        
        do {
            int k = random(0, max);
            insert = integerToByte(k, numeroBytes);
        } while (false);
            dir->insere(insert);
        

    }

}
// para a comparação ser feita de uma forma justa, é garantido que sempre serão geradas n entradas unicas
// caso contratrio usando um gerador aleatorio, a chance de uma chave aleatoria ja esta presente é muito maior no teste 2 com bites iniciais iguais
// portanto sempre terá menos registros na tabela
void randomsB(int N, Diretorio* dir, int max,int ti,std::string inicial) {
    int size;

    for (int i = 0; i < N; i++)
    {

        std::string insert;

        do {
            int k = random(0, max);
            std::string aux = (integerToByte(k, numeroBytes - ti));

            insert = inicial.substr(0, ti);
            insert += aux;
            
        } while (dir->busca(insert));
        dir->insere(insert);
    }
}
int main()
{
    int op, n,m,b;
    Diretorio dir(0,0);

     {
    std::cout << "Digite N para o numero de chaves aleatorias" << std::endl;
    scanf("%d", &n);
    while (n < 1) {
        std::cout << "Digite N >= 1" << std::endl;
        scanf("%d", &n);
    }
    std::cout << "Digite M para o numero de chaves em um balde" << std::endl;
    scanf("%d", &m);
    while (m < 1) {
        std::cout << "Digite M >= 1" << std::endl;
        scanf("%d", &m);
    }
    do {
        std::cout << "Digite 1 para N numeros aleatorios e 2 para N numeros aleatorios com mesma sequencia inicial" << std::endl;
        scanf("%d", &op);
    } while (op != 1 && op != 2);
    
    if (op == 1) {
        std::cout << "Digite B para o numero de bytes" << std::endl;
        scanf("%d", &b);
        while (b < 1) {
            std::cout << "Digite B >= 1" << std::endl;
            scanf("%d", &b);
        }
        while (pow(2,b) < n) {
            std::cout << "Digite B de forma a possibilitar a geração de " << n<<"entradas unicas"<<std::endl;
            scanf("%d", &b);

        }
        numeroBytes = b;
        dir = Diretorio(numeroBytes, m);

        randomB(n, &dir, pow(2, numeroBytes) - 1);

    }
    else if (op == 2) {

        int tI;
        std::cout << "Digite T para o numero de bytes na sequencia inicial " << std::endl;
        scanf("%d", &tI);
        while (tI <0) {
            std::cout << "Digite T > 0 " << std::endl;
            scanf("%d", &tI);
        }
        int k = random(0, pow(2, tI) - 1);
        std::string inicial = integerToByte(k,tI);
        std::cout << "Digite B para o numero de bytes total" << std::endl;
        scanf("%d", &b);
        while (b < 1) {
            std::cout << "Digite B >= 1" << std::endl;
            scanf("%d", &b);
        }
        while (pow(2,(b-tI)) < n) {
            std::cout << "Digite B de forma a possibilitar a geração de " << n << " entradas unicas, considerando que os " <<tI<<"bytes sao iguais"<<std::endl;
            scanf("%d", &b);
        }
        numeroBytes = b;

         dir = Diretorio(numeroBytes, m);

        randomsB(n, &dir, pow(2, numeroBytes-tI) - 1, tI,inicial);
   
    }
    }
    dir.printdir();
    std::cout <<"FATOR DE CARGA "<< dir.getFatorCarga()<<" com "<<Balde::idgenerator<<" baldes";
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
