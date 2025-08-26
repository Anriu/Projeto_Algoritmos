#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

int contador = 0;
char N[10][20]; //Nome dos pontos turisticos
int C[10]; // Quantidade de pessoa por ponto
int V[10]; // Visitas diarias
int T[10]; // Visita totais, onde cada indece do vetor T[] é equivalente a um local turistico
int resultado;

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

void registraVisita(char nome[][20],int quantidade[],int visitas[], int visitastotal[]){
    /*Ao registrar uma visita em um ponto turístico, o usuário deve
    indicar o nome do ponto turístico e a quantidade de pessoas na visita.*/
    char nomeEscolhido[20];
    int pessoas;
    
    system("cls");
    
    printf("Locais disponivels:\n");
    printf("%-25s | %-25s | %-25s |\n", "Nome Do local", "Quanditade maxima", "Quantidade Atual");
    
    for(int i = 0; i < contador; i ++){
        printf("%-25s | %-25d | %-25d |\n", nome[i], quantidade[i], visitas[i]);
    }
    
    printf("Informe em qual distino será a sua visita: ");
    gets(nomeEscolhido);
    printf("Invorme quantas pessoas irão para a visita: ");
    scanf("%d", &pessoas);

    for(int i = 0; i < contador; i ++){
        if (strcmp(nome[i], nomeEscolhido) == 0) {
            if(pessoas <= quantidade[i] && pessoas <= (quantidade[i] - visitas[i])){
                
                visitas[i] += pessoas;
                visitastotal[i] += pessoas;

            }else{
                printf("GENTE DE MAIS\n");
                system("pause");
            }      
        }
    }

}

void iniciarVisita(int visitas_diarias[]){
	//para zerar os valores do vetor V
	for (int i = 0; i < contador; i++) {
        visitas_diarias[i] = 0;
    }
    printf("Contador de visitas diarias zerado com sucesso. Inicie o registro de um novo dia!\n");
    system("pause");
}

void relatorioDiariodeVisitas(char pontos[][20], int quantidade[], int visitasatuais[]){
	system("cls");
	
    if (contador == 0) {
        printf("nenhum ponto turístico cadastrado.\n");
    } else{
        printf("Relatorio diario de visitas-\n");
        for(int i = 0; i < contador; i++){
        printf("_________________________________________\n");
		printf("Ponto turistico: %s\n", pontos[i]);
		printf("Capacidade: %d\n", quantidade[i]);
		printf("Visitates atuais: %d\n", visitasatuais[i]);
        
	    }
    }
	
    system("pause");
}

void relatorioTotaldeVisitas(char pontos[][20], int quantidade[], int visitasatotais[]){
    system("cls");
    printf("TOTAL DE VISITAS\n");
    if (contador == 0) {
        printf("nenhum ponto turístico cadastrado.\n");
    } else {
        for (int i = 0; i < contador; i++) {
        printf("_________________________________________\n");
        printf("ponto turístico: %s\n", pontos[i]);
        printf("Capacidade: %d\n", quantidade[i]);
        printf("Visitates totais: %d\n", visitasatotais[i]);
  
        }  
    } 
    system("pause");
}

void escolha(int resultado){
    switch (resultado){
            case 1:
                cadastrarPontoTuristico(N,C);
                break;
            case 2:
                registraVisita(N,C,V,T);
                break;
            case 3:
                iniciarVisita(V);
                break;
            case 4:
                relatorioDiariodeVisitas(N,C,V);
                break;
            case 5:
                relatorioTotaldeVisitas(N,C,T);
                break;
            
            default:
                system("cls");
                printf("Valor invalido\n");
                system("PAUSE");
                system("cls");
                break;
        }

}

void inicial(){
    for(int i = 0; i < 10; i++){
        T[i] = 0;//Vetor T sempre começa com 0 todos os pontos;
    }
    for(int i = 0; i < 10; i++){
        V[i] = 0;//Vetor V sempre começa com 0 todos os pontos;
    }
}



int main(){

    setlocale(LC_ALL, "Portuguese");
    inicial();

    do{
        resultado = menu();
        escolha(resultado);
    } while (resultado != 6);
    
    system("CLS");
    printf("Obrigado por utilizar nossos servicos  ");
    
    return 0;
}