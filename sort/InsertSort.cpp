

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