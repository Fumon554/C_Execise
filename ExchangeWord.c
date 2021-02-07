#include <stdio.h>
#define MAXSIZE 20  //数组长度
void exchange(char*,char*);
int main(int argc, char const *argv[])
{
    char pln[MAXSIZE] = "AM I OLDER THAN YOU";
    char pOut[MAXSIZE];
    puts(pln);
    exchange(pln,pOut);
    puts(pOut);
    //printf("%s\n",pOut);
    return 0;
}

void exchange(char* pln,char* pOut){
    char *pO,*pA,*pN,*p = pln;
    int len = 0,lenN,lenA,white = 1,flagA = 0;
    //flag：首字母为A则置1，C语言没有布尔型
    //len记录每个单词的长度，lenA和lenN分别为A开头和以N结尾的单词的长度，以便找到每个单词的首地址
    //white指当前字符是否为空格
    //pO:输出字符串，pA、pN分别为A开头和以N结尾的单词的首地址，p为临时
    while (*p)
    {
        if(*p == 'A' && white){
            pA = p;
            flagA = 1;
        }
        if(*p =='N' && (*(p+1) == 32 || !*(p+1))){
            lenN = len+1;
            pN = p - len;
        }
        if(white && *p != 32)
            white = 0;
        else if(*p == 32)
            white = 1;
        if(flagA && white){
            lenA = len;
            flagA = 0;
        }
        if(white == 1)
            len = 0;
        else 
            len++;
        
        p++;
    }
    p = pln;
    pO = pOut;

    //A开头的单词在N结尾的单词前面
    if(pA < pN){
        while (pA > p)  //打印A以前的
            *(pO++) = *(p++);
        while (*pN != 32 && *pN)    //打印N
            *(pO++) = *(pN++);
        p = pA + lenA;
        pN = pN - lenN;
        while (p < pN)  //打印原字符串中N之前的
            *(pO++) = *(p++);
        while (*pA != 32 && *pA)    //打印A
            *(pO++) = *(pA++);  
        p = pN + lenN;
    }

    else{
        while (pN > p)  
            *(pO++) = *(p++);
        while (*pA != 32 && *pA)
            *(pO++) = *(pA++);
        p = pN + lenN;
        pA = pA - lenA;
        while (p < pA)
            *(pO++) = *(p++);
        while (*pN != 32 && *pN)
            *(pO++) = *(pN++);
        p = pA + lenA;
    }

    while (*p)  //打印剩下的
            *(pO++) = *(p++);
        *pO = '\0';

    return;
}
