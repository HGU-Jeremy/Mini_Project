#include "product.h"
#include "manager.h"
#define DEBUG

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
	    #ifdef DEBUG
		printf("기존에 저장된 데이터 유무 확인 단계\n");
	    #endif
	    if(count > 0)
                listProduct(p, index);
            else
                printf("데이터가 없습니다.\n");
        }

        else if (menu == 2){
	    #ifdef DEBUG
		printf("새로운 데이터 추가\n");
	    #endif
            p[index] = (Product *)malloc(sizeof(Product));
            count += createProduct(p[index++]);
            printf("=>추가됨!\n");
        }

        else if (menu == 3){
	    #ifdef DEBUG
		printf("데이터 수정하기\n");
	    #endif
            int no = selectDataNo(p, index);
            if(no == 0){
              printf("=> 취소됨!\n");
                continue;
            }
            updateProduct(p[no-1]);
            listProduct(p, index);
        }

        else if (menu == 4){
	    #ifdef DEBUG
		printf("데이터 삭제하기\n");
	    #endif
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
	    #ifdef DEBUG
		printf("데이터 저장하기\n");
	    #endif	
            saveData(p, index);
        }

        else if(menu == 6){
	    #ifdef DEBUG
		printf("데이터 검색하기\n");
	    #endif
	    printf("무엇을 검색하시겠습니까?\n");
            printf("1. 이름\n");
            printf("2. 가격\n");
            printf("3. 배송방법\n");
            printf("\n=> 원하는 옵션은? ");
            int search;
            scanf("%d", &search);
            
            if (search == 1) searchProduct(p, index);
            else if (search == 2) searchPrice(p, index);
            else if (search == 3) searchCheck(p, index);
        }
    }
    return 0;
}
