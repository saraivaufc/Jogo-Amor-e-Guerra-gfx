main: main.c game.c funcoes.c desenhos.h threads.c
	gcc -o main main.c game.c funcoes.c desenhos.h threads.c gfx.c -std=gnu99 -Werror -Wall -Wformat=0 -lm -lX11
