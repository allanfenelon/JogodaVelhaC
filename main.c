#include <stdio.h>
#include <stdlib.h>
#include "functions.h"
int main(){
    char entradaGame[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};

    jogadorgame pessoa1, pessoa2;
    pessoa1.peca = 'x';
    pessoa1.name = 'x';
    pessoa2.peca = 'O';
    pessoa2.name = 'O';
    int gameON = 0, localLivre=9, vezJogador=0;
    int linha, coluna;
    int gerenciador=0, condicaoigual=0;


    do{
        while(gameON != 1){
            system("clear"); //PARA LINUX
            tabuleiro(entradaGame[0][0],entradaGame[0][1],entradaGame[0][2],entradaGame[1][0],entradaGame[1][1],
                                        entradaGame[1][2],entradaGame[2][0],entradaGame[2][1],entradaGame[2][2]);
            if(vezJogador % 2 == 0){

                do{
                    do{
                        printf("\nVez do %c jogar!", pessoa1.name);
                        printf("\nDigite a Linha: ");
                        scanf("%d", &linha);
                        printf("\nDigite a Coluna: ");
                        scanf("%d", &coluna);
                        if(verificaespaco(entradaGame[linha-1][coluna-1])){
                            printf("Já tem peça nessa posição! Tente novamente\n");
                            condicaoigual=0;
                        }else{
                            condicaoigual=1;
                        }
                    }while(condicaoigual == 0);
                }while(linha < 1 || coluna < 1 || coluna > 3 || linha > 3);
                entradaGame[linha-1][coluna-1]='X';
            }else if(vezJogador % 2 != 0){
                do{
                    do{
                        printf("\nVez do %c jogar!", pessoa2.name);
                        printf("\nDigite a Linha: ");
                        scanf("%d", &linha);
                        printf("\nDigite a Coluna: ");
                        scanf("%d", &coluna);
                        if(verificaespaco(entradaGame[linha-1][coluna-1])){
                            printf("Já tem peça nessa posição! Teste novamente");
                            condicaoigual=0;
                        }else{
                            condicaoigual=1;
                        }
                    }while(condicaoigual == 0);
                }while(linha < 1 || coluna < 1 || coluna > 3 || linha > 3);
                entradaGame[linha-1][coluna-1]='O';
            }


            if(!verifica(entradaGame[0][0],entradaGame[0][1],entradaGame[0][2],entradaGame[1][0],entradaGame[1][1],
                                        entradaGame[1][2],entradaGame[2][0],entradaGame[2][1],entradaGame[2][2])){
                system("clear"); //PARA LINUX

                tabuleiro(entradaGame[0][0],entradaGame[0][1],entradaGame[0][2],entradaGame[1][0],entradaGame[1][1],
                                        entradaGame[1][2],entradaGame[2][0],entradaGame[2][1],entradaGame[2][2]);
                if(vezJogador % 2 == 0){
                    printf("\nO %c é o ganhador!", pessoa1.name);

                }else if(vezJogador % 2 != 0){
                    printf("\nO %c é o ganhador!", pessoa2.name);
                }
                do{
                    char jogardnv;
                    printf("\nVocê deseja jogar dnv? (S) - Sim (N) - Não: ");
                    scanf(" %c", &jogardnv);
                    if(jogardnv == 's' || jogardnv == 'S'){
                        system("clear"); //PARA LINUX

                        gameON = 0, localLivre=9, vezJogador=0;
                        gerenciador++;


                    }else if(jogardnv == 'N' || jogardnv == 'n'){
                        system("clear"); //PARA LINUX
                        printf("\nOk, você não deseja jogar! Até mais! ");
                        gameON = 1;
                        gerenciador++;
                    }else{
                        system("clear"); //PARA LINUX
                        printf("Opção inválida!, tente novamente! \n");
                        gerenciador=0;
                    }
                    for(int i=0; i<3; i++){
                        for(int j=0; j<3;j++){
                            entradaGame[i][j]= ' ';
                        }
                    }
                }while(gerenciador==0);

            }else if(localLivre==0){
                char jogardnv;
                printf("Você deseja jogar dnv? (S) - Sim (N) - Não: ");
                scanf("%c", &jogardnv);
                if(jogardnv == 's' || jogardnv == 'S'){

                }else if(jogardnv == 'N' || jogardnv == 'n'){
                    gameON = 1;
                }else{
                    printf("Opção inválida!");
                }
            }
            vezJogador++;
            localLivre--;
            printf("%d", localLivre);

        }


    }while(gameON != 1);

    return 0;
}
