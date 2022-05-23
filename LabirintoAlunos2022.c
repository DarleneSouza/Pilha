#include <stdio.h>
#include "pilhaEncadeada.h"
#include <stdlib.h>
#define MAX 15

void cria(char l[MAX][MAX]){
     int i,j,x,y;
     srand(time(NULL));
     for(i=0;i<MAX;i++)
        for(j=0;j<MAX;j++){
          if((rand()%5)==1)
             l[i][j]='|';
             else
              l[i][j]='.';
          }
     for(i=0;i<MAX;i++){
           l[0][i]='*';
           l[MAX-1][i]='*';
           l[i][0]='*';
           l[i][MAX-1]='*';
           }// fim for
        x=  rand() % MAX;
        y=  rand() % MAX;
        l[x][y]='Q';
     }// fim funcao cria
     
void mostraLabirinto(char mat[MAX][MAX],int linha,int col){
    int i,j;
     for ( i = 0; i < linha; i++)
    {
     printf("\n");
          for ( j = 0; j < col; j++)
			printf (" %c ",mat[i][j] );
     	}

     } // fim funcao
     
 int funcaoSuperMouse(char lab[MAX][MAX],int i, int j){
     tpilha p1;
     inicializa(&p1);
     tdado pos;
     do{
     	lab[i][j] = 'v';
     	if(lab[i][j+1]=='.'||lab[i][j+1]=='Q')//ou se for o queijo tb
		{
			pos.i = i; 
			pos.j = j;
			push (&p1,pos);
			j++;// vai para prox
			
		}//fim if dir j+1
		
		//else  if baixo i+1
		else if(lab[i+1][j]=='.'||lab[i+1][j]=='Q'){
			pos.i = i;
			pos.j = j;
			push(&p1,pos);
			i++;
		}//fim if dir i++
		
		//else  if esq j-1
		else if(lab[i][j-1]=='.'||lab[i][j-1]=='Q'){
			pos.i = i;
			pos.j = j;
			push(&p1,pos);
			j--;
		}//fim if dir j--
		
		//else  if cima i-1
		else if(lab[i-1][j]=='.'||lab[i-1][j]=='Q'){
			pos.i = i;
			pos.j = j;
			push(&p1,pos);
			i--;
		}//fim if dir i--
		
		//else  tento voltar
		else{
			if(!isEmpty(p1)){
				lab[i][j] = 'x';
				pos = pop(&p1);
				i = pos.i;
				j = pos.j;
				
			}else{
				printf("impossivel :(");
				return 0;
			}
		}
     	
     	Sleep(300);
     	system("cls");
     	mostraLabirinto(lab,MAX,MAX);
     	
	 }while(lab[i][j]!= 'Q');//enquanto nao achar o queijo i,j != 'Q'
	 //if achou
	 	if(lab[i][j]== 'Q'){
	 		printf("\nAchei o queijo na pos: %d,%d",i,j);
		 }
	 	// achei o queijo na pos i,j

 }// fim funcao



int main(){
    char labirinto[MAX][MAX];
    int x,y;
    cria(labirinto);
    mostraLabirinto(labirinto,MAX,MAX);
    printf("\nEntre com a posicao inicial:");
    scanf("%d %d",&x,&y);
    funcaoSuperMouse(labirinto,x,y);
    getch();
    }
