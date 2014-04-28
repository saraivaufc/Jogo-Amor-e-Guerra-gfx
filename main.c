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
#include "threads.h"

extern int comando;
int main(){
	Iniciar_Game();
	Criar_Parede_Chao();
	Iniciar_Variaveis();
		while(1){
			entrada_dados(); //thread 1
			calcula_prox_posicao(); //thread 2
			trata_prox_posicao(); //thread 3
			Atualizar(); //essa funcao atualiza o estado do Jogo
			Verifica_Vitoria();//verifica se o jogador ganhou o jogo
			imprime(); //thread 4
			Zerar_Variaveis(); //Zera algumas variaveis que precisam ser zeradas apos cada execucao
			usleep(4000);
			comando=0;//limpa o comando
		}
	return 0;
}
