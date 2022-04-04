/*
Universidade Federal do Rio Grande do Sul
INF01202 - Trabalho Final
Turma I
Nome do Aluno : Arthur da Rosa Hahn
Cartao UFRGS : 00306037
*/
#include "carros.h"

void novo_carro(carros_t *n_carro){
    int pos_carro = 0, cod_carro;
    carros_t *a;

    while (n_carro[pos_carro].codigo != '0'){
        pos_carro++;
    }
    a = &n_carro[pos_carro];
    cod_carro = pos_carro + 1;
    a->codigo = cod_carro;

    printf("Digite o nome da marca do carro:\n");
    fflush(stdin);
    fgets(a->marca, MAX, stdin);
    a->marca[strlen(a->marca) - 1] = '\0';

    printf("Digite o modelo do carro:\n");
    fflush(stdin);
    fgets(a->modelo, MAX, stdin);
    a->modelo[strlen(a->modelo) - 1] = '\0';

    printf("Digite o ano do carro:\n");
    scanf("%d", &a->ano);

    printf("Digite a placa do carro:\n");
    fflush(stdin);
    fgets(a->placa, MAX, stdin);
    a->placa[strlen(a->placa) - 1] = '\0';

    printf("Digite o valor da diária do carro:\n");
    scanf("%f", &a->valor_diaria);

    printf("Digite o valor do seguro do carro:\n");
    scanf("%f", &a->valor_seguro);

    printf("Digite a quantidade de veículos:\n");
    scanf("%d", &a->quantidade);

    printf("\nCadastro finalizado!\n");
}

void leitura_carros(FILE *arq_carros, carros_t *carros){
    char aux[256];
    char cabecalho[256];
    int i = 0;

    fgets(cabecalho, 256, arq_carros);
    while(!feof(arq_carros));{
        fgets(aux, 256, arq_carros);
        char *piece = strtok(aux,",");
        carros[i].codigo = atoi(piece);
        piece = strtok(NULL, ",");
        strcpy(carros[i].marca, piece);
        piece = strtok(NULL, ",");
        strcpy(carros[i].modelo, piece);
        piece = strtok(NULL, ",");
        carros[i].ano = atoi(piece);
        piece = strtok(NULL, ",");
        strcpy(carros[i].placa, piece);
        piece = strtok(NULL, ",");
        carros[i].valor_diaria = atof(piece);
        piece = strtok(NULL, ",");
        carros[i].valor_seguro = atof(piece);
        piece = strtok(NULL, "\n");
        carros[i].quantidade = atoi(piece);
        i++;
    }


    // le o arquivo carros.csv e preenche o vetor de carros.
}

void info_carro(carros_t *carros, int cod_carro){
    carros_t *a;
    a = &carros[cod_carro];

    printf("\nCódigo do carro: %d.", a->codigo);
    printf("\\Marca do carro: %s.", a->marca);
    printf("\nModelo do carro: %s.", a->modelo);
    printf("\nAno do carro: %d.", a->ano);
    printf("\nPlaca do carro: %s.", a->placa);
    printf("\nValor de diária: %f.", a->valor_diaria);
    printf("\nValor do seguro: %f.", a->valor_seguro);
    printf("\nQuantidade: %d.", a->quantidade);

    //que receba o código de um carro e o vetor contendo todos os
    //carros, realize a busca do carro e imprima na tela todas as informações
    //sobre o mesmo.
}

void lista_carros(carros_t carros[], char marca[]){
    int i=0;

    printf("\nCarros que correspondem a marca [%s]:\n", marca);
    do {
        if(strcmp(carros[i].marca, marca) == 0){
            printf("%s", carros[i].modelo);
        }
        i++;
    } while (carros[i].codigo != '0');
    //que receba a marca e o vetor contendo todos os carros e
    //exiba a lista de carros que correspondem a marca informada.

}

void lista_carros_preco(carros_t carros[], char marca[]){
    int i=0, j=0, sinal;
    carros_t aux1[MAX], aux2;
    do {
        if (strcmp(carros[i].marca, marca) == 0){
            aux1[j] = carros[i];
            j++;
        }
        i++;
    } while (carros[i].codigo != '0');

    do {
        sinal = 0;
        for(i=0; i<(j-1); i++){
            if(aux1[i].valor_diaria > aux1[i +1].valor_diaria){
                aux2 = aux1[i];
                aux1[i] = aux1[i+1];
                aux1[i+1] = aux2;
                sinal = 1;
            }
        }
    }while(sinal == 1);

    for(i=0; i<j; i++){
        printf("\nCarro - valor\n");
        printf("%s - %f\n", aux1[i].modelo, aux1[i].valor_diaria);
    }

    //que receba a marca e o vetor contendo todos os carros e exiba a
    //lista de carros que correspondem a marca informada ordenada
    //por preço decrescente.
}

void grava_carros(FILE *arq_carros, carros_t *carros){
    int i;

    fputs("codigo,marca,modelo,ano,placa,valor_diaria,valor_seguro,quantidade\n", arq_carros);
    for (i=0; i<MAX; i++);{
            fprintf(arq_carros, "%d,%s,%s,%d,%s,%f,%f,%d\n", carros[i].codigo, carros[i].marca, carros[i].modelo, carros[i].ano, carros[i].placa, carros[i].valor_diaria, carros[i].valor_seguro, carros[i].quantidade);
    }
    //que receba o vetor contendo todos os carros e grave no
    //arquivo carros.csv.
}

