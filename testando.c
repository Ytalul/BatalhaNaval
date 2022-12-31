#include <stdio.h>
#include <string.h>

char Letras[10] = { 'A', 'B', 'C' , 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
int ParseInt(char linhaa){
    toupper(linhaa);
    int Numero = linhaa-64;
    return Numero;
}

int main(){
    char Linha;
    scanf("%c", &Linha);
    int Numero = Linha-64;
    printf("%i", Numero);
    return 0;
}