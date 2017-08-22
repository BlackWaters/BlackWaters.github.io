---
layout: post
title: "��ʶ��ϯ��"
date: 2017-08-22
excerpt: "Gym 1012376 & HDU 2665 "
tags: [ACM, ���ݽṹ]
comments: true
---

&#160;&#160;&#160;&#160;��һ�νӴ���ϯ����ǰ����˵�Ǹ�ͦ�򵥵Ķ�����һֱ�������ѧ...

&#160;&#160;&#160;&#160;��ϯ��׼ȷ������һ�ÿ����õ��߶�������Ȼ�ǽ���������⣬���������ѯ�ʻ����ͨ��ѯ�ʸ���һά������ѯ��\\([L,R]\\)�ĵ�kС�����ߵ�k�󣩣��ᷢ��һ����߶������Ѵ�������ʱ����������ϯ����

&#160;&#160;&#160;&#160;��ϯ���ɺܶ���߶�����ɵģ�������Щ�߶������кܶ�ڵ㶼�ǿ��Թ��õġ�����һ���߶������ԣ�������ȥ�������ɺܶ���ڵ㡰ƴ�������ġ�������ÿ���ڵ㣬�����ܻᱻ����߶��������ã�����һ��ʹ�����ǿ��Դ洢�������Ϣ����һ����ʹ�����ǳ���Ŀռ䲻����̫��

&#160;&#160;&#160;&#160;һ��������������ϯ��ϰ����ǰ׺������ǰ׺���Ժܺõ�ά��һЩ���пɼ��Ե����ʣ�������ϻῴ����

## [HDU 2665](http://acm.hdu.edu.cn/showproblem.php?pid=2665)

&#160;&#160;&#160;&#160;�����ᵽ���ģ��������������һ������ĵ�kС�����ǿ���һ�����䣬�������Ҫ���������ĵ�kС�����ǿ����������߶����ϲ���ÿһ��ֵ��Ȼ����������һ�����Ҳ��ҡ�����������n�����䣬���������뵽����ϯ����

&#160;&#160;&#160;&#160;���Ƕ�ÿһ��ǰ׺���߶�������������ÿһ�����䣬���ǿ���ͨ��ǰ׺�Ŀɼ�����������ǰ�����ֵ����Ϊ�����Ƕ���ÿ��ǰ׺���������Բ�ѯ��ʱ���е����������߶����ϲ飬Ȼ�������ǰ�Ľ����

&#160;&#160;&#160;&#160;������д�ĺ�������

{% highlight C++ %}
#include <iostream>
#include <cstring>
#include <cstdio>
#include <map>
#define maxn 100005

using namespace std;

int n,a[maxn],ans[maxn],root[maxn],cnt,q;
map<int,int> mp;
map<int,int>::iterator it;
struct tree
{
    int v,lc,rc;
}d[maxn*18];

void Insert(int pre,int cur,int p,int l,int r)
{
    if (l==r)
    {
        d[cur].v=d[pre].v+1;
        return ;
    }
    int mid=(l+r)>>1;
    if (p<=mid)
    {
        d[cur].lc=cnt++;
        d[cur].rc=d[pre].rc;
        Insert(d[pre].lc,d[cur].lc,p,l,mid);
    }
    else
    {
        d[cur].lc=d[pre].lc;
        d[cur].rc=cnt++;
        Insert(d[pre].rc,d[cur].rc,p,mid+1,r);
    }
    d[cur].v=d[d[cur].lc].v+d[d[cur].rc].v;
}

int query(int curL,int curR,int k,int l,int r)
{
    if (l==r) return l;
    int mid=(l+r)>>1,c=d[d[curR].lc].v-d[d[curL].lc].v;
    if (c>=k) return query(d[curL].lc,d[curR].lc,k,l,mid);
    else return query(d[curL].rc,d[curR].rc,k-c,mid+1,r);
}

int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        memset(d,0,sizeof(d));
        memset(ans,0,sizeof(ans));
        mp.clear();

        scanf("%d%d",&n,&q);
        for (int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            mp[a[i]]=1;
        }
        cnt=0;
        for (it=mp.begin();it!=mp.end();it++)
        {
            it->second=++cnt;
            ans[cnt]=it->first;
        }
        int si=cnt;
        cnt=1;
        for (int i=1;i<=n;i++)
        {
            root[i]=cnt++;
            Insert(root[i-1],root[i],mp[a[i]],1,si);
        }
        while (q--)
        {
            int L,R,k;
            scanf("%d%d%d",&L,&R,&k);
            //k=d[root[R]].v-d[root[L-1]].v-k+1;
            printf("%d\n",ans[query(root[L-1],root[R],k,1,si)]);
        }
    }
    return 0;
}

{% endhighlight %}

## [Gym 101237A](https://cn.vjudge.net/contest/169822#problem/A)

&#160;&#160;&#160;&#160;��һ�����˼�����������һ�������û�г��ֹ�����С��������

&#160;&#160;&#160;&#160;�����Ƕ�ǰ׺������ֻ�������ü��ˣ����Ǽ�¼ÿ��ֵ���ֹ�������λ�ã����߶��������Ǳ������ֵ����Сֵ���������е��ƿڡ�����˼�Ƕ���һ����\\(1..i\\)Ϊ�����߶����У��ڵ�\\([L,R]\\)�������\\([L,R]\\)��Щֵ�У�ĳ��ֵ����λ�õ���Сλ�ã������ֵδ���֣���ô���ֵ����0����

&#160;&#160;&#160;&#160;�������ǾͿ��Բ�ѯ�������ֵ����L���Ƚϣ�����������ֵС��l��˵����������ֵδ��\\([L,R]\\)�г��֣��������ǾͿ�����������һ�����Ҳ�ѯ�ˡ�

{% highlight c++ %}
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#define maxn 1000005

using namespace std;

struct tree
{
    int v,lc,rc;
}d[maxn*21];
int root[maxn],cnt,n,q,L,R;

void Insert(int pre,int cur,int p,int v,int l,int r)
{
    if (l==r)
    {
        d[cur].v=v;
        return ;
    }
    int mid=(l+r)>>1;
    if (p<=mid)
    {
        d[cur].lc=++cnt;
        d[cur].rc=d[pre].rc;
        Insert(d[pre].lc,d[cur].lc,p,v,l,mid);
    }
    else
    {
        d[cur].lc=d[pre].lc;
        d[cur].rc=++cnt;
        Insert(d[pre].rc,d[cur].rc,p,v,mid+1,r);
    }
    d[cur].v=min(d[d[cur].lc].v,d[d[cur].rc].v);
}

int query(int cur,int l,int r)
{
    if (l==r) return l;
    int mid=(l+r)>>1;
    if (d[d[cur].lc].v<L) return query(d[cur].lc,l,mid);
    else return query(d[cur].rc,mid+1,r);
}

int main()
{
   // printf("%lf\n",log2(1e6));
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
    {
        int a;
        scanf("%d",&a);
        root[i]=++cnt;
        Insert(root[i-1],root[i],a+1,i,1,1e6+1);
    }
    scanf("%d",&q);
    while (q--)
    {
        scanf("%d%d",&L,&R);
        printf("%d\n",query(root[R],1,1e6+1)-1);
    }
    return 0;
}
{% endhighlight %}