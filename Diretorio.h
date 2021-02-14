#pragma once
#include <iostream>
#include "Balde.h"

#include "utils.h"
class Diretorio
{

	Balde** baldes;
	int dGlobal;
	int nBalde;
	int M;
	int nB;
	public:
		Diretorio(int,int);

		bool busca(std::string chave);
	bool insere(std::string chave);
	bool hasSpace();
	bool split(std::string);
	void printdir();
	bool aprofundar();
	double getFatorCarga();
		void startDirs();
	};
