#include<iostream>
#include<cstdlib>
#include<chrono>
#include<ctime>

unsigned long findInversionsNaive(int *A, int n)
{
    unsigned long inv = 0;

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j <= n - 1; j++)
        {
            if(A[i] > A[j])
            {
                inv += 1;
            }
        }
    }
    
    return inv;
}

unsigned long merge(int *A, int low, int mid, int high)
{
    int B[100007] = {0}, i = low, j = mid + 1, k = low;
    unsigned long inv = 0;

    while (i <= mid && j <= high)
    {
        if(A[i] <= A[j])
        {
            B[k] = A[i];
            i = i + 1;
        }

        else
        {
            B[k] = A[j];
            inv += (mid - i + 1);
            j = j + 1;
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

    //copy 
    for (int p = low; p <= high; p++)
    {
        A[p] = B[p];
    }
    return inv;
}

unsigned long findInversions(int *A, int low, int high)
{
    unsigned long left = 0, right = 0, middle = 0;
    int mid = 0;
    if(low < high)
    {
        mid = low + (high - low) / 2;
        left = findInversions(A, low, mid);
        right = findInversions(A, mid + 1, high);
        middle = merge(A, low, mid, high);
    }

    return (left + middle + right);
}

int main()
{
    srand(std::time(nullptr));
    int n = 0, x = 0, count = 1;
    unsigned long inv = 0, inv1 = 0;
    
    n = 1;

    while(count < 7){
        int A[100007] = {0};
        std::cout << "The Value of n: " << n << std::endl;

        //std::cout << "The Array of cofficients: ";
        for(int i = 0; i < n; i++)
        {
            A[i] = rand() % 10 + 1; 
            //std::cout << A[i] << " ";
        }


        auto start = std::chrono::high_resolution_clock::now();
        inv = findInversionsNaive(A, n);
        auto end = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
        std::cout << "The findInversionsNaive have " << inv << " inversions and works in time: " 
            << duration.count() << std::endl;

    
        start = std::chrono::high_resolution_clock::now();
        inv1 = findInversions(A, 0, n - 1);
        end = std::chrono::high_resolution_clock::now();
        duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
        std::cout << "The findInversionsUpdate have " << inv1 << " inversions and works in time: " 
            << duration.count() << std::endl;

        n *= 10;
        count++;
    }
    
    return 0;
}

// For testing the algorithm
// int main()
// {
//     int A[5] = {0, -32, 26, -46, 1};
// //    int B[5] = {0, -32, 26, -46, 1};
//     unsigned long inv = 0, inv1 = 0;
//     inv = findInversionsNaive(A, 5);
//     inv1 = findInversions(A, 0, 4);

//     std::cout << inv << " " << inv1 << " ";
//     for(int i = 0; i < 5; i++)
//     {
//         std::cout << A[i] << " " << " ";
//     }

//     return 0;
// }