#pragma once
#include <iostream>
#include "Balde.h"
#include "Diretorio.h"
int Balde::idgenerator = 0;
int Balde::cargaCounter = 0;
Balde::Balde(int n,Diretorio* d,int M) {
    dir = d;
    id = ++idgenerator;
    dLocal = 1;
    numeroBytes = n;
    cargaMax = M;
    k =(std::string*) new std::string[cargaMax];
    for (int i = 0; i < cargaMax; i++)
        k[i] = std::string("");//inicializa o balde vazio

}
int Balde::busca(std::string chave) {

    for (int i = 0; i < cargaMax; i++) {
        if (chave == k[i])
            return i;
        }
    return -1;

}
bool Balde::remove(std::string chave) {

    int indice = busca(chave);
    if (indice == -1) return false;
    k[indice] = "";
    cargaDo();
    return true;
}

void Balde::insere(std::string chave) {
    
    if (cargaMax > carga)
        for (int i = 0; i < cargaMax; i++)
        {
            if (k[i] == "") {
                k[i] = chave;
                    break;
            }
        }
    cargaUp();
    
        
}
bool Balde::hasSpace() { return cargaMax >carga; }

int Balde::reInsert(std::string subchave) {
    int aux=0;
    std::string sc = subchave.substr(0, dLocal);
    this;
    for (int i = 0; i < cargaMax; i++) {
        std::string c = k[i].substr(0, dLocal);

        if (sc == c) {
            std::string auxS = k[i];
            remove(auxS);
            aux++;
            carga--;
            dir->insere(auxS);

        }
    }
    return aux;
}
void Balde::print() {
    std::cout << "--------Balde" << id << "----------" << std::endl;
        for (int i = 0; i < cargaMax; i++) {
            printf("%s \n", k[i].c_str()); //cout nao estava parando no \0, solucao encontrada foi usar o printf com o vetor de caracteres do c_str
    }


}