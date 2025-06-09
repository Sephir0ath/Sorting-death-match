#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <cstdint> // Para int32_t
#include <vector>


// NOTA: SE PUEDE ASUMIR QUE CADA ELEMENTO DE CADA ARRAY ES POSITIVO?


void randomNumbers(int quantity, int size, int range, std::ofstream& outputFile){
    for (int i = 0; i < quantity; i++) { // Cuantos arreglos distintos
        for (int j = 0; j < size; j++) { // Tamaño de cada arreglo
            int32_t num = rand() % range; // Genera un número aleatorio
            outputFile.write(reinterpret_cast<const char*>(&num), sizeof(num)); // Escribe el número en el archivo binario
        }
    }
}

void ascendant(int quantity, int size, std::ofstream& outputFile) {
    int total = quantity * size;
    for (int i = 0; i < total; i++) {
        int32_t num = i;
        outputFile.write(reinterpret_cast<const char*>(&num), sizeof(num));
    }
}

void descendant(int quantity, int size, std::ofstream& outputFile) {
    int total = quantity * size;
    for (int i = total - 1; i >= 0; i--) {
        int32_t num = i;
        outputFile.write(reinterpret_cast<const char*>(&num), sizeof(num));
    }
}

void allSame(int quantity, int size, std::ofstream& outputFile) {
    for (int i = 0; i < quantity; i++) {
        for (int j = 0; j < size; j++) {
            int32_t num = i;
            outputFile.write(reinterpret_cast<const char*>(&num), sizeof(num));
        }
    }
}

void halfSortedHalfRandom(int quantity, int size, int range, std::ofstream& outputFile)
{
    int half_size = size / 2;
    for(int i = 0; i < quantity; i++)
    {
        // -> primera mitad ordenada
        for(int j = 0; j < half_size; j++)
        {
            int32_t num = j;
            
            if(num > range)
            {
                num = range;
            }

            outputFile.write(reinterpret_cast<const char*>(&num), sizeof(num));
        }

        // -> segunda mitad aleatoria
        for(int j = half_size; j < size; j++)
        {
            int32_t num = rand() % range; 
            outputFile.write(reinterpret_cast<const char*>(&num), sizeof(num));
        }


    }


}

void halfRandomHalfSorted(int quantity, int size, int range, std::ofstream& outputFile)
{
    // idea es tener el valor maximo de la primera mitad aleatoria, para darle continuidad
    // en la segunda mitad ordenada, a partir de ese valor máximo

    int half_size = size / 2;
    for(int i = 0; i < quantity; i++)
    {
        std::vector<int32_t> first_half;
        int32_t max_value = 0; // -> se asume range > 0


        // -> primera mitad aleatoria
        for(int j = 0; j < half_size; j++)
        {
            int32_t num = rand() % range;
            first_half.push_back(num);
            if(num > max_value)
            {
                max_value = num;
            }
            
        }
    
        // -> escribir a archivo
        for(int32_t num : first_half)
        {
            outputFile.write(reinterpret_cast<const char*>(&num), sizeof(num));
        }

        // -> segunda mitad ordenada a partir del valor maximo de primera mitad 
        for(int j = 0; j < size - half_size; j++)
        {
            int32_t num = max_value + j;
            outputFile.write(reinterpret_cast<const char*>(&num), sizeof(num));
        }

    }
}

int main(int argc, char* argv[]) {
    if (argc < 5) {
        std::cerr << "Faltan argumentos!" << std::endl;
        return 1;
    }

    srand(time(0));
    int quantity = atoi(argv[2]), size = atoi(argv[3]), range = atoi(argv[4]);
    std::string filename = argv[5];  // El nombre del archivo binario de salida
    std::ofstream outputFile(filename, std::ios::binary);

    if (!outputFile.is_open()) {
        std::cerr << "Error al abrir el archivo!" << std::endl;
        return 1;
    }

    switch (atoi(argv[1])) {
        case 0:
            randomNumbers(quantity, size, range, outputFile);
            break;

        case 1:
            ascendant(quantity, size, outputFile);
            break;

        case 2:
            descendant(quantity, size, outputFile);
            break;

        case 3:
            allSame(quantity, size, outputFile);
            break;

        case 4:
            halfSortedHalfRandom(quantity, size, range, outputFile);
            break;

        case 5:
            halfRandomHalfSorted(quantity, size, range, outputFile);
            break;
                    
        default:
            std::cerr << "Opción no válida!" << std::endl;
            return 1;
    }

    outputFile.close();
    return 0;
}
