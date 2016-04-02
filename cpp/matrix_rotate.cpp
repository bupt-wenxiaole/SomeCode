#include <iostream>
using namespace std;


#define N 4

void rotate(char Matrix[][N])
{
    for(int layer=0;layer<N/2;layer++)   //从最外层开始旋转
    {
        int first=layer;
        int last=N-1-layer;
        for(int i=first;i<last;i++)
        {
            int offset=i-first;
            char top = Matrix[first][i];
            Matrix[first][i]=Matrix[last-offset][first];
            Matrix[last-offset][first]=Matrix[last][last-offset];
            Matrix[last][last-offset]=Matrix[i][last];
            Matrix[i][last]=top;
        }

    }
}

int main(int argc, char const *argv[])
{
    char a[][N]={{'a','b','c','d'},{'e','f','g','h'},{'i','j','k','l'},{'m','n','o','p'}};
    cout<<"before rotate:"<<endl;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
            cout<<a[i][j]<<" ";
        cout<<endl;
    }
    rotate(a);
    cout<<"after rotate:"<<endl;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
            cout<<a[i][j]<<" ";
        cout<<endl;
    }


}