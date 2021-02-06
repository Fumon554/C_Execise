//三天打鱼两天晒网，从1990.1.1开始，在某一天中是打鱼还是晒网
#include<stdio.h>

typedef struct Date{
    int year;
    int month;
    int day;
}Date;

int main(int argc, char const *argv[])
{
    int NetOrFish(Date,Date);
    Date date = {1990,1,1};
    Date now;
    printf("请输入年月日:（用点间隔）\n");
    do{
        scanf("%d.%d.%d",&now.year,&now.month,&now.day);
        if(now.year < 1990 || now.month < 1 || now.month > 12 || now.day < 1 || now.day > 31)
            printf("输入有误，请重新输入：\n");
    } while (now.year < 1990 || now.month < 1 || now.month > 12 || now.day < 1 || now.day > 31);//do while最后要加分号
    NetOrFish(date,now);      
    return 0;
}
//Struct cannot compare directly.
//先算到当年的1.1（闰年366），然后按每月来算（逐加，每月天数不同）
//按上下半年算简便，略去了二月(分的不好会影响冗余量)
//不用改变实参的值，因此值传递即可

int NetOrFish(Date startday,Date oneday){
    //判断年份和月份是否非法
    //if(oneday.year < startday.year || oneday.month < startday.month || oneday.month > 12)
    //    return printf("输入信息有误\n");
    //days为从1990.1.1开始至今经过的总天数，days最少是一天，months为算月时遍历使用
    int days = 1,months = oneday.month,years = oneday.year;
    //算闰年，此处可以改善，一年年加太慢了
    while(years > startday.year){
        if((years % 4 == 0 && years % 100 != 0) || years % 400 == 0)//注意有两种情况
            days += 366;
        else
            days += 365;
        years--;
    }

    //算月（按闰年分）
    // if(oneday.year % 4 == 0){//闰年
    //     while(months > startday.month){           
    //         if(months < 8)
    //             if(months % 2 == 0)
    //                 if(months == 2)
    //                     days += 29; //非闰年是28
    //                 else
    //                     days += 30         
    //             else
    //                 days += 31;    
    //         else
    //             if(months % 2 == 0)
    //                 days += 31;               
    //             else
    //                 days += 30; 
    //         months++
    //     }
    // }

    //算月（按上下半年分），此处有些费时，可以改进
    if(oneday.month < 8){//上
        while(months > startday.month){
            if(months % 2 == 0)
                if(oneday.month == 2)
                    if(oneday.year % 4 == 0)
                        days += 29;
                    else 
                        days += 28;
                else
                    days += 30;
            else
                days += 31;
            months++;
        }
    }
    else{//下
        while(months > startday.month){
            if(months % 2 == 0)
                days += 31;
            else
                days += 30;
            months++;
        }
    }
    //算日,并加上日的错误判断
    if(oneday.month < 8){//上半年
        if(oneday.month % 2 == 0)
            if(oneday.month == 2)
                if(oneday.year % 4 == 0 && oneday.day >= 1 && oneday.day <= 29)
                        days += oneday.day;  
                else if(oneday.day >= 1 && oneday.day <= 28)//大于29也大于28
                    days += oneday.day-1;//当月的一号已算进去所以减去
                else
                    return printf("输入信息有误\n");//调用printf会返回一个整型数4，若错误则返回-1
            else if(oneday.day >= 1 && oneday.day <= 30)
                days += oneday.day-1;
            else
                return printf("输入信息有误\n");
        else if(oneday.day >= 1 && oneday.day <= 31)
            days += oneday.day-1;
        else
            return printf("输入信息有误\n");
    }
    else{//下半年
        if(oneday.month % 2 == 0 && oneday.day >= 1 && oneday.day <= 31)
            days += oneday.day;
        else if(oneday.day >= 1 && oneday.day <= 30)
            days += oneday.day;
        else
            return printf("输入信息有误\n");
    }

    //一个周期五天
    days = days % 5;
    if(days == 4 || days == 0)
        printf("晒网\n");
    else
        printf("打鱼\n");
    return 0;  
}
