#pragma once
#include <iostream>
#include <string> 
#include <vector>
class Diretorio;

class Balde
{
	int id;
	std::vector<std::string> k{ };
	int dLocal;
	int carga = 0; 
	int cargaMax;
	static int* dGlobal;
	int numeroBytes;
	Diretorio*  dir;
	void cargaUp();
	void cargaDo();

public:
	Balde(int n,Diretorio* d,int m);

	
	int busca(std::string chave);
	bool insere(std::string chave);
	bool remove(std::string chave);
	int reInsert(std::string subchave); //remove todo os elementos que os primeiros bits significativos s�o os mesmo que a subchave e os adiciona novamente no diretorio
	bool hasSpace();
	int getDlocal() { return dLocal; }
	void setDlocal(int prof) { dLocal = prof; }
	int getCarga() { return carga; }

	
	int getMaxCarga() { return cargaMax; }
	void print();

};
