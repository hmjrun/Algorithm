#include <stdio.h>
int partition(int *arr,int low,int high)
{
    int pivot=arr[high];
    int i=low-1;
    int j,tmp;
    for(j=low;j<high;++j)
        if(arr[j]<pivot){
            tmp=arr[++i];
            arr[i]=arr[j];
            arr[j]=tmp;
        }
    tmp=arr[i+1];
    arr[i+1]=arr[high];
    arr[high]=tmp;
    return i+1;
}
void quick_sort(int *arr,int low,int high)
{
    if(low<high){
        int mid=partition(arr,low,high);
        quick_sort(arr,low,mid-1);
        quick_sort(arr,mid+1,high);
    }
}
//test
int main()
{
    int arr[10]={1,3,6,2,5,0,7,12,9,6};
    quick_sort(arr,0,9);
    int i;
    for(i=0;i<10;++i)
        printf("%d ",arr[i]);
}
