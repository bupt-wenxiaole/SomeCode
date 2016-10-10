#include <iostream>
using namespace std;


void adjustHeap(int A[], int k, int n)  //数组中A[1....n]存的是待排序元素，A[0]空出方便排序,k表示待调整的元素位置，将以k为根节点的子树调整为大根堆
{
    A[0] = A[k]; //用A[0]保存A[k]
    for(int i = 2*k; i <= n; i *= 2)
    {
        if(i < n && A[i] < A[i + 1])  //右儿子更大
            i++;
        if(A[0] > A[i])  //当前节点比左儿子和右儿子都大，此次调整结束
            break;
        else
        {
            A[k] = A[i];
            k = i;
        }
    }
    A[k] = A[0];

}
void buildHeap(int A[], int n)
{
    for(int i = n/2; i > 0; i--)
    {
        adjustHeap(A, i, n);
    }

}
void heapSort(int A[], int n)
{
    buildHeap(A, n);
    for(int i = n; i > 1; i--)
    {
        swap(A[1], A[i]);
        adjustHeap(A, 1, i - 1);
    }

}
int main(int argc, char const *argv[])
{
    int A[] = {0, 2, 4, 10 ,1, 1, 2, 3, 29, 23 , 40, 12};
    heapSort(A, sizeof(A)/4 - 1);
    for(int i = 1; i <= sizeof(A)/4 - 1; i++)
        cout << A[i] << endl;
    return 0;
}

