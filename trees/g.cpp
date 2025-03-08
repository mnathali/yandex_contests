#include <iostream>
#include <vector>

using namespace std;

// Функция для вычисления факториала
unsigned long long factorial(int n) {
    if (n == 0 || n == 1) return 1;
    unsigned long long result = 1;
    for (int i = 2; i <= n; ++i) {
        result *= i;
    }
    return result;
}

// Функция для вычисления биномиального коэффициента C(n, k)
unsigned long long binomial(int n, int k) {
    if (k > n) return 0;
    return factorial(n) / (factorial(k) * factorial(n - k));
}

// Рекурсивная функция подсчета размещений
unsigned long long countArrangements(int n, int m) {
    // Граничные случаи
    if (n == 0) return 1;  // Один способ — ничего не размещать
    if (m == 0) return 0;  // Невозможно разместить, если нет коробок
    if (m == 1) return factorial(n);  // Все шарики в одной коробке
    
    // Основной расчет
    unsigned long long total = 0;
    for (int k = 0; k <= n; ++k) {
        total += binomial(n, k) * factorial(k) * countArrangements(n - k, m - 1);
    }
    return total;
}

int main() {
    int n = 3; // Число шариков
    int m = 5; // Число коробок

    cout << "Количество размещений: " << countArrangements(n, m) << endl; // Ожидается 30
    return 0;
}
