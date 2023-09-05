#include <stdio.h>
#include "data.h"

int numeroDiasMes(int mes, int ano);
int verificaDataValida(int dia, int mes, int ano)
{
    int max_dias = 0;
    if (dia > 31 || dia < 1 || mes < 1 || mes > 12)
    {
        return 0;
    }
    else
    {
        max_dias = numeroDiasMes(mes, ano);
        if (max_dias >= dia)
        {
            return 1;
        }
        else
            return 0;
    }
}
void imprimeMesExtenso(int mes)
{
    switch (mes)
    {
    case 1:
        printf("Janeiro");
        break;
    case 2:
        printf("Fevereiro");
        break;
    case 3:
        printf("Março");
        break;
    case 4:
        printf("Abril");
        break;
    case 5:
        printf("Maio");
        break;
    case 6:
        printf("Junho");
        break;
    case 7:
        printf("Julho");
        break;
    case 8:
        printf("Agosto");
        break;
    case 9:
        printf("Setembro");
        break;
    case 10:
        printf("Outubro");
        break;
    case 11:
        printf("Novembro");
        break;
    case 12:
        printf("Dezembro");
        break;
    }
}
/**
 * @brief Imprime a data por extenso.
 *
 * @param dia Dia da data.
 * @param mes Mês da data.
 * @param ano Ano da data.
 */
void imprimeData(int dia, int mes, int ano)
{
    printf("%02d/%02d/%04d\n", dia, mes, ano);
}
void imprimeDataExtenso(int dia, int mes, int ano)
{
    printf("%d de ", dia);
    imprimeMesExtenso(mes);
    printf(" de %d", ano);
}

int verificaBissexto(int ano)
{
    if (ano % 4 == 0)
    {
        if (ano % 100 != 0)
        {
            return 1;
        }
        else if (ano % 100 == 0 && ano % 400 == 0)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    else
    {
        return 0;
    }
}
int numeroDiasMes(int mes, int ano)
{
    if (mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10 || mes == 12)
    {
        return 31;
    }
    else if (mes == 4 || mes == 6 || mes == 9 || mes == 1 || mes == 11)
    {
        return 30;
    }
    else
    {
        if (verificaBissexto(ano) == 1)
        {
            return 29;
        }
        else
            return 28;
    }
}
int comparaData(int dia1, int mes1, int ano1, int dia2, int mes2, int ano2)
{
    if (ano1 == ano2)
    {
        if (mes1 == mes2)
        {
            if (dia1 == dia2)
            {
                return 0;
            }
            else if (dia1 > dia2)
            {
                return 1;
            }
            else
            {
                return -1;
            }
        }
        else if (mes1 > mes2)
        {
            return 1;
        }
        else
        {
            return -1;
        }
    }
    else if (ano1 > ano2)
    {
        return 1;
    }
    else
    {
        return -1;
    }
}

/**
 * @brief Calcula o número de dias até o mês.
 *
 * @param mes Mês a ser verificado.
 * @param ano Ano da data.
 * @return int Retorna o número de dias até o mês.
 */
int calculaDiasAteMes(int mes, int ano);
/**
 * @brief Calcula a diferença em dias entre duas datas.
 *
 * @param dia1 Dia da primeira data.
 * @param mes1 Mês da primeira data.
 * @param ano1 Ano da primeira data.
 * @param dia2 Dia da segunda data.
 * @param mes2 Mês da segunda data.
 * @param ano2 Ano da segunda data.
 * @return int Retorna o número de dias de diferença entre as datas.
 */
int calculaDiferencaDias(int dia1, int mes1, int ano1, int dia2, int mes2, int ano2)
{
    int dias_restantes = 0, primeiro_ano, primeiro_mes, primeiro_dia, segundo_ano, segundo_mes, segundo_dia, bissexto, i = 0;
    if (comparaData(dia1, mes1, ano1, dia2, mes2, ano2) == 0)
    {
        return 0;
    }
    else if (comparaData(dia1, mes1, ano1, dia2, mes2, ano2) == 1)
    {
        primeiro_ano = ano1;
        primeiro_mes = mes1;
        primeiro_dia = dia1;
        segundo_ano = ano2;
        segundo_mes = mes2;
        segundo_dia = dia2;
    }
    else
    {
        primeiro_ano = ano2;
        primeiro_mes = mes2;
        primeiro_dia = dia2;
        segundo_ano = ano1;
        segundo_mes = mes1;
        segundo_dia = dia1;
    }
    while ((primeiro_ano != segundo_ano) || (primeiro_mes != segundo_mes) || (primeiro_dia != segundo_dia))
    {
        if ((primeiro_mes == segundo_mes) && (primeiro_ano == segundo_ano))
        {
            if (primeiro_dia >= segundo_dia)
            {
                return dias_restantes + (primeiro_dia - segundo_dia);
            }
            else
            {
                return dias_restantes + (segundo_dia - primeiro_dia);
            }
        }
        else
        {
            if (i == 0)
            {
                dias_restantes = numeroDiasMes(segundo_mes, segundo_ano) - segundo_dia;
                segundo_dia = 0;
            }
            else
            {
                dias_restantes = dias_restantes + numeroDiasMes(segundo_mes, segundo_ano);
            }
            if (segundo_mes == 12)
            {
                segundo_mes = 1;
                segundo_ano++;
            }
            else
            {
                segundo_mes++;
            }
            i++;
        }
    }
    return dias_restantes;
}
void imprimeProximaData(int dia, int mes, int ano)
{
    dia = dia + 1;
    int validade;
    validade = verificaDataValida(dia, mes, ano);
    if (validade == 1)
    {
        imprimeData(dia, mes, ano);
    }
    else
    {
        if (mes <= 11)
        {
            mes++;
        }
        else
        {
            mes = 1;
            ano++;
        }
        dia = 1;
        imprimeData(dia, mes, ano);
    }
}
