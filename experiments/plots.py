import matplotlib.pyplot as plt
import numpy as np

n = np.array([10, 100,1000, 10000, 100000, 1000000, 10000000])

""" Plantilla
heapsort = np.array([])
quicksort = np.array([])
sortSTL = np.array([])
quicksortrandom = np.array([])
mergeinsertionsort = np.array([])
mergesort = np.array([])
insertionsort = np.array([])
"""

""" Datos aleatorios
heapsort = np.array([0.00035916, 0.00705996, 0.0830545, 0.757148, 10.3555, 120.858, 1951.9])
quicksort = np.array([ 0.00046356, 0.00578308, 0.0373907, 0.475485, 6.03127, 69.7039, 823.563])
sortSTL = np.array([0.00020951, 0.00424605, 0.0329327, 0.445826, 5.93856, 63.6368, 749.892])
quicksortrandom = np.array([0.0048336, 0.0438708,0.340901, 3.65016, 46.016, 382.32, 4022.01])
mergeinsertionsort = np.array([0.00022564, 0.00218892, 0.0350597, 0.531634, 8.5358, 78.3377, 989.233])
mergesort = np.array([0.00066872, 0.000401196, 0.0695842, 0.857686, 15.3243, 114.355, 1350.55])
insertionsort = np.array([0.00016384, 0.000108353, 0.0783128, 7.04195, 763.41, 76341, 7634100])
"""



plt.figure(figsize=(8,6))
plt.loglog(n, heapsort, marker='o', linestyle='-', color='blue', label='Heapsort')
plt.loglog(n, quicksort, marker='s', linestyle='--', color='red', label='Quicksort')
plt.loglog(n, sortSTL, marker='D', linestyle='-.', color='green', label='STL Sort (Introsort)')
plt.loglog(n, quicksortrandom, marker='^', linestyle=':', color='purple', label='Quicksort Random Pivot')
plt.loglog(n, mergeinsertionsort, marker='v', linestyle='-', color='orange', label='Merge + Insertion Sort')
plt.loglog(n, mergesort, marker='*', linestyle='--', color='cyan', label='Mergesort')
plt.loglog(n, insertionsort, marker='x', linestyle='-', color='black', label='Insertion Sort')


plt.xlabel("Tamaño del arreglo (n)")
plt.ylabel("Tiempo promedio (ms)")
plt.title("Comparación de arreglos aleatorios")
plt.legend()
plt.grid(True, which="both", ls="--")

#plt.show()
plt.savefig('graficos/sorting_comparison.png', dpi=300, bbox_inches='tight')
