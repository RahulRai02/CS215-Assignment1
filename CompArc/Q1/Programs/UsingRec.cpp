//(a) Using Recursion
#include<iostream>
#include <time.h>
#define ull unsigned long long
// #define nano 1000000000
using namespace std;

ull fibo(ull n){
    if(n == 0){
        return 0;
    }
    if(n == 1){
        return 1;
    }
    ull smallOuptut1 = fibo(n - 1);
    ull smallOutput2 = fibo(n - 2);
    return smallOuptut1 + smallOutput2;
}

int main(){
    ull n;
    cin >> n;
    // auto start = high_resolution_clock::now();
    struct timespec before;
    clock_gettime(CLOCK_MONOTONIC, &before);
    for (ull i = 0; i < n; i++){
        cout << fibo(i)<<endl;
    }
    struct timespec after;
    clock_gettime(CLOCK_MONOTONIC, &after);
    uint64_t before_ns = (before.tv_sec * 1000000000) + before.tv_nsec;
    uint64_t after_ns = (after.tv_sec * 1000000000) + after.tv_nsec;
    int64_t elapsed = after_ns - before_ns;

    cout <<"Nanoseconds before " << before_ns << endl;
    cout << "Nanoseconds after " << after_ns <<endl;

    cout << " Nanoseconds elapsed " << elapsed << endl;
    
    
    
    // cout << before.tv_sec << " seconds, " << before.tv_nsec << " nano seconds before" << endl;
    // cout << after.tv_sec << " seconds, " << after.tv_nsec << " nano seconds after" << endl;
    // cout << (after.tv_sec - before.tv_sec) << " seconds, " << after.tv_nsec - before.tv_nsec << " nanoseconds elapsed";

    // cout << after.tv_sec - before.tv_sec << " seconds elapsed" << endl;
    // cout << after.tv_nsec - before.tv_nsec << " nano seconds elapsed" << endl;
    // cout << (long)(after.tv_sec - before.tv_sec) * 1000 + (long)(after.tv_nsec - before.tv_nsec) / 1000000;
    // auto end = high_resolution_clock::now();
    // auto timedur = duration_cast<seconds>(end - start);
    // cout << timedur.count()<<endl;
}


