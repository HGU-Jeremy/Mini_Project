#ifndef _PRODUCT_H
#define _PRODUCT_H

#include <stdio.h>
#include <stdlib.h>

typedef struct{
    char name[20]; // 이름
    char desc[20]; // 설명
    char weight[20]; // 중량
    int price; // 가격
    int check; // 배송방법 (1. 새벽배송 / 2. 택배배송)
} Product;

int createProduct(Product *p);
void readProduct(Product p);
void listProduct(Product *p[], int count);
int updateProduct(Product *p);
int deleteProduct(Product *p);
int selectProduct();
int selectDataNo(Product *p[], int count);


#endif
