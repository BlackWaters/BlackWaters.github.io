#include "minwise.h"
#include <map>
#include <iostream>
#include <cmath>

using namespace std;

minwise::minwise(const map<ULL,int> &s1,const map<ULL,int> &s2)
{
    S1.clear(); S2.clear(); D.clear(); S.clear(); S1_.clear(); S2_.clear();
    map<ULL,int>::const_iterator it;

    for (it=s1.begin();it!=s1.end();it++) D[it->first]++;
    for (it=s2.begin();it!=s2.end();it++) D[it->first]++;

    int up=0;
    for (it=D.begin();it!=D.end();it++) if (it->second>1) up++;
    Real=1.0*up/D.size();

    ULL cnt=1;
    for (it=D.begin();it!=D.end();it++)
    {
        D[it->first]=cnt;
        S.push_back(cnt);
        cnt++;
    }

    for (it=s1.begin();it!=s1.end();it++) S1.push_back(D[it->first]);
    for (it=s2.begin();it!=s2.end();it++) S2.push_back(D[it->first]);
}

minwise::~minwise()
{
    //dtor
}

ULL minwise::initseed(int b)
{
    ULL ret=0;
    while (b)
    {
        ret<<=1;
        ret|=1;
        b--;
    }
    return ret;
}

long double minwise::Pow(long double a,int b)
{
    long double ret=1;
    while (b)
    {
        if (b&1) ret*=a;
        b>>=1;
        a*=a;
    }
    return ret;
}

void minwise::initMinSet(int k,int b)
{
    if (Kflag==k && Bflag==b) return ; //has been done
    //init
    Kflag=k; Bflag=b;
    S1_.clear(); S2_.clear();
    while (k--)
    {
        random_shuffle(S.begin(),S.end());
        //for (int i=0;i<S.size();i++) printf("%llu ",S[i]);
        //printf("\n");
        ULL Min=0xffffffffffffffff;
        for (int i=0;i<S1.size();i++) Min=min(Min,S[S1[i]-1]);
        S1_.push_back(Min);
        Min=0xffffffffffffffff;
        for (int i=0;i<S2.size();i++) Min=min(Min,S[S2[i]-1]);
        S2_.push_back(Min);
    }
    // &
    ULL mask=initseed(b);
    for (int i=0;i<S1_.size();i++) S1_[i]&=mask;
    for (int i=0;i<S2_.size();i++) S2_[i]&=mask;
}

long double minwise::calculate_C(int k,int b,int n)
{
    initMinSet(k,b);
    // connect
    vector<ULL> A,B;
    //connect S1_
    A.clear(); B.clear();
    int cnt=0; ULL ret=0;
    for (int i=0;i<S1_.size();i++)
    {
        ret<<=b;
        ret|=S1_[i]; cnt++;
        if (cnt==n)
        {
            A.push_back(ret);
            ret=0; cnt=0;
        }
    }
    if (cnt) A.push_back(ret);
    //connect S2_
    cnt=0; ret=0;
    for (int i=0;i<S2_.size();i++)
    {
        ret<<=b;
        ret|=S2_[i]; cnt++;
        if (cnt==n)
        {
            B.push_back(ret);
            ret=0; cnt=0;
        }
    }
    if (cnt) B.push_back(ret);

    //calculate
    long double G_1n=0,up=0;
    for (int i=0;i<A.size();i++) if (A[i]==B[i]) up+=1;
    G_1n=up/((long double) A.size());

    long double r1=1.0*S1.size()/S.size(),r2=1.0*S2.size()/S.size(),A_1b,A_2b,C_1b,C_2b;
    A_1b= (1.0*r1*pow(1.0-r1,pow(2,b)-1))/(1.0-pow(1.0-r1,pow(2,b)));
    A_2b= (1.0*r2*pow(1.0-r2,pow(2,b)-1))/(1.0-pow(1.0-r2,pow(2,b)));

    C_1b=A_1b*r2/(r1+r2)+A_2b*r1/(r1+r2);
    C_2b=A_1b*r1/(r1+r2)+A_2b*r2/(r1+r2);
    long double ans=pow(G_1n,1.0/n);

    return (ans-C_1b)/(1.0-C_2b);
}

long double minwise::calculate_M(int k,int b)
{
    initMinSet(k,b);
    // connect
    vector<ULL> A,B;
    /*
    //connect S1_
    A.clear(); B.clear();
    int cnt=0; ULL ret=0;
    for (int i=0;i<S1_.size();i++)
    {
        ret<<=b;
        ret|=S1_[i]; cnt++;
        if (cnt==n)
        {
            A.push_back(ret);
            ret=0; cnt=0;
        }
    }
    if (cnt) A.push_back(ret);
    //connect S2_
    cnt=0; ret=0;
    for (int i=0;i<S2_.size();i++)
    {
        ret<<=b;
        ret|=S2_[i]; cnt++;
        if (cnt==n)
        {
            B.push_back(ret);
            ret=0; cnt=0;
        }
    }
    if (cnt) B.push_back(ret);
    */

    //calculate
    long double G_1n=0,up=0;
    for (int i=0;i<S1_.size();i++) if (S1_[i]==S2_[i]) up+=1;
    G_1n=up/((long double) S1_.size());

    long double r1=1.0*S1.size()/S.size(),r2=1.0*S2.size()/S.size(),A_1b,A_2b,C_1b,C_2b;
    A_1b= (1.0*r1*pow(1.0-r1,pow(2,b)-1))/(1.0-pow(1.0-r1,pow(2,b)));
    A_2b= (1.0*r2*pow(1.0-r2,pow(2,b)-1))/(1.0-pow(1.0-r2,pow(2,b)));

    C_1b=A_1b*r2/(r1+r2)+A_2b*r1/(r1+r2);
    C_2b=A_1b*r1/(r1+r2)+A_2b*r2/(r1+r2);
    long double ans=G_1n;

    return (ans-C_1b)/(1.0-C_2b);

}
