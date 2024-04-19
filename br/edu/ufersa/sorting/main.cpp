#include <iostream>
#include <chrono>
#include <random>
#include <fstream>
#include "vnsort.h"

const int SIZE_C0 = 100;
const int SIZE_C1 = 500;
const int SIZE_C2 = 1000;


//const int ARRAYSIZE = 100;

// void generateRandom(int[], const int);
void generateArray(char*, int size);
void showArray(const int[], const int);

int main(int argc, char const *argv[])
{
    vnsort vn;
    std::cout << "Hi there!" << std::endl;
    
    /*

    // Shellsort
    
    std::cout << "Array before shellsort: " << std::endl;    
    showArray(array, ARRAYSIZE);

    vn.shellsort(array, ARRAYSIZE);

    std::cout << "Array after shellsort: " << std::endl;    
    showArray(array, ARRAYSIZE);
    


    // Heapsort
    /*
    std::cout << "Array before heapsort: " << std::endl;
    showArray(array, ARRAYSIZE);

    vn.heapsort(array, ARRAYSIZE);

    std::cout << "Array after heapsort: " << std::endl;
    showArray(array, ARRAYSIZE);
    */


    // Quicksort
    /*
    std::cout << "Array before heapsort: " << std::endl;
    showArray(array, ARRAYSIZE);

    vn.quicksort(array, 0, ARRAYSIZE - 1);

    std::cout << "Array after heapsort: " << std::endl;
    showArray(array, ARRAYSIZE);
    delete [] array;
    */

    char conjunto0[] = "Conjunto0.dat";
    char conjunto1[] = "Conjunto1.dat";
    char conjunto2[] = "Conjunto2.dat";

    std::ifstream fin;

    std::cout << "\Abrindo primeiro conjunto\n" << std::endl;

    fin.open(conjunto0, std::ios_base::in | std::ios_base::binary);

    int* vet = new int[SIZE_C0];

    fin.read((char*)vet, sizeof(int) * SIZE_C0);
    fin.close();



    delete[] vet;


    std::cout << "\Abrindo segundo conjunto\n" << std::endl;

    fin.open(conjunto1, std::ios_base::in | std::ios_base::binary);

    vet = new int[SIZE_C1];

    fin.read((char*)vet, sizeof(int) * SIZE_C1);
    fin.close();

    delete[] vet;


    std::cout << "\Abrindo terceiro conjunto\n" << std::endl;

    fin.open(conjunto2, std::ios_base::in | std::ios_base::binary);

    vet = new int[SIZE_C2];

    fin.read((char*)vet, sizeof(int) * SIZE_C2);
    fin.close();

    delete[] vet;

    
    return 0;
}


void generateArray(char* file_name, int size)
{
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<int> dist(0, size * 10);

    int* vet = new int[size];

    for (int i = 0; i < size; i++)
    {
        vet[i] = dist(mt);
    }

    std::ofstream fout;
    fout.open(file_name, std::ios_base::out | std::ios_base::binary);

    fout.write((char*)vet, sizeof(int) * size);
    fout.close();

    delete[] vet;
}

void showArray(const int array[], const int size)
{
    for (int i = 0; i < size; i++)
    {
        if (i != 0 && i % 10 == 0)
        {
            std::cout << std::endl;
        }
        std::cout << array[i] << "\t";       
    }
    std::cout << "\n";
}