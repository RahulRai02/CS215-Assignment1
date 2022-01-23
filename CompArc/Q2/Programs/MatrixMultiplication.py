# To make the program for integer, Uncomment Line 11 and 12 and then comment Line 13 and Line 14
import numpy as np
import time
import random

global n
n = 512

np.random.seed(42)
A = [[float(random.randint(0,10) + random.random()) for x in range(n)] for y in range (n)]
# A = np.random.randint(0,10, size=(n,n))
# B = np.random.randint(0,10, size=(n,n))
B = [[float(random.randint(0,10) + random.random()) for x in range(n)]for y in range (n)]
result = [[ 0 for i in range(n)] for j in range(n)]

start = time.perf_counter()

for i in range(len(A)):
    for j in range(len(B[0])):
        for k in range(len(B)):
            result[i][j] += A[i][k] * B[k][j]

end = time.perf_counter()
for a in A:
    print(a)

for b in B:
    print(b)

for l in result:
    print(l)

print("Seconds")
print(end - start)