#include <stdio.h>
#include "pessoa.h"
#include <string.h>

/**
 * @brief Cria uma nova pessoa e inicializa os ponteiros.
 *
 * @return Uma nova pessoa e sem pais.
 */
tPessoa CriaPessoa()
{
    tPessoa pessoa;
    pessoa.pai = NULL;
    pessoa.mae = NULL;
    return pessoa;
}

/**
 * @brief Lê os dados de uma pessoa.
 *
 * @param pessoa Ponteiro para a pessoa a ser lida.
 */
void LePessoa(tPessoa *pessoa)
{
    char nome[100];
    scanf("%*c");
    scanf("%[^\n]", pessoa->nome);
}

/**
 * @brief Imprime os dados de uma pessoa caso tenha pai e/ou mae associado(s).
 *
 * @param pessoa Ponteiro para a pessoa a ser impressa.
 */
void ImprimePessoa(tPessoa *pessoa)
{
    if ((*pessoa).mae != NULL || (*pessoa).pai != NULL)
    {
        printf("NOME COMPLETO: %s\n", (*pessoa).nome);

        if ((*pessoa).pai == NULL)
        {
            printf("PAI: NAO INFORMADO\n");
        }
        else
        {
            printf("PAI: %s\n", pessoa->pai->nome);
        }
        if ((*pessoa).mae == NULL)
        {
            printf("MAE: NAO INFORMADO\n\n");
        }
        else
        {
            printf("MAE: %s\n\n", pessoa->mae->nome);
        }
    }
}

/**
 * @brief Associa as famílias e grupos de pessoas.
 * Alem disso, e nessa funcao que sera lida a associacao entre as pessoas.
 *
 * @param pessoas Ponteiro para a lista de pessoas a serem associadas.
 */
void AssociaFamiliasGruposPessoas(tPessoa *pessoas)

{   int associados = 0;
    scanf("%d", &associados);
    for (int i = 0; i < associados; i++)
    {
    
    int ind_filho, ind_pai, ind_mae;
    scanf("%*c");
    scanf("mae: %d, pai: %d, filho: %d", &ind_mae, &ind_pai, &ind_filho);

    if (ind_pai != -1)
    {
        pessoas[ind_filho].pai = &pessoas[ind_pai];
    }
    if (ind_mae != -1)
    {
        pessoas[ind_filho].mae = &pessoas[ind_mae];
    }
    }
}
