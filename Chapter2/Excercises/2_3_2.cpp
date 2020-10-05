//taking n = 5 but you can take any value you want
#include<iostream>

void merge(int *A, int low, int high, int mid)
{
    int B[5] = {0};
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
    
    for (size_t p = low; p <= high; p++)
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

int main()
{
    int A[5] = {0};

    std::cout << "The array which to be started: ";
    for(int i = 0; i < 5; i++)
    {
        std::cin >> A[i];
    }   
    mergeSort(A, 0, 4);

    std::cout << "The array which is sorted: ";
    for(int i = 0; i < 5; i++)
    {
        std::cout << A[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}