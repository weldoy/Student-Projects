#include <stdio.h> 
#include <math.h>
#include <stdlib.h>

void createlist(int *lst, int n){
    printf("Введите элементы массива: \n");
    for (int i = 0; i < n; i++){
        printf("B[%d]: ", i);
        scanf("%d", &lst[i]);
    }
}

void printlist(int *lst, int n){
    printf("Массив: ");
    for (int i = 0; i < n; i++){
        printf("%d ", lst[i]);
    }
    printf("\n");
}

// Task 1
int findMinElem(int *lst, int n, int x){
    int cond = 0, minElem = 0;

    for (int i = 0; i < n; i++){
        if (abs(lst[i]) > x) {
            if (!cond) {
                minElem = lst[i];
                cond = 1;
            } else if (lst[i] < minElem) {
                minElem = lst[i];
            }
        }
    }

    if (cond) return minElem;
    else {
        printf("Не было найдено минимального элемента\n");
        return 0;
    }
}

// Task 2
double specialAverage(int *lst, int n){
    int first = -1, last = -1;

    for (int i = 0; i < n; i++){
        if (abs(lst[i]) >= 10 && abs(lst[i]) <= 99){
            if (first == -1) first = i;
            last = i;
        }
    }

    if (first == -1 || last == -1 || first == last){
        printf("Недостаточно подходящих двузначных чисел :( \n");
        return 0;
    }

    int sum = 0, count = 0;
    for (int i = first + 1; i < last; i++){
        sum += lst[i];
        count++;
    }

    if (count == 0){
        printf("Между числами нет элементов\n");
        return 0;
    }

    return (double)sum / count;
}

int main(void) {
    int n, x;

    printf("Введите кол-во элементов массива:\n ");
    scanf("%d", &n);

    /*
    int *lst = (int *)malloc(n * sizeof(int));
    if (!lst) {
        printf("Ошибка выделения памяти!");
    }
    */
   int lst[n];

    createlist(lst, n);
    printlist(lst, n);
    
    printf("Введите значение x: ");
    scanf("%d", &x);

    int minElem = findMinElem(lst, n, x);
    printf("Минимальный элемент массива |bi| > %d = %d\n", x, minElem);

    double aver = specialAverage(lst, n);
    if (aver != 0){
        printf("Среднее арифметическое чисел между первым и последним двузначными числами = %.2f\n", aver);
    }
    
    return 0;
}
