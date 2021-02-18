#pragma once
#include <iostream>
#include "Balde.h"
#include "Diretorio.h"
Balde::Balde(int n,Diretorio* d,int M) {
    dir = d;
    id = d->getNewBaldeId(); //indentificação dos baldes, usada para facilitar visualização no debug
    dLocal = 1;
    numeroBytes = n;
    cargaMax = M;
    k.resize(M);
    for (int i = 0; i < M; i++) 
        k[i] = "";
}
void Balde::cargaUp() { dir->cargaUp(); carga++; }
void Balde:: cargaDo() { dir->cargaDo(); carga--; }

int Balde::busca(std::string chave) {

    for (int i = 0; i < cargaMax; i++) {
        if (chave == k[i])
            return i;
        }
    return -1;

}
bool Balde::remove(std::string chave) {

    int indice = busca(chave);
    if (indice != -1){
    k[indice]="";
    cargaDo();
    return true;
    }
    return false;
}

bool Balde::insere(std::string chave) {
    
    if (cargaMax > carga)
    
        for (int i = 0; i < cargaMax; i++) {
            if ("" == k[i]){
                cargaUp();
                k[i] = chave;
                return true;
        }
    } 
    return false;
        
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
            dir->insere(auxS);

        }
    }
    return aux;
}
void Balde::print() {
    std::cout << "--------Balde" << id << "------ Profundidade" << dLocal << "----" << std::endl;
    for (int i = 0; i < k.size(); i++) {
      
        if(k[i]!="")printf("%s \n", k[i].c_str()); //cout nao estava parando no \0, solucao encontrada foi usar o printf com o vetor de caracteres do c_str
    }


}
