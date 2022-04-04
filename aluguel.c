/*
Universidade Federal do Rio Grande do Sul
INF01202 - Trabalho Final
Turma I
Nome do Aluno : Arthur da Rosa Hahn
Cartao UFRGS : 00306037
*/
#include "aluguel.h"

void novo_aluguel(aluguel_t *novo_aluguel, clientes_t consulta_cliente[], carros_t *carros){
    int cod_aluguel = 0, invalido, i;
    aluguel_t *a;

    while(novo_aluguel[cod_aluguel].codigo != '0'){
        cod_aluguel++;
    }

    a = &novo_aluguel[cod_aluguel];
    a->codigo = cod_aluguel + 1;

    do { // codigo do cliente
        printf("\nDigite o codigo do cliente:\n");
        scanf("%d", &a->codigo_cliente);
        i = 0;
        for(i=0; i<MAX; i++){
            if (consulta_cliente[i].codigo != a->codigo_cliente){
                invalido = 1; //codigo invalido
                i++;
            }
            else{
                invalido = 0;
                i = MAX + 1;
            }
        }
        if(invalido == 1){
            printf("\nCódigo do cliente inválido.\n");
        }
    } while(invalido == 1);

    do { //codigo do carro
        printf("Digite o codigo do carro:\n");
        scanf("%d", &a->codigo_carro);
        i = 0;
        for (i=0; i<MAX; i++){
            if (carros[i].codigo != a->codigo_carro){
                invalido = 1;
                i++;
            }
            else{
                invalido = 0;
                i = MAX +1;
            }
        }
        if (invalido == 1){
            printf("\nCódigo do carro inválido.\n");
        }
        if (invalido == 0 && carros[a->codigo_carro].quantidade == 0){
            printf("\nCarro não disponivel, tente outro código.\n");
            invalido = 1;
        }
        if (invalido == 0 && carros[a->codigo_carro].quantidade > 0){
            carros[a->codigo_carro].quantidade = carros[a->codigo_carro].quantidade - 1;
        }

    } while(invalido == 1);

    printf("Digite a data(xx xx xxxx) do aluguel\n");
    scanf("%d" "%d" "%d", &a->dia, &a->mes, &a->ano);

    printf("Digite o número de diárias:\n");
    scanf("%d", &a->ndiarias);

    a->valor = carros[a->codigo_cliente].valor_seguro + (a->ndiarias*carros[a->codigo_cliente].valor_diaria);
   // printf("Digite valor:\n");
    //scanf("%f", &a->valor);

    printf("Digite S se o carro tem seguro ou N se não tem seguro:\n");
    scanf("%c", &a->seguro);

    a->sit = 'L';

    printf("\nAluguel finalizado!\n");
}

void leitura_alugueis(aluguel_t *aluguel){// le o arquivo alugueis.bin e preenche o vetor de alugueis
    FILE *arq;
    arq = fopen("alugueis.bin", "r");

    if (arq == NULL)
    {
        printf("\n\tErro: o arquivo de alugueis não pode ser aberto.\n");
        return 0;
    }
    fread(aluguel, sizeof(aluguel_t), MAX, arq);
    fclose(arq);
}

void info_aluguel(aluguel_t *aluguel, int cod_aluguel){
    aluguel_t *a;
    a = &aluguel[cod_aluguel];

    printf("\nCódigo do aluguel: %d.", a->codigo);
    printf("\nCódigo do cliente: %d.", a->codigo_cliente);
    printf("\nCódigo do carro: %d", a->codigo_carro);
    printf("\nData do aluguel: %d/%d/%d.", a->dia, a->mes, a->ano);
    printf("\nNúmero de diárias: %d.", a->ndiarias);
    printf("\nValor: %f.", a->valor);
    printf("\nSeguro: %c.", a->seguro);
    printf("\nSituação: %c.", a->sit);
    //que receba o código de um aluguel e o vetor contendo todos os alugueis,
    //realize a busca do aluguel e imprima na tela todas as
    //informações sobre o mesmo.
}

void lista_alugueis(aluguel_t aluguel[], int cod_cliente){
    int i=0, sinal=0;
    do {
        if(aluguel[i].codigo_cliente == cod_cliente){
            printf("\nAluguis do cliente %d:\n", cod_cliente);
            printf("Carro alugado: %d.\n", aluguel[i].codigo_carro);
            printf("Data do aluguel: %d/%d/%d.\n", aluguel[i].dia, aluguel[i].mes, aluguel[i].ano);
            printf("Valor a pagar: %f\n", aluguel[i].valor);
            sinal = 1;
        }
        i++;
    } while(aluguel[i].codigo_cliente != '0');

    if(sinal == 0){
        printf("Nenhum aluguel encontrado!");
    }
        // que receba o código de um cliente e o vetor contendo
    //todos os alugueis e exiba a lista de alugueis deste cliente.
}

void lista_atrasados(aluguel_t aluguel[], clientes_t clientes[]){
    int nclientes = 0, cod_cliente, i;

    while (clientes[nclientes].codigo != '0'){
        nclientes++;
    }
    printf("\nClientes com alugueis pendentes:\n");
    for(i=0; i<nclientes; i++){
        cod_cliente = aluguel[i].codigo_cliente;
        if(aluguel[i].sit == 'L'){
            printf("---------\n");
            printf("%d\n", clientes[cod_cliente].codigo);
            printf("%s\n", clientes[cod_cliente].nome);
            printf("%s\n", clientes[cod_cliente].cnh);
            printf("%s\n", clientes[cod_cliente].ddd);
            printf("%s\n", clientes[cod_cliente].telefone);
        }

    }

    // que receba o vetor contendo todos os alugueis e o vetor
    //contendo todos os clientes e exiba as informações de todos os clientes (uma
    //vez por cliente) que possuem carros não entregues.
}

void grava_alugueis(FILE *arq_alugueis, aluguel_t *alugueis){
    fwrite(&alugueis, sizeof(aluguel_t), MAX, arq_alugueis);
    //que receba o vetor contendo todos os alugueis e grave no
    //arquivo binário alugueis.bin.
}

void devolucao(aluguel_t *devolve, int cod_aluguel){
    int i=0;

    while(devolve[i].codigo != cod_aluguel){
        i++;
    }
    devolve[i].sit = 'E';
     //que receba o código do aluguel e o vetor contendo todos os
    //alugueis, realize a busca do aluguel e modifique o campo situação para//’E’.
}
