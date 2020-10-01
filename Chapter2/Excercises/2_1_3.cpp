//Linear Search for elements n = 5
#include<iostream>

int linearSearch(int *A, int n, int key)
{
    int index = -1, i = 0;

    while (A[i] != key && i < n)
    {
        i++;
        index = i;
    }
    index = (i < n) ? i : -1;
    return index;
}

int main()
{
    int A[5] = {0}, key = 0, found = 0, index = 0;

    std::cout << "The Array for which we have to search: ";
    for (size_t i = 0; i < 5; i++)
    {
        std::cin >> A[i];
    }
    std::cout << "The key which is to find: ";
    std::cin >> key;

    found = ((index = linearSearch(A, 5, key)) >= 0) ? 1 : 0;
    
    found? std::cout << "Found at " << index : std::cout << "Not Found";

    return 0;
}