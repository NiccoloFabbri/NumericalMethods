//
// Created by Niccolò Fabbri on 08/09/23.
//
#include "RandomSampling.h"
#include <cmath>


std::vector<double> GenerateUniformSamples(int N, unsigned long long seed)
{
    LCG generator(seed);
    std::vector<double> samples;
    for (int i = 0; i < N; ++i)
    {
        samples.push_back(generator.next());
    }
    return samples;
}


std::vector<double> a{2.50662823884, -18.61500062529, 41.39119773534, -25.44106049637};
std::vector<double> b{-8.47351093090, 23.08336743743, -21.06224101826,  3.13082909833};
std::vector<double> c{0.3374754822726147, 0.9761690190917186, 0.1607979714918209,
                      0.0276438810333863, 0.0038405729373609, 0.0003951896511919,
                      0.0000321767881768, 0.0000002888167364, 0.0000003960315187 };


double InverseTransformation(double u) // Springer-Moro algorithm
{
    double r;
    double x;
    double y = u - 0.5;
    if(std::abs(y) < 0.42)
    {
        r = y*y;
        x = y * (((a[3] * r + a[2]) * r + a[1]) * r + a[0]) /
            ((((b[3] * r + b[2]) * r + b[1]) * r + b[0]) * r + 1);
    }
    else{
        r = u;
        if(y > 0){
            r = 1 - u;
        }
        r = std::log(-std::log(r));
        x = c[0] + r * (c[1] + r * (c[2] + r * (c[3] + r * (c[4] + r *(c[5] + r * (c[6] + r * (c[7] + r * c[8])))))));
        if (y < 0){
            x = -x;
        }
    }
    return x;
}


std::vector<double> GenerateNormalSamples(std::size_t N, unsigned long long seed) {
    LCG generator(seed);
    std::vector<double> samples;
    for (int i = 0; i < N; ++i) {
        // Generate a number strictly between 0 and 1
        double u;
        do {
            u = generator.next();
        } while(u <= 0.0 || u >= 1.0);

        samples.push_back(InverseTransformation(u)); // Make sure this is the correct function name
    }
    return samples;
}



double AcceptanceRejection(std::vector<double>& uniform_samples, int& index)
{
    const double c = std::sqrt(2.0 * std::exp(1.0) / M_PI);

    while (true)
    {
        double u1 = uniform_samples[index++];
        double u2 = uniform_samples[index++];
        double u3 = uniform_samples[index++];

        double X = -std::log(u1);

        if (u2 > std::exp(-0.5 * std::pow(X - 1, 2))) {
            continue;
        } else {
            if (u3 <= 0.5) {
                X = -X;
            }
            return X;
        }
    }
}


std::vector<double> BoxMuller(double N) {

    double u1, u2, X;
    LCG lcg(1);
    int count = 0;
    std::vector<double> res;
    while (count < N) {
        do {
            u1 = 2. * lcg.next() - 1.;
            u2 = 2. * lcg.next() - 1.;
            X = u1 * u1 + u2 * u2;
        } while (X > 1);

        double Y = std::sqrt(-2. * std::log(X) / X);
        res.push_back(u1 * Y);
        res.push_back(u2 * Y);
        count += 2;
    }
    return res;
}



