//Selection Sort where n = 5
#include<iostream>

void swap(int *a, int *b)
{
    int temp = 0;

    temp = *a;
    *a = *b;
    *b = temp;
}

void selectionSort(int *A, int n)
{
    int minPos = 0;

    for(int i = 0; i < n - 1; i++)
    {
        minPos = i;
        for(int j = i + 1; j < n; j++)
        {
            if(A[j] < A[minPos])
                minPos = j;
        }

        swap(&A[i], &A[minPos]);
    }
}

int main()
{
    int A[5] = {0};

    std::cout << "The array which need to be sorted: ";
    for(int i = 0; i < 5; i++)
    {
        std::cin >> A[i];
    }

    selectionSort(A, 5);

    std::cout << "The sorted array:";
    for(int i = 0; i < 5; i++)
    {
        std::cout << A[i] << " ";
    }

    return 0;
}