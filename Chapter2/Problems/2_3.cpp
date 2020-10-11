#include<iostream>
#include<cstdlib>
#include<chrono>
#include<ctime>

int naivePolynomial(int *A, int n, int x)
{
    int sum = 0, y = 0;

    for(int i = 0; i <= n; i++)
    {
        y = A[i];
        for(int j = 1; j <= i; j++)
        {
            y = y * x;
        }
        sum = sum + y;
    }

    return sum;
}

int hornersRule(int *A, int n, int x)
{
    int y = 0;
    for(int i = n; i >= 0; i--)
    {
        y = A[i] + x * y;
    }

    return y;
}

int main()
{
    srand(std::time(nullptr));
    int n = 0, x = 0, count = 1, sum = 0;
    long long unsigned y = 0;
    n = 1;

    while(count < 6){
        int A[100000] = {0};
        std::cout << "The Value of n: " << n << std::endl;

        //std::cout << "The Array of cofficients: ";
        for(int i = 0; i <= n; i++)
        {
            A[i] = rand() % 10 + 1; 
            //std::cout << A[i] << " ";
        }

        x = rand() % 10 + 1;
        std::cout << "The Value of x: " << x << std::endl;

        auto start = std::chrono::high_resolution_clock::now();
        y = hornersRule(A, n, x);
        auto end = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
        std::cout << "The solution to the polynomial(horner) is " << y << " in time: " << duration.count() << std::endl;

    
        start = std::chrono::high_resolution_clock::now();
        y = naivePolynomial(A, n, x);
        end = std::chrono::high_resolution_clock::now();
        duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
        std::cout << "The solution to the polynomial(naive) is " << y << " in time: " << duration.count() << std::endl;

        n *= 10;
        count++;
    }
    
    return 0;
}