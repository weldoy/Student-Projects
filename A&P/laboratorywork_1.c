#include <stdio.h>

double my_abs(double n){ // Функция вычисления модуля числа
    return (n < 0.0) ? -n : n; // Тернарный оператор
}

double input_double(const char* input) {
    double x;
    int res;
    char c;
    int bad_input = 0;
    
    do {
        printf("%s", input);
        res = scanf("%lf", &x);
        
        bad_input = 0;
        while ((c = getchar()) != '\n' && c != EOF) { // Проверяем, есть ли лишние символы после числа
            if (!bad_input) {
                bad_input = 1; // Найден лишний символ
            }
        }
        
    } while (res != 1 || bad_input);
    
    return x;
}

int input_int(const char* input) { // Функция, проверяющая, что человек ввел int
    int x; // Выше строкой - const - инпут не будет изменятся, char* - указатель на первой символ ввода, чтобы оценить ввод
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
                bad_input = 1; // Найден лишний символ
            }
        }
        
    } while (res != 1 || check_float || bad_input);
    
    return x;
}

int main(void){ // Основная программа
    double x;
    int option;

    do {
        x = input_double("Введите x (|x| > 1): "); // Получение числа x и его проверка на корректность
    } while (my_abs(x) <= 1);

    do {
        option = input_int("Выберите способ вычисления\n1 - по точности\n2 - по кол-ву членов суммы\n"); // Получение желаемого типа подсчета
    } while (option != 1 && option != 2); // Проверка на корректность

    int invert = 0; // Инвертирование числа, для ускорения подсчета
    if (my_abs(x) > 1) {
        invert = 1;
        x = 1.0 / x;
    }

    double sum = 0.0; // Инициализация суммы 

    if (option == 1){ // Логика первого варианта вычисления
        double e, current;
        int n = 0;

        do {
            e = input_double("Введите точность (e > 0): "); // Проверка и получение корректности ввода точности
        } while (e <= 0);

        current = x;
        while (my_abs(current) > e) { // Вычисление ряда
            sum += current;
            n++;
            current = -current * x * x * (2*n - 1.0) / (2*n + 1.0);
        }
    } else {
        int N;
        double current;
        int n;

        do {
            N = input_int("Введите кол-во членов ряда (> 0): "); // Проверка и получение корректности кол-во членов ряда
        } while (N <= 0);

        current = x; 
        for (n = 0; n < N; n++){ // Вычисление ряда
            sum += current;
            current = -current * x * x * (2*n + 1.0) / (2*n + 3.0);
        }
    }

    if (invert) { // Обратное инвертирование числа
        sum = 1.5707963267948966 - sum; // pi/2 - sum
    }

    printf("Результат ряда: %lf\n", sum); // Вывод результата

    return 0;
}
