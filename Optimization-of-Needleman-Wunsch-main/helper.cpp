#define _XOPEN_SOURCE

#include <bits/stdc++.h>
#include <stdlib.h>
#include <sys/time.h>

using namespace std;

void tick(struct timeval *t) {
    gettimeofday(t, NULL);
}

double tock(struct timeval *t) {
    struct timeval now;
    gettimeofday(&now, NULL);
    return (double)(now.tv_sec - t->tv_sec) +
           ((double)(now.tv_usec - t->tv_usec) / 1000000.);
}

void RandomVector_f(int n, float *A) {
    for (int i = 0; i < n; ++i) {
        A[i] = (float)rand() / RAND_MAX;
    }
}

void RandomVector_d(int n, double *A) {
    for (int i = 0; i < n; ++i) {
        A[i] = drand48();
    }
}

string RandomSeqGen(int n) {
    string seq = "";
    // srand(time(0));
    for (int i = 0; i < n; ++i) {
        int val[4];
        val[0] = 0;
        val[1] = 2;
        val[2] = 6;
        val[3] = 19;
        seq.push_back(val[(int)rand() % 4] + 'A');
    }
    return seq;
}