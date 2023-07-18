
#include <stdio.h>
int main(){
    int s1=0, s2=0, s3=0, s4=0, s5=0,t1=0, t2=0, t3=0, t4=0, t5=0, password, semente, senha, tentativas, tentativa, cont=0, i, TempSenha, TempTentativa;
    printf("Bem vinda(o) ao Numle\n");
    printf("Digite a semente para sortear a senha (0 a 10000): ");
    scanf("%d", &semente);
    semente = semente % 134456;
    /* sorteia um numero ’aleatorio’ entre 0 e 99999 */
    senha = ((8121 * semente + 28411) % 134456) % 100000;
    password = senha;
    for(i = 0; i <5 ; i++){
            TempSenha = senha %10;
            if(i == 4){
                s1= TempSenha;
            }
            if(i == 3){
                s2= TempSenha;
            }   
            if(i == 2){
                s3= TempSenha;
            }
            if(i == 1){
                s4= TempSenha;
            }
            if(i == 0){
                s5= TempSenha;
            }
            senha = senha/ 10;
        } 
    printf("Quantidade de tentativas (1 a 10):");
    scanf("%d", &tentativas);
    printf("\n");
    while(tentativas > cont && (s1 != t1 || s2 != t2 || s3 != t3 || s4 != t4 || s5 != t5)){
        printf("Digite a tentativa (0 a 99999):");
        scanf("%d", &tentativa);
        for(i = 0; i <5 ; i++){
            TempTentativa = tentativa %10 ;

            if(i == 4){
                t1= TempTentativa;
            }
            if(i == 3){
                t2= TempTentativa;
            }
            if(i == 2){
                t3= TempTentativa;
            }
            if(i == 1){
                t4= TempTentativa;
            }
            if(i == 0){
                t5= TempTentativa;
            }
            tentativa = tentativa/10;
        }

        if(t1 != s1 || t2 != s2 || t3 != s3 || t4 != s4 || t5 != s5){
            if(t1 != s1){
                if((t1 == s5 && t5 != s5)|| (t1 == s2 && t2 != s2)|| (t1 == s3 && t3 != s3) || (t1 == s4 && t4 != s4))
                    printf("Primeiro digito em posicao incorreta.\n");
            }else{
                printf("Primeiro digito certo!\n");
            }

            if(t2 != s2){
                if((t2 == s1 && t1 != s1)|| (t2 == s5 && t5 != s5)|| (t2 == s3 && t3 != s3) || (t2 == s4 && t4 != s4))
                    printf("Segundo digito em posicao incorreta.\n");
            }else{
                printf("Segundo digito certo!\n");
            }

            if(t3 != s3){
                if((t3 == s1 && t1 != s1)|| (t3 == s2 && t2 != s2)|| (t3 == s5 && t5 != s5) || (t3 == s4 && t4 != s4))
                    printf("Terceiro digito em posicao incorreta.\n");
            }else{
                printf("Terceiro digito certo!\n");
            }

            if(t4 != s4){
                if((t4 == s1 && t1 != s1)|| (t4 == s2 && t2 != s2)|| (t4 == s3 && t3 != s3) || (t4 == s5 && t5 != s5))
                    printf("Quarto digito em posicao incorreta.\n");
            }else{
                printf("Quarto digito certo!\n");
            }

            if(t5 != s5){
                if((t5 == s1 && t1 != s1)|| (t5 == s2 && t2 != s2)|| (t5 == s3 && t3 != s3) || (t5 == s4 && t4 != s4))
                    printf("Quinto digito em posicao incorreta.\n");
            }else{
                printf("Quinto digito certo!\n");
            }
            cont++;
            if(cont < tentativas)
                printf("\n");
        }
        
        }
    if(s1 != t1 || s2 != t2 || s3 != t3 || s4 != t4 || s5 != t5){
        printf("Voce perdeu! A senha era %d.\n", password);
    }else{
        printf("Voce acertou! A senha eh de fato %d\n", password);
    }
    return 0;
}
