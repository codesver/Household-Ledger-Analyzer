#include <stdio.h>

#include "lastDay.h"

#define MONTH_V     12
#define DAY_V       31
#define SPENDC_V    9

/* 선택 월의 지출 입력 현황을 확인하는 함수 */
void showSpend(int y[MONTH_V][DAY_V][SPENDC_V], char *contentS[SPENDC_V]) {

    /* 변수 */
    int selectMonth;                                            // 지출 현황을 확인하고자 하는 달을 저장하는 정수형 변수

    /* 달 선택 */
    printf("현황을 확인하고자 하는 월을 입력하세요.\n");
    printf("월 : ");
    scanf("%d", &selectMonth);
    if (selectMonth > MONTH_V){                                    // 올바른 월을 입력하지 않으면 메뉴 화면으로 초기화
        printf("올바른 월 입력이 아닙니다. Menu 화면으로 넘어갑니다.\n\n");
        return;
    }

    /* 선택 월의 지출 입력 현황 출력 반복문 */
    printf("< %d월 달의 지출 현황 >\n", selectMonth);
    printf("==============================================================\n");
    for (int i = 0; i < lastDay(selectMonth); i++){
        printf("%2d일\n", i + 1);
        for (int j = 0; j < SPENDC_V; j++){
                printf("%-s : %7d원 ", contentS[j], y[selectMonth - 1][i][j]);
                if ((j != 0) && ((j + 1) % 3 == 0))
                    printf("\n");
        }
        printf("\n");
    }
    printf("==============================================================\n\n");
}
