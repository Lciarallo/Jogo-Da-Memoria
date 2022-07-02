#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <unistd.h>

void matriz();
void matrizjogo(); 
void jogo();
int compare();
void loop();

void main()
{
    char matriz1[6][6] = {{'A', 'A', 'B', 'B', 'C', 'C'},
                          {'D', 'D', 'E', 'E', 'F', 'F'},
                          {'G', 'G', 'H', 'H', 'I', 'I'},
                          {'J', 'J', 'K', 'K', 'L', 'L'},
                          {'M', 'M', 'N', 'N', 'O', 'O'},
                          {'P', 'P', 'Q', 'Q', 'R', 'R'}};

    char matriz2[6][6] = {{'?', '?', '?', '?', '?', '?'},
                          {'?', '?', '?', '?', '?', '?'},
                          {'?', '?', '?', '?', '?', '?'},
                          {'?', '?', '?', '?', '?', '?'},
                          {'?', '?', '?', '?', '?', '?'},
                          {'?', '?', '?', '?', '?', '?'}};
    int op;

    printf("----------------------------------------------\n");
    printf("              JOGO DA MEMÓRIA\n");
    printf("----------------------------------------------\n");
    printf("\n[1] Jogar\n");
    printf("[2] Como jogar\n");
    printf("[3] Sair\n");

    printf("\nDigite a opção desejada: ");
    scanf("%d", &op);
    system("clear");

    if(op < 1 || op > 3){

            system("clear");
            printf("\nVocê digitou uma opção inválida, por favor digite a opção desejada: \n");
            main();
 
    }

    switch (op)
    {
    case 1:
        matriz(6, matriz1);
        printmatriz(6, matriz1);
        for(int x = 10; x > 0; x--){ 
            printf("Você tem %d segundos para memorizar\n", x);
            sleep(1);
            
        }
        system("clear");
        matrizjogo(6,matriz2 );
        loop(matriz1,matriz2);

        break;
        
        case 2:
            
            printf("----------------------------------------------\n");
            printf("                COMO JOGAR\n");
            printf("----------------------------------------------\n");

            puts("1. Selecione o numero 1 no menu em jogar;");
            puts("2. Você terá 10 segundos para memomrizar rapidamente os pares;");
            puts("3. Selecione as coordenadas da primerio elemtento(x1, y1) e do segundo (x2, y2);");
            puts("4. O programa comparará se os elementos formam um par identico ou não, retornando verdaeiro ou falso;");
            puts("");
            puts("");
            puts("Selecione 0 para retornar ao menu");
            scanf("%d", &op);
            if(op == 0){
                    system("clear");
                    main();
            }

        case 3:
            printf("Até logo!\n"); 
    }
}

void matriz(int t, char matriz1[t][t]){
    int i, lo, co, ld, cd;
    char temp;

    srand(time(NULL));
    for(i = 0; i <= 100000; i++){
        lo = rand() %6; //lo = linha origem
        co = rand() %6; //co = coluna origem
        ld = rand() %6; //ld = linha destino
        cd = rand() %6; //cd = coluna destino
        temp = matriz1[lo][co];
        matriz1[lo][co] = matriz1[ld][cd];
        matriz1[ld][cd] = temp;
    }
}

void printmatriz(int t, char matriz1[t][t]){
    int linha, coluna, i = 0;
    puts("  0     1     2     3     4     5 ");
    for(linha = 0; linha < t; linha++){
        
        puts("|---|-|---|-|---|-|---|-|---|-|---| ");
        for(coluna = 0; coluna < t; coluna++){
            printf("| %c | ", matriz1[linha][coluna]); 
            if(coluna == 5){ 
                printf("%d", i);
                i++;}
            
        }
        
        puts("");
        
    }
    puts("-----------------------------------\n ");
    printf("************************************************************************************************\n"); i = 0;


}

matrizjogo(int t, char matriz2[t][t], char matriz1[t][t]){
    int linha = 0, coluna=0, i = 0;
    puts("y");
    puts("  0     1     2     3     4     5 ");
    
        for(linha = 0; linha < t; linha++){
            
            puts("|---|-|---|-|---|-|---|-|---|-|---| ");
            for(coluna = 0; coluna < t; coluna++){
                printf("| %c | ", matriz2[linha][coluna]); 
                if(coluna == 5){ 
                    printf("%d", i);
                    i++;}
                
            }
            
            puts("");
            
        }
    puts("----------------------------------- x");



}

void loop(char matriz1[6][6],char matriz2[6][6]){
        int a,b,i,j,temp;
        puts("Digite os valores da primeira coordenada");
        puts("Insira o valor de x1:");
        scanf("%d", &a );
        puts("Insira o valor de y1':");
        scanf("%d", &b);
        printf("1.\t %d x %d = %c \n", a,b,matriz1[a][b]);
        puts("Digite os valores da segunda coordenada");
        puts("Insira o valor de x2:");
        scanf("%d", &i);
        puts("Insira o valor de y2:");
        scanf("%d", &j);
        compare(a,b,i,j, matriz1,matriz2);
}

int compare(int a,int b,int i, int j, char matriz1[6][6], char matriz2[6][6]){
    int op;
    char temp1 = 0, temp2 = 0;
    printf(" a = %d , b = %d, matriz1[%d][%d] = %c\n",a,b,a,b, matriz1[a][b] );
    printf(" a = %d , b = %d, matriz1[%d][%d] = %c\n",i,j,i,j, matriz1[i][j] );

    temp1 = matriz1[i][j]; 
    temp2 = matriz1[a][b]; 
    printf("temp1 = %c, temp2 = %c\n", temp1, temp2);
    if(temp1 == temp2){
        
        system("clear");
        puts("Verdadeiro!!!!!");
        matriz2[i][j] = matriz1[a][b];
        matriz2[a][b] = matriz1[i][j];
        matrizjogo(6,matriz2,matriz1);
        loop(matriz1,matriz2);
    }
    else{
        system("clear");
        printf("1.%d x %d = %c\n 2.%d x %d = %c\n", a,b,matriz1[a][b],i,j,matriz1[i][j]);
        puts("Falso");
        matrizjogo(6,matriz2,matriz1);
        loop(matriz1,matriz2);
    }

return 0;
}
