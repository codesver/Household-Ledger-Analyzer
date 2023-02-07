#include <stdio.h>

#include "lastDay.h"

#define MONTH_V     12
#define DAY_V       31
#define SPENDC_V    9

/* 지출 입력 함수 */
void spend(int y[MONTH_V][DAY_V][SPENDC_V], char *contentS[SPENDC_V]) {

    /* 변수 */
    int selectMonth;                                                // 지출을 입력하려는 월을 저장하는 정수형 변수
    int selectDay;                                                  // 지출을 입력하려는 일을 저장하는 정수형 변수
    int spendValue;                                                 // 지출을 입력하는 정수형 변수
    int selectContent;                                              // 내역을 선택하는 정수형 변수

    /* 지출 입력 반복문 */
    printf("< 지출 입력을 시작합니다 >.\n\n");
    for (int closeSpend = 1; closeSpend != 3;){                     // 반복문을 1회 실행하고 closeSpend = 3이 되면 반복 종료

        /* 지출 입력을 하려는 달 입력 */
        printf("지출 입력 달 입력 : ");                                  // 지출 입력 달 입력
        scanf("%d", &selectMonth);
        if (selectMonth > MONTH_V){                                 // 올바른 월을 입력하지 않으면 메뉴 화면으로 초기화
            printf("올바른 월 입력이 아닙니다. Menu 화면으로 넘어갑니다.\n\n");
            return;
        }
        closeSpend = 1;                                             // 중첩 반복문의 워활한 실행을 위해 1로 초기화

        /* 해당 월의 지출 입력 */
        for (; closeSpend != 2 && closeSpend != 3;){
            printf("\n입력하고자 하는 날, 금액, 내역을 입력\n");

            /* 날짜 입력 */
            printf("날짜 : ");
            scanf("%d", &selectDay);
            if (selectDay > lastDay(selectMonth)){                // 올바른 일을 입력하지 않으면 메뉴 화면으로 초기화
                printf("올바른 날짜 입력이 아닙니다. Menu 화면으로 넘어갑니다.\n\n");
                return;
            }

            /* 지출 입력 */
            printf("금액 : ");
            scanf("%d", &spendValue);
            if (spendValue < 0){                                   // 올바른 형식의 금액을 입력하지 않으면 메뉴 화면으로 초기화
                printf("올바른 금액 입력이 아닙니다. Menu 화면으로 넘어갑니다.\n\n");
                return;
            }

            /* 내역 입역 */
            printf("내역 (1. 식비 2. 식비외 3. 주거비 4. 의류비 5. 교통비 6. 교육비 7. 미용비 8. 의료비 9. 기타) : ");
            scanf("%d", &selectContent);
            if (selectContent > 9 || selectContent < 1){           // 올바른 형식의 내역을 입력하지 않으면 메뉴 화면으로 초기화
                printf("올바른 내역 입력이 아닙니다. Menu 화면으로 넘어갑니다.\n\n");
                return;
            }

            /* 데이터 저장 */
            printf("%d월 %d일에 %s(으)로인한 지출 %d원을 입력합니다.\n",
                   selectMonth, selectDay, contentS[selectContent - 1], spendValue);
            y[selectMonth - 1][selectDay - 1][selectContent - 1] += spendValue;

            /* 차후 실행 선택 */
            printf("\n1. %d월의 추가 지출 입력 2. 다른 달의 지출 입력 3. 지출 입력 종료\n", selectMonth);
            printf("선택 번호 : ");
            scanf("%d", &closeSpend);
            if (closeSpend > 3 || closeSpend < 1) {
                printf("지출 입력을 종료합니다.");
                return;
            }
        }
    }

    printf("지출 입력이 종료되었습니다.\n\n");
}

