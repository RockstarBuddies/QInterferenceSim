#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846
#define WAVELENGTH 0.5
#define SLIT_DISTANCE 1.0
#define SCREEN_DISTANCE 10.0
#define NUM_POINTS 1000
#define INTENSITY_SCALE 1000.0

double calculate_intensity(double x);
void simulate_experiment();

int main() {
    simulate_experiment();
    return 0;
}

double calculate_intensity(double x) {
    double path_diff1 = sqrt((x - SLIT_DISTANCE / 2) * (x - SLIT_DISTANCE / 2) + SCREEN_DISTANCE * SCREEN_DISTANCE);
    double path_diff2 = sqrt((x + SLIT_DISTANCE / 2) * (x + SLIT_DISTANCE / 2) + SCREEN_DISTANCE * SCREEN_DISTANCE);

    double phase_diff = 2 * PI * (path_diff1 - path_diff2) / WAVELENGTH;

    double amplitude = 2.0 * cos(phase_diff / 2.0);
    double intensity = amplitude * amplitude;

    return intensity;
}

void simulate_experiment() {
    FILE* file = fopen("double_slit_simulation.txt", "w");
    if (file == NULL) {
        fprintf(stderr, "Error opening file for writing\n");
        exit(1);
    }

    double screen_range = 20.0;
    double step_size = screen_range / NUM_POINTS;

    for (int i = 0; i < NUM_POINTS; i++) {
        double x = -screen_range / 2 + i * step_size;
        double intensity = calculate_intensity(x) * INTENSITY_SCALE;
        fprintf(file, "%lf %lf\n", x, intensity);
    }

    fclose(file);
}
