#include <stdio.h>
#include <string.h>

#define MAX_CONTATOS 100

typedef struct {
    char nome[50];
    char telefone[15];
} Contato;

int comparacoes_bubble = 0;
int movimentacoes_bubble = 0;

void bubbleSort(Contato arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            comparacoes_bubble++;
            if (strcmp(arr[j].nome, arr[j + 1].nome) > 0) {
                movimentacoes_bubble += 3; // 3 movimentações para trocar
                Contato temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int comparacoes_merge = 0;
int movimentacoes_merge = 0;

void merge(Contato arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;
    Contato L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        comparacoes_merge++;
        if (strcmp(L[i].nome, R[j].nome) <= 0) {
            movimentacoes_merge++;
            arr[k++] = L[i++];
        } else {
            movimentacoes_merge++;
            arr[k++] = R[j++];
        }
    }
    while (i < n1) {
        movimentacoes_merge++;
        arr[k++] = L[i++];
    }
    while (j < n2) {
        movimentacoes_merge++;
        arr[k++] = R[j++];
    }
}

void mergeSort(Contato arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

int main() {
    Contato contatos[MAX_CONTATOS];
    int n = 5;

    // Exemplo de contatos
    strcpy(contatos[0].nome, "Carlos");
    strcpy(contatos[0].telefone, "1234-5678");

    strcpy(contatos[1].nome, "Ana");
    strcpy(contatos[1].telefone, "2345-6789");

    strcpy(contatos[2].nome, "Bruno");
    strcpy(contatos[2].telefone, "3456-7890");

    strcpy(contatos[3].nome, "Diana");
    strcpy(contatos[3].telefone, "4567-8901");

    strcpy(contatos[4].nome, "Felipe");
    strcpy(contatos[4].telefone, "5678-9012");

    // Ordenação com Bubble Sort
    bubbleSort(contatos, n);
    printf("Bubble Sort:\n");
    printf("Comparações: %d, Movimentações: %d\n\n", comparacoes_bubble, movimentacoes_bubble);

    // Resetar contadores
    comparacoes_bubble = 0;
    movimentacoes_bubble = 0;

    // Ordenação com Merge Sort
    mergeSort(contatos, 0, n - 1);
    printf("Merge Sort:\n");
    printf("Comparações: %d, Movimentações: %d\n", comparacoes_merge, movimentacoes_merge);

    return 0;
}
