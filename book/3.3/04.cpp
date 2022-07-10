

Queue q; //过江渡船队列
Queue q1; //客车队列
Queue q2; //货车队列

void manager(){
    int i = 0; j = 0;
    while(j<10){
        if(!QueueEmpty(q1)&&i<4){
            DeQueue(q1,x);
            EnQueue(q,x);
            i++;
            j++;
        }
        else if(!QueueEmpty(q2)&& i == 4){
            DeQueue(q2,x);
            EnQueue(q,x);
            j++;
            i=0;
        }
        else if(QueueEmpty(q1)&&!QueueEmpty(q2)&&j<10)
        {
            DeQueue(q2,x);
            EnQueue(q,x);
            j++;
        }
        else if(!QueueEmpty(q1)&&QueueEmpty(q2)&&j<10)
        {
            DeQueue(q1,x);
            DeQueue(q,x);
            j++;
        }
        else if(QueueEmpty(q1)&&QueueEmpty(q2)&&j<10){
            j=11;//货车和客车的数量加起来不足10辆
        }
}