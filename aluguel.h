/*
Universidade Federal do Rio Grande do Sul
INF01202 - Trabalho Final
Turma I
Nome do Aluno : Arthur da Rosa Hahn
Cartao UFRGS : 00306037
*/
#include <stdio.h>
#include <string.h>
#include "carros.h"
#include "clientes.h"
#define MAX 100

typedef struct aluguel {
    int codigo;
    int codigo_cliente;
    int codigo_carro;
    int dia, mes, ano;
    int ndiarias;
    float valor;
    char seguro; // S ou N -> USAR TOUPPER
    char sit; // L(locado) ou E(entregue) -> USAR TOUPPER
} aluguel_t;

void novo_aluguel(aluguel_t *novo_aluguel, clientes_t consulta_cliente[], carros_t *carros);
void leitura_alugueis(aluguel_t *aluguel);
void info_aluguel(aluguel_t *aluguel, int cod_aluguel);
void lista_alugueis(aluguel_t aluguel[], int cod_cliente);
void lista_atrasados(aluguel_t aluguel[], clientes_t clientes[]);
void grava_alugueis(FILE *arq_alugueis, aluguel_t *alugueis);
void devolucao(aluguel_t *devolve, int cod_aluguel);
