#include <math.h>
#include "vnsort.h"

vnsort::vnsort(){}

void vnsort::shellsort(int array[], int n)
{
    for (int h = ceil(n/2); h > 0; h = ceil(h / 2))
    {
        for (int i = h; i < n; i++)
        {
            int temp = array[i];
            int j;

            for (j = i; j >= h && array[j - h] > temp; j -= h)
                array[j] = array[j - h];

            array[j] = temp;
        }
    }
}

void vnsort::swap(int & i, int & j)
{
    int temp = i;
    i = j;
    j = temp;
}

void vnsort::heapify(int array[], int N, int i)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < N && array[l] > array[largest])
        largest = l;
    if (r < N && array[r] > array[largest])
        largest = r;
    if (largest != i) {
        swap(array[i], array[largest]);
        heapify(array, N, largest);
    } 
}

void vnsort::heapsort(int array[], int N)
{
    for (int i = N/2 - 1; i >=  0; i--)
        heapify(array, N, i);

    for (int i = N - 1; i > 0; i--)
    {
        swap(array[0], array[i]);
        heapify(array, i, 0);
    }
    
}

int vnsort::partition(int array[], int low, int high)
{
    int pivot = array[high];
    int i = (low - 1);

    for (int j = low; j <= high; j++)
    {
        if (array[j] < pivot)
        {
            i++;
            swap(array[i], array[j]);
        }
    }

    swap(array[i + 1], array[high]);
    return (i + 1);
}

void vnsort::quicksort(int array[], int low, int high)
{
    if (low < high) 
    {
        int pi = partition(array, low, high);
        quicksort(array, low, pi - 1);
        quicksort(array, pi + 1, high);
    }

}

vnsort::~vnsort() {}
