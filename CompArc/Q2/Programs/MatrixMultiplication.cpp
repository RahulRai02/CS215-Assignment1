
#include<iostream>
#include<math.h>
#include <cstdlib>
#include<time.h>
#define N 256
#define ull int
const int mod=1000000007;
using namespace std;

int main(){
    double arr1[N][N];
    double arr2[N][N];
    for (ull i = 0; i < N; i++){
        for (ull j = 0; j < N; j++){
            // arr1[i][j] = rand() % 10;
            // arr2[i][j] = rand() % 10;
            arr1[i][j] = (rand() % 100000)*0.132 ;
            arr2[i][j] = (rand() % 100000)*0.132;
        }
    }
    cout << "A is " << endl;
    for (ull i = 0; i < N; i++){
        for (ull j = 0; j < N; j++){
            cout << arr1[i][j]<<" ";
        }
        cout << endl;
    }
    cout << endl;
    cout << "B is " << endl;
    for (ull i = 0; i < N; i++){
        for (ull j = 0; j < N; j++){
            cout << arr2[i][j]<<" ";
        }
        cout << endl;
    }

    // Multiplication
    struct timespec before;
    clock_gettime(CLOCK_MONOTONIC, &before);

    double arr3[N][N];
    for (ull i = 0; i < N; i++){
        for (ull j = 0; j < N; j++){
            arr3[i][j] = 0;
            for (ull k = 0; k < N; k++){
                arr3[i][j] += arr1[i][k] * arr2[k][j];
            }
        }
    }

    struct timespec after;
    clock_gettime(CLOCK_MONOTONIC, &after);
    uint64_t before_ns = (before.tv_sec * 1000000000) + before.tv_nsec;
    uint64_t after_ns = (after.tv_sec * 1000000000) + after.tv_nsec;
    int64_t elapsed = after_ns - before_ns;

    // Print the multiplied Matrix
    cout << endl;
    cout << "Matrix Multiplication result is " << endl;
    for (ull i = 0; i < N; i++){
        for (ull j = 0; j < N; j++){
            cout << arr3[i][j]<<" ";
        }
        cout << endl;
    }

    cout <<"Nanoseconds before " << before_ns << endl;
    cout << "Nanoseconds after " << after_ns <<endl;

    cout << "Nanoseconds elapsed " << elapsed << endl;

    cout<<"END !!!!!!!!!!"<<endl;
}