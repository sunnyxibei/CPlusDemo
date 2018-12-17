//
//  teststring.c
//  CPlusDemo
//
//  Created by xibei sunny on 2018/12/17.
//  Copyright © 2018 xibei sunny. All rights reserved.
//

#include <string.h>
#include "teststring.h"

/*在字符串中查找定位一段字符串，双重循环+判断*/
char* findString(char* src,char* dst){
    //同样，定义两个指针，一个指向循环的最前线，一个指向目标字符串的首地址
    char* fpointer;
    char* rpointer;
    
    while (*src) {
        fpointer = src;
        rpointer = dst;
        while (*rpointer) {
            if (*fpointer == *rpointer) {
                fpointer ++;
            }else{
                break;
            }
            rpointer ++;
        }
        if (*rpointer == 0) {
            //此时获取到匹配字符串的位置
            return src;
        }
        src ++;
    }
    return NULL;
}
