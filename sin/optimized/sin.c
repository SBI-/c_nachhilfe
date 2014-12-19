#include <errno.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

// Either comment this in or compile with the -std=gnu11 flag.
// This is necessary because later POSIX specifications have removed PI from the standard library.
// In case your math.h doesn't contain M_PI, or you can't get your compiler to comply, use this.
// # define M_PI       3.14159265358979323846  /* pi */

const double FACTOR = M_PI / 180;
const int START = 1;
const int LIMIT = 6;

double deg_to_rad(double deg);
double approx_sin(double rad);

int main(int argc, char* argv[])
{
    if (argc != 2) {
        fprintf(stderr, "Invalid argument count\n");
        exit(EIO);
    }

    double angle = deg_to_rad(atof(argv[1]));
    printf("%lf\n", approx_sin(angle));

    return EXIT_SUCCESS;
}

double approx_sin(double rad)
{
    double result = 0, nfac = 1, power = rad;
    int sign = 1;

    for (int n = START; n <= LIMIT * 2; n += 2) {
        result += power / nfac * sign;
        power *= rad * rad;
        nfac *= (n + 1) * (n + 2);
        sign = -sign;
    }

    return result;
}

double deg_to_rad(double deg)
{
    return deg * FACTOR;
}
