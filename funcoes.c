#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <time.h>
#include <unistd.h>
#include <math.h>
#include "gfx.h"
#include "game.h"
#include "desenhos.h"

#define x_janela 50
#define y_janela 30
#define Numero_Coracoes  10 //aqui  a quantidade de coracoes

typedef struct{
    int x;//posicao atual
    int y;//posicao atual
    int xA;//posiaoo anterior
    int yA;//posiaoo anterior
    char forma;
    char *forma_Dir;//para cada posiÃ§Ã£o o Objeto possui uma forma prÃ©_definida
    char *forma_Esq;
    char *forma_Cim;
    char *forma_Bai;
    int existe;//boolean dizendo se ele existe 1 ou nÃ£o 0, muito usado na hora de imprimir
    int moveu;//boolean dizendo se ele se moveu 1 ou nÃ£o moveu 0
}Objeto_;

typedef struct{
    int x;
    int y;
    int xA;
    int yA;
    char *forma;
    int existe;
    int moveu;
}Coracao_;

Objeto_ Robo;
Objeto_ Projetil;
Coracao_ Coracao[Numero_Coracoes];
extern int comando;
extern char * cabecaDireita;
extern char * cabecaEsquerda;
extern char * cabecaCima;
extern char * cabecaBaixo;
extern char * balaDireita;
extern char * balaEsquerda;
extern char * balaCima;
extern char * balaBaixo;
extern char * coracao;
extern char * parede;
extern char * branco;

//tenho de trocar isso por listas encadeadas
extern char *micro;
extern char *micro1;
extern char *micro2;
extern char *micro3;
extern char *micro4;
extern char *micro5;
extern char *micro6;
extern char *micro7;
extern char *micro8;
extern char *micro9;
extern char *micro10;
extern char *nada;
//


void Criar_Parede_Chao(); //essa funÃ§Ã£o cria a parede e o chÃ£o do jogo
void Limpar_Buffer(); //Limpa o Buffer do teclado, caso o usuario matenha pressionado alguma tecla
void explodir(int x , int y);
void Explodir_Robo(); //se algum coraÃ§Ã£o bater no Robo ele explode
void Explodir_Coracao(int x, int y); //essa funcÃ£o explode o CoraÃ§Ã£o
void Mata_Robo(); //essa funÃ§Ã£o mata o robo
void Mata_Coracao(); //essa funÃ§Ã£o mata o coraÃ§Ã£o
void Impede_Choque_Parede();//mata o proetil quando ele se chocar com a parede
void Matar_Projetil(); //mata o projetil
void Ganhou(); //se o usuario ganhou
void Perdeu(); //se o usuario perdeu
void Apagar_Robo(); //apaga a posiÃ§Ã£o anterior ou atual do Robo
void Apagar_Coracao();//verifica se CoraÃ§Ã£o se mexeu, se sim, apaga a posiÃ§Ã£o anterior
void Apagar_Projetil();//apaga a posiÃ§Ã£o anterio do projetil
int Verifica_Bateu_Parede(int x, int y);//verifica se x e y est00o em alguma parede
void Imprime_Parede(int x, int y);//essa fun0400o imprime uma parede na Pos0400o (X,Y)

void Criar_Parede_Chao(){
	for(int i=0;i<x_janela;i++)
	{
		for(int j=0;j<y_janela;j++)
		{
			if(i==0 || i==x_janela-1 || j==0 || j==y_janela-1)
			{
				movexy(i,j);
				dpixel(parede);
			}
		}
	}
}
void Limpar_Buffer(){}

void Explodir_Robo(int x, int y){
    explodir(x,y);
}

void Explodir_Coracao(int x, int y){
	explodir(x ,y);
}
void Mata_Robo(){}
void Mata_Coracao(){}
void Impede_Choque_Parede(){
}
void Matar_Projetil(){}
void Ganhou(){


}

void Perdeu(){
   set_fundo('r');
   limpar_tela();
}

void Apagar_Robo(){}
void Apagar_Coracao(){}

void Apagar_Projetil(){
    if(Projetil.x != Projetil.xA || Projetil.y != Projetil.yA)
    {
	    if(Projetil.x == x_janela || Projetil.x == 0 || Projetil.y == y_janela || Projetil.y == 0 ){
	    	movexy(Projetil.x,Projetil.y);
    		dpixel(parede);
	    	Projetil.existe=0;
	    	Projetil.moveu=0;
    	}else{
	    	imprime_objeto(Projetil.xA,Projetil.yA,branco);
	    }
    }
}

void explodir(int x , int y){//tenho de passar essa funÃ§Ã£o para uma Lista encadeada ou Arvore Binaria

	imprime_objeto(Projetil.xA,Projetil.yA,branco);
	imprime_objeto_pequeno(x,y,micro);
	usleep(100000);
	system("aplay tiro.wav&");
	imprime_objeto_pequeno(x,y,micro2);
	usleep(100000);
	system("aplay tiro.wav&");
	imprime_objeto_pequeno(x,y,micro3);
	usleep(100000);
	system("aplay tiro.wav&");
	imprime_objeto_pequeno(x,y,micro4);
	usleep(100000);
	system("aplay tiro.wav&");
	imprime_objeto_pequeno(x,y,micro5);
	usleep(100000);
	system("aplay tiro.wav&");
	imprime_objeto_pequeno(x,y,micro6);
	usleep(100000);
	system("aplay tiro.wav&");
	imprime_objeto_pequeno(x,y,micro7);
	usleep(100000);
	system("aplay tiro.wav&");
	imprime_objeto_pequeno(x,y,micro8);
	usleep(100000);
	system("aplay tiro.wav&");
	imprime_objeto_pequeno(x,y,micro9);
	usleep(100000);
	system("aplay tiro.wav&");
	imprime_objeto_pequeno(x,y,micro10);
	usleep(100000);
	system("aplay tiro.wav&");
	imprime_objeto_pequeno(x,y,nada);
}

int Verifica_Bateu_Parede(int x, int y){
    if(x == x_janela-1 || y == y_janela-1 || x == 0 || y == 0)//O Robo se chocou com a Parede
	{
	    return 1;
	}else
	    return 0;
}

void Imprime_Parede(int x, int y){
    movexy(x,y);
    dpixel(parede);
}



