#include <iostream>
#include <cstdlib>
#include <omp.h>

void Trap(double a, double b, int n, double* global_result_p);

int main(int argc, char* argv[]) {
    if (argc != 4) {
        std::cerr << "Usage: " << argv[0] << " a b n\n";
        return 1;
    }

    double a = std::stod(argv[1]);
    double b = std::stod(argv[2]);
    int n = std::stoi(argv[3]);
    // int thread_count = std::stoi(argv[4]);

    double global_result = 0.0;

    #pragma omp parallel
    Trap(a, b, n, &global_result);

    std::cout << "With n = " << n << " trapezoids, our estimate = ";
    std::cout << global_result << std::endl;

    return 0;
}

/* Function to be integrated */
double f(double x) {
    // Define your function here
    return x; // Example function (identity function)
}

void Trap(double a, double b, int n, double* global_result_p) {
    double h, local_a, local_b;
    double my_result = 0.0;
    int i;
    int my_rank = omp_get_thread_num();
    int thread_count = omp_get_num_threads();

    h = (b - a) / n;
    int local_n = n / thread_count;
    local_a = a + my_rank * local_n * h;
    local_b = local_a + local_n * h;
    my_result = (f(local_a) + f(local_b)) / 2.0;
    for (i = 1; i <= local_n - 1; i++) {
        double x = local_a + i * h;
        my_result += f(x);
    }
    my_result *= h;

    #pragma omp critical
    *global_result_p += my_result;
}
