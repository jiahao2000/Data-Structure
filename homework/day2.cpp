#include<stdio.h>
#include<stdlib.h>

void fun(char *&p){ //必须使用引用传递 即在变量名前加一个&，这样能改变p在主函数中的指向
    p = (char*)malloc(100*sizeof(char));
    fgets(p,100,stdin);
}

int main(){
    char *p;
    fun(p);
    puts(p);
    free(p);

    return 0;
}