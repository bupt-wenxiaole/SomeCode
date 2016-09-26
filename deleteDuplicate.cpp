//deleteDupliate
#include <iostream>
using namespace std;

void deleteDuplicate(int a[], int n)
{
    int i = 0, j = 0;
    while(i < n && j < n)
    {
        if(a[i] == a[j])
            j++; 
        else
            a[++i] = a[j++];
    }
}

int main(int argc, char const *argv[])
 {
    int a[] = {1,2,2,3,3,3,4,5,6,7};
    deleteDuplicate(a, 10);
    for(int i = 0; i < 7; i++)
        cout << a[i] << endl;
    return 0;
 } 