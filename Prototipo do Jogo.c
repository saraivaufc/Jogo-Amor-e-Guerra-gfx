Bibliotecas
    main.c      game.h funcoes.h desenhos.h gfx.h
    
    
    
game.h  funcoes.h

    void Iniciar_Game();//essa funcão cria a janela inicial
        void Criar_Parede_Chao(); //essa função cria a parede e o chão do jogo
    void Iniciar_Variaveis();//essa função inicializa todas as variaveis do jogo
    void Recebe_Comando();//recebe um comando do teclado
        void Limpar_Buffer(); //Limpa o Buffer do teclado, caso o usuario matenha pressionado alguma tecla
    void Proxima_Posicao_Robo(int c); //essa funcão calcula qual será a proxima posição do Robo
    void Proxima_Posicao_Coracao();//essa função calcula a posição de todos os corações
    void Proxima_Posicao_Projetil(int c); //verifica qual será a proxima posição do Projetil se esse "Existir();"
    void Trata_Posicao_Robo(); //impede que o robo se choque o a parede
    void Trata_Posicao_Coracao(); //impede que algum coração se choque com a parede e com o Robo
        void Explodir_Robo(); //se algum coração bater no Robo ele explode
        void Mata_Coracao(); //essa função mata o coração
        void Mata_Robo(); //essa função mata o robo
    void Trata_Posicao_Projetil();//verifica se o projetiu se chocou com algum Coração ou com alguma parede
        void Explodir_Coracao(); //essa funcão explode o Coração
        void Impede_Choque_Parede();//mata o proetil quando ele se chocar com a parede
        void Matar_Projetil(); //mata o projetil
    void Atualizar(); //essa função atualiza o estado do Jogo
    void Verifica_Vitoria_Derrota(); //verifica se o jogador ganhou o jogo
        void Ganhou(); //se o usuario ganhou
        void Perdeu(); //se o usuario perdeu
    void Desenha_Robo(); //Imprime o Robo
        void Apagar_Robo(); //apaga a posição anterior ou atual do Robo
    void Desenha_Coracao(); //Imprime todos os corações
        void Apagar_Coracao();//verifica se Coração se mexeu, se sim, apaga a posição anterior
    void Desenha_Projetil(); //Se Projetil existir(); imprime ele
        void Apagar_Projetiu();
    void Zerar_Variaveis(); //Zera algumas variaveis que precisam ser zeradas após cada execução
    
desenhos.h 
    //Nessa função estaram somente os desenhos de todos os personagens



Objetos:

    typedef struct{
        int x;//posição atual
        int y;//posição atual
        int x_Anterior;//posição anterior
        int y_Anterior;//posição anterior
        char *forma_Dir; 
        char *forma_Esq;
        char *forma_Cim;
        char *forma_Bai;
        int existe;//boolean dizendo se ele existe 1 ou não 0, muito usado na hora de imprimir
        int moveu;//boolean dizendo se ele se moveu 1 ou não moveu 0
    }Objeto;
    
    
    typedef struct{
        int x;
        int y;
        int x_Anterior;
        int y_Anterior;
        char *forma;
        int existe;
        int moveu;
    }Coracao;









