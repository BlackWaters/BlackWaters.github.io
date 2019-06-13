#ifndef READFILE_H
#define READFILE_H

#include <vector>
#include <iostream>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include "stopwords.h"
#include <map>
#define ULL unsigned long long

using namespace std;

class ReadFile
{
    public:
        const map<ULL,int> &MP=mp;
        ReadFile();
        virtual ~ReadFile();

        void d_shingling(int d,char filename[])
        {
            v.clear();
            FILE *fp=fopen(filename,"r");
            char s[20];
            while (~fscanf(fp,"%s",s))
            {
                //printf("%s",s);
                string a=solve(s);
                if (stp.Search(a)) continue;
                //cout << a<<endl;
                v.push_back(a);
            }
            fclose(fp);

            // d-shingling

            string ret; mp.clear();
            ret.clear();
            int sz=v.size(),cnt=0;
            for (int i=0;i<sz-d+1;i++)
            {
                ret.clear();
                for (int j=0;j<d;j++) ret+=v[i+j];
                //cout << ret <<endl;
                mp[Hash(ret)]=1;
            }
        }

        void show()
        {
            printf("%d\n",v.size());
            for (int i=0;i<v.size();i++) cout << v[i] <<" ";
        }

    private:
        map<ULL,int> mp;
        stopwords stp;
        vector<string> v;
        bool upperword(char s);
        bool lowerword(char s);
        bool number(char s);
        ULL Pow(ULL a,ULL b);
        ULL Hash(string s);
        string solve(char s[]);
};

#endif // READFILE_H
