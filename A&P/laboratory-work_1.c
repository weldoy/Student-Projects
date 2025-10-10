#include <stdio.h>

double my_abs(double n){
    return (n < 0.0) ? -n : n; // Тернарный оператор
}

double input_double(const char* prompt) {
    double x;
    int res;
    char c;
    do {
        printf("%s", prompt);
        res = scanf("%lf", &x);
        while ((c = getchar()) != '\n' && c != EOF); // Очистка буфера, проверка, что пользователь ввел только число
    } while (res != 1);
    return x;
}

int input_int(const char* prompt) {
    int x;
    int res;
    char c;
    do {
        printf("%s", prompt);
        res = scanf("%d", &x);
        while ((c = getchar()) != '\n' && c != EOF);
    } while (res != 1);
    return x;
}

int main(void){
    double x;
    int option;

    do {
        x = input_double("Введите x (|x| > 1): ");
    } while (my_abs(x) <= 1);

    do {
        option = input_int("Выберите способ вычисления\n1 - по точности\n2 - по кол-ву членов суммы\n");
    } while (option != 1 && option != 2);

    int invert = 0;
    if (my_abs(x) > 1) {
        invert = 1;
        x = 1.0 / x;
    }

    double sum = 0.0;

    if (option == 1){
        double e, current;
        int n = 0;

        do {
            e = input_double("Введите точность (e > 0): ");
        } while (e <= 0);

        current = x;
        while (my_abs(current) > e) {
            sum += current;
            n++;
            current = -current * x * x * (2*n - 1.0) / (2*n + 1.0);
        }
    } else {
        int N;
        double current;
        int n;

        do {
            N = input_int("Введите кол-во членов ряда (> 0): ");
        } while (N <= 0);

        current = x;
        for (n = 0; n < N; n++){
            sum += current;
            current = -current * x * x * (2*n + 1.0) / (2*n + 3.0);
        }
    }

    if (invert) {
        sum = 1.5707963267948966 - sum;
    }

    printf("Результат ряда: %lf\n", sum);

    return 0;
}
