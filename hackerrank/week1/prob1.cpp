#include <bits/stdc++.h>

int main(){

    int n, x, negs = 0, zeros = 0, pos = 0;

    std::cin >> n;

    for(int i=0; i<n; i++){
        std::cin >> x;
        if(x < 0) negs++;
        else if(x == 0) zeros++;
        else pos++;
    }

    std::cout << std::setprecision(6) << 1.0 * pos / n << "\n"
        << 1.0 * negs / n << '\n'
        << 1.0 * zeros / n << '\n';

}