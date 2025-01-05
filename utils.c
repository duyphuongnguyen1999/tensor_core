#include <stdlib.h>
#define _USE_MATH_DEFINES
#include <math.h>

// Helper function to generate random numbers from a normal distribution, use Box-Muller transform
double box_muller_generator(double mean, double stddev)
{
    // Generate 2 random uniform distribution numbers using rand()
    double u1 = (double)rand() / RAND_MAX;
    double u2 = (double)rand() / RAND_MAX;

    // Use Box-Muller transform to generate standard normal random variables
    double R = sqrt(-2.0 * log(u1));
    double theta = 2.0 * M_PI * u2;
    double z0 = R * cos(theta);

    // Scale and shift to match desired mean and stddev
    z0 = z0 * stddev + mean;

    return z0;
}