#include<stdio.h>
#include"data.h"
/**
 * @brief Cria uma data a partir de valores de dia, mês e ano.
 * 
 * @param dia Dia da data a ser criada.
 * @param mes Mês da data a ser criada.
 * @param ano Ano da data a ser criada.
 * @return tData Data criada a partir dos valores de dia, mês e ano.
 */
tData CriaData(int dia, int mes, int ano){
    tData data;
    data.dia = dia;
    data.mes = mes;
    data.ano = ano;
    return data;
}

/**
 * @brief Verifica se uma data é válida.
 * 
 * @param data Data a ser verificada.
 * @return int 1 se a data é válida, 0 caso contrário.
 */
int VerificaDataValida(tData data){
    int max_dias = 0;
    if (data.dia > 31 || data.dia < 1 || data.mes < 1 || data.mes > 12)
    {
        return 0;
    }
    else
    {
        max_dias = NumeroDiasMes(data);
        if (max_dias >= data.dia)
        {
            return 1;
        }
        else
            return 0;
    }
}

/**
 * @brief Imprime o mês de uma data em formato extenso.
 * 
 * @param data Data cujo mês será impresso em formato extenso.
 */
void ImprimeMesExtenso(tData data){
     switch (data.mes)
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
 * @brief Imprime uma data em formato extenso.
 * 
 * @param data Data a ser impressa em formato extenso.
 */
void ImprimeDataExtenso(tData data){
     printf("%02d de ", data.dia);
    ImprimeMesExtenso(data);
    printf(" de %d\n", data.ano);
}

/**
 * @brief Verifica se um ano é bissexto.
 * 
 * @param data Data cujo ano será verificado.
 * @return int 1 se o ano é bissexto, 0 caso contrário.
 */
int VerificaBissexto(tData data){
     if (data.ano % 4 == 0)
    {
        if (data.ano % 100 != 0)
        {
            return 1;
        }
        else if (data.ano % 100 == 0 && data.ano % 400 == 0)
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

/**
 * @brief Retorna o número de dias de um determinado mês.
 * 
 * @param data Data cujo mês terá o número de dias retornado.
 * @return int Número de dias do mês da data.
 */
int NumeroDiasMes(tData data){
     if (data.mes == 1 || data.mes == 3 || data.mes == 5 || data.mes == 7 || data.mes == 8 || data.mes == 10 || data.mes == 12)
    {
        return 31;
    }
    else if (data.mes == 4 || data.mes == 6 || data.mes == 9 || data.mes == 1 || data.mes == 11)
    {
        return 30;
    }
    else
    {
        if (VerificaBissexto(data) == 1)
        {
            return 29;
        }
        else
            return 28;
    }
}

/**
 * @brief Compara duas datas.
 * 
 * @param data1 Primeira data a ser comparada.
 * @param data2 Segunda data a ser comparada.
 * @return int 1 se data1 é maior que data2, -1 se data1 é menor que data2, 0 se as datas são iguais.
 */
int ComparaData(tData data1, tData data2){
    if (data2.ano == data1.ano)
    {
        if (data1.mes == data2.mes)
        {
            if (data1.dia == data2.dia)
            {
                return 0;
            }
            else if (data1.dia > data2.dia)
            {
                return -1;
            }
            else
            {
                return 1;
            }
        }
        else if (data1.mes > data2.mes)
        {
            return -1;
        }
        else
        {
            return 1;
        }
    }
    else if (data1.ano > data2.ano)
    {
        return -1;
    }
    else
    {
        return 1;
    }
}

/**
 * @brief Calcula o número de dias até o início do mês de uma determinada data.
 * 
 * @param data Data cujo número de dias até o início do mês será calculado.
 * @return int Número de dias até o início do mês da data.
 */
int CalculaDiasAteMes(tData data){ 
    return NumeroDiasMes(data);
    }

/**
 * @brief Calcula a diferença em dias entre duas datas.
 * 
 * @param data1 Primeira data a ser comparada.
 * @param data2 Segunda data a ser comparada.
 * @return int Número de dias entre as duas datas.
 */
int CalculaDiferencaDias(tData data1, tData data2){
    int dias_restantes = 0, primeiro_ano, bissexto, i = 0;
    tData primeiro, segundo;
    if (ComparaData(data1, data2) == 0)
    {
        return 0;
    }
    else if (ComparaData(data1,data2) == -1)
    {
       primeiro = data1;
       segundo = data2;    }
    else
    {
        primeiro = data2;
        segundo = data1; 
    }
    while ((primeiro.ano != segundo.ano) || (primeiro.mes != segundo.mes) || (primeiro.dia != segundo.dia))
    {
        if ((primeiro.mes == segundo.mes) && (primeiro.ano == segundo.ano))
        {
            if (primeiro.dia >= segundo.dia)
            {
                return dias_restantes + (primeiro.dia - segundo.dia);
            }
            else
            {
                return dias_restantes + (segundo.ano - primeiro.dia);
            }
        }
        else
        {
            if (i == 0)
            {
                dias_restantes = NumeroDiasMes(segundo) - segundo.dia;
                segundo.dia = 0;
            }
            else
            {
                dias_restantes = dias_restantes + NumeroDiasMes(segundo);
            }
            if (segundo.mes == 12)
            {
                segundo.mes = 1;
                segundo.ano++;
            }
            else
            {
                segundo.mes++;
            }
            i++;
        }
    }
}
