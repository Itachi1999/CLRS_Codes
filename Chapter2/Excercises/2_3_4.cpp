//Insertion Sort Using Recursion
//Also, n = 5 for my convenience
#include<iostream>

void putItems(int *A, int n, int key)
{
    int j = n - 2;

    while(j >= 0 && A[j] > key)
    {
        A[j + 1] = A[j];
        j--;
    }

    A[j + 1] = key;
}

void insertionSort(int *A, int n)
{
    if(n > 1)
    {
        insertionSort(A, n - 1);
        putItems(A, n, A[n - 1]);
    }
}

int main()
{
    int A[5] = {0};

    std::cout << "The array to sort: ";
    for(int i = 0; i < 5; i++)
    {
        std::cin >> A[i];
    }

    insertionSort(A, 5);
    std::cout << "The sorted array is: ";
    for(int i = 0; i < 5; i++)
    {
        std::cout << A[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}