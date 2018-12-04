//
//  main.c
//  CPlusDemo
//
//  Created by xibei sunny on 2018/11/7.
//  Copyright © 2018 xibei sunny. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//#include 有以下两种写法，其中第一种适用于引用标准库函数，第二种用于引入自己定义的函数
//#include <文件名>
//#include "文件名"
#define MAX 100

int main(int argc, const char * argv[]) {
    printf("Hello, World!\n");
    //system函数用于执行一个shell命令，和shell窗口里面执行一致，可以通过分号分割多个命令
    system("git --version");
    system("cd /usr/include/;ls -l | grep stdio.h");
    system("python --version");
    printf("%d\n",MAX);
   
    short x = 0;
    int y = 1;
    long z = 2L;
    printf("sizeof(x) = %lu\n",sizeof(x));
    printf("sizeof(y) = %lu\n",sizeof(y));
    printf("sizeof(y) = %lu\n",sizeof(z));
    
    char ch = 'a';
    printf("%c\n",ch);
    //打印字符型变量的askii码值
    printf("%d\n",ch);
    printf("sizeof(ch) = %lu\n",sizeof(ch));
    
    //测试转义字符
    printf("\a\n");
    printf("\\\"\n");
    
    //打印变量的内存地址
    printf("mem(x) = %p\n",&x);
    
//    int a;
//    printf("please input a integer number \n");
//    scanf("%d",&a);
//    switch (a) {
//        case 1:
//            printf("星期一\n");
//            break;
//        case 2:
//            printf("星期二\n");
//            break;
//        case 3:
//            printf("星期三\n");
//            break;
//        case 4:
//            printf("星期四\n");
//            break;
//        case 5:
//            printf("星期五\n");
//            break;
//        case 6:
//            printf("星期六\n");
//            break;
//        default:
//            printf("星期天\n");
//            break;
//    }
//
    //一维数组初始化的方式
    //全局数组若不初始化，默认初始化为零 局部l数组若不初始化，默认初始化为随机值
    
    //demo 一维数组的反转
//    int arr[] = { 1, -2, 3,- 4, 5, -6, 7, -8, -9, 10 };
//    int length = sizeof(arr)/sizeof(arr[0]);
//    printf("原始数组为:\n");
//    for(int x = 0; x < length; x++ ){
//        printf("arr[%d] = %d\n",x,arr[x]);
//    }
//
//    //两个标记位i和j，分别从两端开始遍历
//    int i = 0;
//    int j = length -1;
//    while(i < j){
//        //交换两个位置上的数组元素
//        int temp = arr[i];
//        arr[i] = arr[j];
//        arr[j] = temp;
//        i++;
//        j--;
//    }
//
//    printf("反转数组为:\n");
//    for(int y = 0; y < length; y++ ){\
//        printf("arr[%d] = %d\n",y,arr[y]);
//    }
//
//    printf("arr = %p\n",arr);
//
    
//    //定义了一个二维数组，名字叫a
//    //二维数组是本质上还是一维数组，此一维数组有3个元素
//    //每个元素又是一个一维数组int[4]
//    int a[3][4] = { 1, 2, 3, 4 , 5, 6, 7, 8, 9, 10, 11, 12  };
//
//    //数组名为数组首元素地址，二维数组的第0个元素为一维数组
//    //第0个一维数组的数组名为a[0]
//    printf("a = %p\n", a);
//    printf("a[0] = %p\n", a[0]);

//    char str1[] = {'a',' ','b','c'};
//    printf("%s\n",str1);
//
//    char str2[] = {'a',' ','b','c','\0'};
//    printf("%s\n",str2);
//
//    //字符串处理以‘\0’(ASCII码值=0)作为结束符，后面的'h', 'l', 'l', 'e', 'o'不会输出
//    char c3[] = { 'c', ' ', 'p', 'r', 'o', 'g', '\0', 'h', 'l', 'l', 'e', 'o', '\0'};
//    printf("c3 = %s\n", c3);
    
//    //不指定长度, 没有0结束符，有多少个元素就有多长
//    char buf[] = { 'a', 'b', 'c' };
//    printf("buf = %s\n", buf);    //乱码
//
//    //指定长度，后面没有赋值的元素，自动补0
//    char buf2[100] = { 'a', 'b', 'c' };
//
//    printf("buf2 = %s\n", buf2);
    
//    char * arr = "hello hahaha";
//    printf("%s\n", arr);
//    //使用string.h中的strlen获取字符串的长度
//    //字符串的长度实际上是第一个ascii码0之前的字符的个数
//    printf("%lu\n",strlen(arr));
    
    long mill;
    time(&mill);
    printf("%ld\n",mill);

    return 0;
}
