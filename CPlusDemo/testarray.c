//
//  testarray.c
//  CPlusDemo
//
//  Created by xibei sunny on 2018/12/15.
//  Copyright © 2018 xibei sunny. All rights reserved.
//

#include "testarray.h"

void testArray(){
    int a[] = {1,2,3};
    int b[] = {4,5,6};
    int c[] = {7,8,9};
    
    int* arr[] = {a,b,c};
    //数组arr的首地址
    printf("%p\n",arr);
    //数组arr第一个元素的首地址，这里其实还是一个二级指针
    printf("%p\n",&arr[0]);
    //数组arr第一个元素的值的首地址
    printf("%p\n",a);
    
    //指针数组是一个特殊的二维数组
    //下面测试一下多级指针的操作
    int** p = arr;
    //遍历并打印指针数组
    for (int i = 0; i < 3; i ++) {
        for (int j = 0; j < 3; j++) {
            printf("%d， ",arr[i][j]);
        }
        puts("");
    }
    
    for (int i = 0; i < 3; i ++) {
        for (int j = 0; j < 3; j++) {
            //二级指针的偏移，代表的是数组的行数的移动
            //一级指针的偏移，代表的是列数（具体的元素）的移动
            printf("%d， ",*(*(arr + i) + j));
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
    printf("x的值为: %d\n",x);
    printf("x的值为: %d\n",*p1);
    printf("x的值为: %d\n",**p2);
    printf("x的值为: %d\n",***p3);
    
    //这里尝试使用多级指针更改变量的值
    //所有的问题的根源，就是这次CPU的运算，操作的是到底是哪块内存区域
    //p2里面存储的其实是p1的地址，把p2的值改了，也就是说，把p1的指向改了
    //p1中存储的，变成了y的地址
    *p2 = &y;
    printf("x的值为: %d\n",***p3);
    
    //这里和上面的方式是等价的，因为 *p2 == p1
    p1 = &x;
    printf("x的值为: %d\n",***p3);
}
