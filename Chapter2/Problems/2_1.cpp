#include<iostream>
#include<cstdlib>
#include<chrono>
#include<ctime>

void insertionSort(int *vec, int len)
{
    for (int i = 1; i < len; i++)
    {
        int j = i - 1, key = vec[i];

        while (j >= 0 && vec[j] > key)
        {
            vec[j + 1] = vec[j];
            j--;
        }
        
        vec[j + 1] = key;
    }
}

void merge(int *A, int low, int high, int mid)
{
    int B[100007] = {0};
    int i = low, j = mid + 1, k = low;

    while (i <= mid && j <= high)
    {
        if (A[i] <= A[j])
        {
            B[k] = A[i];
            i++;
        }
        else
        {
            B[k] = A[j];
            j++;
        }
        k++;
    }
    
    if (i > mid)
    {
        for(int p = j; p <= high; p++)
        {
            B[k] = A[p];
            k++;
        }
    }
    
    else
    {
        for(int p = i; p <= mid; p++)
        {
            B[k] = A[p];
            k++;
        }
    }
    
    for (int p = low; p <= high; p++)
    {
        A[p] = B[p];
    }
    
}

void mergeSort(int *A, int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;
        mergeSort(A, low, mid);
        mergeSort(A, mid + 1, high);
        merge(A, low, high, mid);
    }
    return;
}

void mergeInsertionSort(int *A, int low, int high)
{
    if ((high - low + 1) <= 8196)
    {
        insertionSort(A, (high - low + 1));
    }
    else
    {
        int mid = low + (high - low) / 2;
        mergeSort(A, low, mid);
        mergeSort(A, mid + 1, high);
        merge(A, low, high, mid);
    }
    return;
}

int main()
{
    srand(std::time(nullptr));
    int n = 0, count = 1;
    
    n = 1;

    while(count < 18){
        int A[100007] = {0}, B[100007] = {0}, C[100007] = {0};
        std::cout << "The Value of n: " << n << std::endl;

        //std::cout << "The Array of cofficients: ";
        for(int i = 0; i < n; i++)
        {
            A[i] = rand() % 10 + 1; 
            B[i] = rand() % 10 + 1;
            C[i] = rand() % 10 + 1; 
            //std::cout << A[i] << " ";
        }


        auto start = std::chrono::high_resolution_clock::now();
        insertionSort(A, n);
        auto end = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
        std::cout << "The insertionSort works in time: " << duration.count() << std::endl;

    
        start = std::chrono::high_resolution_clock::now();
        mergeSort(B, 0, n - 1);
        end = std::chrono::high_resolution_clock::now();
        duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
        std::cout << "The mergeSort works in time: " << duration.count() << std::endl;

        start = std::chrono::high_resolution_clock::now();
        mergeInsertionSort(C, 0, n - 1);
        end = std::chrono::high_resolution_clock::now();
        duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
        std::cout << "The mergeInsertionSort works in time: " << duration.count() << std::endl << std::endl;

        n *= 2;
        count++;
    }
    
    return 0;
}

// For testing the algorithm
// int main()
// {
//     int A[5] = {0, -32, 26, -46, 1};
//     int B[5] = {0, -32, 26, -46, 1};
//     int C[5] = {0, -32, 26, -46, 1};

//     insertionSort(A, 5);
//     mergeSort(B, 0, 4);
//     mergeInsertionSort(C, 0, 4);

//     for(int i = 0; i < 5; i++)
//     {
//         std::cout << A[i] << " " << B[i] << " " << C[i] << " ";
//     }

//     return 0;
// }