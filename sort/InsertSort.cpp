

#define ElemType int

void InsertSort(ElemType A[], int n){
    int i, j;
    for(i = 2 ; i <= n; i++){
        if(A[i]<A[i-1]){ //如果A[i]的关键字小于其前驱，将A[i]插入前面已排序序列
            A[0] = A[i];// 复制为哨兵，
            for( j = i - 1; A[0]<A[j]; j--)//如果A[0]<A[j]的话，将A[j]向后移动，结束循环时，j指向要插入位置的前一个位置
                A[j+1] = A[j];
            A[j+1] = A[0];
        }
    }
}

// 折半插入排序
// 折半插入排序是稳定的
void InsertSort2(ElemType A[], int n){
    int i, j, low, high, mid;
    for(i = 2; i<=n; i++){
        if(A[i]<A[i-1]){
            A[0] = A[i];
            low = 1;
            high = i - 1;
            while(low<=high){//使用折半查找找到要插入的位置；结束条件为low>high,此时插入位置即为low或者high+1
                mid = (low+high)/2;
                if(A[mid] > A[0]) high = mid - 1;
                else low = mid + 1; 
            }
            for(j = i -1 ; j >= high + 1; j--) //将插入位置之后的元素全部后移一位
                A[j+1] = A[j];
            A[high+1] = A[0];
        }
    } 
}

// 希尔排序
// 将表里的元素拆分为多个子表，对每个子表进行直接插入排序
// 希尔排序不稳定
// 只能基于顺序表实现，因为需要进行随机访问

void ShellSort(ElemType A[], int n){
    int d, i, j;
    for(d = n/2;d>=1;d = d/2){
        for(i = d+1; i<=n;++i){//i++实际上是在交替的处理不同子表中的元素
            A[0] = A[i];
            for(j = i - d; j>0&&A[0]<A[j];j-=d){
                A[j+d] = A[j];
            }
            A[j+d] = A[0];
        }
    }
}