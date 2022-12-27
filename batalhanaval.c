#include <stdio.h>
#include <time.h>
char campo[10][10];
char campoMaquina[10][10];

int LimparCampo()
{
    for (int counter = 1; counter <= 10; counter++)
    {
        for (int count = 1; count <= 10; count++)
        {
            campo[counter][count] = 126;
            printf("%c  ", campo[counter][count]);
        }
        printf("\n");
    }
    return 0;
}
int Campo()
{
    for (int counter = 1; counter <= 10; counter++)
    {
        for (int count = 1; count <= 10; count++)
        {
            printf("%c  ", campo[counter][count]);
        }
        printf("\n");
    }
    return 0;
}
int CampoMaquina()
{
    for (int counter = 1; counter <= 10; counter++)
    {
        for (int count = 1; count <= 10; count++)
        {
            campoMaquina[counter][count] = 126;
            printf("%c  ", campoMaquina[counter][count]);
        }
        printf("\n");
    }
    return 0;
}

void Navio1()
{
    char nav[4][1];
    for (int x = 0; x < 4; x++)
    {
        nav[x][0] = 35;
    }
    for (int a = 0; a < 4; a++)
    {
        printf("%c \n", nav[a][0]);
    }
}

void Navio2()
{
    char nav[4][3];
    for (int x = 0; x < 4; x++)
    {
        if (x == 0 || x == 2 || x == 3)
        {
            nav[x][0] = 32;
            nav[x][2] = 32;
            nav[x][1] = 35;
            printf("%c %c %c \n", nav[x][0], nav[x][1], nav[x][2]);
        }
        if (x == 1)
        {
            nav[x][0] = 35;
            nav[x][1] = 35;
            nav[x][2] = 35;
            printf("%c %c %c\n", nav[x][0], nav[x][1], nav[x][2]);
        }
    }
}

void Navio3()
{
    char nav[2][5];
    for (int x = 0; x < 2; x++)
    {
        for (int y = 0; y < 5; y++)
        {
            if (x == 0 && y != 2)
            {
                nav[x][y] = 32;
            }
            if (x == 0 && y == 2)
            {
                nav[x][y] = 35;
            }
            if (x == 1)
            {
                nav[x][y] = 35;
            }
        }
        printf("%c %c %c %c %c \n", nav[x][0], nav[x][1], nav[x][2], nav[x][3], nav[x][4]);
    }
}


// variável para interromper o loop
int verificar = 0;
int Navio1Add(int linha, int coluna)
{
    int L, C, S;
    L = linha;
    C = coluna;
    if ( L + 4 <=10 ){
        for (int x = 0; x < 4; x++)
        {
            S = L+ x;
            if ( campo[S][C] == 126) 
            {
                campo[S][C] = 35;
            }
            verificar = 1;
        }
    }
    else {
        printf("Posicao invalida para alocar o navio 1, tente outra!\n");
    }
    return 0;
}
void Navio2Add(int linha, int coluna)
{
    int L = linha;
    int C = coluna;
    int S;

    if (L + 4 <=10 && C-1>0 && C+1 <=10)
    {
        for (int x = 0; x < 4; x++)
        {
            S = L+ x;
            if (campo[S][C] == 126 && campo[S][C-1] == 126 && campo[S][C+1] == 126)
            {
                if (x == 0 || x == 2 || x == 3)
                {
                    
                    campo[S][C] = 35;
                }
                if (x == 1)
                {
                    campo[S][C] = 35;
                    campo[S][C-1] = 35;
                    campo[S][C+1] = 35;                
                }
                verificar = 1;
            }
            
        } 
    }
    else {
        printf("Posicão inválida para alocar o navio 2, tente outra!\n");
    } 
}

void Navio3Add(int linha, int coluna)
{
    int L = linha;
    int C = coluna;
    int S;
    if (L+1 <=10 && C-2>0 && C+2 <=10)
    {
        for (int x = 0; x < 2; x++)
        {
            S = L + x;
            if (campo[S][C] == 126 && campo[S][C-2] == 126 && campo[S][C+2] == 126)
            {
                if (x == 0 && C == 2)
                {
                    campo[L][C] = 35;
                }
                if (x == 1)
                {
                    campo[S][C-2] = 35;
                    campo[S][C-1] = 35;
                    campo[S][C] = 35;
                    campo[S][C+1] = 35;
                    campo[S][C+2] = 35;
                }
                verificar = 1;
            } 
        }
    }
    else{
        printf("Local invalido para adicionar o navio 3, tente outro!\n");
    }
}


int main(){
    printf("========== Campo de batalha ==========\n");
    LimparCampo();
    printf("========== Navios disponiveis ==========\n");
    Navio1();
    Navio2();
    Navio3();

    // Posicionar os navios
    int linha, coluna;
    
    while (verificar ==0){
        printf("Qual linha e coluna voce quer posicionar o navio 1? linha[0-10] coluna[0-10]  ");
        scanf("%d %d", &linha, &coluna);
        Navio1Add(linha, coluna);
    }
    verificar=0;
    Campo();

    while ( verificar == 0 ){
        printf("Qual linha e coluna voce quer posicionar o navio 2? linha[0-10] coluna[0-10]");
        scanf("%d %d", &linha, &coluna);
        Navio2Add(linha, coluna);
    }
    verificar = 0;    
    Campo();

    while (verificar == 0)
    {
        printf("Qual linha e coluna voce quer posicionar o navio 3? linha[0-10] coluna[0-10]");
        scanf("%d %d", &linha, &coluna);
        Navio3Add(linha, coluna);
    }
    
    printf("========== Seu mapa ==================\n");
    Campo();

    printf("========== Mapa do oponente ==========\n");
    CampoMaquina();
    printf("Que os jogos comecem!");
    // Criar campo do computador

    // Criar sistema de batalha

    
    return 0;

}