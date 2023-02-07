#include <stdio.h>

#include "income.h"
#include "spend.h"
#include "showIncome.h"
#include "showSpend.h"
#include "analyze.h"

#define MONTH_V     12
#define DAY_V       31
#define INCOMEC_V   3
#define SPENDC_V    9

/* ���α׷� �޴� �۵� �Լ� */
void performMenu(int sm, int yi[MONTH_V][DAY_V][INCOMEC_V], int ys[MONTH_V][DAY_V][SPENDC_V], char *contentI[INCOMEC_V], char *contentS[SPENDC_V]) {
    switch(sm) {
        case 1 :
            income(yi, contentI);
            break;
        case 2 :
            spend(ys, contentS);
            break;
        case 3 :
            showIncome(yi, contentI);
            break;
        case 4 :
            showSpend(ys, contentS);
            break;
        case 5 :
            analyze(yi, ys, contentI, contentS);
            break;
        case 6 :
            printf("�ҵ�, ���� �м� ���α׷��� ����˴ϴ�.\n");
            break;
        default :
            printf("�Է��� �߸� �Ǿ����ϴ�. �ٽ� �Է��� �ּ���.\n\n ");
    }
}

