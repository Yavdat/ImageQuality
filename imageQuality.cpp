#include <iostream>
#include <vector>

using namespace std;

struct Image {
    double quality;
    double freshness;
    double rating; // добавил rating
};

struct Params {
    double a;
    double b;
    double c; // т.к добавили новый параметр к изображению
};

class FunctionPart {
public:
    FunctionPart(char new_operation, double new_value) {
        operation = new_operation;
        value = new_value;
    }
    double Apply(double source_value) const {
        if (operation == '+') {
            return source_value + value;
        } else {
            return source_value - value;
        }
    }
    void Invert() {
        if (operation == '+') {
            operation = '-';
        } else {
            operation = '+';
        }
    }
private:
    char operation;
    double value;
};
// Если у нас есть способ вычисления веса по его 
// качеству(который неявно дублируется в коде),
// то мы для этого можем написать класс.

// Как и говорилось выше, создадим Класс, который будет содержать набор функций
class Function {
public:
    void AddPart(char operation, double value);
    double Apply(double value) const;
    void Invert();
private:
    // каждая элементарная операция - это некий объект FunctionPart
    vector<FunctionPart> parts;
}

Function MakeWeightFunction(const Params& params, const Image& image) {
    // создадим некоторый объект который хотим использовать в ниже приведенных функциях.
    Function function;
    function.AddPart('-', image.freshness * params.a + params.b);
    function.AddPart('+', image.rating * params.c);
    return function;
}

// // некий алгоритм для вычисления веса изображения
// double ComputeImageWeight(const Params& params, const Image& image) {
//     double weight = image.quality;
//     weight -= image.freshness * params.a + params.b;
//     weight += image.rating * params.c; // добавил rating
//     return weight;
// }
// // некий алгоритм для вычисления качества изображения
// double ComputeQualityByWeigh(const Params& params, 
//                             const Image& image, 
//                             double weight) {
//     double quality = weight;
//     quality -= image.rating * params.c; // добавил rating
//     quality += image.freshness * params.a + params.b;
//     return weight;
// }

// некий алгоритм для вычисления веса изображения
double ComputeImageWeight(const Params& params, const Image& image) {
    Function function = MakeWeightFunction(params, image);
    return function.Apply(image.quality);
}
// некий алгоритм для вычисления качества изображения
double ComputeQualityByWeigh(const Params& params, 
                            const Image& image, 
                            double weight) {
    Function function = MakeWeightFunction(params, image);
    function.Invert();
    return function.Apply(weight);
}

int main() {
    return 0;
}