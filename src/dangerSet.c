#include <stdio.h>

/* 위험 단계에 따른 추천 행동 요령 */
void dangerSet(int level){
    switch(level) {
        // 위험 단계를 1,2,3 단계 4, 5, 6 단계 7, 8, 9 단계 10 단계로 구별하여 그에 맍는 행동 요령을 추천한다.
        case 1 :
        case 2 :
        case 3 : printf("위험 단계는 아니지만 지출 관리를 하는 것을 추천합니다.\n"); break;
        case 4 :
        case 5 :
        case 6 : printf("고위험까지는 아니지만 불필요한 지출은 최대한 줄이는 것을 추천합니다.\n"); break;
        case 7 :
        case 8 :
        case 9 : printf("고위험 단계입니다. 필요한 지출을 제외하고는 지출을 줄이는 것을 추천합니다.\n"); break;
        case 10 : printf("최고 위험 단계입니다. 지출을 최소화하는 것을 권고드립니다.\n");
    }
}
