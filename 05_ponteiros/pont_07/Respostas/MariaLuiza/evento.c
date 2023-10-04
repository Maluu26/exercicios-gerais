#include <stdio.h>
#include "evento.h"
#define MAX_EVENTOS 10

/**
 * Cadastra um novo evento no calendário e o insere na próxima posição do array.
 *
 * @param eventos Array de eventos onde o novo evento será cadastrado.
 * @param numEventos Ponteiro para o número atual de eventos cadastrados.
 */
void cadastrarEvento(Evento *eventos, int *numEventos)
{
    scanf("%s %d %d %d", eventos[*numEventos].nome, &eventos[*numEventos].dia, &eventos[*numEventos].mes, &eventos[*numEventos].ano);
    *numEventos += 1;
    printf("Evento cadastrado com sucesso!\n");
}

/**
 * Exibe todos os eventos cadastrados no calendário.
 *
 * @param eventos Array de eventos a serem exibidos.
 * @param numEventos Ponteiro para o número total de eventos cadastrados.
 */
void exibirEventos(Evento *eventos, int *numEventos)
{
    for (int i = 0; i < *numEventos; i++)
    {
        printf("%d - %s - %02d/%02d/%04d\n", i, eventos[i].nome, eventos[i].dia, eventos[i].mes, eventos[i].ano);
    }
}

/**
 * Troca a data de um evento específico no calendário.
 *
 * @param eventos Array de eventos onde o evento será modificado.
 * @param numEventos Ponteiro para o número total de eventos cadastrados.
 */
void trocarDataEvento(Evento *eventos, int *numEventos)
{
    int indice;
    scanf("%d", &indice);
    int *ind = &indice;
    scanf("Eventos cadastrados:\n%d %d %d", &eventos[*ind].dia, &eventos[*ind].mes, &eventos[*ind].ano);
}

/**
 * Troca a posição de dois eventos, a partir do índice, dentro do array de eventos.
 *
 * @param eventos Array de eventos onde a troca será realizada.
 * @param indiceA Ponteiro para o primeiro índice.
 * @param indiceB Ponteiro para o segundo índice.
 * @param numEventos Ponteiro para o número total de eventos cadastrados.
 */
void trocarIndicesEventos(Evento *eventos, int *indiceA, int *indiceB, int *numEventos)
{
    Evento aux;
    aux.dia = eventos[*indiceA].dia;
    aux.mes = eventos[*indiceA].mes;
    aux.ano = eventos[*indiceA].ano;
    eventos[*indiceA].dia = eventos[*indiceB].dia;
    eventos[*indiceA].mes = eventos[*indiceB].mes;
    eventos[*indiceA].ano = eventos[*indiceB].ano;
    eventos[*indiceA].dia = aux.dia;
    eventos[*indiceA].mes = aux.mes;
    eventos[*indiceA].ano = aux.ano;
}
