/*
Universidade Federal do Rio Grande do Sul
INF01202 - Trabalho Final
Turma I
Nome do Aluno : Arthur da Rosa Hahn
Cartao UFRGS : 00306037
*/

#include "clientes.h"

void novo_cliente(clientes_t *n_cliente){
    int pos_cliente = 0, cod_cliente;
    clientes_t *a;

    while(n_cliente[pos_cliente].codigo != '0'){
        pos_cliente++;
    }
    a = &n_cliente[pos_cliente];
    cod_cliente = pos_cliente + 1;
    a->codigo = cod_cliente;

    printf("\nDigite o nome do cliente:\n");
    fflush(stdin);
    fgets(a->nome, MAX, stdin);
    a->nome[strlen(a->nome) - 1] = '\0';

    printf("Digite a CNH do cliente:\n");
    fflush(stdin);
    fgets(a->cnh, MAX, stdin);
    a->cnh[strlen(a->cnh) - 1] = '\0';

    printf("Digite o DDD do cliente:\n");
    fflush(stdin);
    fgets(a->ddd, MAX, stdin);
    a->ddd[strlen(a->ddd)-1] = '\0';

    printf("Digite o telefone do cliente:\n");
    fflush(stdin);
    fgets(a->telefone, MAX, stdin);
    a->telefone[strlen(a->telefone) - 1] = '\0';

    printf("\nCadastro finalizado!\n");

    return 0;
}

void leitura_clientes(FILE *arq_clientes, clientes_t *clientes){
    char aux[256];
    char cabecalho[256];
    char *p;
    int i = 0;

    fgets(cabecalho, 256, arq_clientes);
    while(!feof(arq_clientes)){
        fgets(aux, 256, arq_clientes);
        p = strtok(aux, ",");
        clientes[i].codigo = atoi(p);
        p = strtok(NULL, ",");
        strcpy(clientes[i].nome, p);
        p = strtok(NULL, ",");
        strcpy(clientes[i].cnh, p);
        p = strtok(NULL, ",");
        strcpy(clientes[i].ddd, p);
        p = strtok(NULL, "\n");
        strcpy(clientes[i].telefone, p);
        i++;
    }
    // le o arquivo clientes.csv e preenche o vetor de clientes

}

void info_cliente(clientes_t *clientes, int cod_cliente){
    clientes_t *a;
    a = &clientes[cod_cliente];

    printf("\nCodigo do cliente: %d", a->codigo);
    printf("\nNome do cliente: %s", a->nome);
    printf("\nCNH do cliente: %s", a->cnh);
    printf("\nTelefone do cliente: %s - %s", a->ddd, a->telefone);
    //nfo_cliente que receba o código de um cliente e o vetor contendo todos
    //os clientes, realize a busca do cliente e imprima na tela todas as informações sobre o mesmo.
}

void lista_clientes(clientes_t clientes[]){
    int i, n=0, sinal;
    char nome1[MAX], nome2[MAX];
    clientes_t aux = {0};

    do {
        sinal = 0;
      //  for(n=0; n<(MAX-1); n++){
        strcpy(nome1, clientes[n].nome);
        strcpy(nome2, clientes[n+1].nome);
        for (i=0; i<MAX; i++);{ //transforma a palavra em maiuscula, podendo comparar com ascii
            nome1[i] = toupper(nome1[i]);
            nome2[i] = toupper(nome2[i]);
        }
        if(strcmp(nome1, nome2) > 0){ //se for maior, nome1 vai depois de nome2 alfabeticamente
            aux = clientes[n];//strcpy(aux, clientes[n]);
            clientes[n] = clientes[i+1];// strcpy(clientes[n], clientes[i+1]);
            clientes[n+1] = aux;// strcpy(clientes[n+1], aux);
            sinal = 1;
        }
        n++;
    } while(sinal==1);//(clientes[n+1].nome != '0');

    i = 0;

    printf("\n");
    do {
        printf("%s\n", clientes[i].nome);
        i++;
    } while(clientes[i].nome != '0');
    // que receba o vetor contendo todos os clientes e exiba a
    //lista de clientes em ordem alfabética do primeiro nome, não é necessário
    //considerar nomes compostos.
}

void grava_clientes(FILE *arq_clientes, clientes_t *cliente){
    int i;

    fputs("codigo, nome, cnh, ddd, telefone\n", arq_clientes);
    for (i=0; i<MAX; i++){
        fprintf(arq_clientes, "%d,%s,%s,%s,%s\n", cliente[i].codigo, cliente[i].nome, cliente[i].cnh, cliente[i].ddd, cliente[i].telefone);
    }
    //que receba o vetor contendo todos os clientes e grave no
    //arquivo clientes.csv.
}

