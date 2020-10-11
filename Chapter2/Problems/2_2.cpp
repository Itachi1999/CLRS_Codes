#include<iostream>
#include<cstdlib>
#include<ctime>
#include<chrono>

void swap(int &a, int &b)
{
    int temp = 0;
    temp = a;
    a = b;
    b = temp;
}

void bubbleSortNaive(int *A, int n)
{
    for(int i = 0; i < n - 1; i++)
    {
        for(int j = n - 1; j >= i + 1; j--)
        {
            if(A[j] < A[j - 1])
            {
                swap(A[j], A[j - 1]);
            }
        }
    }
    return;
}

void bubbleSortUpdate(int *A, int n)
{
    bool flag = false;
    for(int i = 0; i < n - 1; i++)
    {   
        flag = false;
        for(int j = n - 1; j >= i + 1; j--)
        {
            if(A[j] < A[j - 1])
            {
                swap(A[j], A[j - 1]);
                flag = true;
            }
        }

        if(!flag)
            return;
    }
    return;
}

int main()
{
    srand(std::time(nullptr));
    int n = 0, x = 0, count = 1;
    
    n = 1;

    while(count < 7){
        int A[100007] = {0}, B[100007] = {0};
        std::cout << "The Value of n: " << n << std::endl;

        //std::cout << "The Array of cofficients: ";
        for(int i = 0; i < n; i++)
        {
            A[i] = rand() % 10 + 1; 
            B[i] = rand() % (i + 1) + 1; //The probability of sorted array is more
            //std::cout << A[i] << " ";
        }


        auto start = std::chrono::high_resolution_clock::now();
        bubbleSortNaive(A, n);
        auto end = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
        std::cout << "The bubbleSortNaive works in time: " << duration.count() << std::endl;

    
        start = std::chrono::high_resolution_clock::now();
        bubbleSortUpdate(B, n);
        end = std::chrono::high_resolution_clock::now();
        duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
        std::cout << "The bubbleSortUpdate works in time: " << duration.count() << std::endl;

        n *= 10;
        count++;
    }
    
    return 0;
}

// int main()
// {
//     int A[5] = {0, -32, 26, -46, 1};
//     int B[5] = {0, -32, 26, -46, 1};

//     bubbleSortNaive(A, 5);
//     bubbleSortUpdate(B, 5);

//     for(int i = 0; i < 5; i++)
//     {
//         std::cout << A[i] << " " << B[i] << " ";
//     }

//     return 0;
// }