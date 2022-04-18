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

    for(; i < 100; i++){
        p[i] = (Product *)malloc(sizeof(Product));
        //if(feof(fp)) break;
        //if(s[i] == NULL) fclose(fp); break;
        fscanf(fp, "%[^\t]\t", p[i]->name);
        fscanf(fp, "%[^\t]\t", p[i]->desc);
        fscanf(fp, "%[^\t]\t", p[i]->weight);

        if(feof(fp)) break;



        fscanf(fp, "%d", &p[i]->price);
        fscanf(fp, "%d\n", &p[i]->check);

    }
    fclose(fp);
    printf("=> 로딩 성공!\n");
    return i;
} // FILE 불러오기

void searchProduct(Product *p[], int count)
    int scnt = 0;
    char search[20];

    printf("검색할 이름? ");
    scanf("%s", search);

    printf("\nNo            Name Description Weight Price Delivery\n");
    printf("================================================\n");
    for(int i = 0; i < count; i++){
        //if(s[i]->price == -1) continue;
        if(p[i] == NULL) continue;
        if(strstr(p[i]->name, search)){
            printf("%2d ", i+1);
            readProduct(*p[i]);
            scnt++;
        }

