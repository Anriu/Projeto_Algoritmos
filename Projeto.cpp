#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
int contador = 0;

int menu(){

    int restultado;
    system("cls");
    printf("Tecle a opção desejada: \n");
    printf("1 - Cadastrar ponto Turístico\n");
    printf("2 - Registrar visita\n");
    printf("3 - Iniciar visita\n");
    printf("4 - Relatório diário de visitas\n");
    printf("5 - Relatório total de visitas\n");
    printf("6 - sair\n");
    printf("O que deseja: ");
    scanf("%d", &restultado);
    getchar();
    return restultado;

}

void cadastrarPontoTuristico(char nome[][20], int quantidade[]){ 
    system("cls");
    printf("Informe o nome do lugar: \n");
    gets(nome[contador]);
    printf("Informe a quantidade de pessoas: \n");
    scanf("%d", &quantidade[contador]);
    contador++; 
}

void registraVisita();

void iniciarVisita(){

}

void relatorioDiariodeVisitas(){

}

void relatorioTotaldeVisitas(){

}

int main(){
    //Recebe o nome do ponto turistico
    char N[10][20];
    int C[10];
    int resultado;

    do{
        resultado = menu();
        switch (resultado){
        case 1:
            cadastrarPontoTuristico(N,C);
            break;
        case 2:
           
            break;
        case 3:

            break;
        case 4:
        
            break;
        case 5:

           break;
        
        default:
            system("cls");
            printf("Valor invalido\n");
            system("PAUSE");
            system("cls");
            break;
        }
    } while (resultado != 6);
    
    system("CLS");
    printf("Obrigado por utilizar nossos servicos");
    
    return 0;
}