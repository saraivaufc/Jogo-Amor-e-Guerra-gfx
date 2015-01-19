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

extern int comando;
int main(){
    Iniciar_Game();
    while(1)
    {
       Criar_Parede_Chao();
        Iniciar_Variaveis();
        while(1){
		    Recebe_Comando();//recebe um comando do teclado
		     if(comando == 'r'){
		        limpar_tela();
		        break;
		     }else
		        if(comando == 'e'){
		            comando=0;
		            return 0;
		        }
		    Proxima_Posicao_Robo();//calcula a proxima posição do Robo
		    Proxima_Posicao_Coracao();//calcula a proxima posição de todos os corações
		    Proxima_Posicao_Projetil();//calcula a proxima posicao do Projetil se caso ele exista
		    Trata_Posicao_Robo();////impede que o robo se choque o a parede
		    Trata_Posicao_Coracao();//impede que algum coracao se choque com a parede e com o Robo
		    Trata_Posicao_Projetil();//verifica se o projetiu se chocou com algum Coracao ou com alguma parede
		    Atualizar(); //essa funcao atualiza o estado do Jogo
		    Verifica_Vitoria();//verifica se o jogador ganhou o jogo
		    Desenha_Robo();//Imprime o Robo
		    Desenha_Coracao();//Imprime todos os coracoes
		    Desenha_Projetil();//Se Projetil existir(); imprime ele
		    Zerar_Variaveis(); //Zera algumas variaveis que precisam ser zeradas apos cada execucao
		    usleep(10000);
		    comando=0;//limpa o comando
        }
    }
    return 0;
}
