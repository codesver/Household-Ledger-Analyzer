#include <stdio.h>

#include "lastDay.h"

#define MONTH_V     12
#define DAY_V       31
#define INCOMEC_V   3

/* ���� ���� �ҵ� �Է� ��Ȳ�� Ȯ���ϴ� �Լ� */
void showIncome(int y[MONTH_V][DAY_V][INCOMEC_V], char *contentI[INCOMEC_V]) {

    /* ���� */
    int selectMonth;                                            // �ҵ� ��Ȳ�� Ȯ���ϰ��� �ϴ� ���� �����ϴ� ������ ����

    /* �� ���� */
    printf("��Ȳ�� Ȯ���ϰ��� �ϴ� ���� �Է��ϼ���.\n");
    printf("�� : ");
    scanf("%d", &selectMonth);
    if (selectMonth > MONTH_V){                                // �ùٸ� ���� �Է����� ������ �޴� ȭ������ �ʱ�ȭ
        printf("�ùٸ� �� �Է��� �ƴմϴ�. Menu ȭ������ �Ѿ�ϴ�.\n\n");
        return;
    }

    /* ���� ���� �ҵ� �Է� ��Ȳ ��� �ݺ��� */
    printf("< %d�� ���� �ҵ� ��Ȳ >\n", selectMonth);
    printf("==============================================================\n");
    for (int i = 0; i < lastDay(selectMonth); i++){
        printf("%2d�� : ( ", i + 1);
        for (int j = 0; j < INCOMEC_V; j++){
                printf("%s : %7d�� ", contentI[j], y[selectMonth - 1][i][j]);
        }
        printf(")\n");
    }
    printf("==============================================================\n\n");
}
