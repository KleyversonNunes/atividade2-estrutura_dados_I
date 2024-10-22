/*
    Alunos:
        Breno Yuri Saraiva Sawaki - 202311140015
        Kleyverson Nunes da Silva - 202311140004
*/

#include "atividade2.cpp"
#include <iostream>
#include <stdio.h>
#include <time.h>
using namespace std;

int quantd;
TipoItem *valores;

clock_t inicio, fim;
double tempo_util_cpu;

// Menu
char opcoes()
{
    system("cls");
    char op;    
    printf("------------------------------------------------------- MENU -------------------------------------------------------\n");
    printf("1 - Escolha a quantidade de valores de entrada.\n");
    printf("2 - Escolha como os valores de entrada devem ficar antes da ordenacao.\n");
    printf("3 - Exibir os valores de entrada antes da ordenacao\n");
    printf("4 - Escolha um algoritmo de ordenacao\n");
    printf("5 - Encerrar execucao\n\n");

    printf("Escolha uma opcao: ");
    scanf("%c",&op);
    return op;
}

void Menu()
{
    char op1, op2, op3, op4, op5;
    char escolha;
    while(1)
    {
        escolha = opcoes();
        if(escolha == '1')
        {
            printf("Entre as opcoes:\n");
            printf("1 - 10\n");
            printf("2 - 100\n");
            printf("3 - 1000\n");
            printf("4 - 10000\n");
            scanf(" %c",&op1);

            if(op1 == '1')
            {
                quantd = 10;
                valores = criarVetor(quantd);
                entrada(valores,quantd);
            }
            else if(op1 == '2')
            {
                quantd = 100;
                valores = criarVetor(quantd);
                entrada(valores,quantd);
            }
            else if(op1 == '3')
            {
                quantd = 1000;
                valores = criarVetor(quantd);
                entrada(valores,quantd);
            }
            else if(op1 == '4')
            {
                quantd = 10000;
                valores = criarVetor(quantd);
                entrada(valores,quantd);
            }
            system("pause");
        }
        else if(escolha == '2')
        {
            // Por padrão os valores já estarão dispostos de forma aleatória
            printf("Entre as opcoes:\n");
            printf("1 - Descendente\n");
            printf("2 - Aleatorio\n");
            scanf(" %c",&op2);

            if(op2 == '1')
            {
                // Irá ordenar de modo descendente
                SelectionSort(valores,quantd);
            }
            system("pause");

        }
        else if(escolha == '3')
        {
            Imprime(valores,quantd);
            system("pause");
        }
        else if(escolha == '4')
        {
            printf("Entre as opcoes:\n");
            printf("1 - BubbleSort\n");
            printf("2 - QuickSort\n");
            printf("3 - RadixSort\n");
            scanf(" %c",&op4);

            if(op4 == '1')
            {
                inicio = clock();
                BubbleSort(valores,quantd);
                fim = clock();
            }
            else if(op4 == '2')
            {
                inicio = clock();
                QuickSort(valores,0,quantd-1);
                fim = clock();
            }
            else if(op4 == '3')
            {
                inicio = clock();
                RadixSort(valores,quantd);
                fim = clock();
            }
            tempo_util_cpu = (double(fim-inicio))/CLOCKS_PER_SEC;
            Imprime(valores,quantd);
            printf("Numero de comparacoes = %ld\nNumero de trocas = %ld\nTempo de execucao = %lf\n\n",num_comparacoes,num_trocas,tempo_util_cpu);
            system("pause");
            num_trocas = 0;
            num_comparacoes = 0;
            tempo_util_cpu = 0;
        }
        else if(escolha == '5')
        {
            break;
        }
        system("cls");
    }
}

int main()
{
    Menu();
    return 0;
}
