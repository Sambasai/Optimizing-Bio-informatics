#include <bits/stdc++.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "helper.h"
using namespace std;
int main(int argc, char *argv[]) {
    string a, b;
    string c;
    srand(time(NULL));
    c = RandomSeqGen(30000 + 30000);
    a = c.substr(0, 30000);
    b = c.substr(30000, 60000);
    // a="GGCCT";
    // b="AGCC";
    // ifstream inputFile("String1");
    // if (inputFile.is_open()) {
    //     getline(inputFile, a);
    //     inputFile.close();
    // } else {
    //     cout << "Unable to open file\n";
    //     return 0;
    // }
    // ifstream inputFile2("String2");
    // if (inputFile2.is_open()) {
    //     getline(inputFile2, b);
    //     inputFile2.close();
    // } else {
    //     cout << "Unable to open file\n";
    //     return 0;
    // }
    // cout<<(int)a.size()<<"\n";
    int gap = -2;
    int match = 1;
    int mismatch = -1;
    // for (int i = 1; i <= 10000; i += 500) {
    // cout << i << " ";
    // c = RandomSeqGen(2 * i);
    // a = c.substr(0, i);
    // b = c.substr(i, 2 * i);
    if (strcmp(argv[1], "-unopt") == 0) {
        Needleman_Wunsch(a, b, match, mismatch, gap);
    } else if (strcmp(argv[1], "-optv1") == 0)
        Needleman_Wunsch_optv1(a, b, match, mismatch, gap);
    else if (strcmp(argv[1], "-optv2") == 0)
        Needleman_Wunsch_optv2(a, b, match, mismatch, gap);
    else if (strcmp(argv[1], "-optv3") == 0)
        Needleman_Wunsch_optv3(a, b, match, mismatch, gap);
    else if (strcmp(argv[1], "-optv4") == 0)
        Needleman_Wunsch_optv4(a, b, match, mismatch, gap);
    else if (strcmp(argv[1], "-optv5") == 0)
        Needleman_Wunsch_optv5(a, b, match, mismatch, gap);
    else if (strcmp(argv[1], "-optv6") == 0) {
        // for (int i = 200; i <= 400; i += 20) {
        //     cout << i << " ";
        //     Needleman_Wunsch_optv6(a, b, match, mismatch, gap, i);
        // }
        // for (int i = 400; i <= 600; i += 20) {
        //     cout << i << " ";
        //     Needleman_Wunsch_optv6(a, b, match, mismatch, gap, i);
        // }
        // for (int i = 600; i <= 800; i += 20) {
        //     cout << i << " ";
        //     Needleman_Wunsch_optv6(a, b, match, mismatch, gap, i);
        // }
        // for (int i = 800; i <= 1000; i += 20) {
        //     cout << i << " ";
        //     Needleman_Wunsch_optv6(a, b, match, mismatch, gap, i);
        // }
        Needleman_Wunsch_optv6(a, b, match, mismatch, gap);
    } else if (strcmp(argv[1], "-optv7") == 0)
        Needleman_Wunsch_optv7(a, b, match, mismatch, gap);
    // }
}