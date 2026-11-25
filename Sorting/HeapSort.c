#include<stdio.h>

void heapify(int a[],int n,int i){
    int temp;
    int smallest=i;
    int left=2*i+1;
    int right=2*i+2;

    if(left<n && a[left]<a[smallest]){
        smallest=left;
    }
    if(right<n && a[right]<a[smallest]){
        smallest=right;
    }
    if(smallest!=i){
        temp=a[i];
        a[i]=a[smallest];
        a[smallest]=temp;

        heapify(a,n,smallest);
    }
}
int main()
{
    int a[100],b[100];
    int n,i;
    printf("Enter n:");
    scanf("%d",&n);

    printf("Enter the numbers:");
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    printf("Sorting....\n");
    //Build Min-Heap
    for(i=n/2-1;i>=0;i--){
        heapify(a,n,i);
    }
    //Delete the root one by one and store the value in another array
    for(i=0;i<n;i++){
        b[i]=a[0];
        a[0]=a[n-i-1];
        heapify(a,n-i-1,0);
    }
    printf("Sorted Numbers are:\n");
    for(i=0;i<n;i++){
        printf("%d ",b[i]);
    }
    return 0;
}
//Time Complexity:O(nlogn);