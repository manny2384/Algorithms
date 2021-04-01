#include <bits/stdc++.h>


int main(){
    std::vector<int> a;
    int size, num_generated;
    std::cout << " Input size: ";
    std::cin >> size;

    srand(time(NULL));
    for(int i=0; i<size; i++){
        num_generated = rand() % size + 1;
        a.push_back(num_generated);
        std::cout << num_generated << " ";
    }

    return 0;
}