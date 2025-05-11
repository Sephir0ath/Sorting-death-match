import matplotlib.pyplot as plt
import numpy as np

n = np.array([10, 100,1000, 10000, 100000, 1000000, 10000000])
heapsort = np.array([0.00090745, 0.0166557, 0.174373, 2.13726, 25.8169, 297.763, 3440.8])
quicksort = np.array([0.00103488, 0.0310146, 2.86428, 283.248, 28356.2, 2760000, 276000000])
sortSTL = np.array([0.00048091, 0.00769649, 0.0613045, 0.739031, 8.12983, 92.717, 1148.14])

plt.figure(figsize=(8,6))
plt.loglog(n, heapsort, marker='o', linestyle='-', color='blue', label='Heapsort')
plt.loglog(n, quicksort, marker='s', linestyle='--', color='red', label='Quicksort')
plt.loglog(n, sortSTL, marker='D', linestyle='-.', color='green', label='STL Sort (Introsort)')
plt.xlabel("Tamaño del arreglo (n)")
plt.ylabel("Tiempo promedio (ms)")
plt.title("Comparación de arreglos ascendentes")
plt.legend()
plt.grid(True, which="both", ls="--")

#plt.show()
plt.savefig('sorting_comparison.png', dpi=300, bbox_inches='tight')
