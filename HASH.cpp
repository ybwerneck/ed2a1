// HASH.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Diretorio.h"
#include "utils.h"
#include <cmath>
#include "stdio.h"
#include <time.h>
int numeroBytes;
void randomB(int N, Diretorio* dir, int max) {
	srand(time(NULL));
	
	for (int i = 0; i < N; i++)
	{

		std::string insert;

		do {
	
			int k = random(0, max);
			insert = integerToByte(k, numeroBytes);
		} while (dir->busca(insert));
		dir->insere(insert);


	}

}
// para a comparação ser feita de uma forma justa, é garantido que sempre serão geradas n entradas unicas
// caso contratrio usando um gerador aleatorio, a chance de uma chave aleatoria ja esta presente é muito maior no teste 2 com bites iniciais iguais
// portanto sempre terá menos registros na tabela
void randomsB(int N, Diretorio* dir, int max, int ti, std::string inicial) {
	srand(time(NULL));

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
	int  n, m, b, tI;
	std::string inicial;

	{          //bloco de leitura de input
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
		std::cout << "Digite T para o numero de bytes iguais na sequencia inicial no segundo teste " << std::endl;
		scanf("%d", &tI);
		while (tI < 0) {
			std::cout << "Digite T > 0 " << std::endl;
			scanf("%d", &tI);
		}
		int k = random(0, pow(2, tI) - 1);
		inicial = integerToByte(k, tI);
		std::cout << "Digite B para o numero de bytes total em ambos os testes" << std::endl;
		scanf("%d", &b);
		while (b < 1) {
			std::cout << "Digite B >= 1" << std::endl;
			scanf("%d", &b);
		}
		while (pow(2, (b - tI)) < n) {
			std::cout << "Digite B de forma a possibilitar a geração de " << n << " entradas unicas, considerando que os " << tI << "bytes sao iguais no segundo teste" << std::endl;
			scanf("%d", &b);
		}
		numeroBytes = b;
	}
	//fim da leitura de input

	Diretorio dir1 = Diretorio(numeroBytes, m);
	randomB(n, &dir1, pow(2, numeroBytes) - 1);
	std::cout << std::endl << "T1 concluido";
	Diretorio dir2 = Diretorio(numeroBytes, m);
	randomsB(n, &dir2, pow(2, numeroBytes - tI) - 1, tI, inicial);
	std::cout << std::endl << "T2 concluido";

	int op;
	//  A ideia foi construir um progama que cumprisse todos os requisitos do documento enunciado e ao mesmo tempo que permitisse a rapida realização
	// de varios conjuntos de teste( T1 e T2) para facitar a comparacao das metricas em multiplas instancias de T1 e T2
	do {
		std::cout <<std::endl <<"Imprimir ?"<<std::endl<<" 1- Imprime T1 (N entradas) 2-Imprime T2 (N entradas com bytes iniciais iguais)  3-Imprime metricas"<<std::endl<<"  5-Sair"<<std::endl;
		scanf("%d", &op);
		switch (op) {
		case 1:
			dir1.printdir();
			std::cout << std::endl << "T1 - FATOR DE CARGA " << dir1.getFatorCarga() << " com " << dir1.getBaldeCount() << " baldes";
			break;
		case 2:
			dir2.printdir();
			std::cout << std::endl << "FATOR DE CARGA " << dir2.getFatorCarga() << " com " << dir2.getBaldeCount() << " baldes";
			break;
		case 3:
			std::cout << std::endl << "T1 - FATOR DE CARGA " << dir1.getFatorCarga() << " com " << dir1.getBaldeCount() << " baldes e carga:" << dir1.getCarga();
			std::cout << std::endl << "T2 - FATOR DE CARGA " << dir2.getFatorCarga() << " com " << dir2.getBaldeCount() << " baldes e carga"<<dir2.getCarga()<<std::endl;
			break;
	}
	} while (op != 5);
}

