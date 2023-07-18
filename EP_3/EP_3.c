
#include <stdio.h>
#include <stdlib.h>
#define MAX 100
void inicializa(char campo[MAX][MAX], int N){
    int i,j;
    for( i = 0; i < N; i++){
        for(j = 0; j < N; j++){
            campo[i][j] = '-';
        }
    }
}

void torre (char campo[MAX][MAX], int posi, int posj, int tamanho){
    int i, j;
    for(i = posi, j = 0; j < tamanho; j++){
        if(i != posi || j != posj) campo[i][j] = 'o';
    }
    for(i = 0, j = posj; i < tamanho; i++){
        if(i != posi || j != posj) campo[i][j] = 'o';
    }

}

void bispo(char campo[MAX][MAX], int posi, int posj , int tamanho){
    int i,j; 
    
    for(i = posi+1, j = posj+1 ; i < tamanho && j < tamanho; i++, j++){
        campo[i][j] = 'o';
    }
    for(i = posi-1, j = posj-1 ; i >= 0 && j >= 0; i--,j--){
        campo[i][j] = 'o';
    }
    for(i = posi-1, j = posj+1 ; i >= 0 && j < tamanho; i--, j++){
        campo[i][j] = 'o';
    }
    for(i = posi+1, j = posj-1 ; i < tamanho && j >= 0; i++, j--){
        campo[i][j] = 'o';
    }
}

void cavalo(char campo[MAX][MAX],  int posi, int posj){
    if(posi+1 < MAX && posj+2 < MAX) campo[posi+1][posj+2] = 'o';
    if(posi+2 < MAX && posj+1 < MAX) campo[posi+2][posj+1] = 'o';
    if(posi+2 >= 0 && posj-1 < MAX) campo[posi+2][posj-1] = 'o';
    if(posi+1 < MAX && posj-2 >= 0) campo[posi+1][posj-2] = 'o';
    if(posi-1 >= 0 && posj-2 >= 0) campo[posi-1][posj-2] = 'o';
    if(posi-2 >= 0 && posj-1 >= 0) campo[posi-2][posj-1] = 'o';
    if(posi-2 >= 0 && posj+1 < MAX) campo[posi-2][posj+1] = 'o';
    if(posi-1 >= 0 && posj+2 < MAX) campo[posi-1][posj+2] = 'o';
}

void rei(char campo[MAX][MAX], int posi, int posj){
    if(posj+1 < MAX) campo[posi][posj+1] = 'o';
    if(posj+1 < MAX && posi+1 < MAX) campo[posi+1][posj+1] = 'o';
    if(posi+1 < MAX) campo[posi+1][posj] = 'o';
    if(posj-1 >= 0 && posi+1 < MAX) campo[posi+1][posj-1] = 'o';
    if(posj-1 >= 0) campo[posi][posj-1] = 'o';
    if(posj-1 >= 0 && posi-1 >= 0) campo[posi-1][posj-1] = 'o';
    if(posi-1 >= 0) campo[posi-1][posj] = 'o';
    if(posj+1 < MAX && posi-1 >= 0) campo[posi-1][posj+1] = 'o';


}

void imprime_campo(char campo[MAX][MAX], int tamanho){
    int i,j;
    for(i = 0; i < tamanho; i++){
        for(j = 0; j < tamanho; j++){
            if (campo[i][j] == 'o'){
                printf("-");
            }else{
                printf("%c", campo[i][j]);
            }
        }
        printf("\n");
    }
    printf("\n\n");
}

void imprime_frequencia(float frequencia[MAX][MAX], int tamanho){
    int i,j;
    for(i = 0; i < tamanho; i++){
        for(j = 0; j < tamanho; j++){
            printf("%.4f ", frequencia[i][j]);
        }
        printf("\n");
    }
    printf("\n\n");
}


/*procura em uma linha do campo todas a posições validas e armazena sua coordenadas em um vetor
e retorna o numero de posçõs validas*/
int procura_posicoes_validas(char campo[MAX][MAX], int posicao_valida[], int tamanho, int linha){
    int j, cont=0;
    for(j = 0; j < tamanho; j++){
        if(campo[linha][j] != 'o'){
            posicao_valida[cont] = j;
            cont ++;
        }
    }
    return cont; 
}

void recursion(char campo[MAX][MAX], int tamanho,int linha, int b, int c,int r, int v,int f,int *cont_valida, 
int *total,float frequencia[MAX][MAX]){
    int cont, pos_val[tamanho], coluna, i, j;
    char campo_temp[MAX][MAX];
    cont = procura_posicoes_validas(campo, pos_val,tamanho,linha);
    *cont_valida = *cont_valida + 1;
    if(cont > 0){
        for(coluna = 0; coluna < cont; coluna++){
            /*armazena o campo em uma variavel temporária para que que o campo possa ser usada de forma recursiva*/
            for(i = 0; i < tamanho; i++){
                for(j = 0; j < tamanho; j++){
                    campo_temp[i][j] = campo[i][j];
                }
            }
            campo_temp[linha][pos_val[coluna]] = 'X';
            movimentos(campo_temp,b,c,r,linha,pos_val[coluna],tamanho);

            if(linha+1 < tamanho) recursion(campo_temp, tamanho, linha+1, b, c, r,v,f,cont_valida,total,frequencia);
            
            if(*cont_valida == tamanho) *total = *total + 1; 

            if(*cont_valida == tamanho && v == 1){
                imprime_campo(campo_temp, tamanho); 
            } 

            if (*cont_valida == tamanho && f == 1){
                for(i = 0; i < tamanho; i++){
                    for(j = 0; j < tamanho; j++){
                        if (campo_temp[i][j] == 'X') frequencia[i][j] = frequencia[i][j] + 1;
                    }
                }
            }
        }
    }
        *cont_valida = *cont_valida -1;

    
}

void movimentos(char campo[MAX][MAX],int b, int c, int r, int posi, int posj, int tamanho){
    torre(campo,posi,posj,tamanho);
    if(b == 1) bispo(campo,posi,posj,tamanho);
    if(c == 1) cavalo(campo,posi,posj);
    if(r == 1) rei(campo,posi,posj);
}

void inicia_frequencia(float frequencia[MAX][MAX], int tamanho){
    int i, j;
    for(i = 0; i < tamanho; i++){
        for(j = 0; j < tamanho; j++){
            frequencia[i][j] = 0;
        }
    }
}

void generate(int N, int b, int c, int r, int f, int v){
    int i,j,k, cont_valida = 1,total = 0;
    char campo[MAX][MAX];
    float frequencia[MAX][MAX];
    inicia_frequencia(frequencia,N);
    /*este for indica que o programa vai percorrer aprimeira linha*/
    for(k = 0; k < N; k++){
        inicializa(campo,N);
        campo[0][k] = 'X';
        movimentos(campo,b,c,r,0,k,N);
        recursion(campo,N,1,b,c,r,v,f,&cont_valida,&total,frequencia);
    }
    printf("Total de solucoes: %d\n\n", total);

    if (f == 1){
        for(i = 0; i < N; i++){
            for(j = 0; j < N; j++){
                frequencia[i][j] = frequencia[i][j]/total;
            }
        }
        imprime_frequencia(frequencia,N);
    }
}

int main(int argc, char *argv[]) {

    int N = atoi(argv[1]);
    int b = atoi(argv[2]);
    int c = atoi(argv[3]);
    int r = atoi(argv[4]);
    int f = atoi(argv[5]);
    int v = atoi(argv[6]);
    generate(N, b, c, r, f, v);
    return 0;
}