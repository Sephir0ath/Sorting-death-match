#include <stdlib.h>
#include <iostream>

void randomNumbers(int quantity, int size, int range){
	for (int i = 0; i < quantity; i++){ // Cuantos arreglos distintos 
		for (int j = 0; j < size; j++){ // Tamaño de cada arreglo
			std::cout << rand() % range << " "; // Rango de números aleatorios de cada arreglo
		}
		std::cout << std::endl;
	}
}

void ascendant(int quantity, int size) {
    int total = quantity * size;
    for (int i = 0; i < total; i++) {
        std::cout << i << " ";
        if ((i + 1) % size == 0) std::cout << std::endl;
    }
}

void descendant(int quantity, int size) {
    int total = quantity * size;
    for (int i = total - 1; i >= 0; i--) {
        std::cout << i << " ";
        if (i % size == 0) std::cout << std::endl;
    }
}

void allSame(int quantity, int size){
	for (int i = 0; i < quantity; i++){
		for (int j = 0; j < size; j++){
			std::cout << i << " ";
		}
		std::cout << std::endl;
	}
	
}


int main(int argc, char* argv[]){
	srand(time(0));
	int quantity = atoi(argv[2]), size = atoi(argv[3]), range = atoi(argv[4]); 
	
	if (argc < 2){
		exit(0);
	}

	

	switch(atoi(argv[1])){
		case 0:
			randomNumbers(quantity, size, range);
			break;
		case 1:
			ascendant(quantity, size);
			break;
		case 2:
			descendant(quantity, size);
		
		case 3:
			allSame(quantity, size);				
	}
	
	
}
