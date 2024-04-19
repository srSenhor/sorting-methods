#include <benchmark/benchmark.h>
#include <fstream>
#include "vnsort.h"

const int SIZE_C0 = 100;
const int SIZE_C1 = 500;
const int SIZE_C2 = 1000;

const char conjunto[] = "../test/Conjunto2.dat";

const int SIZE = SIZE_C2;

static void shellsortTest(benchmark::State &s)
{
    vnsort vn;
    
    std::ifstream fin;

    fin.open(conjunto, std::ios_base::in | std::ios_base::binary);

    int* vet = new int[SIZE];

    fin.read((char*)vet, sizeof(int) * SIZE);
    fin.close();

    for (auto _ : s) 
    {
        vn.shellsort(vet, SIZE);
    }
    
    delete[] vet;
}
static void heapsortTest(benchmark::State &s)
{
    vnsort vn;
    
    std::ifstream fin;

    fin.open(conjunto, std::ios_base::in | std::ios_base::binary);

    int* vet = new int[SIZE];

    fin.read((char*)vet, sizeof(int) * SIZE);
    fin.close();

    for (auto _ : s) 
    {
        vn.heapsort(vet, SIZE);
    }

    delete[] vet;
}

static void quicksortTest(benchmark::State &s)
{
    vnsort vn;
    
    std::ifstream fin;

    fin.open(conjunto, std::ios_base::in | std::ios_base::binary);

    int* vet = new int[SIZE];

    fin.read((char*)vet, sizeof(int) * SIZE);
    fin.close();

    for (auto _ : s) 
    {
        vn.quicksort(vet, 0, SIZE - 1);
    }

    delete[] vet;
}

BENCHMARK(shellsortTest);
BENCHMARK(heapsortTest);
BENCHMARK(quicksortTest);
BENCHMARK_MAIN();