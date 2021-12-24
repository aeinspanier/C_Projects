#include <stdio.h>
#include <stdlib.h>

struct Array {
    int A[10];
    int size;
    int length;
};

void Display(struct Array arr){

    printf("elements are\n");
    for(int i=0;i<arr.length;i++)
        printf("%d ",arr.A[i]);

}

void Append(struct Array *arr, int x){
    if(arr->length < arr->size)
        arr->A[arr->length++]=x;
}

void Insert(struct Array *arr, int idx, int x){
    if(idx>=0 && idx<=arr->length){
        for(int i=arr->length;i>idx;i--)
            arr->A[i]=arr->A[i-1];
        arr->A[idx] = x;
        arr->length++;
    }
}

int Delete(struct Array *arr, int idx){
    int x=0;
    
    if(idx>=0 && idx<=arr->length){
        x=arr->A[idx];

        for(int i=idx;i<arr->length-1;i++)
            arr->A[i] = arr->A[i+1];
        arr->length--;
    }
    return x;
}

void swap(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y=temp;
}

int LinearSearch(struct Array *arr, int key){
    for(int i=0;i<arr->length;i++){
        if(key == arr->A[i]){
            swap(&arr->A[i], &arr->A[0]);
            return i;
        }
    }
    return -1;
}

int RBinSearch(int a[], int l, int h, int key){
    int mid;

    if(l<=h){
        mid = (l+h)/2;
        if(key==a[mid]){
            return mid;
        }else if(key<a[mid]){
            return RBinSearch(a,l,mid-1,key);
        }else{
            return RBinSearch(a,mid+1,h,key);
        }
    }
    return -1;
}

int Get(struct Array arr, int idx){
    if(idx >= 0 && idx<arr.length){
        return arr.A[idx];
    }
    return -1;
}

void Set(struct Array *arr, int idx, int key){
    if(idx>=0 && idx<arr->length){
        arr->A[idx]=key;
    }
}

int Max(struct Array arr){
    int max=arr.A[0];

    for(int i=1;i<arr.length;i++){
        if(arr.A[i]>max)
            max = arr.A[i];
    }
    return max;
}


int Min(struct Array arr){
    int min=arr.A[0];

    for(int i=1;i<arr.length;i++){
        if(arr.A[i]<min)
            min = arr.A[i];
    }
    return min;
}

int Sum(struct Array arr){
    int sum=0;

    for(int i=0;i<arr.length;i++){
        sum += arr.A[i];
    }
    return sum;
}

float Avg(struct Array arr){
    return (float)Sum(arr)/arr.length;
}

void Reverse(struct Array *arr){
    int i,j;
    for(i=0, j=arr->length-1;i<j;i++, j--){
        swap(&arr->A[i],&arr->A[j]);
    }
}

void InsertSort(struct Array *arr, int x){
    int i=arr->length-1;
    if(arr->length == arr->size)
        return;

    while(i>=0 && arr->A[i]>x){
        arr->A[i+1] = arr->A[i];
        i--;        
    }
    arr->A[i+1] = x;
    arr->length++;
}

int isSorted(struct Array arr){
    int i;
    for(i=0;i<arr.length-1;i++){
        if(arr.A[i] > arr.A[i+1])
            return 0;
    }
    return 1;
}

void Rearrange(struct Array *arr){
    int i,j;
    i=0;
    j=arr->length;

    while(i<j){
        while(arr->A[i]<0)i++;
        while(arr->A[j]>=0)j--;
        if(i<j) swap(&arr->A[i],&arr->A[j]);
    }
}

struct Array * Merge(struct Array *arr1, struct Array *arr2){
    int i, j, k;
    i=j=k=0;
    struct Array *arr3;
    arr3 = (struct Array *)malloc(sizeof(struct Array));

    while(i<arr1->length && j<arr2->length){
        if(arr1->A[i] < arr2->A[j]){
            arr3->A[k++] = arr1->A[i++];
        }else{
            arr3->A[k++] = arr2->A[j++];
        }
    }

    for(;i<arr1->length;i++)
        arr3->A[k++] = arr1->A[i];
    for(;j<arr2->length;j++)
        arr3->A[k++] = arr2->A[j];

    arr3->length = arr1->length + arr2->length;
    arr3->size = 10;
    return arr3;
}

struct Array * Union(struct Array *arr1, struct Array *arr2){
    int i, j, k;
    i=j=k=0;
    struct Array *arr3;
    arr3 = (struct Array *)malloc(sizeof(struct Array));

    while(i<arr1->length && j<arr2->length){
        if(arr1->A[i] < arr2->A[j]){
            arr3->A[k++] = arr1->A[i++];
        }else if(arr1->A[i] == arr2->A[j]){
            arr3->A[k++] = arr1->A[i++];
            j++;
        }
        else{
            arr3->A[k++] = arr2->A[j++];
        }
    }

    for(;i<arr1->length;i++)
        arr3->A[k++] = arr1->A[i];
    for(;j<arr2->length;j++)
        arr3->A[k++] = arr2->A[j];

    arr3->length = k;
    arr3->size = 10;
    return arr3;
}

struct Array * Intersection(struct Array *arr1, struct Array *arr2){
    int i, j, k;
    i=j=k=0;
    struct Array *arr3;
    arr3 = (struct Array *)malloc(sizeof(struct Array));

    while(i<arr1->length && j<arr2->length){
        if(arr1->A[i] < arr2->A[j]){
            i++;
        }else if(arr1->A[i] == arr2->A[j]){
            arr3->A[k++] = arr1->A[i++];
            j++;
        }
        else{
            j++;
        }
    }

    arr3->length = k;
    arr3->size = 10;
    return arr3;
}

struct Array * Difference(struct Array *arr1, struct Array *arr2){
    int i, j, k;
    i=j=k=0;
    struct Array *arr3;
    arr3 = (struct Array *)malloc(sizeof(struct Array));

    while(i<arr1->length && j<arr2->length){
        if(arr1->A[i] < arr2->A[j]){
            arr3->A[k++] = arr1->A[i++];
        }else if(arr1->A[i] == arr2->A[j]){
            i++;
            j++;
        }
        else{
            j++;
        }
    }

    for(;i<arr1->length;i++)
        arr3->A[k++] = arr1->A[i];

    arr3->length = k;
    arr3->size = 10;
    return arr3;
}

int main(){
    struct Array arr1;
    int ch;

    printf("Enter size of array \n");
    scanf("%d\n",&arr1.size);
    arr1.A = (int *)malloc(arr1.size*sizeof(int));

    printf("Menu \n");
    printf("1. Insert \n");
    printf("2. Delete \n");
    printf("3. Search \n");
    printf("4. Sum \n");
    printf("5. Display \n");
    printf("6. Exit \n");

    printf("Enter your choice \n");
    scanf("%d\n",&ch);

}
