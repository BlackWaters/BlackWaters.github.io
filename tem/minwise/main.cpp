#include <iostream>
#include "stopwords.h"
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include "minwise.h"
#include "ReadFile.h"
#define Ktimes 100

using namespace std;

char s[15];
FILE *fp;

int main()
{
    ReadFile S1; ReadFile S2;
    S1.d_shingling(2,"plaintext.txt");
    S2.d_shingling(2,"plaintext2.txt");
    //S1.show();
    printf("\n");
    //S2.show();


    minwise M(S1.MP,S2.MP);
    //M.show();
    long double ansC=M.calculate_C(Ktimes,2,2);
    ansC=max(ansC,(long double)0);
    long double ansM=M.calculate_M(Ktimes,2);
    ansM=max(ansM,(long double)0);
    printf("Actualval :\t\t%.10lf\nMinwise :\t\t%.10lf\nConnect Minwise:\t%.10lf\n",M.Actualval,ansM,ansC);
    return 0;

}
