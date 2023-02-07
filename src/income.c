#include <stdio.h>

#include "lastDay.h"

#define MONTH_V     12
#define DAY_V       31
#define INCOMEC_V   3

/* 소득 입력 함수 */
void income(int y[MONTH_V][DAY_V][INCOMEC_V], char *contentI[INCOMEC_V]) {

    /* 변수 */
    int selectMonth;                                               // 소득을 입력하려는 월을 저장하는 정수형 변수
    int selectDay;                                                 // 소득을 입력하여는 일을 저장하는 정수형 변수
    int incomeValue;                                               // 소득을 입력하는 정수형 변수
    int selectContent;                                             // 내역을 선택하는 정수형 변수

    /* 소득 입력 반복문 */
    printf("< 소득 입력을 시작합니다 >.\n\n");
    for (int closeIncome = 1; closeIncome != 3;){                  // 반복문을 1회 실행하고 closeIncome = 3이 되면 반복 종료

        /* 소득 입력을 하려는 달 입력 */
        printf("소득 입력 달 입력 : ");                                 // 소득 입력 달 입력
        scanf("%d", &selectMonth);
        if (selectMonth > MONTH_V){                                // 올바른 월을 입력하지 않으면 메뉴 화면으로 초기화
            printf("올바른 월 입력이 아닙니다. Menu 화면으로 넘어갑니다.\n\n");
            return;
        }
        closeIncome = 1;                                           // 중첩 반복문의 원활한 실행을 위해 1로 초기화

        /* 해당 월의 소득 입력 */
        for (; closeIncome != 2 && closeIncome != 3;){
            printf("\n입력하고자 하는 날, 금액, 내역을 입력\n");

            /* 날짜 입력 */
            printf("날짜 : ");
            scanf("%d", &selectDay);
            if (selectDay > lastDay(selectMonth)){                // 올바른 일을 입력하지 않으면 메뉴 화면으로 초기화
                printf("올바른 날짜 입력이 아닙니다. Menu 화면으로 넘어갑니다.\n\n");
                return;
            }

            /* 소득 입력 */
            printf("금액 : ");
            scanf("%d", &incomeValue);
            if (incomeValue < 0){                                   // 올바른 형식의 금액을 입력하지 않으면 메뉴 화면으로 초기화
                printf("올바른 금액 입력이 아닙니다. Menu 화면으로 넘어갑니다.\n\n");
                return;
            }

            /* 내역 입력 */
            printf("내역 (1. 월급 2. 용돈 3. 기타) : ");
            scanf("%d", &selectContent);
            if (selectContent > 3 || selectContent < 1){           // 올바른 형식의 내역을 입력하지 않으면 메뉴 화면으로 초기화
                printf("올바른 내역 입력이 아닙니다. Menu 화면으로 넘어갑니다.\n\n");
                return;
            }

            /* 데이터 저장 */
            printf("%d월 %d일에 %s(으)로인한 소득 %d원을 입력합니다.\n",
                   selectMonth, selectDay, contentI[selectContent - 1], incomeValue);
            y[selectMonth - 1][selectDay - 1][selectContent - 1] += incomeValue;

            /* 차후 실행 선택 */
            printf("\n1. %d월의 추가 소득 입력 2. 다른 달의 소득 입력 3. 소득 입력 종료\n", selectMonth);
            printf("선택 번호 : ");
            scanf("%d", &closeIncome);
            if (closeIncome > 3 || closeIncome < 1) {
                printf("소득 입력을 종료합니다.");
                return;
            }
        }
    }

    printf("소득 입력이 종료되었습니다.\n\n");
}
