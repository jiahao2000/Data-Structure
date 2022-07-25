// 交换排序，比较两个元素的大小 进行交换

#define ElemType int

void swap(int &a, int &b){
    int temp;
    temp = a;
    a = b;
    b = temp;
}

// 冒泡排序
// 算法稳定
// 空间复杂度 O(1)
// 最好时间复杂度 O(n) :原本就是有序的，比较次数n-1,交换次数为0
// 最坏情况 O(n^2)：逆序 比较次数：(n-1)+.....+1 = 交换次数 
// 平均时间复杂度 O(n^2)
// 冒泡排序可以用于链表之中

void BubbleSort(ElemType A[], int n){
    for(int i = 0;i<n-1;i++){
        bool flag = false;
        for(int j = n-1; j>i;j--){
            if(A[j-1]>A[j]){ //如果逆序，则进行交换 
                swap(A[j-1], A[j]);
                flag = true;
            }
           
        } 
        if(flag == false){
                return ; //如果一趟冒泡排序中没有发生任何一次交换，说明表已经有序，可以直接推出排序
            }
    }
}


// 快速排序
void QuickSort(ElemType A[],int low, int high){
    if(low<high){
        //Partition()就是划分操作，将表A[]划分为满足条件的两个子表
        int pivotpos = Partition(A,low,high);
        QuickSort(A,low,pivotpos-1);
        QuickSort(A,pivotpos+1,high);
    }
}

int Partition(ElemType A[], int low, int high){
    ElemType pivot = A[low];
    while(low<high){
        while(low<high && A[high]>=pivot) high--; //循环直到A[high]<pivot
        // 在high减小到和low相等时会循环 此时A[low] == A[high] ，因此下方的赋值语句不会导致出错
            A[low] = A[high];
        while(low<high && A[low]<=pivot) low++;
            A[high] = A[low];
    }
    A[low] = pivot;
    return low; // 返回存放枢轴的最终位置
}