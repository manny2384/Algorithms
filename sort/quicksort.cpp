#include <bits/stdc++.h>
void quicksort(std::vector<int> &arr, int left, int right);

int main(){

    // a stores contents of array
    std::vector<int> a;
    // size = size of array to sort
    // num_generated = randomly generated number
    int size, num_generated;

    std::cout << " Input size: ";
    std::cin >> size;

    std::cout << "\n\n Your Array Before Sort \n \n";
    srand(time(NULL));

    // randomly generates and stores num_generated to array a
    for(int i=0; i<size; i++){
        num_generated = rand() % size + 1;
        a.push_back(num_generated);
        std::cout << num_generated << " ";
    }
    std::cout << std::endl;

    std::cout << " Your Array After Sort \n";
    // call quicksort 
    quicksort(a, 0, size-1);
    for(auto itr=a.begin(); itr!=a.end(); itr++)
        std::cout << *itr << " ";
    
    std::cout << std::endl;
    return 0;
}

void quicksort(std::vector<int> &arr, int left, int right){
    // base case
    if (left >= right) return;

    // assign random pivot
    srand(time(NULL));
    int pivot_idx = (rand() % (right - left)) + left;
    int pivot = arr.at(pivot_idx);

    // assign lower starting index 
    int lower_idx = left;

    for(int i = left; i < right; i++){
        // if elem at i is less then swap with lower index
        if(arr.at(i) < pivot){
            int temp = arr.at(i);
            arr.at(i) = arr.at(lower_idx);
            arr.at(lower_idx++) = temp;
        }

    }

    // swap pivot into correct position
    int temp = arr.at(lower_idx);
    arr.at(lower_idx) = pivot;
    arr.at(right) = temp;

    // recursive call to left and right sub arrays of pivot 
    quicksort(arr, left, lower_idx-1);
    quicksort(arr, lower_idx+1, right);
}
