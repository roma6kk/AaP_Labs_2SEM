#include <iostream>
#include <cmath>
using namespace std;
double dichotomyMethod(double (*equation)(double), double a, double b, double e) {
    double c;
    while (fabs(b - a) > e) {
        c = (a + b) / 2.0;
        if (equation(c) == 0.0)
            return c;
        else if (equation(a) * equation(c) < 0)
            b = c;
        else
            a = c;
    }
    return (a + b) / 2.0;
}

double func1(double x) {
    return x * x * x + 2 * x - 1;
}

double func2(double x) {
    return exp(x) - 2;
}

int main() {
    setlocale(0, "rus");
    double a, b, e;
    cout << "Введите начальное значение a: ";
    cin >> a;
    cout << "Введите конечное значение b: ";
    cin >> b;
    cout << "Введите точность e: ";
    cin >> e;
    double root1 = dichotomyMethod(func1, a, b, e);
    double root2 = dichotomyMethod(func2, a, b, e);
    cout << "Корень первого уравнения: " << root1 << endl;
    cout << "Корень второго уравнения: " << root2 << endl;
    return 0;
}