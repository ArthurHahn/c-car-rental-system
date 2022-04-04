/*
Universidade Federal do Rio Grande do Sul
INF01202 - Trabalho Final
Turma I
Nome do Aluno : Arthur da Rosa Hahn
Cartao UFRGS : 00306037
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 100

typedef struct carros {
    int codigo;
    char marca[MAX];
    char modelo[MAX];
    int ano;
    char placa[MAX];
    float valor_diaria;
    float valor_seguro;
    int quantidade;
} carros_t;

void novo_carro(carros_t *n_carro);
void leitura_carros(FILE *arq_carros, carros_t *carros);
void info_carro(carros_t *carros, int cod_carro);
void lista_carros(carros_t carros[], char marca[]);
void lista_carros_preco(carros_t carros[], char marca[]);
void grava_carros(FILE *arq_carros, carros_t *carros);
