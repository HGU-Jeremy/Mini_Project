#include "product.h"

int createProduct(Product *p){
    printf("이름은? ");
    scanf("%[^\n]", p->name);
    getchar();

    printf("설명은? ");
    scanf("%[^\n]", p->desc);
    getchar();

    printf("무게는? ");
    scanf("%[^\n]", p->weight);
    getchar();

    printf("가격은? ");
    scanf("%d", &p->price);
    getchar();

    printf("배송방법은? (1. 새벽배송 / 2. 택배배송) ");
    scanf("%d", &p->check);
    getchar();

    return 1;
} // 제품 추가

void readProduct(Product p){
    printf("	%8s %11s %4s %5d %2d\n", p.name, p.desc, p.weight, p.price, p.check);
} // 제품 정보 읽어오기

void listProduct(Product *p[], int count){
    printf("\nNo	    Name Description Weight Price Delivery\n");
    printf("================================================\n");
    for(int i = 0; i < count; i++){
        if(p[i] == NULL) continue;
        printf("%2d ", i+1);
        readProduct(*p[i]);
    }
} // 저장되있는 제품 리스트 출력

int updateProduct(Product *p){
    printf("새 이름은? ");
    scanf("%[^\n]", p->name);
    getchar();

    printf("새 설명은? ");
    scanf("%[^\n]", p->desc);
    getchar();

    printf("새 무게는? ");
    scanf("%[^\n]", p->weight);
    getchar();

    printf("새 가격은? ");
    scanf("%d", &p->price);
    getchar();

    printf("새 배송방법은? (1. 새벽배송 / 2. 택배배송) ");
    scanf("%d", &p->check);
    getchar();

    return 1;
} // 제품 정보 수정

int deleteProduct(Product *p){
    //p->name = "-1";
    //p->desc = "-1";
    //p->weight = "-1";
    p->price = -1;
    p->check = -1;
    return 1;
} // 제품 정보 삭제

int selectProduct(){
    int menu;
    printf("\n*** 제레미 미니 마켓 ***\n");
    printf("1. 상품조회\n");
    printf("2. 상품추가\n");
    printf("3. 상품수정\n");
    printf("4. 상품삭제\n");
    printf("5. 파일저장\n");
    printf("6. 상품검색\n");
    printf("0. 종료\n\n");
    printf("=> 원하는 옵션은? ");
    scanf("%d", &menu);
    getchar();
    return menu;
} // 프로그램 기본 UI 출력

int selectDataNo(Product *p[], int count){
    int no;
    listProduct(p, count);
    printf("번호는 (취소 :0)? ");
    scanf("%d", &no);
    getchar();
    return no;    
} // 수정 및 삭제에 필요한 특정 숫자 받기
