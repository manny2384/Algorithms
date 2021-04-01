#include <bits/stdc++.h>

void mergesort(std::vector<int> &arr, int, int);
void merge(std::vector<int>&arr, int, int);
int main(){
    std::vector<int> a;
    a.push_back(7);
    a.push_back(6);
    a.push_back(5);
    a.push_back(4);
    a.push_back(3);
    a.push_back(2);
    int size, num_generated;
    std::cout << " Input size: ";
    std::cin >> size;

    /*
    srand(time(NULL));
    for(int i=0; i<size; i++){
        num_generated = rand() % size + 1;
        a.push_back(num_generated);
        std::cout << num_generated << " ";
    }
    */

    std::cout << " \n starting merge sort \n " << std::endl;
    mergesort(a, 0, size-1);
    /*
        for(auto itr = a.begin(); itr!= a.end(); itr++)
        std::cout << *itr << " ";
    */

    std::cout << std::endl;
    return 0;

}

void mergesort(std::vector<int> &arr, int left, int right){
    if(right - left < 1) return;

    int mid = (left + right) / 2;
    mergesort(arr, left, mid);
    mergesort(arr, mid+1, right);

    std::cout << "merging: \n";
    for(int i=0; i<=mid; i++)
        std::cout << arr.at(i) << " ";
    std::cout << " \n with \n";
    for(int i=mid+1; i<=right; i++)
        std::cout << arr.at(i) << " ";
    
    std::cout << std::endl;

    merge(arr, left, right);
}

void merge(std::vector<int> &arr, int left, int right){

    int left_idx = 0;
    int mid = (left+right) / 2;
    int right_idx = mid+1;
    std::vector<int> new_arr;

    while(left_idx <= mid && right_idx <= right){
        if(arr.at(left_idx) < arr.at(right_idx)) 
            new_arr.push_back(arr.at(left_idx++));
        else if(arr.at(left_idx) > arr.at(right_idx)) 
            new_arr.push_back(arr.at(right_idx++));
        else{
            new_arr.push_back(arr.at(left_idx++));
            new_arr.push_back(arr.at(right_idx++));
        }
        
    }

    if(left_idx == mid+1){
        while(right_idx <= right)
            new_arr.push_back(arr.at(right_idx++));
    }
    else{
        while(left_idx <= mid)
            new_arr.push_back(arr.at(left_idx++));
    }

    // copy values into original
    for(auto itr = new_arr.begin(); itr!=new_arr.end(); itr++)
        std::cout << *itr << " ";
    std::cout << std::endl;
    for(int i=0; i<right; i++)
        arr.at(i+left) = new_arr.at(i);
}