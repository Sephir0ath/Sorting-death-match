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
heapsort = np.array([0.00042603, 0.00616826, 0.0616511, 0.735662, 9.26665, 119.646, 1939.05])
quicksort = np.array([0.00019239, 0.00271011, 0.0366828, 0.488155, 5.93696, 70.0742, 815.858])
sortSTL = np.array([0.00014943, 0.00270442, 0.0331546, 0.421855, 5.28987, 62.5495, 727.147])
quicksortrandom = np.array([0.00298035, 0.0399941, 0.398902, 3.66027, 37.727, 390.481, 3936.6])
mergeinsertionsort = np.array([0.0001419, 0.00224196, 0.0351345, 0.512291, 6.5969, 80.0306, 932.247])
mergesort = np.array([0.00022357, 0.00306839, 0.0444755, 0.574855, 7.34587, 88.6231, 989.348])
insertionsort = np.array([0.00014429, 0.00193759, 0.082863, 6.93874, 659.491, 65949, 6594910])
"""
""" Arreglos ordenados en orden ascendente
heapsort = np.array([9.16e-05, 0.00092445, 0.0245757, 0.440529, 4.82991, 52.7296, 586.573])
quicksort = np.array([8.537e-05, 0.00305874, 0.247773, 23.8087, 2481.59, 248100, 24810000]) 
sortSTL = np.array([4.832e-05, 0.00031174, 0.00422537, 0.0537534, 0.597158, 6.98417, 86.7627])
quicksortrandom = np.array([0.00349121, 0.0358748, 0.339942, 4.73374, 61.3074, 1827.1, 23648.645])
mergeinsertionsort = np.array([4.836e-05, 0.00030206, 0.00425567, 0.0553565, 0.689751, 9.23823, 126.685])
mergesort = np.array([8.213e-05, 0.00026066, 0.00183742, 0.0202312, 0.220803, 2.49907, 27.0341])
insertionsort = np.array([4.85e-05, 0.00011384, 0.00076772, 0.00697973, 0.0697288, 0.960569, 9.95646])
"""

#Arreglos ordenados en orden descendente
heapsort = np.array([8.455e-05, 0.00081758, 0.0200874, 0.488517, 5.401, 62.1919, 974.489])
quicksort = np.array([8.565e-05, 0.00311789, 0.214689, 19.9931, 2767.91, 276700.0, 27670000.0]) 
sortSTL = np.array([9.188e-05, 0.00045233, 0.00296143, 0.0384211, 0.447895, 7.08807, 96.1349])
quicksortrandom = np.array([0.00584584, 0.0587516, 0.414323, 4.39686, 42.8719, 545.552, 4893.43])
mergeinsertionsort = np.array([0.00015089, 0.00179551, 0.0238554, 0.152024, 2.21928, 28.651, 284.208])
mergesort = np.array([0.00016449, 0.00195614, 0.012023, 0.234106, 2.27419, 22.6458, 294.936])
insertionsort = np.array([7.905e-05, 0.00469863, 0.295544, 25.3377, 1854.51, 185400.0, 18540000.0]) 



"""# Arreglos con todos los elementos iguales
heapsort = np.array([6.931e-05, 0.00033203, 0.003778, 0.0295245, 0.294784, 3.14765, 37.4403])
quicksort = np.array([0.00022936, 0.00314972, 0.26722, 24.7819, 3259.38, 325900.0, 32590000.0]) 
sortSTL = np.array([5.658e-05, 0.00046249, 0.00381944, 0.0515763, 0.62765, 8.42094, 122.959])
quicksortrandom = np.array([0.00482982, 0.0595563, 0.899436, 40.0374, 3159.71, 315900.0, 31590000.0]) 
mergeinsertionsort = np.array([6.996e-05, 0.00035486, 0.00455966, 0.0713852, 1.34818, 15.5091, 212.777])
mergesort = np.array([0.00013805, 0.00058914, 0.00429605, 0.0422489, 0.3824, 3.65084, 44.1407])
insertionsort = np.array([6.591e-05, 0.00015959, 0.00097256, 0.019148, 0.121656, 1.82988, 15.3272])
"""

"""# Arreglos con la primera mitad de los elementos ordenados
heapsort = np.array([0.00019135, 0.00406105, 0.0610745, 0.871837, 11.7956, 248.185, 1570.54])
quicksort = np.array([0.00020785, 0.00393309, 0.0845196, 5.64559, 162.874, 269.096, 1320.83]) 
sortSTL = np.array([7.467e-05, 0.00129701, 0.0172712, 0.212732, 2.74087, 39.4308, 492.796])
quicksortrandom = np.array([0.00039391, 0.00548386, 0.0444117, 0.530821, 8.71809, 148.877, 1097.73]) 
mergeinsertionsort = np.array([0.0001409, 0.00169093, 0.0223555, 0.238035, 3.13928, 38.7172, 475.429])
mergesort = np.array([0.00024287, 0.0017062, 0.020546, 0.259627, 3.30348, 40.1424, 482.126])
insertionsort = np.array([0.0001047, 0.00075905, 0.0203077, 1.61047, 155.946, 15808.2, 1550000]) 
"""

#Arreglos con la segunda mitad de los elementos ordenados
"""heapsort = np.array([0.00011993, 0.00290443, 0.0438809, 0.528532, 6.1036, 78.8204, 1649.92])
quicksort = np.array([0.00036927, 0.00367274, 0.195314, 16.8054, 1775.11, 177500, 17750000]) # 2
sortSTL = np.array([0.0001438, 0.00188333, 0.0225369, 0.319333, 4.38304, 55.3902, 749.643])
quicksortrandom = np.array([0.00040042, 0.00454561, 0.0739847, 1.64332, 42.0358, 1394.1, 139400]) # 1 
mergeinsertionsort = np.array([0.00013239, 0.00227596, 0.0247322, 0.447353, 6.19536, 80.7185, 1023.26])
mergesort = np.array([0.00014789, 0.00158937, 0.0223016, 0.301483, 4.20761, 57.7972, 608.522])
insertionsort = np.array([7.922e-05, 0.00079139, 0.0201653, 1.62514, 180.333, 18000, 1800000])  # 2
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
plt.title("Comparación de arreglos con la segunda mitad ordenada")
plt.legend()
plt.grid(True, which="both", ls="--")

#plt.show()
plt.savefig('graficos/arreglos2.png', dpi=300, bbox_inches='tight')
