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

typedef struct clientes {
    int codigo;
    char nome[MAX];
    char cnh[MAX];
    char ddd[MAX];
    char telefone[MAX];
} clientes_t;

void novo_cliente(clientes_t *n_cliente);
void leitura_clientes(FILE *arq_clientes, clientes_t *clientes);
void info_cliente(clientes_t *clientes, int cod_cliente);
void lista_clientes(clientes_t clientes[]);
void grava_clientes(FILE *arq_clientes, clientes_t *cliente);
