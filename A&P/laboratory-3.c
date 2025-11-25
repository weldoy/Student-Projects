#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int input_int(const char* input) { // Функция проверки ввода int
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
        while ((c = getchar()) != '\n' && c != EOF) { // Проверка на оставшиеся символы в потоке
            if (c == '.' || c == ',') {
                check_float = 1;
            }
            bad_input = 1; // ошибка, тк лишний символ в потоке
        }

        if (res != 1 || check_float || bad_input) {
            printf("Ошибка! Введите целое число.\n");
        } else break; // Ввод корректный

    } while (1);

    return x;
}

void create_matrix(int matrix[MAX][MAX], int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            char input[50];
            sprintf(input, "matrix[%d][%d] = ", i, j);
            matrix[i][j] = input_int(input);
        }
    }
}

void print_matrix(int matrix[MAX][MAX], int m, int n) {
    printf("Матрица:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%4d", matrix[i][j]);
        }
        printf("\n");
    }
}

// Функция поиска минимального элемента
int min_in_row_with_max_sum(int matrix[MAX][MAX], int m, int n) {
    int max_sum = -2147483647; // Минимально возможное число, которое хранит int
    int row_index = 0;
    for (int i = 0; i < m; i++) { // Поиск максимальной суммы
        int sum = 0;
        for (int j = 0; j < n; j++) {
            sum += matrix[i][j];
        }
        if (sum > max_sum) {
            max_sum = sum;
            row_index = i;
        }
    }

    int min_value = matrix[row_index][0]; // Ищем минимальное число
    for (int j = 1; j < n; j++) {
        if (matrix[row_index][j] < min_value)
            min_value = matrix[row_index][j];
    }
    return min_value;
}

// Вывод квадратного фрагмента k x k по диагонали
void print_diagonal_fragment(int matrix[MAX][MAX], int k) {
    printf("Квадратный фрагмент %d x %d по диагонали:\n", k, k);
    for (int sum = 0; sum <= k - 1; sum++) {
        for (int i = 0; i <= sum; i++) {
            int j = sum - i;
            printf("%4d", matrix[i][j]);
        }
        printf("\n");
    }
}

// Основная функция
int main(void) {
    int m, n;

    do {
        m = input_int("Введите количество строк: ");
        if (m <= 1 || m > MAX) {
            printf("Количество строк должно быть от 2 до %d!\n", MAX);
        }
    } while (m <= 1 || m > MAX);

    do {
        n = input_int("Введите количество столбцов: ");
        if (n <= 1 || n > MAX) {
            printf("Количество столбцов должно быть от 2 до %d!\n", MAX);
        }
    } while (n <= 1 || n > MAX);

    int matrix[MAX][MAX]; // Инициализация матрицы 
    create_matrix(matrix, m, n);
    print_matrix(matrix, m, n);

    int min_value = min_in_row_with_max_sum(matrix, m, n); // Минимальный элемент
    printf("Минимальное значение в строке с максимальной суммой: %d\n", min_value);

    int k = (m < n) ? m : n; // Квадратный элемент
    print_diagonal_fragment(matrix, k);

    return 0;
}