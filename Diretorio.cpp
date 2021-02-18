#pragma once

#include <iostream>
#include <math.h>       /* pow */
#include "Diretorio.h"
void Diretorio::startDirs() {
	Balde* baldeInicial1 =  new Balde(nB, this,M);
	Balde* baldeInicial2 = new Balde(nB, this,M);
	baldes[0] = baldeInicial1;
	baldes[1] = baldeInicial1;
	baldes[2] = baldeInicial2;
	baldes[3] = baldeInicial2;

}
double Diretorio::getFatorCarga() {
	return ((double)cargaCounter /( (double) idgenerator*M));
}
Diretorio::Diretorio(int nBytes,int m) {
	cargaCounter = 0;
	idgenerator = 0;
	nB = nBytes;
	M = m;
	dGlobal = 2;
	nBalde = pow(2, dGlobal); //numero maximo de baldes
	baldes = new Balde*[nBalde];
	startDirs();
}
bool Diretorio::split(std::string subchave) {
	
	int indexBalde = bytesToInteger(subchave);
	Balde* baldeAntigo = baldes[indexBalde];
	if ((baldeAntigo->getDlocal() >= dGlobal))
		return false;
	int difprof = dGlobal - baldeAntigo->getDlocal();
	int indicesafetados =pow(2,difprof);

	std::string aux = subchave;
	for (int i = 0; i < dGlobal ; i++) {
		aux[i] = (i < baldeAntigo->getDlocal()) ? subchave[i] : '0'; //calcula primeiro indice do diretorio que deve ser atualizado
	}
	int indiceInicial = bytesToInteger(aux);
	Balde* baldeNovo = new Balde(nB,this,M);
	
	int meio = indiceInicial + indicesafetados / 2;
	for (int i = indiceInicial; i < indicesafetados + indiceInicial; i++) {

			baldes[i ] = (i <meio) ? baldeNovo: baldeAntigo ;
		}
	baldeNovo->setDlocal(baldeAntigo->getDlocal() + 1);
	baldeAntigo->setDlocal(baldeAntigo->getDlocal() + 1);
		baldeAntigo->reInsert(aux);


	return true;
}
int a = 0;
bool Diretorio::insere(std::string chave) {
	a++;
	if (busca(chave))
		return false; //nao insere chaves repetidas
	std::string aux = chave.substr(0, dGlobal); //primerios n bits significantes, n= profundidade globa
	int indexBalde = bytesToInteger(aux);
	Balde* b = baldes[indexBalde];
	if (baldes[indexBalde]->hasSpace()) {
		baldes[indexBalde]->insere(chave);

		return true;
	}
	else if (split(aux)) {
	
		bool b=  insere(chave);
		return b;
	}
	else if (aprofundar())
		return insere(chave);

	std::cout << "tabela cheia!";

return false;
}
void Diretorio::printdir() {
	for (int i = 0; i < pow(2, dGlobal); i++) {
		std::cout << "Indice " << i << " -> ";
		baldes[i]->print();

	}
}
bool Diretorio::busca(std::string chave) {
	std::string aux = chave.substr(0, dGlobal); //primerios n bits significantes
	int indexBalde = bytesToInteger(aux);
	Balde* b = baldes[indexBalde]; 
	return b->busca(chave)!=-1;
}
bool Diretorio::aprofundar() {

	if (dGlobal >= nB)
		return false;
		dGlobal++;
	
		Balde** balden=new Balde* [nBalde*2];
		for (int i = 0,k=0; i < pow(2, dGlobal - 1); i++) {
			balden[k++] = baldes[i];
			balden[k++] = baldes[i];
	}
		nBalde = pow(2, dGlobal);
		baldes = balden;
		return true;
}