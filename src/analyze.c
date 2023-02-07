#include <stdio.h>

#include "rate.h"
#include "dangerSet.h"
#include "safetySet.h"

#define MONTH_V     12
#define DAY_V       31
#define INCOMEC_V   3
#define SPENDC_V    9

int rate(int level, int income);
void dangerSet(int level);
void safetySet(int level);

/* 소득, 지출 분석 함수 */
void analyze(int yi[MONTH_V][DAY_V][INCOMEC_V], int ys[MONTH_V][DAY_V][SPENDC_V], char *contentI[INCOMEC_V], char *contentS[SPENDC_V]) {
    /* 변수 */
    int selectMonth;                                            // 분석하고자 하는 월 선택

    int totalIncome[MONTH_V] = {0};                             // 월별 총 소득 저장 1차원 배열 (합계를 위해 0으로 초기화)
    int totalSpend[MONTH_V] = {0};                              // 월별 총 지출 저장 1차원 배열 (합계를 위해 0으로 초기화)

    int sumContentI[MONTH_V][INCOMEC_V] = {0};                  // 월별, 내역별로 소득을 저장하는 2차원 배열 (합계를 위해 0으로 초기화)
    int sumContentS[MONTH_V][SPENDC_V] = {0};                   // 월별, 내역별로 지출을 저장하는 2차원 배열 (합계를 위해 0으로 초기화)

    int difference[MONTH_V];                                             // 월별 소득, 지출 차액
    int rateLevel;                                                    // 적자 위험 단계


    /* 각 월별 소득, 지출을 내역별로 합계 내는 중첩 반복문 */
    for (int i = 0; i < MONTH_V; i++) {
        for (int j = 0; j < DAY_V; j++) {
            for (int k = 0; k < INCOMEC_V; k++) {
                sumContentI[i][k] += yi[i][j][k];
                totalIncome[i] += yi[i][j][k];
            }
            for (int k = 0; k < SPENDC_V; k++) {
                sumContentS[i][k] += ys[i][j][k];
                totalSpend[i] += ys[i][j][k];
            }
        }
    }

    /* 소득 지출 분석 반복문 */
    printf(" < 소득, 지출 분석 > ");
    for (int closeSI = 1; closeSI != 2; ){
        /* 월 입력 */
        printf("소득 지출 분석을 확인하고자 하는 달을 입력하세요.\n월 : ");
        scanf("%d", &selectMonth);
        if (selectMonth > MONTH_V){                                    // 올바른 월을 입력하지 않으면 메뉴 화면으로 초기화
            printf("올바른 월 입력이 아닙니다. Menu 화면으로 넘어갑니다.\n\n");
            return;
        }

        printf("\n%d월의 소득, 지출 분석 현황입니다.\n\n", selectMonth);

        /* 소득 현황 */
        printf("\n%d월의 소득 현황입니다.\n", selectMonth);
        printf("==============================\n");
        printf("%d월의 총 소득 : %d원\n", selectMonth, totalIncome[selectMonth - 1]);
        for (int i = 0; i < INCOMEC_V; i++) {
            printf("%s에 의한 소득 : %d원\n", contentI[i], sumContentI[selectMonth - 1][i]);
        }
        printf("==============================\n\n");

        /* 지출 현황 */
        printf("%d월의 지출 현황입니다.\n", selectMonth);
        printf("==============================\n");
        printf("%d월의 총 지출 : %d원\n", selectMonth, totalSpend[selectMonth - 1]);
        for (int i = 0; i < SPENDC_V; i++) {
            printf("%s에 의한 지출 : %d원\n", contentS[i], sumContentS[selectMonth - 1][i]);
        }
        printf("==============================\n\n");

        /* 소득, 지출 비교 */
        printf("%d월의 소득, 지출 비교 현황입니다.\n", selectMonth);
        printf("==============================\n");
        difference[selectMonth - 1] = totalIncome[selectMonth - 1] - totalSpend[selectMonth - 1];
        rateLevel = rate(totalIncome[selectMonth - 1], totalSpend[selectMonth - 1]);

        /* 흑자일 때의 출력 */
        if (difference[selectMonth - 1] > 0){
            printf("소득이 지출보다 %d원 더 많습니다.\n", difference[selectMonth - 1]);
            printf("흑자 안정성 단계 10단계 중 %d단계 입니다.\n", rateLevel);
            safetySet(rateLevel);
        }

        /* 적자일 때의 출력 */
        else if (difference[selectMonth - 1] < 0){
            printf("지출이 소득보다 %d원 더 많습니다.\n", -difference[selectMonth - 1]);
            printf("적자 위험 단계 10단계 중 %d단계 입니다.\n", rateLevel);
            dangerSet(rateLevel);
        }

        /* 소득 = 지출일 때의 출력 */
        else{
            printf("소득과 지출이 동일합니다.\n");
            printf("==============================\n");
        }

        /* 이후 실행 선택 */
        printf("분석에 대한 추가 확인이 있으면 1을 없으면 2를 입력하세요. : ");
        scanf("%d", &closeSI);
        printf("\n\n");
    }
}
