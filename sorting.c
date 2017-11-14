#include <stdio.h>
#include <stdlib.h>

#define MaxSize 20
#define INFINITE 1000

void StraightInsertSort(int *a, int n);

void ShellInsert(int *a,int n,int dk);
void ShellSort(int *a,int n);

void BubbleSort(int *a,int n);
void QuickSort(int *a,int low,int high);

void MaxHeap(int *a,int n,int i);
void CreatHeap(int *a,int n);
void HeapSort(int *a,int n);

void StraightSelectionSort(int *a,int n);

void Merge(int *a,int start,int mid,int end);
void MergeSort();



void StraightInsertSort(int *a, int n){
    int i,j = 0;
    int temp = 0;
    for (i=1;i<n;i++){
        temp=a[i];
        j=i-1;
        for(j=i-1;j>=1;j--){
            if(temp < a[j])
                a[j+1]=a[j];
        else
            break;
        }
    }
    a[j+1]=temp;
}

void ShellInsert(int *a,int n,int dk){
    int i,j,temp;
    for(i=dk+1;i<=n;i+=dk){
        temp=a[i];
        for(j=i-dk;j>=0;j-=dk)
            if(a[j]>temp)
                a[j+dk]=a[j];
            else
                break;
        a[j+dk]=temp;
    }
}

void ShellSort(int *a,int n){
    int i;
    int dk[]={5,4,3,2,1};
    for(i=0;i<5;i++)
        ShellInsert(a,6,dk[i]);
}

void BubbleSort(int *a,int n){
    int i,j;
    for(i=1;i<n;i++){
        for(j=1;j<n-i+1;j++){
            if(a[j+1]<a[j]){
                a[j]=a[j]+a[j+1];
                a[j+1]=a[j]-a[j+1];
                a[j]=a[j]-a[j+1];
            }
        }
    }
}


void QuickSort(int *a,int low,int high){
    int pivotkey=a[low];
    int i=low,j=high;
    if(low>=high)
        return;
    while(i<j){
        while(i < j && a[j] >= pivotkey)
            j--;
        a[i]=a[j];
        while(i < j && a[i] <= pivotkey)
            i++;
        a[j]=a[i];
    }
    a[i]=pivotkey;
    QuickSort(a,low,i-1);
    QuickSort(a,i+1,high);
}

void MaxHeap(int *a,int n,int i){
    int left,right,largest;
    largest=left=2*i;
    if(left>n)
        return;
    right=2*i+1;
    if(right<=n && a[right]>a[left]){
        largest=right;
    }
    if(a[i]<a[largest]){
        a[i]=a[i]+a[largest];
        a[largest]=a[i]-a[largest];
        a[i]=a[i]-a[largest];
        MaxHeap(a,n,largest);
    }
}

void CreatHeap(int *a,int n){
    int i;
    for(i=n/2;i>=1;i--)
        MaxHeap(a,n,i);
}

void HeapSort(int *a,int n){
    int i;
    CreatHeap(a,n);
    for(i=n;i>=2;i--){
        a[1]=a[1]+a[i];
        a[i]=a[1]-a[i];
        a[1]=a[1]-a[i];
        MaxHeap(a,i-1,1);
    }
}

void StraightSelectionSort(int *a,int n){
    int i,j,index;
    for(i=1;i<n;i++){
        index=i;
            for(j=i+1;j<=n;j++)
            if(a[j]<a[index])
                index=j;
        
        if(index!=i){
            a[i]=a[i]+a[index];
            a[index]=a[i]-a[index];
            a[i]=a[i]-a[index];
        }
    }
}

void Merge(int *a,int start,int mid,int end){
    int i,j,k;
    int *array1=(int*)malloc(sizeof(int)*(mid-start+2));
    int *array2=(int*)malloc(sizeof(int)*(end-mid+1));
    for(i=0;i<mid-start+1;i++)
      *(array1+i)=a[start+i];
    
    *(array1+i)=INFINITE;
    for(i=0;i<end-mid;i++)
        *(array2+i)=a[i+mid+1];
    *(array2+i)=INFINITE;
    
    i=j=0;
    for(k=start;k<=end;k++){
        if(*(array1+i) > *(array2+j)){
            a[k]=*(array2+j);
            j++;
        }
        else{
            a[k]=*(array1+i);
            i++;
        }
    }
    free(array1);
    free(array2);
}

void MergeSort(int *a,int start,int end){
    int mid=(start+end)/2;
    if(start<end){
        MergeSort(a,start,mid);
        MergeSort(a,mid+1,end);
        Merge(a,start,mid,end);
    }
}
int main(int argc, const char * argv[]) {
    int i;
    int a[11]={0, 513, 87, 512, 61, 908, 170, 897, 275, 653, 462};
    
    StraightInsertSort(a,10);
    for(i=1;i<=10;i++)
        printf("%-4d",a[i]);
    printf("\n");
    
    ShellSort(a,10);
    for(i=1;i<=10;i++)
        printf("%-4d",a[i]);
    printf("\n");
    
    BubbleSort(a,10);
    for(i=1;i<=10;i++)
        printf("%-4d",a[i]);
    printf("\n");
    
    QuickSort(a,1,10);
    for(i=1;i<=10;i++)
        printf("%-4d",a[i]);
    printf("\n");

    HeapSort(a,10);
    for(i=1;i<=10;i++)
        printf("%-4d",a[i]);
    printf("\n");
    
    StraightSelectionSort(a,10);
    for(i=1;i<=10;i++)
        printf("%-4d",a[i]);
    printf("\n");
    
    MergeSort(a,1,10);
    for(i=1;i<=10;i++)
        printf("%-4d",a[i]);
    printf("\n");
    
    return 0;
}
