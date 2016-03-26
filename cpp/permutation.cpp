#include <iostream>
using namespace std;

void permutation(char *a,int k,int m)
{
    if(k==m)
    {
        for(int i=0;i<m;i++)
            cout<<a[i];
        cout<<endl;
    }
    else
    {
        for(int i=k;i<m;i++)
        {
            swap(a[k],a[i]);
            permutation(a,k+1,m);
            swap(a[k],a[i]);
        }
    }
}


int main(int argc, char const *argv[])
{
    char a[]="abcd";
    permutation(a,0,4);
    return 0;
}