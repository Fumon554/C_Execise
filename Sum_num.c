//求num各项之和
//num可以是小数
//（未实现）功能plus：还可加入负数
#include<stdio.h>
#include<math.h>
//double fmod(double,double)

int main(int argc, char const *argv[])
{
    int Sum_N(double);
    double num;
    printf("please input a +number:\n");
    scanf("%lf",&num); 
    int sum = Sum_N(num);
    printf("num各项之和为%d",sum);
    return 0;
}
int Sum_N(double num){
    //除以10，若余数为本身，则为最后一个；反之取商的整数部分
    //使用fmod求除以整数部分的余数得出小数部分，而%只能两边只能是整型；乘以10取整数部分在用小数部分继续，直到小数为0
    int integer = (int)num;
    double decimal;
    if(integer == 0)
        decimal = num;
    else
        decimal = fmod(num,integer);//integer不能为0
    printf("%d,%f\n",integer,decimal);//用%lf会显示0.0000... 因为printf没有lf格式 操
    int sum = 0;
    int remainder;
    //整数部分
    while(integer != 0){
        remainder = integer % 10;  
        sum += remainder;
        integer = integer / 10;
    }
    //小数部分
    while(decimal > 0){//浮点型不能做相等比较，因此程序死循环
        decimal *= 10;
        integer = (int)decimal;
        sum += integer;
        decimal = fmod(decimal,integer) ;
    }
    return sum;
}

