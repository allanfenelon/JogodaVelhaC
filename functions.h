
typedef struct jogador{
    char peca;
    char name;
}jogadorgame;

void tabuleiro(char a11, char a12, char a13, char a21,
char a22, char a23, char a31, char a32, char a33){
    printf("\t      1     2     3");
    printf("\n\t 1    %c  |  %c  |  %c  \n", a11, a12, a13);
    printf("\t    -----|-----|------\n");
    printf("\t 2    %c  |  %c  |  %c  \n", a21, a22, a23);
    printf("\t    -----|-----|------\n");
    printf("\t 3    %c  |  %c  |  %c  \n", a31, a32, a33);

}
char verifica(char a11, char a12, char a13, char a21,
char a22, char a23, char a31, char a32, char a33){

    if((a11 == a12 && a12 == a13) && a11 != ' '){
        return 0;
    }else if((a21 == a22 && a22 == a23) && a21 != ' '){
        return 0;
    }else if((a31 == a32 && a32 == a33) && a31!= ' '){
        return 0;
    }else if((a11 == a21 && a21 == a31) && a11 != ' '){
        return 0;
    }else if((a12 == a22 && a22 == a32) && a12 != ' '){
        return 0;
    }else if((a13 == a23 && a23 == a33) && a13 != ' '){
        return 0;
    }else if((a11 == a22 && a22 == a33) && a11 != ' '){
        return 0;
    }else if((a31 == a22 && a22 == a31) && a31!= ' '){
        return 0;
    }else{
        return 1;
    }
}

char verificaespaco(char posVerificar){
    if(posVerificar != ' '){
        return 1;
    }else{
        return 0;
    }
}
