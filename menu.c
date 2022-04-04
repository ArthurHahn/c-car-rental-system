/*
Universidade Federal do Rio Grande do Sul
INF01202 - Trabalho Final
Turma I
Nome do Aluno : Arthur da Rosa Hahn
Cartao UFRGS : 00306037
*/
#include <stdio.h>

int menu(){
    int ret;
    printf("Selecione a operação que deseja realizar, digitando o índice de acordo.\n"
           "\t1) Realizar um cadastro.\n"
           "\t2) Realizar um aluguel. \n"
           "\t3) Obter informaçoes. \n"
           "\t4) Obter relatórios.\n"
           "\t5) Sair do programa.\n");
    scanf("%d", &ret);
    return ret;
}

int menu_cadastro(){
    int ret;
    printf("\nMENU CADASTRO\n"
           "Deseja realizar o cadastro de:\n"
           "\t1) Clientes.\n"
           "\t2) Carros.\n"
           "\t3) Voltar para o menu.\n");
    scanf("%d", &ret);
    return ret;
}

int menu_alugar(){
    int ret;
    printf("\nMENU ALUGAR\n"
           "Escolha uma opção:\n"
           "\t1) Realizar um aluguel.\n"
           "\t2) Realizar uma devolução.\n"
           "\t3) Voltar para o menu.\n");
    scanf("%d", &ret);
    return ret;
}

int menu_infos(){
    int ret;
    printf("\nMENU DE INFORMAÇÕES\n"
           "Selecione a informação que deseja obter, digitando o índice de acordo.\n"
           "\t1) Informações de um cliente.\n"
           "\t2) Informações de um carro..\n"
           "\t3) Informações de um aluguel.\n"
           "\t4) Voltar para o menu.\n");
    scanf("%d", &ret);
    return ret;
}

menu_relatorios(){
    int ret;
    printf("\nMENU DE RELATÓRIOS\n"
           "\n"
           "Selecione o relatório que deseja obter, digitando o índice de acordo.\n"
           "\t1) Lista de todos os clientes.\n"
           "\t2) Lista de todos os carros de uma determinada marca.\n"
           "\t3) Lista de todos os carros de uma determinada marca, em ordem decrescente de acordo com o preço.\n"
           "\t4) Lista de todos os alugueis de um cliente.\n"
           "\t5) Lista dos alugueis atrasados de um cliente,\n"
           "\t6) Voltar para o menu.\n");
    scanf("%d", &ret);
    return ret;
}
