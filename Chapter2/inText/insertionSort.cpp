#include<iostream>
#include<vector>

void insertionSort(std::vector<int> &vec, int len)
{
    for (size_t i = 1; i < len; i++)
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

int main()
{
    int temp = 0;
    std::vector<int> vec;
    std::cout << "The list of length 5 which to be sorted: ";

    for (size_t i = 0; i < 5; i++)
    {
        std::cin >> temp;
        vec.push_back(temp);
    }
    
    insertionSort(vec, 5);
    std::cout << "The sorted list is: ";
    for(int i: vec)
        std::cout << i << " ";
    return 0;
}