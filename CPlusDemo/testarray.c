//
//  testarray.c
//  CPlusDemo
//
//  Created by xibei sunny on 2018/12/15.
//  Copyright © 2018 xibei sunny. All rights reserved.
//

#include <string.h>
#include "testarray.h"

void newStrcat(char* src, char* amend);

void removeSpaceViaPointer(char* src);

void removeSpace(char* src, long length);

void findSecondNum();

void testArray() {
    
    int a[] = {1, 2, 3};
    int b[] = {4, 5, 6};
    int c[] = {7, 8, 9};
    
    int* arr[] = {a, b, c};
    //数组arr的首地址
    printf("%p\n", arr);
    //数组arr第一个元素的首地址，这里其实还是一个二级指针
    printf("%p\n", &arr[0]);
    //数组arr第一个元素的值的首地址
    printf("%p\n", a);
    
    //指针数组是一个特殊的二维数组
    //下面测试一下多级指针的操作
    int** p = arr;
    //遍历并打印指针数组
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d， ", arr[i][j]);
        }
        puts("");
    }
    
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            //二级指针的偏移，代表的是数组的行数的移动
            //一级指针的偏移，代表的是列数（具体的元素）的移动
            printf("%d， ", *(*(arr + i) + j));
        }
        puts("");
    }
    
    //多级指针的使用
    int x = 10;
    int y = 20;
    
    int* p1 = &x;
    int** p2 = &p1;
    int*** p3 = &p2;
    
    //这里牢记一句话，*是升维操作，&是降维操作
    printf("x的值为: %d\n", x);
    printf("x的值为: %d\n", *p1);
    printf("x的值为: %d\n", **p2);
    printf("x的值为: %d\n", ***p3);
    
    //这里尝试使用多级指针更改变量的值
    //所有的问题的根源，就是这次CPU的运算，操作的是到底是哪块内存区域
    // p2里面存储的其实是p1的地址，把p2的值改了，也就是说，把p1的指向改了
    // p1中存储的，变成了y的地址
    *p2 = &y;
    printf("x的值为: %d\n", ***p3);
    
    //这里和上面的方式是等价的，因为 *p2 == p1
    p1 = &x;
    printf("x的值为: %d\n", ***p3);
    
    //数组名作为参数传递时，会丢失数组的精度，所以要把数组的精度（长度|维度）作为参数传递到函数中
    
    char ch[] = "hello";
    printf("%lu\n", sizeof(ch));
    printf("%lu\n", strlen(ch));
    
    printf("测试字符串的追加");
    char src[100] = "hello";
    char amend[] = "world";
    newStrcat(src, amend);
    printf("追加之后的字符串结果：%s\n", src);
    
    printf("测试字符串的去除空格操作\n");
    char hello[] = "   h e l  l    o    w  or l   d ! ";
    
    removeSpace(hello, strlen(hello));
    removeSpaceViaPointer(hello);
}

/*使用指针偏移操作字符串*/
void newStrcat(char* src, char* amend) {
    while (*src) {
        src++;
    }
    while (*src++ = *amend++);
}

/*字符串去除空格操作*/
void removeSpaceViaPointer(char* src){
    //定义两个指针，分别记录遍历的位置和有效字符的位置
    char* pre = src;
    char* record = src;
    while (*pre) {
        if (*pre != ' ') {
            //如果当前字符不等于0且不为空格，那么就把当前的地址赋值给记录指针，并且记录指针向前移动
            *record = *pre;
            record ++;
        }
        pre ++;
    }
    printf("%s\n",src);
}

/*使用数组下标取值来实现，这种实现方式比较直观，且便于理解*/
void removeSpace(char* src,long length){
    int i = 0;
    int j = 0;
    
    for (i = 0 ; i < length; i ++) {
        if (src[i] != ' ') {
            src[j] = src[i];
            src[i] = 0;
            j ++;
        }
    }
    src[j] = 0;
    printf("%s\n",src);
}

int findSecondMax(int arr[], int len);

/*有个数组，找出第二大的数，并且打印出来（使用*操作数组元素个数，不要使用[])*/
void findSecondNum(){
    
//    int a[] = {100,99,32,45,21,67,32,68,41,2,13,71};
//    int a[] = {1,2,3,4,5,6,7,8,9,10,11,12};
    int arr[] = {10,9,3,4,5,6,7};
    int length = sizeof(arr)/sizeof(arr[1]);
    
    printf("第二大的数字是 ： %d\n",findSecondMax(arr,length));
    
    //定义三个指针，一个最大值，一个第二大，一个遍历的最前线
//    int* first = a;
//    int* second = a;
//    int* front = a;
//
//    while (length --) {
//        if (*front < *first) {
//            second = first;
//            first = front;
//        }else if(*front < *second){
//            second = front;
//        }
//        front++;
//    }
    //首先，第二小的secondNum的初始值，必须是int的最小值-32767，避免原始数字对逻辑判断的影响
    int secondNum = -32767;
    int* front = arr;
    int* first = arr;
    int* second = &secondNum;
    //这里总的循环次数是length-1
    while (--length) {
        //首先做累加运算，从i=1的位置开始比较
        front ++;
        if (*front > *first) {
            second = first;
            first = front;
        }else if(*front > *second){
            second = front;
        }
    }
    printf("second num is : %d\n",*second);
    //同时，这里可以通过指针的偏移量获取第二大的数字的下标
    int step = second - arr;
    printf("second num location : %d\n",step);
}

int findSecondMax(int arr[], int len){
    int sec_Max = -32767;
    int Max = arr[0];
    for (int i = 1; i < len; i++)
    {
        if (arr[i] > Max)
        {
            sec_Max = Max;
            Max = arr[i];
        }
        else
        {
            if (arr[i] > sec_Max)
                sec_Max = arr[i];
        }
    }
    
    return sec_Max;
}
