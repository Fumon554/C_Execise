//strcpy()函数实现
#include <stdio.h>
int my_strcpy_s(char*,int,const char*);
int main(int argc, char const *argv[])
{
    int result;
    char dest[] = "tian";
    char scr[] = "liumk";
    result = my_strcpy_s(dest,5,scr);
    if(!result)
        printf("Copying is successful\n");
    else
        printf("Failed\n");
    return 0;
}

int my_strcpy_s(char* Dest,int Size,const char* Src){ //const point var cannot vary.
    int i;
    if((!Dest && !Src) || (Size == 0))
        return 1;
    for(i = 0;i < Size;i++){
        if(*(Src+i) == '\0'){
            *(Dest+i) = '\0';
            return 0;
        }
        else
        {
            *(Dest+i) = *(Src+i);
        }
    }
    return 1;
}
