//
//  operatordemo.c
//  CPlusDemo
//
//  Created by xibei sunny on 2018/12/15.
//  Copyright © 2018 xibei sunny. All rights reserved.
//

#include "operatordemo.h"

/*测试指针运算*/
void testOperator(){
    
}

/*测试字符串拷贝，分别使用三种方式：数组，指针，指针简化*/
void strCopy(char* src , char* dst){
    /*第一种方式，使用数组下标取值*/
//    int i = 0;
//    while (src[i]) {
//        dst[i] = src[i];
//        i ++;
//    }
//    dst[i] = 0;
    //第二种方式，使用指针偏移量
//    while (*src) {
//        *dst = *src;
//        src++;
//        dst++;
//    }
//    *dst = 0;
    //第三种方式，简化版指针偏移方式
    //这里其实还是分了三个过程
    //第一步，做累加运算
    //第二步，把src指针内存的值赋值给dst内存区域
    //第三步，根据赋值运算的结果，做while循环的判断
    while (*dst++ = *src++);
    
    //指针的运算，通常只认为指针的加法|减法（偏移）是有意义的，这种操作类似于数组的寻址
    //另外，判空和逻辑运算也是有意义的
    //注意 NULL 是一个宏定义常量
}
