class vnsort
{
    private:
        void swap(int&, int&);
    public:
        vnsort();
        void shellsort(int array[], int n);
        void heapify(int array[], int N, int i);
        void heapsort(int array[], int N);
        int partition(int array[], int left, int right);
        void quicksort(int arra[], int left, int right);
        ~vnsort();
        
};