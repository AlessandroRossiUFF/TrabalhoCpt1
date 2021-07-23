#include <stdio.h>
#include <stdlib.h>

struct jogada{
int linha;
int coluna;
};
typedef struct jogada Nova;

void iniciaTabuleiro(int tab[8][8]){
  for(int i=0; i<8; i++){
    for(int j=0; j<8; j++){
      tab[i][j]=0;
    }
  }
  tab[3][3]=1;
  tab[4][4]=1;
  tab[3][4]=-1;
  tab[4][3]=-1;
  //   //   //
  //tab[3][2]=1;
  //tab[5][3]=-1;
  //tab[6][4]=1;
};
void DesenhaTabuleiro(int tab[8][8]){
  printf("\n\n+    1   2   3   4   5   6   7   8    +\n");
  printf("   +---+---+---+---+---+---+---+---+\n");
  for(int i=0; i<8; i++){
    printf("%d  |", i+1);
    for(int j=0; j<8; j++){
      if(tab[i][j]>0){
        printf("  %d|", tab[i][j]);
      }else if(tab[i][j]==0){
        printf("   |");
      }else if(tab[i][j]<0){
        printf(" %d|", tab[i][j]);
      }
    }
    printf("  %d\n   +---+---+---+---+---+---+---+---+\n", i+1);
  }
  printf("+    1   2   3   4   5   6   7   8    +");
};
void EscolheJogada(Nova *nova){
  printf("\nEscreva a linha e a coluna onde quer colocar sua peça: ");
  scanf("%d %d", &nova[0].linha, &nova[0].coluna);
};
int ExecutaJogada(Nova *nova, int player, int tab[8][8]){
  int j=0, val=0;
  //  RIGHt
  if(tab[nova[0].linha-1][nova[0].coluna]==player*-1){
    while(tab[nova[0].linha-1][nova[0].coluna+j]==player*-1){
      j+=1;
    }
  if(tab[nova[0].linha-1][nova[0].coluna+j]!=player){
    j=0;
    }
  }
  for(int i=0; i<j; i++){
    tab[nova[0].linha-1][nova[0].coluna-1+i]=player;
    i+=1;
    tab[nova[0].linha-1][nova[0].coluna-1+i]=player;
    i-=1;
  }
  val+=j;
  j=0;
  //  LEFT
  if(tab[nova[0].linha-1][nova[0].coluna-2]==player*-1){
    while(tab[nova[0].linha-1][nova[0].coluna-2-j]==player*-1){
      j+=1;
    }
  if(tab[nova[0].linha-1][nova[0].coluna-2-j]!=player){
    j=0;
    }
  }
  for(int i=0; i<j; i++){
    tab[nova[0].linha-1][nova[0].coluna-1-i]=player;
    i+=1;
    tab[nova[0].linha-1][nova[0].coluna-1-i]=player;
    i-=1;    
  }
  val+=j;
  j=0;
  //  BAIXO
  if(tab[nova[0].linha][nova[0].coluna-1]==player*-1){
    while(tab[nova[0].linha+j][nova[0].coluna-1]==player*-1){
      j+=1;
    }
  if(tab[nova[0].linha+j][nova[0].coluna-1]!=player){
    j=0;
    }
  }
  for(int i=0; i<j; i++){
    tab[nova[0].linha-1+i][nova[0].coluna-1]=player;
    i+=1;
    tab[nova[0].linha-1+i][nova[0].coluna-1]=player;
    i-=1;        
  }
  val+=j;
  j=0;
  //  CIMA
  if(tab[nova[0].linha-2][nova[0].coluna-1]==player*-1){
    while(tab[nova[0].linha-2-j][nova[0].coluna-1]==player*-1){
      j+=1;
    }
  if(tab[nova[0].linha-2-j][nova[0].coluna-1]!=player){
    j=0;
    }
  }
  for(int i=0; i<j; i++){
    tab[nova[0].linha-1-i][nova[0].coluna-1]=player;
    i+=1;
    tab[nova[0].linha-1-i][nova[0].coluna-1]=player;
    i-=1;   
  }
  val+=j;
  j=0;
  //  CIMA LEFT
  if(tab[nova[0].linha-2][nova[0].coluna-2]==player*-1){
    while(tab[nova[0].linha-2-j][nova[0].coluna-2-j]==player*-1){
      j+=1;
    }
  if(tab[nova[0].linha-2-j][nova[0].coluna-2-j]!=player){
    j=0;
    }
  }
  for(int i=0; i<j; i++){
    tab[nova[0].linha-1-i][nova[0].coluna-1-i]=player;
    i+=1;
    tab[nova[0].linha-1-i][nova[0].coluna-1-i]=player;
    i-=1;   
  }
  val+=j;
  j=0;
  //  CIMA RIGHT
  if(tab[nova[0].linha-2][nova[0].coluna]==player*-1){
    while(tab[nova[0].linha-2-j][nova[0].coluna+j]==player*-1){
      j+=1;
    }
  if(tab[nova[0].linha-2-j][nova[0].coluna+j]!=player){
    j=0;
    }
  }
  for(int i=0; i<j; i++){
    tab[nova[0].linha-1-i][nova[0].coluna-1+i]=player;
    i+=1;
    tab[nova[0].linha-1-i][nova[0].coluna-1+i]=player;
    i-=1;   
  }
  val+=j;
  j=0;
  //  BAIXO RIGHT
  if(tab[nova[0].linha][nova[0].coluna]==player*-1){
    while(tab[nova[0].linha+j][nova[0].coluna+j]==player*-1){
      j+=1;
    }
  if(tab[nova[0].linha+j][nova[0].coluna+j]!=player){
    j=0;
    }
  }
  for(int i=0; i<j; i++){
    tab[nova[0].linha-1+i][nova[0].coluna-1+i]=player;
    i+=1;
    tab[nova[0].linha-1+i][nova[0].coluna-1+i]=player;
    i-=1;   
  }
  val+=j;
  j=0;
  //  BAIXO LEFT
  if(tab[nova[0].linha][nova[0].coluna-2]==player*-1){
    while(tab[nova[0].linha+j][nova[0].coluna-2-j]==player*-1){
      j+=1;
    }
  if(tab[nova[0].linha+j][nova[0].coluna-2-j]!=player){
    j=0;
    }
  }
  for(int i=0; i<j; i++){
    tab[nova[0].linha-1+i][nova[0].coluna-1-i]=player;
    i+=1;
    tab[nova[0].linha-1+i][nova[0].coluna-1-i]=player;
    i-=1;   
  }
  val+=j;
  // RETORNO
  if(val>0){
    val=1;
  }
  return val;
};

int main(void) {
  int tabuleiro[8][8], aux=0;
  Nova *p;
  int *tab, res, player=-1;
  p = (Nova*)malloc(sizeof(Nova));
  iniciaTabuleiro(tabuleiro);
  DesenhaTabuleiro(tabuleiro);
  printf("\n\nJogador da vez: %d\n", player);
  while(1){
    EscolheJogada(&p[0]);
    int res = ExecutaJogada(&p[0], player, tabuleiro);
    if(res){
      printf("\n\nJogada válida, passe a vez para o próximo jogador.\n");
      player*=-1;
    }else{
      printf("\n\nJogada inválida, jogue outra vez.\n");
    }
    DesenhaTabuleiro(tabuleiro);
    printf("\n\nJogador da vez: %d\n", player);
  }
  return 0;
};
