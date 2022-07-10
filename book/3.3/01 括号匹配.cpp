#include<stdio.h>
#include<stdlib.h>

bool BracketsCheck(char *str){
    Stack S;
    InitStack(S);
    int i = 0;
    char e;
    while(str[i]!='\0'){
        switch(str[i]){
            case '(': Push(S,str[i]); break;
            case '[': Push(S,str[i]); break;
            case '{': Push(S,str[i]); break;
            case ')':Pop(S,e); if(e != '(') return false;
            case ']':Pop(S,e); if(e != '[') return false;
            case '}':Pop(S,e); if(e != '{') return false;
            default:
                break;
        }
    }
    if(!isEmpty(S)){
        printf("括号不匹配\n");
        return false; 
    }
    else{
        printf("括号匹配");
        return true;
    } 

        
}