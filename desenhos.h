#ifndef DESENHOS_H
#define DESENHOS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <unistd.h>
#include <time.h>
#include "gfx.h"
#include "game.h"
#include "funcoes.h"

char *branco="\
WWWWWWWWWWW\n\
WWWWWWWWWWW\n\
WWWWWWWWWWW\n\
WWWWWWWWWWW\n\
WWWWWWWWWWW\n\
WWWWWWWWWWW\n\
WWWWWWWWWWW\n\
WWWWWWWWWWW\n\
WWWWWWWWWWW\n\
WWWWWWWWWWW\n\
WWWWWWWWWWW";




//usarei essa para criar uma parede
char *parede="\
rrrrrrrrrrrrrrrrrrrrr\n\
rrrrrrrrrrrrrrrrrrrrr\n\
rrrrrWWWrrrrrWWWrrrrr\n\
rrrrWWWWWrrrWWWWWrrrr\n\
rrrWWWWWWWrWWWWWWWrrr\n\
rrWWWWWWWWWWWWWWWWWrr\n\
rWWWWWWWWWWWWrrrWWWWr\n\
rWWWWWWWWWWWWWrrrWWWr\n\
rWWWWWWWWWWWWWWrrWWWr\n\
rWWWWWWWWWWWWWWrrWWWr\n\
rWWWWWWWWWWWWWWrWWWWr\n\
rrWWWWWWWWWWWWWWWWWrr\n\
rrrWWWWWWWWWWWWWWWrrr\n\
rrrrWWWWWWWWWWWWWrrrr\n\
rrrrrWWWWWWWWWWWrrrrr\n\
rrrrrrWWWWWWWWWrrrrrr\n\
rrrrrrrWWWWWWWrrrrrrr\n\
rrrrrrrrWWWWWrrrrrrrr\n\
rrrrrrrrrWWWrrrrrrrrr\n\
rrrrrrrrrrWrrrrrrrrrr\n\
rrrrrrrrrrrrrrrrrrrrr";


//essa será a cabeça do meu Robo
char *cabecaCima="\
        kkkkk        \n\
        kkkkk        \n\
         kGk         \n\
         kGk         \n\
         kGk         \n\
         kGk         \n\
         kGk         \n\
  kk GGGGGrGGGGG kk  \n\
  kkGGrrrGrGrrrGGkk  \n\
  kkGrGrrGrGrrGrGkk  \n\
  kkGrrGrGrGrGrrGkk  \n\
  kkGrrrGGGGGrrrGkk  \n\
  kkGGGGGkkkGGGGGkk  \n\
  kkGrrrGkkkGrrrGkk  \n\
  kkGGGGGGGGGGGGGkk  \n\
  kkGrrrGGGGGrrrGkk  \n\
  kkGrrGrGrGrGrrGkk  \n\
  kkGrGrrGrGrrGrGkk  \n\
  kkGGrrrGrGrrrGGkk  \n\
  kk GGGGGGGGGGG kk  \n\
                     ";

char *cabecaDireita="\
                     \n\
                     \n\
 kkkkkkkkkkkkk       \n\
 kkkkkkkkkkkkk       \n\
  GGGGGGGGGGG        \n\
 GGrrrGrGrrrGG       \n\
 GrGrrGrGrrGrG       \n\
 GrrGrGrGrGrrG       \n\
 GrrrGGGGGrrrG     kk\n\
 GGGGGGkkGrGGGkkkkkkk\n\
 GrrrGGkkGrrrrGGGGGkk\n\
 GGGGGGkkGrGGGkkkkkkk\n\
 GrrrGGGGGrrrG     kk\n\
 GrrGrGrGrGrrG       \n\
 GrGrrGrGrrGrG       \n\
 GGrrrGrGrrrGG       \n\
  GGGGGGGGGGG        \n\
 kkkkkkkkkkkkk       \n\
 kkkkkkkkkkkkk       \n\
                     \n\
                     ";

char *cabecaBaixo="\
                     \n\
  kk GGGGGGGGGGG kk  \n\
  kkGGrrrGrGrrrGGkk  \n\
  kkGrGrrGrGrrGrGkk  \n\
  kkGrrGrGrGrGrrGkk  \n\
  kkGrrrGGGGGrrrGkk  \n\
  kkGGGGGGGGGGGGGkk  \n\
  kkGrrrGkkkGrrrGkk  \n\
  kkGGGGGkkkGGGGGkk  \n\
  kkGrrrGGGGGrrrGkk  \n\
  kkGrrGrGrGrGrrGkk  \n\
  kkGrGrrGrGrrGrGkk  \n\
  kkGGrrrGrGrrrGGkk  \n\
  kk GGGGGGGGGGG kk  \n\
         kGk         \n\
         kGk         \n\
         kGk         \n\
         kGk         \n\
         kGk         \n\
        kkkkk        \n\
        kkkkk        ";


char *cabecaEsquerda="\
                     \n\
                     \n\
       kkkkkkkkkkkkk \n\
       kkkkkkkkkkkkk \n\
        GGGGGGGGGGG  \n\
       GGrrrGrGrrrGG \n\
       GrGrrGrGrrGrG \n\
       GrrGrGrGrGrrG \n\
kk     GrrrGGGGGrrrG \n\
kkkkkkkGGGGGkkGGGGGG \n\
kkGGGGGrrrrGkkGGrrrG \n\
kkkkkkkGGGGGkkGGGGGG \n\
kk     GrrrGGGGGrrrG \n\
       GrrGrGrGrGrrG \n\
       GrGrrGrGrrGrG \n\
       GGrrrGrGrrrGG \n\
        GGGGGGGGGGG  \n\
       kkkkkkkkkkkkk \n\
       kkkkkkkkkkkkk \n\
                     \n\
                     ";


char *coracao="\
                     \n\
                     \n\
    rrr       rrr    \n\
   rrrrr     rrrrr   \n\
  rrrrrrrr rrrrrrrr  \n\
 rrrrrrrrrrrrrrWrrrr \n\
rrrrrrrrrrrrrrWWWrrr \n\
rrrrrrrrrrrrrrrWWrrrr\n\
rrrrrrrrrrrrrrrWWrrrr\n\
rrrrrrrrrrrrrrrrWrrrr\n\
rrrrrrrrrrrrrrrrrrrrr\n\
 rrrrrrrrrrrrrrrrrrr \n\
  rrrrrrrrrrrrrrrrr  \n\
   rrrrrrrrrrrrrrr   \n\
    rrrrrrrrrrrrr    \n\
     rrrrrrrrrrr     \n\
      rrrrrrrrr      \n\
       rrrrrrr       \n\
        rrrrr        \n\
         rrr         \n\
          r          ";

//aqui está minha bala
char *balaDireita="\
                       \n\
                       \n\
                       \n\
                       \n\
                       \n\
                       \n\
   rr           rrr    \n\
   yrr           rrr   \n\
 yyyyrr           rrr  \n\
yyyyyyrrrrrrrrrrrrrrrr \n\
yyyyyyrrrrrrrrrrrrrrrrr\n\
yyyyyyrrrrrrrrrrrrrrrr \n\
 yyyyrr           rrr  \n\
   yrr           rrr   \n\
   rr           rrr    \n\
                       \n\
                       \n\
                       \n\
                       \n\
                       \n\
                     ";


char *balaEsquerda="\
                       \n\
                       \n\
                       \n\
                       \n\
                       \n\
                       \n\
    rrr           rr   \n\
   rrr           rry   \n\
  rrr           rryyyy \n\
 rrrrrrrrrrrrrrrryyyyyy\n\
rrrrrrrrrrrrrrrrryyyyyy\n\
 rrrrrrrrrrrrrrrryyyyyy\n\
  rrr           rryyyy \n\
   rrr           rry   \n\
    rrr           rr   \n\
                       \n\
                       \n\
                       \n\
                       \n\
                       \n\
                     ";

char *balaCima="\
          r          \n\
         rrr         \n\
        rrrrr        \n\
       rrrrrrr       \n\
      rrrrrrrrr      \n\
      rr rrr rr      \n\
      r  rrr  r      \n\
         rrr         \n\
         rrr         \n\
         rrr         \n\
         rrr         \n\
         rrr         \n\
         rrr         \n\
         rrr         \n\
         rrr         \n\
        rrrrr        \n\
       rrrrrrr       \n\
      rryyyyyrr      \n\
      ryyyyyyyr      \n\
      ryyyyyyyr      \n\
       yyyyyyy       \n\
       yyyyyyy       \n\
        yyyyy       ";


char *balaBaixo="\
       yyyyyyy       \n\
       yyyyyyy       \n\
       yyyyyyy       \n\
      ryyyyyyyr      \n\
      rryyyyyrr      \n\
       rryyyrr       \n\
        rrrrr        \n\
         rrr         \n\
         rrr         \n\
         rrr         \n\
         rrr         \n\
         rrr         \n\
         rrr         \n\
         rrr         \n\
         rrr         \n\
         rrr         \n\
      r  rrr  r      \n\
      rr rrr rr      \n\
      rrrrrrrrr      \n\
       rrrrrrr       \n\
        rrrrr        \n\
         rrr         \n\
          r          ";

char *micro="\
                     \n\
                     \n\
                     \n\
                     \n\
                     \n\
                     \n\
                     \n\
                     \n\
                     \n\
          r          \n\
         rrr         \n\
          r          \n\
                     \n\
                     \n\
                     \n\
                     \n\
                     \n\
                     \n\
                     \n\
                     \n\
                     ";
char *micro2="\
                     \n\
                     \n\
                     \n\
                     \n\
                     \n\
                     \n\
                     \n\
                     \n\
        r r r        \n\
         rWr         \n\
        rWyWr        \n\
         rWr         \n\
        r r r        \n\
                     \n\
                     \n\
                     \n\
                     \n\
                     \n\
                     \n\
                     \n\
                     ";

char *micro3="\
                     \n\
                     \n\
                     \n\
                     \n\
                     \n\
                     \n\
                     \n\
        r r r        \n\
       r rWr r       \n\
     r  rWyWr r      \n\
       rWryyWr       \n\
        rWyrr r      \n\
       r rWr r       \n\
          r          \n\
                     \n\
                     \n\
                     \n\
                     \n\
                     \n\
                     \n\
                     ";

char *micro4="\
                     \n\
                     \n\
                     \n\
                     \n\
                     \n\
                     \n\
          r  r r     \n\
      r  rWr  r      \n\
    r   rWyWr  r     \n\
     r rWryWWr  r    \n\
     rrWyWryrWr      \n\
    r  rWyryWr r     \n\
     r  rWyWr rr     \n\
       r rWr r       \n\
      r r r          \n\
            r        \n\
                     \n\
                     \n\
                     \n\
                     \n\
                     ";

char *micro5="\
                     \n\
                     \n\
                     \n\
                     \n\
           r         \n\
      r   r  r       \n\
    r r  rWr   r     \n\
     rr rWyWr   r    \n\
    r  ryrWyWr r     \n\
    r rWyWyrWWr  r   \n\
     rWWWyrWyWyr     \n\
      rWWryWyWr  r   \n\
     rrrWyryWr   r   \n\
     r  rryWr  r     \n\
      r rrWr r  r    \n\
       r  r          \n\
                     \n\
                     \n\
                     \n\
                     \n\
                     ";

char *micro6="\
                     \n\
                     \n\
                     \n\
        r  r  r      \n\
     r   rr  r       \n\
    r    rWr   r     \n\
        rWrWr   rr   \n\
  r  r rWyyWWr r     \n\
      rWyyWyWWr r    \n\
  r  rWWrWWyWyyr r  r\n\
    rWWyWyWyyWWWr  r \n\
   r rWWyWyWyyWr r r \n\
    r rWWyryWyr r    \n\
   r r rWyWyWr    r  \n\
    rr  rWyWr  rr r  \n\
      r  rWrr  r     \n\
        rrr   r      \n\
                     \n\
                     \n\
                     \n\
                     ";

char *micro7="\
                     \n\
                     \n\
             r       \n\
   r  r  rr   r      \n\
   r  r  rWr   r     \n\
   rr   rWWWr  r     \n\
       rWrWWWr  rr   \n\
  r   rWWyryWWr  r   \n\
  r  rWrWyWrrWWr r   \n\
    rWWWryWyyrWWr r r\n\
 r rWWWrWryryyrWWr   \n\
    rWrrWWrWyWyWr  r \n\
  r  rWyryyrWyWr  rr \n\
   r  rWWWyWrWr   r  \n\
 r     rWrWyWr  rr   \n\
   rr   rWyWr  r   rr\n\
      r  rWr  r rr r \n\
       r  r  r       \n\
         r r         \n\
                     \n\
                     ";

char *micro8="\
                     \n\
              r      \n\
      r   r   r      \n\
   r r   rWr    r    \n\
  r r r rWWWr  r     \n\
rr r   rWyryWr   rr  \n\
      rWyWyrWWr   r  \n\
  r  rWyWyWyrWWr  r  \n\
 r  rWWrWrrWWyyWr    \n\
   rWWrWWWWrWryWWr   \n\
  rWWWryyryyyWWWWWr  \n\
   rWyWWyyWyrWyWWr   \n\
    rWWWWrWWyyWWr r  \n\
 r   rWWyWWyyWWr  r  \n\
  r   rWWyyyWWr    r \n\
    r  rWyyWWr  r    \n\
   rr   rWWWr  r     \n\
       r rWr  r  r   \n\
  r   r   r   r   r  \n\
                     \n\
                     ";
char *micro9="\
     r               \n\
          r  r r r   \n\
   r rr  rWr r r  r r\n\
        rrWWr     r  \n\
   r  rrWyWWWr       \n\
  r rrrWWWyWWWr r    \n\
   r rWWyWyyrWWr r   \n\
 r  rWWrWWyyyrWWr    \n\
   rWWyyWyyyryyWWr r \n\
  rWWWrWWWWrWyWWWWr  \n\
 rWWrWWrWrWrWryrWWWr \n\
  rWWWyWyyWWyWrWWWrr \n\
 r rWWWyWyryyWyWWr   \n\
 r  rWWryWrWWrWWr    \n\
  r  rWWWyWrWWWr   r \n\
   r  rWWryrWrr  r   \n\
   r   rWWryWr   r   \n\
 r r  r rWWWr  r r   \n\
   r    rrWr   r     \n\
  r r     r   r  r   \n\
     r        r      ";

char *micro10="\
 rr rr r  r  r r r r \n\
r r r r rrWr r r r r \n\
 rr r r rWWWr r r r r\n\
r r  r rWyWWWr r rr  \n\
 r r rryWWyWWWr r r r\n\
 r r rWWyWryWWWrr r r\n\
r r rWWrWyWWyWWWrr   \n\
r rrWWyWrWyWWyyWWrr  \n\
  rWWrWyWrWyrWWWWWrr \n\
 rWWryyryyyryWWyWWWr \n\
rWWyWrWyWyrWWyWWyWWWr\n\
 rWWyyrWyWyWrryrWWWr \n\
  rWWWyrryyyWrWWWWrr \n\
r  rWWWyWWWWyrWWWrr  \n\
 r  rWWWyyWWWyWWr  r \n\
 r   rWWWWyrWWWrrr   \n\
  rr  rWWryyWWrr  r  \n\
r   r  rWWrWyr  rrr  \n\
 r r r  rWWWr   rr   \n\
  rr  r  rWr r rrr rr\n\
r   r  r  r  r rr r  ";

char *nada="\
WWWWWWWWWWWWWWWWWWWWW\n\
WWWWWWWWWWWWWWWWWWWWW\n\
WWWWWWWWWWWWWWWWWWWWW\n\
WWWWWWWWWWWWWWWWWWWWW\n\
WWWWWWWWWWWWWWWWWWWWW\n\
WWWWWWWWWWWWWWWWWWWWW\n\
WWWWWWWWWWWWWWWWWWWWW\n\
WWWWWWWWWWWWWWWWWWWWW\n\
WWWWWWWWWWWWWWWWWWWWW\n\
WWWWWWWWWWWWWWWWWWWWW\n\
WWWWWWWWWWWWWWWWWWWWW\n\
WWWWWWWWWWWWWWWWWWWWW\n\
WWWWWWWWWWWWWWWWWWWWW\n\
WWWWWWWWWWWWWWWWWWWWW\n\
WWWWWWWWWWWWWWWWWWWWW\n\
WWWWWWWWWWWWWWWWWWWWW\n\
WWWWWWWWWWWWWWWWWWWWW\n\
WWWWWWWWWWWWWWWWWWWWW\n\
WWWWWWWWWWWWWWWWWWWWW\n\
WWWWWWWWWWWWWWWWWWWWW\n\
WWWWWWWWWWWWWWWWWWWWW";

#endif
