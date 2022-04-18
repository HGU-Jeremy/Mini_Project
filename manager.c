#include <string.h>
#include "product.h"

void saveData(Product *p[], int count){
    FILE *fp;
    fp = fopen("product.txt", "wt");

    for(int i = 0; i < count; i++){
        if(p[i] == NULL) continue;
        fprintf(fp, "%s\t %s\t %s\t %d %d\n", p[i]->name, p[i]->desc, p[i]->weight, p[i]->price, p[i]->check);
    }

