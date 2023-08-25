import numpy as np
import matplotlib.pyplot as plt

# Datos proporcionados
N = np.array([100, 1000, 10000, 100000])
T = np.array([0.000117, 0.005721, 0.531206, 60.181500])

# Aplicar logaritmo a los datos
log_N = np.log(N)
log_T = np.log(T)

# Ajustar una línea recta a los datos transformados
coefficients = np.polyfit(log_N, log_T, 1)
a_fit = np.exp(coefficients[1])
b_fit = coefficients[0]

print("Parámetros ajustados:")
print("a =", a_fit)
print("b =", b_fit)

# Estimación de tiempo para 1,000,000 de elementos
num_elementos = 1000000
tiempo_estimado = a_fit * num_elementos ** b_fit

print("Tiempo estimado para", num_elementos, "elementos:", tiempo_estimado, "segundos")