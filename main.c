#include "product.h"
#include "manager.h"

int main(void){
    int count = 0; // 데이터개수
    int menu = 0;

    Product *p[100];
    int index = 0; // 데이터번호

    count = loadData(p);
    index = count;


    while (1){
        menu = selectProduct();
        if (menu == 0) break;

        if (menu == 1){
            if(count > 0)
                listProduct(p, index);
            else
                printf("데이터가 없습니다.\n");
        }

        else if (menu == 2){
            p[index] = (Product *)malloc(sizeof(Product));
            count += createProduct(p[index++]);
            printf("=>추가됨!\n");
        }

        else if (menu == 3){
            int no = selectDataNo(p, index);
            if(no == 0){
              printf("=> 취소됨!\n");
                continue;
            }
            updateProduct(p[no-1]);
            listProduct(p, index);
        }

        else if (menu == 4){
            int no = selectDataNo(p, index);
            if(no == 0){
                printf("=> 취소됨!\n");
                continue;
            }

            int deleteok;
            printf("정말로 삭제하시겠습니까?(삭제 :1)");
            scanf("%d", &deleteok);
            if(deleteok == 1){
                if(deleteProduct(p[no-1])){
                    p[no-1] = NULL;
                //free(sp[no-1]);
                    count--;
                }
            }
            printf("=>삭제됨!\n");
	}

        else if(menu == 5){
            saveData(p, index);
        }

        else if(menu == 6){
            searchProduct(p, index);
        }
    }
    return 0;
}
