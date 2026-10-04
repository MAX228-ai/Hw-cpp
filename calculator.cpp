/*
Дополните  Calculator базовыми арифметическими операциями:
1) Суммирование, разность, умножение
2) Деление всех видов (целое, с остатком, обычное деление)
3) Не забудьте учесть особенности типов и поиграться с перегрузками

В main нужно придумать запустить свой простенький тест (например, проверить каждую операцию по очереди)


Не забывайте про кодстайл, за решение задачки дают семинарские баллы)
*/

#include <cassert>
#include <iostream>
#include <cmath>

// Базовые методы для арифм. операций
class Add {
    public:
        static double AddDouble(const double a, const double b) {
            return a+b;
        };

        static int AddInt(const int a, const int b) {
            return a+b;
        }
};

class Minus {
    public:
        static double MinusDouble(const double a, const double b) {
            return a-b;
        };

        static int MinusInt(const int a, const int b) {
            return a-b;
        }
};

class Multiply {
    public:
        static double MultiplyDouble(const double a, const double b){
            return a*b;
        };

        static int MultiplyInt(const int a, const int b) {
            return a*b;
        }
};

class Divide {
public:
    static double DivideDouble(const double a = 0 , const int b = 0, const double x = 0, const int y = 0, const int sw = 0 ) {
        if (not(x or y)) {
            throw std::runtime_error("Division by zero");
        }
        if (!a&&!b) {
            return 0.0;
        }
        if (a&&x){
            switch(sw) {
                default:
                    return a/x;
                case 1:
                    return std::fmod(a, x);
                case 2:
                    return static_cast<int>(a / x);
            }
        }
        if (a&&y){
            switch(sw) {
                default:
                    return a/y;
                case 1:
                    return std::fmod(a, y);
                case 2:
                    return a/y-std::fmod(a, y);
            }
        }
        if (b&&x){
            switch(sw) {
                default:
                    return b/x;
                case 1:
                    return std::fmod(b, x);
                case 2:
                    return b/x-std::fmod(b, x);
            }
        }
        if (b&&y){
            switch(sw) {
                default:
                    return static_cast<double>(b) / y;;
                case 1:
                    return b%y;
                case 2:
                    return b/y;
            }
        }
    }
};

int main() {
    int a = 10;
    int b = 5;

    assert(Add::AddInt(a, b) == 15);
    assert(Add::AddDouble(10.5, 5.5) == 16.0);

    assert(Minus::MinusInt(a, b) == 5);
    assert(Minus::MinusDouble(10.5, 5.5) == 5.0);

    assert(Multiply::MultiplyInt(a, b) == 50);
    assert(Multiply::MultiplyDouble(10.5, 2.0) == 21.0);

    assert(Divide::DivideDouble(0, a, 0, b) == 2);
    assert(Divide::DivideDouble(0, a, 0, b, 1) == 0);
    assert(Divide::DivideDouble(10, 0, 5, 0, 2) == 2);

    return 0;
}


