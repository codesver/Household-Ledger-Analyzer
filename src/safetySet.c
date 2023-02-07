#include <stdio.h>

/* 안정성 단계에 따른 추천 행동 요령 */
void safetySet(int level){
    // 안정성 단계를 1, 2 단계 3, 4, 5단계 6, 7, 8단계 9, 10단계로 구별하여 그에 맞는 행동 요령을 추천한다.
    switch(level) {
        case 1 :
        case 2 : printf("소득이 지출보다 많지만 이 이상의 지출은 자제하시길 바랍니다.");
        case 3 :
        case 4 :
        case 5 : printf("적절한 소비 생활입니다. 대출금 조기 상환을 하시길 추천드립니다.");
        case 6 :
        case 7 :
        case 8 : printf("지출 대비 소득이 높습니다. 적금을 통해 돈을 모으시는 것을 추천드립니다.");
        case 9 :
        case 10 : printf("지출 대비 소득이 상당히 높습니다. 삶의 질을 높이기 위한 지출을 하는 것을 추천드립니다.");
    }
}
