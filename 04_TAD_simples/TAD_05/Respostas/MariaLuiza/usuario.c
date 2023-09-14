#include <stdio.h>
#include "usuario.h"
#include<string.h>
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
tUsuario CriaUsuario(char nome[20], char cpf[15])
{
    tUsuario user;
    int i = 0, j = 0;
    strcpy(user.nome,nome);
    strcpy(user.cpf, cpf);
    return user;
}

/**
 * @brief Imprime os dados de um usuário.
 * @param user Usuário a ser impresso.
 */
void ImprimeUsuario(tUsuario user)
{
    printf("Nome: %s\nCPF: %s\n", user.nome, user.cpf);
}
