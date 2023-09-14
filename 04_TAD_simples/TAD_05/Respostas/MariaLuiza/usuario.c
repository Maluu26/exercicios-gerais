#include <stdio.h>
#include "usuario.h"
/**
 * @struct tUsuario
 * @brief Estrutura que representa um usuário do sistema bancário.
 */
/**
 * @brief Cria um novo usuário.
 * @param nome Nome do usuário.
 * @param cpf CPF do usuário.
 * @return O novo usuário criado.
 */
tUsuario criar_usuario(char nome[20], char cpf[15])
{
    tUsuario user;
    int i = 0, j = 0;
    while (nome[i] != '\0')
    {
        user.nome[i] = nome[i];
        i++;
    }
    while (cpf[i] != '\0')
    {
        user.cpf[i] = cpf[i];
    }
    return user;
}

/**
 * @brief Imprime os dados de um usuário.
 * @param user Usuário a ser impresso.
 */
void imprime_usuario(tUsuario user)
{
    printf("Nome: %s\nCPF: %s\n", user.nome, user.cpf);
}
