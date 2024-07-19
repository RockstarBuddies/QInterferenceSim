#include <stdio.h>
#include <stdlib.h>
#include <math.h>


#define PI 3.141592653589793


double calculateIntensity(double wavelength, double slitDistance, double screenDistance, double x) {
    double k = (2 * PI) / wavelength;
    double d = slitDistance; 
    double z = screenDistance; 
    double pathDifference = (d * x) / z;
    double phaseDifference = k * pathDifference;
    double intensity = pow(cos(phaseDifference / 2), 2);
    return intensity;
}

int main() {
    double wavelength, slitDistance, screenDistance, x;

    // User inputs
    printf("Enter the wavelength (in meters): ");
    scanf("%lf", &wavelength);

    printf("Enter the slit distance (in meters): ");
    scanf("%lf", &slitDistance);

    printf("Enter the screen distance (in meters): ");
    scanf("%lf", &screenDistance);

    
    printf("\nPosition on Screen (m)\tIntensity\n");
    printf("----------------------\t---------\n");

    
    for (x = -0.01; x <= 0.01; x += 0.0001) {
        double intensity = calculateIntensity(wavelength, slitDistance, screenDistance, x);
        printf("%-22.4e\t%-10.4e\n", x, intensity);
    }

    return 0;
}
