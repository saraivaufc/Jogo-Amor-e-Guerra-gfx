#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <time.h>
#include <unistd.h>
#include <math.h>
#include "gfx.h"
#include "game.h"
#include "funcoes.h"
#include "desenhos.h"

void entrada_dados(){
	Recebe_Comando();//recebe um comando do teclado
}

void calcula_prox_posicao(){
	Proxima_Posicao_Robo();//calcula a proxima posicao do do Robo
	Proxima_Posicao_Coracao();//calcula a proxima posicao de todos os coracoes
	Proxima_Posicao_Projetil();//calcula a proxima posicao do Projetil se caso ele exista
}

void trata_prox_posicao(){
	Trata_Posicao_Robo();////impede que o robo se choque o a parede
	Trata_Posicao_Coracao();//impede que algum coracao se choque com a parede e com o Robo
	Trata_Posicao_Projetil();//verifica se o projetiu se chocou com algum Coracao ou com alguma parede
}

void imprime(){
	Desenha_Robo();//Imprime o Robo
	Desenha_Coracao();//Imprime todos os coracoes
	Desenha_Projetil();//Se Projetil existir(); imprime ele
}
