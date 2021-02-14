#pragma once
#include <iostream>
#include <string> 

class Diretorio;

class Balde
{
	int id;
	std::string* k;
	int dLocal;
	int carga = 0; 
	int cargaMax;
	static int* dGlobal;
	int numeroBytes;
	Diretorio*  dir;
public:
	Balde(int n,Diretorio* d,int m);

	static int idgenerator;
	static int cargaCounter;

	int busca(std::string chave);
	void insere(std::string chave);
	bool remove(std::string chave);
	int reInsert(std::string subchave); //remove todo os elementos que os primeiros bits significativos s�o os mesmo que a subchave e os adiciona novamente no diretorio
	bool hasSpace();
	int getDlocal() { return dLocal; }
	void setDlocal(int prof) { dLocal = prof; }
	int getCarga() { return carga; }
	void cargaUp() { cargaCounter++; carga++; }
	void cargaDo() { cargaCounter--; carga--; }
	
	int getMaxCarga() { return cargaMax; }
	void print();

};
