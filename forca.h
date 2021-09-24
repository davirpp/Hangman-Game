#ifndef FORCA_H
#define FORCA_H

#include <iostream>
#include <cstdlib>
#include <ctime>

/* PROTÓTIPOS DAS FUNÇÕES */
//Exclui conteúdo anterior à chamada da função 
void LimpaConsole(); 

//Retorna um número aletorio no intervalo dado
int numeroAleatorio(int menor, int maior);

//Apresenta a tela inicial e retorna o nivel
int tela_inicial();

//Deixa o codigo em 'stand-by' por x milissegundos
void wait(unsigned milissegundos);

//Desenha um boneco numa forca
void desenha_boneco(int tentativas);

#endif