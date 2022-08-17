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

void Needleman_Wunsch_optv4(string &A, string &B, int match, int mismatch, int gap) {
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
    // columns more than rows
    int tilesize = min(szseq1/10 + 1,min(1000,szseq2/10 + 1));
    int ntiles = (szseq1 + 1) / tilesize;
    int ntiles2 = (szseq2 + 1) / tilesize;
    // cout << tilesize << "\n";
    for (int i = 0; i < ntiles2; i++) {
        for (int j = 0; j < ntiles; j++) {
            // i,j th tile
            // left top corner starts from
            // i*tilesize, j*tilesize
            for (int k = i * tilesize; k < (i + 1) * tilesize; k++) {
                int iters = min(k - i * tilesize + 1, tilesize);
                int start_col = k, start_row = j * tilesize;
                for (int l = 0; l < iters; l++) {
                    // cout << "computing " << start_row + l << " " << start_col - l << "\n";
                    if ((start_row + l) == 0 or (start_col - l) == 0) continue;
                    // computing dp[start_row+l][start_col-l]
                    char seqAati = A[start_row + l - 1];
                    char seqBatj = B[start_col - l - 1];
                    int matchdiag = dp[start_row + l - 1][start_col - l - 1] + (seqAati == seqBatj ? match : mismatch);
                    int gapA = dp[start_row + l][start_col - l - 1] + gap;
                    int gapB = dp[start_row + l - 1][start_col - l] + gap;
                    dp[start_row + l][start_col - l] = max(max(gapA, gapB), matchdiag);
                }
            }
            for (int k = j * tilesize + 1; k < (j + 1) * tilesize; k++) {
                int iters = (j + 1) * tilesize - k;
                int start_col = (i + 1) * tilesize - 1, start_row = k;
                for (int l = 0; l < iters; l++) {
                    // cout << "computing " << start_row + l << " " << start_col - l << "\n";
                    if ((start_row + l) == 0 or (start_col - l) == 0) continue;
                    // computing dp[start_row+l][start_col-l]
                    char seqAati = A[start_row + l - 1];
                    char seqBatj = B[start_col - l - 1];
                    int matchdiag = dp[start_row + l - 1][start_col - l - 1] + (seqAati == seqBatj ? match : mismatch);
                    int gapA = dp[start_row + l][start_col - l - 1] + gap;
                    int gapB = dp[start_row + l - 1][start_col - l] + gap;
                    dp[start_row + l][start_col - l] = max(max(gapA, gapB), matchdiag);
                }
            }
        }
    }
    for (int i = 1; i < ntiles * tilesize; i++) {
        for (int j = ntiles2 * tilesize; j < szseq2 + 1; j++) {
            // cout << "computing " << i << " " << j << "\n";
            char seqAati = A[i - 1];
            char seqBatj = B[j - 1];
            int matchdiag = dp[i - 1][j - 1] + (seqAati == seqBatj ? match : mismatch);
            int gapA = dp[i][j - 1] + gap;
            int gapB = dp[i - 1][j] + gap;
            dp[i][j] = max(max(gapA, gapB), matchdiag);
        }
    }

    for (int i = ntiles * tilesize; i < szseq1 + 1; i++) {
        for (int j = 1; j < szseq2 + 1; j++) {
            // i,j th tile
            // cout << "computing " << i << " " << j << "\n";
            char seqAati = A[i - 1];
            char seqBatj = B[j - 1];
            int matchdiag = dp[i - 1][j - 1] + (seqAati == seqBatj ? match : mismatch);
            int gapA = dp[i][j - 1] + gap;
            int gapB = dp[i - 1][j] + gap;
            dp[i][j] = max(max(gapA, gapB), matchdiag);
        }
    }
    // i,j th tile
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