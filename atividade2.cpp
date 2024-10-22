#include "atividade2.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;
long long int num_comparacoes = 0, num_trocas = 0;

// Criando um vetor de tamanho dinâmico
TipoItem* criarVetor(int tam)
{
    TipoItem *vector;
    vector = (TipoItem*)malloc(tam*sizeof(TipoItem));
    
    if (vector == NULL) {
        printf("Erro ao alocar memoria.\n");
        exit(1);  // Sai do programa em caso de falha na alocação
    }

    return vector;
}

// Gerando números aleatórios
void entrada(TipoItem* valores,int quantd)
{
    int i;
    
    TipoChave ch;

    printf("\n\nForam gerados %d valores aleatorios.\n\n",quantd);

    srand(time(NULL));
    for (i=0;i<quantd;i++)
    {
        // gerando valores aleatórios na faixa de 0 a 100
        //printf("%d ", rand()%quantd + 1);
        ch = rand()%quantd+1;
        valores[i].Chave = ch;
    }

    cout << "\n";
}

// Exibir elementos do vetor
void Imprime(TipoItem* Vector,int quantd)
{
    for(int i = 0;i<quantd;i++)
    {
        printf("%ld ",Vector[i].Chave);
    }
    printf("\n");
}

// BubbleSort - Ordenação por flutuação
void BubbleSort(TipoItem *A, int n)
{
    int i, j;
    TipoItem temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            num_comparacoes++;
            if (A[j].Chave > A[j + 1].Chave) {
                temp = A[j];
                A[j] = A[j + 1];
                A[j + 1] = temp;
                num_trocas++;
            }
        }
    }
}

// SelectionSort - Ordenação por seleção
// Irá ordenar de forma descendente
void SelectionSort(TipoItem *A,TipoIndice n)
{
    TipoIndice i, j, Min, Max;
    TipoItem x;
    for(i = 0;i<=n-1;i++)
    {
        Max = i;
        for(j=i+1;j<n;j++)
        {
            if(A[j].Chave > A[Max].Chave)
            {
                Max = j;
            }
        }
        x = A[Max];
        A[Max] = A[i];
        A[i] = x;
    }
}

// QuickSort
int Partition(TipoItem *A, int low, int high)
{
    TipoChave pivot = A[high].Chave;
    int i = low - 1;
    TipoItem temp;

    for (int j = low; j < high; j++) {
        num_comparacoes++;
        if (A[j].Chave <= pivot) {
            i++;
            temp = A[i];
            A[i] = A[j];
            A[j] = temp;

            num_trocas;
        }
    }

    temp = A[i + 1];
    A[i + 1] = A[high];
    A[high] = temp;

    num_trocas++;

    return i + 1;
}

void QuickSort(TipoItem *A, int low, int high)
{
    if (low < high) {
        int pi = Partition(A, low, high);
        QuickSort(A, low, pi - 1);
        QuickSort(A, pi + 1, high);
    }
}

// RadixSort
int getMax(TipoItem *A, int n)
{
    int max = A[0].Chave;
    for (int i = 1; i < n; i++){
        num_comparacoes++;
        if (A[i].Chave > max)
            max = A[i].Chave;
    }
    return max;
}

void CountingSortForRadix(TipoItem *A, int n, int exp)
{
    TipoItem *output = (TipoItem *)malloc(n * sizeof(TipoItem));
    int count[10] = {0};

    for (int i = 0; i < n; i++){
        num_comparacoes++;
        count[(A[i].Chave / exp) % 10]++;
    }
    for (int i = 1; i < 10; i++)
    {
        num_comparacoes++;
        count[i] += count[i - 1];
    }

    for (int i = n - 1; i >= 0; i--)
    {
        num_comparacoes++;
        output[count[(A[i].Chave / exp) % 10] - 1] = A[i];
        count[(A[i].Chave / exp) % 10]--;
        num_trocas++;
    }

    for (int i = 0; i < n; i++)
    {
        num_comparacoes++;
        A[i] = output[i];
        num_trocas++;
    }
    free(output);
}

void RadixSort(TipoItem *A, int n)
{
    int m = getMax(A, n);

    for (int exp = 1; m / exp > 0; exp *= 10){
        num_comparacoes++;
        CountingSortForRadix(A, n, exp);
    }
}
