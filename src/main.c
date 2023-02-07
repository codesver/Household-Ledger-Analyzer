#include <stdio.h>
#include <stdlib.h>

#include "aboutProgram.h"
#include "showMenu.h"
#include "performMenu.h"

#define MONTH_V     12
#define DAY_V       31
#define INCOMEC_V   3
#define SPENDC_V    9

/* < 2020년 월별  소득, 지출 분석 프로그램 > */
int main()
{
    /* 변수 선언 */
    int yearIncome[MONTH_V][DAY_V][INCOMEC_V] = {0};                // 소득을 저장하는 3차원 배열 [월][일][내역]
    int yearSpend[MONTH_V][DAY_V][SPENDC_V] = {0};                  // 지출을 저장하는 3차원 배열 [월][일][내역]
    int selectMenu;                                                 // 메뉴 선택 변수
    int startProgram;                                               // 프로그램 실행 변수

    /*  소득, 지출로 표기가 가능한 내역 */
    char *contentI[INCOMEC_V] = {"월급", "용돈", "기타"};                 // 소득 내역을 주소로 저장하는 1차원 포인터 배열
    char *contentS[SPENDC_V] = {"  식비", "식비외", "주거비",               // 지출 내역을 주소로 저장하는 1차원 포인터 배열
                                "의류비", "교통비", "교육비",
                                "미용비", "의료비", "  기타"};

    /* 프로그램 시작 및 설명 */
    printf("< 2020년의 소득, 지출을 다루는 프로그램 >\n\n");
    aboutProgram();

    /* 프로그램 실행 조건문 */
    printf("프로그램을 실행하시겠습까? (1. Yes 2. NO) : ");
    scanf("%d", &startProgram);
    if (startProgram == 1){
        /* 메뉴 선택 실행 */
        for (; selectMenu != 6;) {
            showMenu();                                         // 메뉴 화면 출력
            scanf("%d", &selectMenu);                           // 메뉴 옵션 선택
            printf("\n");
            performMenu(selectMenu, yearIncome, yearSpend, contentI, contentS);
        }
    }
    else
        printf("프로그램을 실행하지 않습니다.");

    return 0;
}




