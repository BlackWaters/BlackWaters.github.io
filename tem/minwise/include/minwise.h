#ifndef MINWISE_H
#define MINWISE_H

#include <iostream>
#include <map>
#include <vector>
#include <cstdio>
#include <algorithm>
#define ULL unsigned long long
#define LL long long

using namespace std;

class minwise
{
    public:
        const long double &Actualval=Real;
        minwise(const map<ULL,int> &s1,const map<ULL,int> &s2);
        virtual ~minwise();
        long double calculate_M(int k,int b) ;
        long double calculate_C(int k,int b,int n) ;

        void show()
        {
            for (int i=0;i<S1.size();i++) printf("%llu\n",S1[i]);
            printf("\n");
            for (int i=0;i<S2.size();i++) printf("%llu\n",S2[i]);
            printf("\n");
            for (int i=0;i<S.size();i++) printf("%llu\n",S[i]);
        }
    protected:

    private:
        vector<ULL> S1,S1_;
        vector<ULL> S2,S2_;
        vector<ULL> S;
        map<ULL,int> D;
        int Kflag=-1,Bflag=-1;
        long double Real;

        ULL initseed(int b);
        long double Pow(long double a,int b);
        void initMinSet(int k,int b);
};

#endif // MINWISE_H
