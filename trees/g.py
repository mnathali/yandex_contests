from math import factorial

def binomial(n, k):
    if k > n:
        return 0
    return factorial(n) // (factorial(k) * factorial(n - k))

def count_arrangements(n, m):
    # Граничные случаи
    if n == 0:
        return 1  # Один способ — ничего не размещать
    if m == 0:
        return 0  # Невозможно разместить, если нет коробок
    if m == 1:
        return factorial(n)  # Все шарики в одной коробке
    
    # Основной рекурсивный расчет
    total = 0
    for k in range(n + 1):
        total += binomial(n, k) * factorial(k) * count_arrangements(n - k, m - 1)
    return total

# Пример использования
n = 3
m = 5
print(count_arrangements(n, m))  # Ожидается 30
