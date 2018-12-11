//
//  test.h
//  CPlusDemo
//
//  Created by xibei sunny on 2018/12/10.
//  Copyright © 2018 xibei sunny. All rights reserved.
//
// 该声明是为了避免重复引用|嵌套引用
//#pragma once 这种方式只适用于Windows unix要使用下面的声明方式，避免重复|嵌套引用
#ifndef test_h
#define test_h

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>

void printRandom();

void testPointer();

void testPointerWithArray();

void testPointerOperator();
 
#endif
