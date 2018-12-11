//
//  test.c
//  CPlusDemo
//
//  Created by xibei sunny on 2018/12/10.
//  Copyright © 2018 xibei sunny. All rights reserved.
//

#include "test.h"

/* test 调用系统函数，生成随机数
 * 1. 使用time函数获取当前时间戳，作为种子数
 * 2. 通过srand函数设定种子数
 * 3. 通过rand函数获取随机数
 */
void printRandom(){
    
    //使用当前的时间戳，作为种子数
    srand((unsigned int)time(NULL));
    printf("%s\n","开始生成随机数");
    for (int i = 0; i < 100; i++) {
        printf("第%d个随机数是 : ",i);
        printf("%d\n",rand() % 100 + 1);
    }
    printf("%s\n","生成随机数完成");
}

/*
 * 测试C语言中的指针以及指针变量的使用
 */
void testPointer(){
    
    int a = 0;
    int b = 10;
    printf("%p\n",&a);
    printf("%p\n",&b);
    
    //定义一个指针变量
    int *p;
    //将a的地址赋值给指针变量p，现在p指针指向变量a的d内存地址
    p = &a;
    printf("%d\n",*p);
    
    char arr[] = {'h','e','l','l','o','\0'};
//    char *ch[6];
//    ch[1] = &arr;
    printf("%s\n",arr);
    printf("%p\n",&arr);
    //question？指向数组的指针如何声明，指针的地址应该指向的是数组第一个元素的地址（首地址）
    //指向数组的指针变量类型，也是一个指针数组，每个指针指向数组对应下标元素的内存地址
    //数组的指针变量，只是一个变量，而不是一个数组
    char (*pointer)[6] = &arr;
    printf("%s\n",*pointer);
    
    //通过指针间接修改变量的值
    printf("%p\n",&(arr[2]));
    printf("%p\n",pointer[2]);
    //arr[2] = 'a';
    (*pointer)[2] = 'a';
    printf("%s\n",arr);
    printf("%s\n",*pointer);
    
    //测试指针变量的sizeof
    //所有的指针变量，占用的内存空间都是32bit（32位操作系统）或者64bit(64位操作系统)
    int *p1;
    char *p2;
    double *p3;
    char **p4;
    printf("p1占用的内存空间 : %lu\n",sizeof(p1));
    printf("p2占用的内存空间 : %lu\n",sizeof(p2));
    printf("p3占用的内存空间 : %lu\n",sizeof(p3));
    printf("p4占用的内存空间 : %lu\n",sizeof(p4));
    
    //C语言中，可以把NULL赋值给此指针，这样就标志此指针为空指针，没有任何指针
    //其中NULL是一个值为零的宏常量
    p1 = NULL;
    
    //测试万能指针的使用
    void *allKey = NULL;
    int num = 10;
    allKey = &num;
    printf("%d\n",*((int *)allKey));
    
    int aaa = 10010;
    //const用来修饰指针的类型，效果是，指针指向内存区域的值不可以被修改，但是指针变量本身可以被修改
    const int * intPointer;
    //const用来修饰变量的类型，那么指针变量本身不可以被修改（重新指向），但是内存地址中的值可以被修改
    int * const intPointer2 = &num;
    *intPointer2 = 200;
    printf("intPointer2指针指向的内存区域的值为 ： %d\n",*intPointer2);
    //指针变量本身和指针变量指向的内存区域的值都不能修改，但是可以通过二级指针修改
    const int * const intPointer3;
    
    intPointer = &aaa;
    aaa = 10011;
    //由下面的用例可以看出来，const修饰的指针变量，其实就是一个指针常量，不能修改指针地址里面的值，但是可以修改指针的指向
    //其实这就是语法层面上的一个限定，我们通过给aaa赋新的值，还是可以修改这个内存空间的值|或者通过二级指针，也可以修改
    //* intPointer = 10012;
    printf("%d\n",*intPointer);
    int bbb = 10086;
    intPointer = &bbb;
    printf("%d\n",*intPointer);
    
    printf("测试万能指针\n");
    int ske = 100;
    void * nothing = &ske;
    //把万能指针赋值给指定类型的指针，居然不需要强制类型转换
    int * intP = nothing;
    printf("nothing = %d\n",*((int * )nothing));
    printf("intP = %d\n",*intP);
}

/*测试通过指针操作数组*/
void testPointerWithArray(){
    int a[] = {1,2,3,4,5,6,7,8,9,0};
    //打印数组的元素
    int lenght = sizeof(a)/sizeof(a[1]);
    for (int i = 0; i < lenght; i ++) {
        printf("%d\n",a[i]);
    }
    
    //也就是说，数组变量本身就是一个指针变量，该指针变量指向数组的第一个元素的内存地址
    int *p = a;
    
    //通过指针偏移取操作数组元素
    //这种方式理论上看，比上面一种方式更容易理解
    for (int i = 0; i < lenght; i ++) {
        *(p+i) = i * 2;
    }
    for (int i = 0; i < lenght; i ++) {
        printf("%d\n",*(p+i));
    }
    for (int i = 0; i < lenght; i ++) {
        printf("%d\n",a[i]);
    }
}

/*测试指针运算*/
void testPointerOperator(){
    //指针的加法运算（偏移），实际偏移一个相同类型的指针的size
    int a = 100;
    int *p = &a;
    printf("%p\n",p);
    p += 2;
    printf("%p\n",p);
    //从打印的结果来看，是偏移了8个字节
    
    //通过改变指针指向，来操作数组元素
    int arr[] = {1,2,3,4,5,6,7,8,9,0};
    //打印数组的元素
    int lenght = sizeof(arr)/sizeof(arr[1]);
    int *p1 = arr;
    for (int i = 0; i < lenght; i ++) {
        printf("%d\n",*p1++);
    }
    
    int * p11 = &arr[1];
    int * p12 = &arr[2];
    long n1 = p12 - p11;
    long n2  = (long)p12 - (long)p11;
    printf("n1 = %ld , n2 = %ld \n",n1,n2);
    
    // * 取值操作符，降维操作
    // & 取地址操作，升维操作
    // 注意，定义指针类型时，要和变量类型保持一致
    // 非法的间接寻址
}
