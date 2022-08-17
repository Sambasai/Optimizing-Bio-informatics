// #pragma GCC optimize("O3")
// #pragma GCC optimize("Ofast")
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

void Needleman_Wunsch_optv3(string &A, string &B, int match, int mismatch, int gap) {
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
    // Columns more than rows
    loop(i, 1, szseq2 + 1) {
        int iters = min(i, szseq1 + 1);
        int start_row = 0, start_col = i;
#pragma omp parallel for
        for (int j = 0; j < iters; j++) {
            if ((start_row + j) == 0 or (start_col - j) == 0) continue;
            // computing dp[start_row+j][start_col-j]
            char seqAati = A[start_row + j - 1];
            char seqBatj = B[start_col - j - 1];
            int matchdiag = dp[start_row + j - 1][start_col - j - 1] + (seqAati == seqBatj ? match : mismatch);
            int gapA = dp[start_row + j - 1][start_col - j] + gap;
            int gapB = dp[start_row + j][start_col - j - 1] + gap;
            dp[start_row + j][start_col - j] = max(max(gapA, gapB), matchdiag);
        }
    }
    loop(i, 1, szseq1 + 1) {
        int iters = szseq1 + 1 - i;
        int start_row = i, start_col = szseq2;
#pragma omp parallel for
        for (int j = 0; j < iters; j++) {
            if ((start_row + j) == 0 or (start_col - j) == 0) continue;
            // computing dp[start_row+j][start_col-j]
            char seqAati = A[start_row + j - 1];
            char seqBatj = B[start_col - j - 1];
            int matchdiag = dp[start_row + j - 1][start_col - j - 1] + (seqAati == seqBatj ? match : mismatch);
            int gapA = dp[start_row + j - 1][start_col - j] + gap;
            int gapB = dp[start_row + j][start_col - j - 1] + gap;
            dp[start_row + j][start_col - j] = max(max(gapA, gapB), matchdiag);
        }
    }
    double time = tock(&t);
    cout << "Exec Time: " << time * 1000 << "\n";
    cout << "GIPS: " << gflops / time / 1e9 << "\n";
    // cout << "Operational Intensity: " << (double)(gflops) / (4 * szseq1 * szseq2) << "\n";

    // cout << A << " " << B << "\n";
    // loop(i, 0, szseq1 + 1) {
    //     loop(j, 0, szseq2 + 1) {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    // cout<<dp[szseq1][szseq2]<<"\n";

    // cout<<time*1000<<"\n";
}