// 双向冒泡算法

#define ElemType int

void swap(int &a, int &b){
    int temp = a ;
    a = b;
    b = temp;
}

void DoubleBubbleSort(ElemType A[], int n){
    int i = 0;
    int j = n;
    while(i<j){
        bool flag = false;
        for(i;i<j;i++){
            if(A[i]>A[i+1])
            {
                swap(A[i],A[i+1]);
                flag = true;
            }
        }
        if(flag == false)
            return ;
        j--;
        flag = false;
        for(j;j>i;j--){
            if(A[j]<A[j-1])
            {
                swap(A[j],A[j-1]);
                flag = true;
            }
        }
        if(flag == false)
            return ;
        i++;
    }
    
}