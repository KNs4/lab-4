#include <iostream>
#include <cmath>
using namespace std;

class LineSegment {
private:
    double x; // Координата начала отрезка
    double y; // Координата конца отрезка

public:
    // Конструкторы
    LineSegment() : x(0), y(0) {} // Конструктор по умолчанию
    LineSegment(double x, double y) : x(x), y(y) {} // Конструктор с параметрами
    LineSegment(const LineSegment& other) : x(other.x), y(other.y) {} // Конструктор копирования

    // Свойства (геттеры и сеттеры)
    double getX() const { return x; }
    void setX(double value) { x = value; }

    double getY() const { return y; }
    void setY(double value) { y = value; }

    // Проверка, попадает ли число в отрезок
    bool isWithinSegment(double number) const {
        return (number >= x && number <= y) || (number >= y && number <= x);
    }

    // Унарные операции
    double operator!() const {
        return abs(y - x); // Длина отрезка
    }

    LineSegment& operator++() { // Префиксный инкремент
        ++x;
        ++y;
        return *this;
    }

    // Операции приведения типа
    explicit operator int() const { return static_cast<int>(x); } // Явное приведение к int
    operator double() const { return y; } // Неявное приведение к double

    // Бинарные операции
    LineSegment operator+(int d) const { // Сдвиг границ отрезка на число d
        return LineSegment(x + d, y + d);
    }

    bool operator>(int d) const { // Проверка, попадает ли число в отрезок
        return isWithinSegment(d);
    }

    // Перегрузка оператора вывода
    friend ostream& operator<<(ostream& os, const LineSegment& segment) {
        os << "LineSegment: [" << segment.x << ", " << segment.y << "]";
        return os;
    }
};

int main() {
    // Ввод данных
    double start, end, testPoint;
    cout << "Введите начало и конец отрезка: ";
    cin >> start >> end;

    LineSegment segment(start, end);

    cout << "Введите число для проверки: ";
    cin >> testPoint;

    // Метод
    cout << segment << endl;
    if (segment.isWithinSegment(testPoint)) {
        cout << "Число " << testPoint << " попадает в отрезок." << endl;
    } else {
        cout << "Число " << testPoint << " не попадает в отрезок." << endl;
    }

    // Унарные операции
    cout << "Длина отрезка (!segment): " << !segment << endl;

    ++segment; // Инкремент границ
    cout << "После инкремента (++segment): " << segment << endl;

    // Приведение типа
    int startAsInt = static_cast<int>(segment);
    double endAsDouble = segment;
    cout << "Приведение к int: " << startAsInt << endl;
    cout << "Приведение к double: " << endAsDouble << endl;

    // Бинарные операции: ввод числа для сдвига
    int shiftValue;
    cout << "Введите число, на которое хотите сдвинуть границы отрезка: ";
    cin >> shiftValue;

    LineSegment newSegment = segment + shiftValue;
    cout << "Сдвиг отрезка (segment + " << shiftValue << "): " << newSegment << endl;

    int testInt = static_cast<int>(testPoint);
    if (segment > testInt) {
        cout << "Число " << testInt << " попадает в отрезок." << endl;
    } else {
        cout << "Число " << testInt << " не попадает в отрезок." << endl;
    }

    return 0;
}
