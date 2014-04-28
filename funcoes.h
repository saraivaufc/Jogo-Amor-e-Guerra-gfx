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

void Imprime_Parede(int x, int y);
