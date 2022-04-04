/*
Universidade Federal do Rio Grande do Sul
INF01202 - Trabalho Final
Turma I
Nome do Aluno : Arthur da Rosa Hahn
Cartao UFRGS : 00306037
*/
/* Programa que administra a logística de uma locadora de carros (LocAU!).
Esse arquivo é o principal. Funções não serão específicadas neste, somente chamadas. */

#include <stdio.h>
#include <string.h>
#include <unistd.h> // para implementar a função sleep
#include "clientes.h"
#include "carros.h"
#include "aluguel.h"

int main()
{
    int op, x, cod_cliente, cod_carro, cod_aluguel;
    char marca[MAX];
    clientes_t cliente[MAX] = {0};
    carros_t carro[MAX] = {0};
    aluguel_t aluguel[MAX] = {0};

    FILE *arq_clientes = fopen("clientes.csv", "r"); //LEITURA CLIENTES
    if (arq_clientes == NULL){
        printf("\nProblema na abertura do arquivo clientes.\n");
        return 0;
    }
    leitura_clientes(arq_clientes, &cliente);
    fclose(arq_clientes);

    FILE *arq_carros = fopen("carros.csv", "r"); //LEITURA CARROS
    if (arq_carros == NULL){
        printf("\nProblema na abertura do arquivo carros.\n");
        return 0;
    }
    leitura_carros(arq_clientes, &carro);
    fclose(arq_carros, &carro);

    FILE *arq_alugueis = fopen("alugueis.bin", "r"); //LEITURA ALUGUEIS
    if (arq_alugueis == NULL){
        printf("\nProblema na abertura do arquivo alugueis.\n");
        return 0;
    }
    leitura_alugueis(arq_alugueis, &aluguel);
    fclose(arq_alugueis);


    printf("Sistema de logistica da empresa LocAU!\n");
    do
    {
        //sleep(200); // delay na tela, pro programa ficar mais apresentavel
        //system("cls");
        op = menu();
        switch (op)
        {
        case 1: // cadastro de clientes ou carros
            do {
                x = menu_cadastro();
                if (x==1){  // cadastro de clientes
                    novo_cliente(&cliente);
                }
                if (x==2){  // cadastro de carros
                    novo_carro(&carro);
                }
            } while (x!= 3 && x<3);
        break;

        case 2:// realização de alguel
            do {
                x = menu_alugar();
                if x(==1){
                    novo_aluguel(&aluguel, cliente[MAX], &carro);
                }
                if(==2){
                    printf("\nDigite o código do aluguel:\n");
                    scanf("%d", &cod_aluguel);
                    devolucao(&aluguel, cod_aluguel);
                }
            } while(x!=3 && x<3);
        break;

        case 3:
            do { //obter informações de um carro, cliente ou aluguel
            x = menu_infos();

            if (x==1){
                printf("\nDigite o código do cliente que deseja consultar:\n");
                scanf("%d", &cod_cliente);
                info_cliente(&cliente, cod_cliente);
            }

            else if (x==2){
                printf("\nDigite o código do carro que deseja consultar:\n");
                scanf("%d", &cod_carro);
                info_carro(&carro, cod_carro);
            }

            else if (x==3){
                printf(("Digite o código do aluguel que deseja consultar:\n"))
                scanf("%d", &cod_aluguel);
                info_aluguel(&aluguel, cod_aluguel);
            }
            while (x!=4 && x<4);
        break;

        case 4: // relatorios
            do{
                x = menu_relatorios();
                if (x==1){
                    printf("\nLista de todos os clientes em ordem alfabética:\n")
                    lista_clientes(cliente[MAX]);
                }
                if (x==2){
                    marca[MAX] = {0};
                    printf("\nDigite a marca dos carros:\n");
                    fgets(marca, MAX, stdin);
                    marca[strlen(marca)-1] = '\0';
                    lista_carros(carro[MAX], marca[MAX]);

                }
                if (x==3){
                    marca[MAX] = {0};
                    printf("\nDigite a marca dos carros:\n");
                    fgets(marca, MAX, stdin);
                    lista_carros_preco(carro[MAX], marca[MAX]);
                }
                if (x==4){
                    printf("\nDigite o código do cliente:\n");
                    scanf("%d", &cod_cliente);
                    lista_alugueis(aluguel[MAX], cod_cliente);
                }
                if (x==5){
                    printf("\nDigite o código do cliente:\n");
                    scanf("%d", &cod_cliente);
                    lista_atrasados(aluguel[MAX], cliente[MAX]);
                }
            } while(x!=6 && x<6);
        break;
        }
    }
    while (op!= 5 && op<5);

    FILE *arq_clientes = fopen("clientes.csv","w");
    if (arq_clientes == NULL){
        printf("\nErro na gravação do arquivo.");
        return 0;
    }
    grava_clientes(arq_clientes, &cliente);
    fclose(arq_clientes);

    FILE *arq_carros = fopen("carros.csv", "w");
    if (arq_carros == NULL){
        printf("\nErro na gravação do arquivo.");
        return 0;
    }
    grava_carros(arq_carros, &carro);
    fclose(arq_carros);

    FILE *arq_alugueis = fopen("alugueis.bin", "w");
    if (arq_carros == NULL){
        printf("\nErro na gravação do arquivo.");
        return 0;
    }
    grava_alugueis(arq_alugueis, &aluguel);
    fclose(arq_alugueis);
    return 0;
}
