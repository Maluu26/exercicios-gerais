#include <stdio.h>
#include "string_utils.h"

/**
 * @brief Retorna o tamanho de uma string.
 * @param str A string para obter o tamanho.
 * @return O tamanho da string.
 */
int string_length(char *str)
{
    int i = 0, comprimento = 1;
    while (str[i] != '\0')
    {

        comprimento++;
        i++;
    }
    return comprimento;
}

/**
 * @brief Copia uma string de origem para destino.
 * @param src A string de origem.
 * @param dest A string de destino.
 */
void string_copy(char *src, char *dest)
{
    int i = 0;
    while (src[i] != '\0')
    {
        dest[i] = src[i];
        i++;
    }
}

/**
 * @brief Converte todos os caracteres de uma string para maiúsculas.
 * @param str A string para converter.
 */
void string_upper(char *str)
{
    int i = 0;
    while (str[i] != '\0')
    {
        if ('a' <= str[i] && str[i] <= 'z')
        {
            str[i] = str[i] - 32;
        }
        i++;
    }
}

/**
 * @brief Converte todos os caracteres de uma string para minúsculas.
 * @param str A string para converter.
 */
void string_lower(char *str)
{
    int i = 0;
    while (str[i] != '\0')
    {
        if (('A' <= str[i]) && (str[i] <= 'Z'))
        {
            str[i] = str[i] + 32;
        }
        i++;
    }
}

/**
 * @brief Inverte uma string.
 * @param str A string para inverter.
 */
void string_reverse(char *str)
{
    int i = 0;
    if (str[0] != '\0')
    {
        string_reverse(str + 1);
        printf("%c", str[0]);
    }
}
