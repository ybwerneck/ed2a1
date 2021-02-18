#include<iostream>
#include <cmath>
#include <time.h>
#include "utils.h"
std::string integerToByte(int n, int numBytes) {
	int num= n;
	std::string k = std::string(" ", numBytes);//inicializa o balde vazio

	int i=0;
	for (int aux = num; aux > 0 ; i++){
		k = ((aux % 2)==0 ? '0' : '1' )+k;
		aux = aux / 2;
	}
	for (int aux = numBytes; aux > i ; i++) {
		k = '0' + k;
	}

	k[i] = '\0';
	return k;
}

int bytesToInteger(std::string bytes) {
	int total = 0;
	int k = 0;
	for (int i = 0; bytes[i++] != '\0'; k++);
	for (int i = 0; bytes[i] != '\0'; i++) {

		total += pow(2, (k - i - 1)) * (bytes[i] - '0');
	};
	return total;

}
int random(int min, int max) {

	return rand() % (max + 1 - min) + min;

}
