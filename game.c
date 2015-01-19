#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <time.h>
#include <unistd.h>
#include <math.h>
#include "gfx.h"
#include "funcoes.h"
#include "desenhos.h"

#define x_janela 50
#define y_janela 30
#define tamanho_janela_x 1000
#define tamanho_janela_y 600

#define Numero_Coracoes  10 //aqui 茅 a quantidade de cora莽玫es
#define fori(x) for(int x=0;x<Numero_Coracoes;x++)

typedef struct{
    int x;//posi莽茫o atual
    int y;//posi莽茫o atual
    int xA;//posi莽茫o anterior
    int yA;//posi莽茫o anterior
    char forma;
    char *forma_Dir;//para cada posi莽茫o o Objeto possui uma forma pr茅_definida
    char *forma_Esq;
    char *forma_Cim;
    char *forma_Bai;
    int existe;//boolean dizendo se ele existe 1 ou n茫o 0, muito usado na hora de imprimir
    int moveu;//boolean dizendo se ele se moveu 1 ou n茫o moveu 0
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
    int comando;

void Iniciar_Game();//essa func茫o cria a Janela inicial
void Iniciar_Variaveis();//essa fun莽茫o inicializa todas as variaveis do jogo
void Recebe_Comando();//recebe um comando do teclado
void Proxima_Posicao_Robo(); //essa func茫o calcula qual ser谩 a proxima posi莽茫o do Robo
void Proxima_Posicao_Coracao();//essa fun莽茫o calcula a posi莽茫o de todos os cora莽玫es
void Proxima_Posicao_Projetil(); //verifica qual ser谩 a proxima posi莽茫o do Projetil se esse "Existir();"
void Trata_Posicao_Robo(); //impede que o Robo se choque o a parede
void Trata_Posicao_Coracao(); //impede que algum cora莽茫o se choque com a parede e com o Robo
void Trata_Posicao_Projetil();//verifica se o projetiu se chocou com algum Cora莽茫o ou com alguma parede
void Atualizar(); //essa fun莽茫o atualiza o estado do Jogo
void Verifica_Vitoria(); //verifica se o jogador ganhou o jogo
void Desenha_Robo(); //Imprime o Robo
void Desenha_Coracao(); //Imprime todos os cora莽玫es
void Desenha_Projetil(); //Se Projetil existir(); imprime ele
void Zerar_Variaveis(); //Zera algumas variaveis que precisam ser zeradas ap贸s cada execu莽茫o

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


void Iniciar_Game(){
    criar_janela(tamanho_janela_x,tamanho_janela_y,"Jogo Perfeito");
    limpar_tela();
}

void Iniciar_Variaveis(){
//aqui eu inicializo as variaveis do Robo
    Robo.x=2;
    Robo.y=2;
    Robo.xA=-1;
    Robo.yA=-1;
    Robo.existe=1;
    Robo.moveu=0;
    Robo.forma='>';
    Robo.forma_Dir=cabecaDireita;
    Robo.forma_Esq=cabecaEsquerda;
    Robo.forma_Cim=cabecaCima;
    Robo.forma_Bai=cabecaBaixo;

//aqui eu inicializo as variaveis do Projetil
    Projetil.x=1;
    Projetil.y=1;
    Projetil.xA=-1;
    Projetil.yA=-1;
    Projetil.existe=0;
    Projetil.moveu=0;
    Projetil.forma='>';
    Projetil.forma_Dir=balaDireita;
    Projetil.forma_Esq=balaEsquerda;
    Projetil.forma_Cim=balaCima;
    Projetil.forma_Bai=balaBaixo;

//aqui eu inicializo as variaveis dos Cora莽玫es
    srand(time(NULL));
    fori(i){
        Coracao[i].x=(int) (rand()%(x_janela-6))+4;
        Coracao[i].y=(int) (rand()%(y_janela-6))+4;
        Coracao[i].xA=-1;
        Coracao[i].yA=-1;
        Coracao[i].forma=coracao;
        Coracao[i].existe=1;
        Coracao[i].moveu=0;
    }

}

void Recebe_Comando(){
    char c;
    if(tecla_pressionada()){
        comando=get_tecla();
	while(tecla_pressionada()){
		c=get_tecla();
	}
	printf("%d",c);
    }
    if(comando == TECLA_ESPACO){
		system("aplay tiro.wav&");
		Projetil.existe=1;
		Projetil.forma=Robo.forma;
		if(Verifica_Bateu_Parede(Projetil.x,Projetil.y)){
		    Imprime_Parede(Projetil.x,Projetil.y);
		}else imprime_objeto(Projetil.x,Projetil.y,branco);
		Projetil.x=Robo.x;
		Projetil.y=Robo.y;
	}
}

void Proxima_Posicao_Robo(){

    Robo.xA=Robo.x;
    Robo.yA=Robo.y;

    if (comando == TECLA_RIGHT)// >
    {
        if(Robo.forma == '>') Robo.forma='v';
        else
            if(Robo.forma == 'v') Robo.forma='<';
            else
            if(Robo.forma == '<') Robo.forma='A';
                else
                    if(Robo.forma == 'A') Robo.forma='>';
    }

    if(comando == TECLA_LEFT)//<
    {
        if(Robo.forma == '>') Robo.forma='A';
        else
            if(Robo.forma == 'v') Robo.forma='>';
            else
                if(Robo.forma == '<') Robo.forma='v';
                else
                    if(Robo.forma == 'A') Robo.forma='<';
    }

    if(comando == TECLA_UP)//A
    {
        if(Robo.forma == '>') Robo.x++;
        else
            if(Robo.forma == 'v') Robo.y++;
            else
                if(Robo.forma == '<') Robo.x--;
                else
                    if(Robo.forma == 'A') Robo.y--;
    }

    if(comando == TECLA_DOWN)
    {//V
        if(Robo.forma == '>') Robo.x--;
        else
            if(Robo.forma == 'v') Robo.y--;
            else
                if(Robo.forma == '<') Robo.x++;
                else
                    if(Robo.forma == 'A') Robo.y++;
    }
}

void Proxima_Posicao_Coracao(){
    srand(time(NULL));
    fori(k)
    {
		int i=0;
		i=(rand() % 9)+1;
		Coracao[k].xA = Coracao[k].x;
		Coracao[k].yA = Coracao[k].y;
		Coracao[k].moveu=1;
			if(Coracao[k].x < x_janela-1  && Coracao[k].x > 0  && Coracao[k].y > 0 && Coracao[k].y < y_janela-1)
			{
				if(i==1) Coracao[k].x++;
				else
				if(i==2) Coracao[k].x--;
				else
				if(i==3) Coracao[k].y--;
				else
				if(i==4) Coracao[k].y++;
				else
				if(i==5){
					Coracao[k].x++;
					Coracao[k].y++;
				}else
				if(i==6){
					Coracao[k].x--;
					Coracao[k].y--;
				}else
				if(i==7){
					Coracao[k].x++;
					Coracao[k].y--;
				}else
				if(i==8){
					Coracao[k].x--;
					Coracao[k].y++;
				}
			}else
			{
				if(Coracao[k].x >= x_janela-1)
					Coracao[k].x--;
				else
				if(Coracao[k].x <=  0)
					Coracao[k].x++;
				else
				if(Coracao[k].y >= y_janela-1)
					Coracao[k].y--;
				else
				if(Coracao[k].y <=  0)
					Coracao[k].y++;
			}
	}
}


void Proxima_Posicao_Projetil(){
	if(Projetil.existe)
	{
		Projetil.xA=Projetil.x;
		Projetil.yA=Projetil.y;
			if(Projetil.forma == '>')
			{
				Projetil.x++;
			}else
				if(Projetil.forma == 'A')
				{
					Projetil.y--;
				}else
					if(Projetil.forma == '<')
					{
						Projetil.x--;
					}else
						if(Projetil.forma == 'v')
						{
							Projetil.y++;
						}
	}
}

void Trata_Posicao_Robo(){
	if(Verifica_Bateu_Parede(Robo.x,Robo.y))//O Robo se chocou com a Parede
	{
		Imprime_Parede(Robo.x,Robo.y);
		Robo.x=Robo.xA;
		Robo.y=Robo.yA;
	}
	fori(i){
	    if(Robo.x == Coracao[i].x && Robo.y == Coracao[i].y && Coracao[i].existe)//O Robo se chocou com algum Coracao
	    {
	        Explodir_Robo(Robo.x,Robo.y);
	        Perdeu();
	    }
	}
}

void Trata_Posicao_Coracao(){
	fori(i)
	{
		if(Coracao[i].x == Robo.x && Coracao[i].y == Robo.y)
			Perdeu();
	    if(Verifica_Bateu_Parede(Coracao[i].x, Coracao[i].y)){//O coração chocou-se com a parede
	        Imprime_Parede(Coracao[i].x,Coracao[i].y);
	        Coracao[i].x=Coracao[i].xA;
	        Coracao[i].y=Coracao[i].yA;
	    }
	}
}

void Trata_Posicao_Projetil(){
	fori(i){
		if(Projetil.x == Coracao[i].x && Projetil.y == Coracao[i].y){//Se o Projetiu acertou algum Coração
		  movexy(Projetil.x,Projetil.y);
		    dpixel(coracao);
			Projetil.existe=0;
			Projetil.moveu=0;
			Coracao[i].existe=0;
			Coracao[i].moveu=0;
			imprime_objeto(Coracao[i].xA,Coracao[i].yA,branco);
			imprime_objeto(Coracao[i].x,Coracao[i].y,branco);
			Explodir_Coracao(Coracao[i].x,Coracao[i].y);
		}
	}
}

void Atualizar(){

}

void Verifica_Vitoria(){
	int counter=0;
	fori(i){
		if(Coracao[i].existe){

		}else counter++;
	}
	if(counter == Numero_Coracoes){
		Ganhou();
	}
}

void Desenha_Robo(){
	if(Robo.existe)
	{
		imprime_objeto(Robo.xA,Robo.yA,branco);
		movexy(Robo.x,Robo.y);
		if(Robo.forma == '>') dpixel(cabecaDireita);
		else
			if(Robo.forma == 'v') dpixel(cabecaBaixo);
			else
				if(Robo.forma == '<') dpixel(cabecaEsquerda);
				else
					if(Robo.forma == 'A') dpixel(cabecaCima);
	}
}

void Desenha_Coracao(){
	int cont=0;
	fori(i)
	{
		if(Coracao[i].existe)
		{
			if(Coracao[i].x != Coracao[i].xA  ||  Coracao[i].y  !=  Coracao[i].yA)
			{
				imprime_objeto(Coracao[i].xA,Coracao[i].yA,branco);
			}
			movexy(Coracao[i].x,Coracao[i].y);
			dpixel(Coracao[i].forma);
		}else cont++;

		if(cont == Numero_Coracoes) Ganhou();
	}

}


void Desenha_Projetil(){
	if(Projetil.existe)
	{
		if(Projetil.existe)
		{
			if(Projetil.forma == '>')
			{
				if(Projetil.x == x_janela-1)
					Apagar_Projetil();
				else
					imprime_objeto_pequeno(Projetil.x,Projetil.y,balaDireita);
			}else
				if(Projetil.forma == 'A')
				{
					if(Projetil.y == 0)
						Apagar_Projetil();
					else
						imprime_objeto_pequeno(Projetil.x,Projetil.y,balaCima);
				}else
					if(Projetil.forma == '<')
					{
						if(Projetil.x == 0)
							Apagar_Projetil();
						else
							imprime_objeto_pequeno(Projetil.x,Projetil.y,balaEsquerda);
					}else
						if(Projetil.forma == 'v')
						{
							if(Projetil.y == y_janela-1)
								Apagar_Projetil();
							else
								imprime_objeto_pequeno(Projetil.x,Projetil.y,balaBaixo);
						}
			if(Projetil.x != Projetil.xA || Projetil.y != Projetil.yA){
			    imprime_objeto(Projetil.xA,Projetil.yA,branco);
			    if(Verifica_Bateu_Parede(Projetil.x,Projetil.y)){
			        Projetil.existe=0;
			        Projetil.moveu=0;
                    Imprime_Parede(Projetil.x,Projetil.y);
                }
			}
		}
	}
}


void Zerar_Variaveis(){
	comando=0;
}
