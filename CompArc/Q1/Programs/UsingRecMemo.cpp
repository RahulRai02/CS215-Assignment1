//(c)Using Recursion + Memoization
#include <iostream>
#include <time.h>    
#define ull unsigned long long
using namespace std;

ull fibo_help(ull n, ull *ans) {
	if(n <= 1) {
		return n;
	}

	// Checking if output already exists
	if(ans[n] != -1){
		return ans[n];
	}
    // If not, then call recursion
	// Calculate output
	ull a = fibo_help(n-1, ans);
	ull b = fibo_help(n-2, ans);

	// Saving the ouptut
	ans[n] = a + b;
	
	// Returning the final output
	return ans[n];
}

ull fibo(ull n) {
    // Creating ans array to store the answer for recursion
	ull *ans = new ull[n+1];

    // Fill the arr with -1
	for(ull i = 0; i <= n; i++) {
		ans[i] = -1;
	}
	
	return fibo_help(n, ans);
}

int main() {
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
    
}





