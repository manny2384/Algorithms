#include <bits/stdc++.h>

void mergesort(std::vector<int> &arr, int, int);
void merge(std::vector<int>&arr, int, int);

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
    
    // call to mergesort
    mergesort(a, 0, a.size()-1);

    // display sorted array
    std::cout << "\n\n Your Array After Sort \n \n";
    for(auto itr = a.begin(); itr!= a.end(); itr++)
        std::cout << *itr << " ";
    

    std::cout << std::endl;
    return 0;

}

/*
    @param arr = reference of original array
    @param left = first index
    @param right = last index
*/
void mergesort(std::vector<int> &arr, int left, int right){
    if(left >= right) return;

    int mid = (left + right) / 2;

    mergesort(arr, left, mid);
    mergesort(arr, mid+1, right);
    
    merge(arr, left, right); 
}

/*
    @param arr = reference of original array
    @param left = first index
    @param right = last index
    function merges from left to middle and middle+1 to right
*/
void merge(std::vector<int> &arr, int left, int right){
    std::vector<int> a;

    int mid = (right + left) / 2;
    int left_idx = left, right_idx = mid+1;

    // loops and adds elements in order until left or right subarray finishes first   
    while(left_idx <= mid && right_idx <= right){
        if(arr.at(left_idx) <= arr.at(right_idx)){
            a.push_back(arr.at(left_idx));
            left_idx++;
        }
        else{
            a.push_back(arr.at(right_idx));
            right_idx++;
        }
    }

    // if left_idx = mid+1, check for missing right sub array
    if(left_idx == mid+1)
        while(right_idx <= right)
            a.push_back(arr.at(right_idx++));

    // if right idx >= right, check for missing left subarray
    if(right_idx >= right)
        while(left_idx <= mid)
            a.push_back(arr.at(left_idx++));

    // reassign original array with ordered elements 
    for(int i=0; i<a.size(); i++)
        arr.at(left + i) = a.at(i);
}