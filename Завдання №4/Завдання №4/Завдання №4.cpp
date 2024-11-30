#include <iostream>

using namespace std;

int multiply(int a, int b) { // Ця функція реалізує множення чисел a та b через додавання. Якщо b додатне, a додається до result b разів. Якщо b від'ємне, результат змінюється на протилежний знак.
    int result = 0;
    for (int i = 0; i < abs(b); ++i) {
        result += a;
    }
    return (b < 0) ? -result : result;
}

int divide(int a, int power) {
    return a >> power; // Побітове ділення на 2^power
}

int main() {

    setlocale(LC_ALL, "ukr");

    int x, y;
    cout << "Введіть x: ";
    cin >> x;
    cout << "Введіть y: ";
    cin >> y;

    // Обчислення (20 * y - x * 120) / 32
    int part1 = divide(multiply(20, y) - multiply(x, 120), 5); // 32 = 2^5

    // Обчислення (x + 32 * y) / 128
    int part2 = divide(x + multiply(32, y), 7); // 128 = 2^7

    // Обчислення (x + y) % 16
    int part3 = (x + y) & 15; // Операція AND з 15 еквівалентна взяттю залишку від ділення на 16

    // Результат
    int result = part1 + part2 + part3;
    cout << "Результат: " << result << endl;

    return 0;
}
