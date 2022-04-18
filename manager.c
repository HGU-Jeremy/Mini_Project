#include <string.h>
#include "product.h"

void saveData(Product *p[], int count){
    FILE *fp;
    fp = fopen("product.txt", "wt");

    for(int i = 0; i < count; i++){
        if(p[i] == NULL) continue;
        fprintf(fp, "%s\t %s\t %s\t %d %d\n", p[i]->name, p[i]->desc, p[i]->weight, p[i]->price, p[i]->check);
    }

    fclose(fp);
    printf("=> 저장됨! ");
} // FILE 저장


int loadData(Product *p[]){
    int i = 0;
    FILE *fp;
    fp = fopen("product.txt", "rt");

    if (fp == NULL){
        printf("=> 파일 없음\n");
        return 0;
    }

