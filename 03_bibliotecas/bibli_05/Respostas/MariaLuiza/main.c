#include <stdio.h>
#include "string_utils.h"

int main()
{
    char string[1000], copia[1000];
    int opcao = 0;
    scanf("%[^\n]", string);

    while (opcao != 6)
    {
        scanf("%d", &opcao);
        printf("1 - Tamanho da string\n2 - Copiar string\n3 - Converter string para letras maiusculas\n4 - Converter string para letras minusculas\n5 - Imprimir string ao contrario\n6 - Encerrar o programa\nOpcao escolhida: \n");
        if (opcao == 1)
        {
            printf("Tamanho da string: %d", string_length(string));
        }
        else if (opcao == 2)
        {
            string_copy(string, copia);
            printf("String copiada: %s\n", copia);
        }
        else if (opcao == 3)
        {
            string_upper(string);
            printf("String convertida para maiusculas: %s\n", string);
        }
        else if (opcao == 4)
        {
            string_lower(string);
            printf("String convertida para minusculas: %s\n", string);
        }
        else if (opcao == 5)
        {
            printf("String invertida: ");
            string_reverse(string);
            printf("\n");
        }
        else
        {
            break;
        }
    }
    return 0;
}
