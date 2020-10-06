//For my convenience, I'm taking n = 5
//Also, taking the x variable and S as user input array
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

bool solution(int *A, int n, int x)
{
    int i = 0, j = n - 1;
    bool ans;
    mergeSort(A, 0, n - 1);

    // for(int i = 0; i < n; i++)
    // {
    //     std::cout << A[i] << " ";
    // }
    while(i < j)
    {
        if (A[i] + A[j] == x)
        {
            return true;
        }
        else if(A[i] + A[j] < x)
        {
            i += 1;
        }
        else
        {
            j -= 1;
        }
    }
    return false;
}

int main()
{
    int A[5] = {0}, x = 0;

    std::cout << "The array you want to search for: ";
    for(int i = 0; i < 5; i++)
    {
        std::cin >> A[i];
    }

    std::cout << "The search key(x): ";
    std::cin >> x;

    (solution(A, 5, x)) ? std::cout << "Found" : std::cout << "Not Found";
    std::cout << std::endl;
}

