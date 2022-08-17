#include <bits/stdc++.h>
#include <math.h>
#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "helper.h"
#define loop(i, k, n) for (int i = k; i < n; i++)
using namespace std;

void Needleman_Wunsch(string &A, string &B, int match, int mismatch, int gap) {
    int szseq1 = A.size();
    int szseq2 = B.size();
    int **dp = new int *[szseq1 + 1];
    for (int i = 0; i <= szseq1; i++) {
        dp[i] = new int[szseq2 + 1];
    }
    double gflops = 6 * szseq1 * szseq2;
    struct timeval t;
    tick(&t);
    if (szseq1 > szseq2) {
        swap(szseq1, szseq2);
        swap(A, B);
    }
#pragma omp parallel for
    loop(i, 0, szseq1 + 1) {
        dp[i][0] = i * gap;
    }
#pragma omp parallel for
    loop(i, 0, szseq2 + 1) {
        dp[0][i] = i * gap;
    }
    loop(j, 1, szseq2 + 1) {
        loop(i, 1, szseq1 + 1) {
            char seqAati = A[i - 1];
            char seqBatj = B[j - 1];
            int matchdiag = dp[i - 1][j - 1] + (seqAati == seqBatj ? match : mismatch);
            int gapA = dp[i - 1][j] + gap;
            int gapB = dp[i][j - 1] + gap;
            dp[i][j] = max(max(gapA, gapB), matchdiag);
        }
    }
    double time = tock(&t);
    cout << "Exec Time: " << time * 1000 << "\n";
    cout << "GIPS: " << gflops / time / 1e9 << "\n";
    // cout << "Operational Intensity: " << (double)(gflops) / (4 * szseq1 * szseq2) << "\n";

    // loop(i, 0, szseq1 + 1) {
    //     loop(j, 0, szseq2 + 1) {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << "\n";
    // }

    // cout<<time*1000<<"\n";
}