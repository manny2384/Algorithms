#include <bits/stdc++.h>

// memorizes previous fibonacci
std::map<int, long long int> memo;

// fibonacci algorithm( recursive and dynamic respectively)
long long int findFib(int );
long long int findFib_dp(int);

int main(){
    
    int n;
    std::cout << " Enter n (the n-th fibonacci) : ";
    std::cin >> n;

    long long int n_th_fib = findFib_dp(n);
    std::cout << " fibonacci = " << n_th_fib << std::endl;
    return 0;
}

/*
    @param n = the nth fibonacci to find
    returns returner = nth fibonacci
*/
long long int findFib(int n){
    // base case
    if(n <= 2) return 1;

    // recursive call
    return findFib(n-1) + findFib(n - 2);
}

/*
    @param n = the nth fibonacci to find
    returns returner = nth fibonacci
*/
long long int findFib_dp(int n){

    long long int curr_fib;
    // check if current fibonacci of n is in memo
    try{
        curr_fib = memo.at(n);
        return curr_fib;
    }
    catch(std::exception &e){
        // ignore error
    }

    // base case
    if(n <= 2) return 1;

    // recursive call
    curr_fib = findFib_dp(n-1) + findFib_dp(n - 2);
    memo.insert(std::pair<int, long long int>(n, curr_fib));
    return curr_fib;
}