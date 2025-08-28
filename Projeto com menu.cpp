#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include <locale.h>

/*
    Autores:
    ANRIU OLIVEIRA DOS SANTOS
    HELDER SOARES LOPES FILHO
    JULLIA MARIA DE FREITAS SILVA
    KEVNE SOARES MIRANDA
    NAYELEN DOS SANTOS MENEZES
*/



char N[10][20]; //Nome dos pontos turisticos
int contador = 0; //Conta quantos foram os pontos turisticos cadastrados, para poder percorrer a matriz N e os vetores C V T com mais facilidade
int C[10]; // Quantidade de pessoa por ponto
int V[10]; // Visitas diarias
int T[10]; // Visita totais, onde cada indece do vetor T[] é equivalente a um local turistico
int resultado; //Variavel que recebe a escolha do menu; se resultado = 6 o programa se encerra



//Menu de opções, foi desenhando usando os carateres ┌ ─ ┐ ├ │ ┘ └
int menu(){
    int restultado;
    system("cls");
    printf("┌─────────────────────────────────────────┐\n");
    printf("│           MENU PRINCIPAL                │\n");
    printf("├─────────────────────────────────────────┤\n");
    printf("│ 1 - Cadastrar ponto Turístico           │\n");
    printf("│ 2 - Registrar visita                    │\n");
    printf("│ 3 - Iniciar visita diárias              │\n");
    printf("│ 4 - Relatório diário de visitas         │\n");
    printf("│ 5 - Relatório total de visitas          │\n");
    printf("│ 6 - Sair                                │\n");
    printf("└─────────────────────────────────────────┘\n");
    printf("O que deseja: ");
    scanf("%d", &restultado);
    getchar();
    return restultado;
    //Retorna a escolha de usuario para o main
}

void cadastrarPontoTuristico(char nome[][20], int quantidade[]){ 

    //Só podem ser registrados 10 pontos, caso tentem cadastrar um ponto a mais, o codigo não irá permitir
    system("cls");
    if(contador == 10){
        printf("Numero máximo de pontos turisticos cadastrados\n");
        system("pause");
        return;
    }

    printf("───────────────────Cadastro de Pontos Turísticos───────────────────\n");
    printf("Informe o nome do lugar: ");
    gets(nome[contador]);
    printf("Informe a quantidade de pessoas: ");
    scanf("%d", &quantidade[contador]);
    contador++; //A acada ponto registrado é incrementado 1 ao contador
}

void registraVisita(char nome[][20],int quantidade[],int visitas[], int visitas_total[]){
    /*Ao registrar uma visita em um ponto turístico, o usuário deve
    indicar o nome do ponto turístico e a quantidade de pessoas na visita.*/
    char nomeEscolhido[20];
    int pessoas;
    
    system("cls");
    printf("Locais Disponíveis\n");
    //Partindo do mesmo principio do menu, foi criado uma tabela com o Nome do local, a quantidade maxima e a quantidade de pessoas que estão la
    printf("┌─────────────────────────┬─────────────────────────┬─────────────────────────┐\n");
    printf("│ Nome do Local           │ Quantidade Máxima       │ Quantidade Atual        │\n");
    printf("├─────────────────────────┼─────────────────────────┼─────────────────────────┤\n");                                
    for(int i = 0; i < contador; i ++){
        //Mostra todos os dados dos pontos cadastrados
        printf("│ %-24s│%-25d│%-25d│\n", nome[i], quantidade[i], visitas[i]);
    }
    printf("└─────────────────────────┴─────────────────────────┴─────────────────────────┘\n");
    
    printf("Informe em qual distino será a sua visita (Digite Voltar para retornar ao menu.): ");
    gets(nomeEscolhido);

    int encontrado = 0;

    if(strcasecmp(nomeEscolhido, "voltar") == 0){
        return; //caso o usuario queira, é possivel retornar ao menu.
    } 


    //Como o usuario digitou um nome, temos que percorrer toda a matrix de nome para saber se existe um nome compativel
    for(int i = 0; i < contador; i++){
        if(strcasecmp(nome[i], nomeEscolhido) == 0){
            encontrado = 1; //Encontrado valida ou não se existe um nome correspondente na matriz
            printf("Informe quantas pessoas irão para a visita: ");
            scanf("%d", &pessoas);

            //Teste para saber se o ponto tem capacidade sufiente de abrigar as pessoas da visita
            if(pessoas <= quantidade[i] && pessoas <= (quantidade[i] - visitas[i])){    
                visitas[i] += pessoas; //Faz o calculo de pessoas da visita diaria
                visitas_total[i] += pessoas; //Faz o calculo de pessoas das visitas totais
                system("cls");
                printf("Visita realizada com sucesso!\n");
                system("pause");
            } else {
                system("cls");
                //Caso não tenha espaço suficiente no ponto para realizar 
                if(visitas[i] != 0){
                    printf("Lamentamos muito mas o limite total pessoas visitantes nesse local é de %d\n"
                           "e lá só se encontram %d vagas disponíveis,\n"
                           "sua quantidade de visitantes infelizmente excede o limite\n",
                           quantidade[i], quantidade[i] - visitas[i]);
                } else {
                printf("Lamentamos muito mas o limite total pessoas visitantes nesse local é de %d,\n"
                       "sua quantidade de visitantes infelizmente excede o limite\n",
                       quantidade[i]);
            }
                system("pause");
            }

            break; //Caso encontre o local o for em ecerrado
        }
    }

    //Caso o local não tenha sido econtrado 
    if(!encontrado){
        system("cls");
        printf("Local não encontrado, lamentamos muito.\nTecle Enter para voltar ao menu principal.\n");
        system("pause");
    }

}

void iniciarVisita(int visitas_diarias[]){
	//para zerar os valores do vetor V que representam as visitas diarias
	for (int i = 0; i < contador; i++) {
        visitas_diarias[i] = 0;
    }
    system("cls");
    printf("Contador de visitas diarias zerado com sucesso. Inicie o registro de um novo dia!\n");
    system("pause");
}

void relatorioDiariodeVisitas(char pontos[][20], int quantidade[], int visitas_atuais[]){
	system("cls");
	//Impirmie o registro das visitas que estão o correndo no momento
    if (contador == 0) {
        printf("Nenhum ponto turístico cadastrado.\n");
    } else{
        printf("Relatorio Diário de visitas-\n");
        for(int i = 0; i < contador; i++){
        printf("──────────────────────────────────────────────\n");
		printf("Ponto turistico: %s\n", pontos[i]);
		printf("Capacidade: %d\n", quantidade[i]);
		printf("Visitates atuais: %d\n", visitas_atuais[i]);
        printf("──────────────────────────────────────────────\n");
	    }
    }
	
    system("pause");
}

void relatorioTotaldeVisitas(char pontos[][20], int quantidade[], int visitasa_totais[]){
    system("cls");
    //Impirmie o registro das visitas totais que cada ponto teve
    if (contador == 0) {
        printf("Nenhum ponto turístico cadastrado.\n");
    } else {
        printf("Relatorio Total de visitas\n");
        for (int i = 0; i < contador; i++) {
        printf("──────────────────────────────────────────────\n");
        printf("ponto turístico: %s\n", pontos[i]);
        printf("Capacidade: %d\n", quantidade[i]);
        printf("Visitates totais: %d\n", visitasa_totais[i]);
        printf("──────────────────────────────────────────────\n");
  
        }  
    } 
    system("pause");
}

//Ao iniciar o programa todos os registros de visitas começam com 0
void inicial(){
    for(int i = 0; i < 10; i++){
        T[i] = 0;//Vetor T sempre começa com 0 todos os pontos;
    }
    for(int i = 0; i < 10; i++){
        V[i] = 0;//Vetor V sempre começa com 0 todos os pontos;
    }
}


int main(){


    //Como set Locale não está funcionando corretamente em alguma maquinas, utilizamos o SetConsoleOutputCP
    SetConsoleOutputCP(CP_UTF8); // força saída UTF-8
    SetConsoleCP(CP_UTF8);       // força entrada UTF-8


    inicial();

    do{
        resultado = menu();
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
                if(resultado != 6){
                    printf("Valor invalido\n");
                    system("PAUSE");
                }
                system("cls");
                break;
        }

    } while (resultado != 6);
    
    system("CLS");
    printf("Obrigado por utilizar nossos servicos!\n");
    
    return 0;
}