//测试字符c在字符串s中出现的次数
#include<stdio.h>
#define N 20 

int main(int argc, char const *argv[])
{
    int CharWithinStr(char c,char* s);
    char c,s[N];//数组虽未初始化，但会分配栈地址
    printf("Please input a test char:\n");
    scanf("%c",&c); 
    getchar();     
    printf("Please input the test string\n ");
    gets(s); //s should be uninitialized before used in gets(s).因为要取地址
    //scanf("%s",s); %s is receive a char[] that has no space.
    //gets() will add '\0' to the end of string.
    printf("c occur %d times in s",CharWithinStr(c,s));
    return 0;
}

int CharWithinStr(char c,char* s){
    
    int times = 0;
    while(*s){//一定要记得加*，'\0'不是null      
        if(c == *s)
            times++;    
        s++;
    }
    return times;
    
    
}
