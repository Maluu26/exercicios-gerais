#include <stdio.h>
#include "pessoa.h"

/**
 * @brief Cria uma nova pessoa com nome vazio (primeiro caractere igual a '\0') e inicializa os ponteiros para pai, mae e irmao com NULL.
 *
 * @return Uma nova pessoa e sem pais e irmao.
 */
tPessoa CriaPessoa()
{
    tPessoa pessoa;
    pessoa.pai = NULL;
    pessoa.mae = NULL;
    pessoa.irmao = NULL;
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
 * @brief Verifica se uma pessoa tem pai e/ou mae associado(s).
 * Ou seja, verifica pelo menos um dos ponteiros pai e mae é diferente de NULL.
 *
 * @param pessoa Ponteiro para a pessoa a ser verificada.
 *
 * @return 1 se a pessoa tiver pai e/ou mae associado(s) e 0 caso contrário.
 */
int VerificaSeTemPaisPessoa(tPessoa *pessoa)
{
    if (pessoa->mae != NULL || pessoa->pai != NULL)
    {

        return 1;
    }
    else
    {
        return 0;
    }
}

/**
 * @brief Imprime os dados de uma pessoa caso tenha pai e/ou mae associado(s).
 * Dica: use a função VerificaSeTemPaisPessoa para verificar se a pessoa tem pai e/ou mae associado(s).
 * Alem disso, imprimir o nome do irmao caso exista.
 *
 * @param pessoa Ponteiro para a pessoa a ser impressa.
 */
void ImprimePessoa(tPessoa *pessoa)
{
    if (VerificaSeTemPaisPessoa(pessoa) == 1)
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
            printf("MAE: NAO INFORMADO\n");
        }
        else
        {
            printf("MAE: %s\n", pessoa->mae->nome);
        }
        if ((*pessoa).irmao == NULL)
        {
            printf("IRMAO: NAO INFORMADO\n\n");
        }
        else
        {
            printf("IRMAO: %s\n\n", pessoa->irmao->nome);
        }
    }
}

/**
 * @brief Verifica se duas pessoas são irmãos, ou seja, se os ponteiros pai e mae são iguais.
 *
 * @param pessoa1 Ponteiro para a primeira pessoa.
 * @param pessoa2 Ponteiro para a segunda pessoa.
 *
 * @return 1 se as pessoas forem irmãos e 0 caso contrário.
 */
int VerificaIrmaoPessoa(tPessoa *pessoa1, tPessoa *pessoa2)
{
    if ((pessoa1->pai == pessoa2->pai && pessoa1->pai != NULL) || (pessoa2->mae == pessoa1->mae && pessoa2->mae != NULL))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

/**
 * @brief Le as associciacoes da entrada padrao e altera as pessoas de forma a representar as associacoes lidas
 *
 * Apos a associado dos pais, voce deve verificar se ha irmaos e associar os irmaos.
 *
 * @param pessoas Vetor de pessoas a serem associadas.
 * @param numPessoas Numero de pessoas a serem associadas (tamanho do vetor).
 */
void AssociaFamiliasGruposPessoas(tPessoa *pessoas, int numPessoas)
{
    int associados = 0, irmaos;
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
    for (int i = 0; i < numPessoas; i++)
    {
        for (int j = i + 1; j < numPessoas; j++)
        {
            irmaos = VerificaIrmaoPessoa(&pessoas[i], &pessoas[j]);
            if (irmaos == 1)
            {
                pessoas[i].irmao = &pessoas[j].nome;
                pessoas[j].irmao = &pessoas[i].nome;
            }
        }
    }
}
