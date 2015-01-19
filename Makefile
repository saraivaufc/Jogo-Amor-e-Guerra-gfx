main: main.c game.c funcoes.c desenhos.c
	gcc -o main main.c game.c funcoes.c desenhos.c gfx.c -std=gnu99 -Werror -Wall -Wformat=0 -lm -lX11
