import numpy as np
import matplotlib.pyplot as plt

# Datos proporcionados
N = np.array([100, 1000, 10000, 100000])
T = np.array([0.000117, 0.005721, 0.531206, 60.181500])

# Ajuste de función cuadrática (polinómica de segundo grado)
coefficients = np.polyfit(N, T, 2)
a_fit = coefficients[0]
b_fit = coefficients[1]
c_fit = coefficients[2]

# Función cuadrática ajustada
def quadratic_func(N, a, b, c):
    return a * N**2 + b * N + c

# Valores para la curva ajustada
N_fit = np.linspace(min(N), max(N), 100)
T_fit = quadratic_func(N_fit, a_fit, b_fit, c_fit)

# Graficar los datos y la curva ajustada
plt.scatter(N, T, label='Datos originales')
plt.plot(N_fit, T_fit, label='Curva ajustada', color='red')
plt.xlabel('Cantidad de elementos (N)')
plt.ylabel('Tiempo de ejecución (T)')
plt.title('Ajuste Cuadrático de Tiempo de Ejecución')
plt.legend()
plt.show()

