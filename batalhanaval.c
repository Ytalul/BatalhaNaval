#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
char campo[10][10];
char campoMaquina[10][10];
char campoMaquinaCopia[10][10];
char Letras[10] = { 'A', 'B', 'C' , 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
// variável que valida se as funções estão sendo utilizadas corretamente em sequência
int verificar = 0;

// estrutura para cuidar dos campos
void LimparCampo()
{
    for (int counter = 1; counter <= 10; counter++)
    {
        for (int count = 1; count <= 10; count++)
        {
            campo[counter][count] = 126 ;
        }
    }
}
void Campo()
{
    int x= 0;
    printf("    1  2  3  4  5  6  7  8  9  10\n");
    for (int counter = 1; counter <= 10; counter++)
    {   
        printf(" %c  ", Letras[x]);       
        for (int count = 1; count <= 10; count++)
        {
            printf("%c  ", campo[counter][count]);
        }
        x ++;
        printf("\n");
    }
}
void LimparCampoMaquina()
{
    for (int counter = 1; counter <= 10; counter++)
    {
        for (int count = 1; count <= 10; count++)
        {
            campoMaquina[counter][count] = 126;
        }
    }
}
void CampoMaquina()
{
    for (int counter = 1; counter <= 10; counter++)
    {
        for (int count = 1; count <= 10; count++)
        {
            printf("%c  ", campoMaquina[counter][count]);
        }
        printf("\n");
    }
}
void LimparCampoMaquinaCopiado()
{
    for (int counter = 1; counter <= 10; counter++)
    {
        for (int count = 1; count <= 10; count++)
        {
            campoMaquinaCopia[counter][count] = 126;
        }
    }
}
void CampoMaquinaCopiado()
{
    int x= 0;
    printf("    1  2  3  4  5  6  7  8  9  10\n");
    for (int counter = 1; counter <= 10; counter++)
    {
        printf(" %c  ", Letras[x]);  
        for (int count = 1; count <= 10; count++)
        {
            printf("%c  ", campoMaquinaCopia[counter][count]);
        }
        x ++;
        printf("\n");
    }
}

// navios iniciais 
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

// Funções para adicionar os navios nos seus respectivos campos
int Navio1Add(int linha, int coluna)
{
    int L, C, S;
    L = linha;
    C = coluna;
    if ( L + 3 <=10 ){
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
    if (L + 3 <=10 && C-1>0 && C+1 <=10 && campo[L][C] == 126 
    && campo[L+1][C-1] == 126 && campo[L+1][L+1] == 126 && campo[L+1][C] == 126 
    && campo[L+2][C] == 126 && campo[L+3][C] == 126)
    {
            campo[L][C] = 35;
            campo[L+1][C] = 35;
            campo[L+1][C-1] = 35;
            campo[L+1][C+1] = 35;
            campo[L+2][C] = 35;
            campo[L+3][C] = 35;
            verificar = 1;
    }
    else { printf("Posicao invalida para alocar o navio 2, tente outra!\n"); } 
}
void Navio3Add(int linha, int coluna)
{
    int L = linha;
    int C = coluna;
    int S;
    if (L+1 <=10 && C-2>0 && C+2 <=10 && campo[L][C]  != 35 && campo[L+1][C-2]!= 35 && campo[L+1][C-1] != 35
        && campo[L+1][C]!= 35 && campo[L][C+2] != 35 && campo[L][C+1]!= 35 )
    {
        campo[L][C] = 35;
        campo[L+1][C-2] = 35;
        campo[L+1][C-1] = 35;
        campo[L+1][C] = 35;
        campo[L+1][C+1] = 35;
        campo[L+1][C+2] = 35;
        verificar = 1;
        }
    else { printf("Posicao invalida para adicionar o navio 3, tente outro!\n");}
}
void Navio1AddMaquina(int linha, int coluna)
{
    int L, C, S;
    L = linha;
    C = coluna;
    if ( L + 3 <=10 && campoMaquina[L][C] == 126 && campoMaquina[L+1][C] == 126 && campoMaquina[L+2][C] == 126 && campoMaquina[L+3][C] == 126 ){
        for (int x = 0; x < 4; x++)
        {
            S = L+ x;
            campoMaquina[S][C] = 35;
        }
        verificar = 1;
    }
}
void Navio2AddMaquina(int linha, int coluna)
{
    int L = linha;
    int C = coluna;
    // validações de campo para saber se pode adicionar o navio naquela posição
    if (L + 3 <=10 && C-1>0 && C+1 <=10 && campoMaquina[L][C] == 126 
    && campoMaquina[L+1][C-1] == 126 && campoMaquina[L+1][L+1] == 126 && campoMaquina[L+1][C] == 126 
    && campoMaquina[L+2][C] == 126 && campoMaquina[L+3][C] == 126)
    {
        campoMaquina[L][C] = 35;
        campoMaquina[L+1][C] = 35;
        campoMaquina[L+1][C-1] = 35;
        campoMaquina[L+1][C+1] = 35;
        campoMaquina[L+2][C] = 35;
        campoMaquina[L+3][C] = 35;
        verificar = 1;
    }
}
void Navio3AddMaquina(int linha, int coluna)
{
    int L = linha;
    int C = coluna;
    int S;
    if (L+1 <=10 && C-2>0 && C+2 <=10 && campoMaquina[L][C] == 126 && campoMaquina[L+1][C-2]==126 && campoMaquina[L+1][C-1] == 126 
        && campoMaquina[L+1][C]==126 && campoMaquina[L][C+2] == 126 && campoMaquina[L][C+1]==126)
    {
        for (int x = 0; x < 2; x++)
        {
            S = L + x;
                if (x == 0)
                {
                    campoMaquina[L][C] = 35;
                }
                if (x == 1)
                {
                    campoMaquina[S][C-2] = 35;
                    campoMaquina[S][C-1] = 35;
                    campoMaquina[S][C] = 35;
                    campoMaquina[S][C+1] = 35;
                    campoMaquina[S][C+2] = 35;
                }
        }
        verificar = 1;
    }
}

int NumeroAleatorio(int x){
    int Numero = (rand() % x)+1;
    return Numero;
}

// funções para validar as jogadas da máquina ----------------------------------------------------------
void tiroMal(int lin, int col){
    campo[lin][col]= 32;
    printf("O adversario errou o tiro! \n");
    Campo();
}

int main(){

    // Tela inicial ---------------------------------------------------------------------
    LimparCampoMaquina();
    LimparCampo();
    LimparCampoMaquinaCopiado();
    printf("========== Campo de batalha ==========\n");
    Campo();
    printf("========== Navios disponiveis ==========\n");
    printf("(Navio 1)\n");
    Navio1();
    printf("(Navio 2)\n");
    Navio2();
    printf("(Navio 3)\n");
    Navio3();

    // Configurações do mapa do jogador ---------------------------------------------------
    int linha, coluna;
    char linhaChar;
    while (verificar == 0){
        printf("\nQual linha e coluna voce quer posicionar o navio 1? linha[A-J] coluna[0-10]");
        scanf( "%c%d",&linhaChar,&coluna);
        fflush(stdin);
        linha= linhaChar-64;
        Navio1Add(linha, coluna);}
    verificar=0;
    Campo();

    while ( verificar == 0 ){
        printf("\nQual linha e coluna voce quer posicionar o navio 2? linha[A-J] coluna[0-10]");
        scanf( "%c%d", &linhaChar, &coluna);
        fflush(stdin);
        linha= linhaChar-64;
        Navio2Add(linha, coluna);}
    verificar = 0;    
    Campo();

    while (verificar == 0)
    {
        printf("\nQual linha e coluna voce quer posicionar o navio 3? linha[A-J] coluna[0-10]");
        scanf( "%c%d", &linhaChar, &coluna);
        fflush(stdin);
        linha= linhaChar-64;
        Navio3Add(linha, coluna);}
    verificar = 0;
    printf("========== Seu mapa ==================\n");
    Campo();

    // configurações no mapa da maquina ----------------------------------------------------------
    int LinhaAleatoria, ColunaAleatoria;
    srand(time(NULL));
    while (verificar == 0)
    {
        LinhaAleatoria = NumeroAleatorio(10);
        ColunaAleatoria= NumeroAleatorio(10);
        Navio1AddMaquina(LinhaAleatoria, ColunaAleatoria);
    }
    verificar = 0; 
    while (verificar == 0)
    {
        LinhaAleatoria = NumeroAleatorio(10);
        ColunaAleatoria= NumeroAleatorio(10);
        Navio2AddMaquina(LinhaAleatoria, ColunaAleatoria);
    }
    verificar = 0;
    while (verificar == 0)
    {
        LinhaAleatoria = NumeroAleatorio(10);
        ColunaAleatoria= NumeroAleatorio(10);
        Navio3AddMaquina(LinhaAleatoria, ColunaAleatoria);
    }
    verificar = 0;
    printf("\n========== Mapa do oponente ==========\n");
    CampoMaquinaCopiado();
    printf("\n==========Que os jogos comecem!==========");

    // SISTEMA DE BATALHA  ------------------------------------------------------------------------
    int NaviosPlayer =0, NaviosMaquina=0;
    while (NaviosPlayer<16 || NaviosMaquina < 16)
    {
        int colunaAtkJogador, linhaAtkJogador;
        char linhaChar;
        int JogadaValida = 0;
        while ( JogadaValida == 0 ){
        printf("\nEscolha uma linha e coluna adversaria para atacar! linha[A-J] coluna[1-10] : \n");
        scanf( "%c%d", &linhaChar, &colunaAtkJogador);
        fflush(stdin);
        linhaAtkJogador = linhaChar-64;
        if ( campoMaquina[linhaAtkJogador][colunaAtkJogador] == 35 )
        {
            campoMaquinaCopia[linhaAtkJogador][colunaAtkJogador] = 88;
            campoMaquina[linhaAtkJogador][colunaAtkJogador] = 88;
            printf("\nVoce acertou o alvo!!!\n");
            NaviosMaquina=1;
            JogadaValida = 1;
        }
        else if ( campoMaquina[linhaAtkJogador][colunaAtkJogador] == 88 || campoMaquina[linhaAtkJogador][colunaAtkJogador] == 32 ){
            printf("\nVoce ja atacou este campo!\n");
            JogadaValida = 0;
        }
        else {
            campoMaquinaCopia[linhaAtkJogador][colunaAtkJogador] = 32;
            campoMaquina[linhaAtkJogador][colunaAtkJogador] = 32;
            printf("\nVoce errou :( \n");
            JogadaValida = 1;
        }
        }
        CampoMaquinaCopiado();
        printf("\nVez do adversario!\n");

        // Verificar se a maquina nao vai jogar no mesmo lugar repetidamente  
        int linhaAtkMaquina=0 , colunaAtkMaquina=0;
        JogadaValida = 0;
        while (JogadaValida == 0 )
        {
            linhaAtkMaquina = NumeroAleatorio(10);
            colunaAtkMaquina = NumeroAleatorio(10);
            if ( campo[linhaAtkMaquina][colunaAtkMaquina] == 35 || campo[linhaAtkMaquina][colunaAtkMaquina]== 126 ){
                JogadaValida= 1;    }
            else { 
                JogadaValida = 0; 
                }
            }
        
        // Caso a ultima jogada tenha acertado o alvo -----------------------
        int linhaUltimoTiro=0 , colunaUltimoTiro=0;
        int linhaPenulTiro=0, colunaPenulTiro=0;
        if ( linhaUltimoTiro != 0 || linhaPenulTiro != 0)
        {   
            int linhaCerta, colunaCerta;
            if ( linhaUltimoTiro!=0 ){
                linhaCerta = linhaUltimoTiro;
                colunaCerta = colunaUltimoTiro;
            }
            else {  
                linhaCerta = linhaPenulTiro;
                colunaCerta = colunaPenulTiro;
                linhaUltimoTiro= linhaPenulTiro;  
                colunaUltimoTiro = colunaPenulTiro;
            }
            int proximoTiro = NumeroAleatorio(4);
            if ( proximoTiro == 1 && campo[linhaCerta+1][colunaCerta] == 35 )
            {
                campo[linhaCerta+1][colunaUltimoTiro] = 88;
                linhaUltimoTiro = linhaUltimoTiro+1;
                printf("\nVoce foi atacado!!!\n");
                Campo();
            }
            else {tiroMal(linhaCerta+1,colunaCerta); break;}
            
            if ( proximoTiro == 2 && campo[linhaCerta-1][colunaCerta] == 35 )
            {
                campo[linhaCerta-1][colunaCerta] = 88;
                linhaUltimoTiro = linhaUltimoTiro-1;
                printf("\nVoce foi atacado!!!\n");
                Campo();
            }
            else {tiroMal(linhaCerta-1,colunaCerta); break;}

            if ( proximoTiro == 3 && campo[linhaCerta][colunaCerta-1] == 35 )
            {
                campo[linhaCerta][colunaCerta-1] = 88;
                colunaUltimoTiro = colunaUltimoTiro-1;
                printf("\nVoce foi atacado!!!\n");
                Campo();
            }
            else {tiroMal(linhaCerta,colunaCerta-1); break;}

            if ( proximoTiro == 4 && campo[linhaCerta][colunaCerta+1] == 35 )
            {
                campo[linhaCerta][colunaCerta+1] = 88;
                colunaUltimoTiro = colunaUltimoTiro+1; 
                printf("\nVoce foi atacado!!!\n");
                Campo();
            }
            else {tiroMal(linhaCerta+1,colunaCerta); break;}
        }
        // Caso a ultima jogada nao tenha acertado o alvo ----------------------
        else if ( campo[linhaAtkMaquina][colunaAtkMaquina] == 35 )
        {
            campo[linhaAtkMaquina][colunaAtkMaquina] = 88;
            linhaUltimoTiro = linhaAtkMaquina;
            colunaUltimoTiro = colunaAtkMaquina;
            printf("\nVoce foi atacado!!!\n");
            Campo();
        }
        else {
            linhaUltimoTiro = 0;
            colunaUltimoTiro = 0;
            linhaPenulTiro = linhaUltimoTiro;
            colunaPenulTiro = colunaUltimoTiro;
            tiroMal(linhaAtkMaquina,colunaAtkMaquina);
        }
    }

    if ( NaviosPlayer == 16 ){
        printf("Parabens, voce ganhou o jogo!");
    }
    else { 
        printf("Voce foi derrotado");
    }
    printf("Fim de jogo.");
    return 0;
}
