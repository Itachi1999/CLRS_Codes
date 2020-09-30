//Taking n = 5 to save time, you can take any number
#include<iostream>

void add(int *A, int *B, int *C, int n)
{
    int temp = 0, carry = 0;

    for (int i = n - 1; i >= 0; i--)
    {
        temp = A[i] + B[i] + carry;
        if(temp < 2)
        {
            C[i + 1] = temp;
            carry = 0;
        }
        else
        {
            C[i + 1] = temp - 2;
            carry = 1;
        }
        
        C[0] = carry;
    }
    
}

int main()
{
    int temp = 0, carry = 0, n = 0;
    int A[5] = {0}, B[5] = {0}, C[6] = {0};
    std::cout << "The First Binary Number: ";
    for (size_t i = 0; i < 5; i++)
        std::cin >> A[i];
    
    //std::cout << "no problem here";
    std::cout << "The Second Binary Number: ";
    for (size_t i = 0; i < 5; i++)
        std::cin >> B[i];
    //std::cout << "no problem here";
    
    add(A, B, C, 5);
    
    std::cout << "The Added Binary Number: ";
    for (size_t i = 0; i < 6; i++)
        std::cout << C[i] << " ";

    return 0;
}