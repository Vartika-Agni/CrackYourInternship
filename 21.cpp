#include<bits/stdc++.h>
#include<stdio.h>
#include<list>
#include<algorithm>

class Solution
{
    public:

    int  multiplyTwoLL(node* h1, node* h2)
  {
    int a=0, b=0, c=0;
     while(h1!=NULL)
     {
        a=a*10+ h1->data; h1=h1->next;
     }
     while(h2!=NULL)
     {
        b=b*10+ h2->data; h2=h2->next;
     }

     c=a*b;
     return c;
  }
};

int main()
{
    list<int> l1;
    list<int>l2;

    l1.push_back(9);
    l1.push_back(4);
    l1.push_back(6);
    l2.push_back(3);
    l2.push_back(8);
    l2.push_back(4);

    int res= multiplyTwoLL(&l1,&l2);
}