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
	int idgenerator;
	int cargaCounter;

	public:
		Diretorio(int,int);

		bool busca(std::string chave);
	bool insere(std::string chave);
	bool split(std::string);
	void printdir();
	bool aprofundar();
	double getFatorCarga();
	void startDirs();
	int getNewBaldeId() { return idgenerator++; };
	int getBaldeCount() { return idgenerator; };
	int getCarga() { return cargaCounter; };
	void cargaUp() { cargaCounter++; }
	void cargaDo() { cargaCounter--; }

	};
