#include <iostream>

using namespace std;

struct Image {
    double quality;
    double freshness;
};

struct Params {
    double a;
    double b;
};

double ComputeImageWeight(const Params& params, const Image& image) {
    double weight = image.quality;
    weight -= image.freshness * params.a + params.b;
    return weight;
}

double ComputeQualityByWeigh(const Params& params, 
                            const Image& image, 
                            double weight) {
    double quality = weight;
    quality += image.freshness * params.a + params.b;
    return weight;
}

int main() {
    return 0;
}