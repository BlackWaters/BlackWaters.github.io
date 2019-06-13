#include "ReadFile.h"

#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <string>
#define Pri 16249

ReadFile::ReadFile()
{
    //ctor
    //MP=mp;
}

ReadFile::~ReadFile()
{
    //dtor
}

bool ReadFile::upperword(char s)
{
    if (s>='A' && s<='Z') return 1;
    return 0;
}

bool ReadFile::lowerword(char s)
{
    if (s>='a' && s<='z') return 1;
    return 0;
}

ULL ReadFile::Pow(ULL a,ULL b)
{
    ULL ret=1;
    while (b)
    {
        if (b&1) ret*=a;
        b>>=1;
        a*=a;
    }
    return ret;
}

ULL ReadFile::Hash(string s)
{
    ULL ret=0;
    int l=s.length();
    for (int i=0;i<l;i++) ret+=(ULL)s[i]*Pow(Pri,i);
    return ret;
}

bool ReadFile::number(char s)
{
    if (s>='0' && s<='9') return 1;
    return 0;
}

string ReadFile::solve(char s[])
{
    string ret;
    ret.clear();
    int l=strlen(s);
    for (int i=0;i<l;i++) if (upperword(s[i]) || lowerword(s[i]) || number(s[i])) ret+=s[i];;
    return ret;
}
