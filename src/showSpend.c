#include <stdio.h>

#include "lastDay.h"

#define MONTH_V     12
#define DAY_V       31
#define SPENDC_V    9

/* ���� ���� ���� �Է� ��Ȳ�� Ȯ���ϴ� �Լ� */
void showSpend(int y[MONTH_V][DAY_V][SPENDC_V], char *contentS[SPENDC_V]) {

    /* ���� */
    int selectMonth;                                            // ���� ��Ȳ�� Ȯ���ϰ��� �ϴ� ���� �����ϴ� ������ ����

    /* �� ���� */
    printf("��Ȳ�� Ȯ���ϰ��� �ϴ� ���� �Է��ϼ���.\n");
    printf("�� : ");
    scanf("%d", &selectMonth);
    if (selectMonth > MONTH_V){                                    // �ùٸ� ���� �Է����� ������ �޴� ȭ������ �ʱ�ȭ
        printf("�ùٸ� �� �Է��� �ƴմϴ�. Menu ȭ������ �Ѿ�ϴ�.\n\n");
        return;
    }

    /* ���� ���� ���� �Է� ��Ȳ ��� �ݺ��� */
    printf("< %d�� ���� ���� ��Ȳ >\n", selectMonth);
    printf("==============================================================\n");
    for (int i = 0; i < lastDay(selectMonth); i++){
        printf("%2d��\n", i + 1);
        for (int j = 0; j < SPENDC_V; j++){
                printf("%-s : %7d�� ", contentS[j], y[selectMonth - 1][i][j]);
                if ((j != 0) && ((j + 1) % 3 == 0))
                    printf("\n");
        }
        printf("\n");
    }
    printf("==============================================================\n\n");
}
