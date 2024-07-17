import numpy as np
import matplotlib.pyplot as plt

# Constants and parameters
PI = np.pi
WAVELENGTH = 0.5
SLIT_DISTANCE = 1.0
SCREEN_DISTANCE = 10.0
NUM_POINTS = 1000
INTENSITY_SCALE = 1000.0

def calculate_intensity(x):
    path_diff1 = np.sqrt((x - SLIT_DISTANCE / 2) ** 2 + SCREEN_DISTANCE ** 2)
    path_diff2 = np.sqrt((x + SLIT_DISTANCE / 2) ** 2 + SCREEN_DISTANCE ** 2)

    phase_diff = 2 * PI * (path_diff1 - path_diff2) / WAVELENGTH

    amplitude = 2.0 * np.cos(phase_diff / 2.0)
    intensity = amplitude ** 2

    return intensity

def simulate_experiment():
    screen_range = 20.0
    step_size = screen_range / NUM_POINTS
    x_values = np.linspace(-screen_range / 2, screen_range / 2, NUM_POINTS)
    intensities = np.array([calculate_intensity(x) * INTENSITY_SCALE for x in x_values])

    # Save the data to a file
    with open("double_slit_simulation.txt", "w") as file:
        for x, intensity in zip(x_values, intensities):
            file.write(f"{x} {intensity}\n")

    # Plot the results
    plt.plot(x_values, intensities)
    plt.xlabel("Position on Screen")
    plt.ylabel("Intensity")
    plt.title("Double-Slit Experiment Simulation")
    plt.show()

if __name__ == "__main__":
    simulate_experiment()
