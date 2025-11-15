#include <stdio.h>
#include <stdlib.h>

int input_int(const char* input) { // Функция, проверяющая, что человек ввел int
    int x;
    int res;
    char c;
    int check_float = 0;
    int bad_input = 0;

    do {
        printf("%s", input);
        res = scanf("%d", &x);

        bad_input = 0;
        check_float = 0;
        while ((c = getchar()) != '\n' && c != EOF) {
            if (c == '.' || c == ',') {
                check_float = 1;
            }
            if (!bad_input) {
                bad_input = 1; // найден лишний символ
            }
        }

        if (res != 1 || check_float || bad_input) {
            printf("Ошибка! Введите целое число.\n");
        }

    } while (res != 1);

    return x;
}

void createlist(int *lst, int n) {
    printf("Введите элементы массива: \n");
    for (int i = 0; i < n; i++) {
        char input[50];
        sprintf(input, "B[%d]: ", i);
        lst[i] = input_int(input);
    }
}

void printlist(int *lst, int n) {
    printf("Массив: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", lst[i]);
    }
    printf("\n");
}

// Task 1
int findMinElem(int *lst, int n, int x) {
    int cond = 0, minElem = 0;

    for (int i = 0; i < n; i++) {
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
double specialAverage(int *lst, int n) {
    int first = -1, last = -1;

    for (int i = 0; i < n; i++) {
        if (abs(lst[i]) >= 10 && abs(lst[i]) <= 99) {
            if (first == -1) first = i;
            last = i;
        }
    }

    if (first == -1 || last == -1 || first == last) {
        printf("Недостаточно подходящих двузначных чисел :( \n");
        return 0;
    }

    int sum = 0, count = 0;
    for (int i = first + 1; i < last; i++) {
        sum += lst[i];
        count++;
    }

    if (count == 0) {
        printf("Между числами нет элементов\n");
        return 0;
    }

    return (double)sum / count;
}

int main(void) {
    int n, x;

    do {
        n = input_int("Введите кол-во элементов массива: ");
        if (n <= 0) {
            printf("Количество элементов должно быть положительным!\n");
        }
    } while (n <= 0);

    int lst[n];

    createlist(lst, n);
    printlist(lst, n);

    do {
        x = input_int("Введите значение x: ");
        if (x < 0) printf("X >= 0, попробуйте снова\n");
    } while (x < 0);

    int minElem = findMinElem(lst, n, x);
    printf("Минимальный элемент массива |bi| > %d = %d\n", x, minElem);

    double aver = specialAverage(lst, n);
    if (aver != 0) {
        printf("Среднее арифметическое чисел между первым и последним двузначными числами = %.2f\n", aver);
    }

    return 0;
}