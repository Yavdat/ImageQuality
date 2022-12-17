#include <iostream>

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

// некий алгоритм для вычисления веса изображения
double ComputeImageWeight(const Params& params, const Image& image) {
    double weight = image.quality;
    weight -= image.freshness * params.a + params.b;
    weight += image.rating * params.c; // добавил rating
    return weight;
}
// некий алгоритм для вычисления качества изображения
double ComputeQualityByWeigh(const Params& params, 
                            const Image& image, 
                            double weight) {
    double quality = weight;
    quality -= image.rating * params.c; // добавил rating
    quality += image.freshness * params.a + params.b;
    return weight;
}

int main() {
    return 0;
}