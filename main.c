#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include <locale.h>
#include <malloc.h>

int main()
{
    setlocale(LC_ALL, "Rus");
    srand(time(NULL));
    char* F1 = "F1.txt";
    char* F2 = "F2.txt";
    FILE* file1 = fopen(F1, "w+");
    FILE* file2 = fopen(F2, "w");
    if (file1 == NULL || file2 == NULL)
        return;
    int N, tmp, max = 0;;
    int* coef = NULL;
    printf("Колчиество элементов в массиве: ");
    scanf("%d", &N);
    coef = (int*)malloc(N * sizeof(int));
    
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < N; j++)
        {
            coef[j] = 1 + rand() % 10;
            fprintf(file1, "%d ", coef[j]);
        }
        if (i != 8)
            fprintf(file1, "\n");
    }

    rewind(file1);

   for (int j = 0; j < 9; j++)
   {
        for (int i = 0; i < N; i++)
        {
            fscanf_s(file1, "%d", &coef[i]);
            if (coef[i] > max)
                max = coef[i];
        }
        
        for (int i = 0; i < N; i++)
        {
            if (coef[i] == max)
                coef[i] = 0;
            fprintf(file2, "%d ", coef[i]);
        }
        if (j != 8)
            fprintf(file2, "\n");
        max = 0;
   }

   fclose(file1); fclose(file2); free(coef);
    return 0;
}