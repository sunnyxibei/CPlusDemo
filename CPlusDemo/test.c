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
    
    srand((unsigned int)time(NULL));
    printf("%s\n","开始生成随机数");
    for (int i = 0; i < 100; i++) {
        printf("第%d个随机数是 : ",i);
        printf("%d\n",rand() % 100 + 1);
    }
    printf("%s\n","生成随机数完成");
}
