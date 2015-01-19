void Criar_Parede_Chao(); //essa função cria a parede e o chão do jogo

void Limpar_Buffer(); //Limpa o Buffer do teclado, caso o usuario matenha pressionado alguma tecla

void explodir(int x , int y);

void Explodir_Robo(); //se algum coração bater no Robo ele explode

void Explodir_Coracao(int x, int y); //essa funcão explode o Coração

void Mata_Robo(); //essa função mata o robo

void Mata_Coracao(); //essa função mata o coração

void Impede_Choque_Parede();//mata o proetil quando ele se chocar com a parede

void Matar_Projetil(); //mata o projetil

void Ganhou(); //se o usuario ganhou

void Perdeu(); //se o usuario perdeu

void Apagar_Robo(); //apaga a posição anterior ou atual do Robo

void Apagar_Coracao();//verifica se Coração se mexeu, se sim, apaga a posição anterior

void Apagar_Projetil();//apaga a posição anterio do projetil

int Verifica_Bateu_Parede(int x, int y);//verifica se x e y est�0�0o em alguma parede

void Imprime_Parede(int x, int y);
