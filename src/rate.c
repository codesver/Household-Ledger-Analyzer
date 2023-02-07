#include <stdio.h>

/* 적자 위험 단계 함수 */
/* 지출에 대한 소득의 비율을 확인하여 위험 단계 반환 */
int rate(int income, int spend){
    int levStand = spend / 10;

    if (income >= 10 * spend || income <= levStand)
        return 10;
    else if (income >= 9 * spend || income <= 2 * levStand)
        return 9;
    else if (income >= 8 * spend || income <= 3 * levStand)
        return 8;
    else if (income >= 7 * spend || income <= 4 * levStand)
        return 7;
    else if (income >= 6 * spend || income <= 5 * levStand)
        return 6;
    else if (income >= 5 * spend || income <= 6 * levStand)
        return 5;
    else if (income >= 4 * spend || income <= 7 * levStand)
        return 4;
    else if (income >= 3 * spend || income <= 8 * levStand)
        return 3;
    else if (income >= 2 * spend || income <= 9 * levStand)
        return 2;
    else
        return 1;
}
