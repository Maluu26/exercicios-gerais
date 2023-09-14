#include <stdio.h>
#include "conta.h"

int main()
{
    int quantidade_contas = 0, opcao = -1, num_conta = 0, i = 0, conta_selecionada = 0, j = 0;
    float valor = 0;
    char cpf[15], nome[50];
    scanf("%d", &quantidade_contas);
    tConta contas[quantidade_contas];
    tUsuario user;
    while (opcao != 0)
    {
        scanf("%d", &opcao);
        if (opcao == 3)
        {
            scanf("%s %s", nome, cpf);
            scanf("%d", &num_conta);
            user = CriaUsuario(nome, cpf);
            contas[i] = CriaConta(num_conta, user);
            i++;
        }
        else if (opcao == 1 || opcao == 2)
        {
            scanf("%d %f", &conta_selecionada, &valor);
            for (j = 0; j < i; j++)
            {
                if (VerificaConta(contas[j], conta_selecionada) == 1)
                {
                    if (opcao == 1)
                        contas[j]=SaqueConta(contas[j], valor);
                    else
                        contas[j]= DepositoConta(contas[j], valor);
                }
            }
        }
        else if (opcao == 4)
        {
            printf("===| Imprimindo Relatorio |===\n");
            for (j = 0; j < i; j++)
            {
                ImprimeConta(contas[j]);
            }
        }
        else
            break;
    }
}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
