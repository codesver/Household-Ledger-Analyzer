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

/* �ҵ�, ���� �м� �Լ� */
void analyze(int yi[MONTH_V][DAY_V][INCOMEC_V], int ys[MONTH_V][DAY_V][SPENDC_V], char *contentI[INCOMEC_V], char *contentS[SPENDC_V]) {
    /* ���� */
    int selectMonth;                                            // �м��ϰ��� �ϴ� �� ����

    int totalIncome[MONTH_V] = {0};                             // ���� �� �ҵ� ���� 1���� �迭 (�հ踦 ���� 0���� �ʱ�ȭ)
    int totalSpend[MONTH_V] = {0};                              // ���� �� ���� ���� 1���� �迭 (�հ踦 ���� 0���� �ʱ�ȭ)

    int sumContentI[MONTH_V][INCOMEC_V] = {0};                  // ����, �������� �ҵ��� �����ϴ� 2���� �迭 (�հ踦 ���� 0���� �ʱ�ȭ)
    int sumContentS[MONTH_V][SPENDC_V] = {0};                   // ����, �������� ������ �����ϴ� 2���� �迭 (�հ踦 ���� 0���� �ʱ�ȭ)

    int difference[MONTH_V];                                             // ���� �ҵ�, ���� ����
    int rateLevel;                                                    // ���� ���� �ܰ�


    /* �� ���� �ҵ�, ������ �������� �հ� ���� ��ø �ݺ��� */
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

    /* �ҵ� ���� �м� �ݺ��� */
    printf(" < �ҵ�, ���� �м� > ");
    for (int closeSI = 1; closeSI != 2; ){
        /* �� �Է� */
        printf("�ҵ� ���� �м��� Ȯ���ϰ��� �ϴ� ���� �Է��ϼ���.\n�� : ");
        scanf("%d", &selectMonth);
        if (selectMonth > MONTH_V){                                    // �ùٸ� ���� �Է����� ������ �޴� ȭ������ �ʱ�ȭ
            printf("�ùٸ� �� �Է��� �ƴմϴ�. Menu ȭ������ �Ѿ�ϴ�.\n\n");
            return;
        }

        printf("\n%d���� �ҵ�, ���� �м� ��Ȳ�Դϴ�.\n\n", selectMonth);

        /* �ҵ� ��Ȳ */
        printf("\n%d���� �ҵ� ��Ȳ�Դϴ�.\n", selectMonth);
        printf("==============================\n");
        printf("%d���� �� �ҵ� : %d��\n", selectMonth, totalIncome[selectMonth - 1]);
        for (int i = 0; i < INCOMEC_V; i++) {
            printf("%s�� ���� �ҵ� : %d��\n", contentI[i], sumContentI[selectMonth - 1][i]);
        }
        printf("==============================\n\n");

        /* ���� ��Ȳ */
        printf("%d���� ���� ��Ȳ�Դϴ�.\n", selectMonth);
        printf("==============================\n");
        printf("%d���� �� ���� : %d��\n", selectMonth, totalSpend[selectMonth - 1]);
        for (int i = 0; i < SPENDC_V; i++) {
            printf("%s�� ���� ���� : %d��\n", contentS[i], sumContentS[selectMonth - 1][i]);
        }
        printf("==============================\n\n");

        /* �ҵ�, ���� �� */
        printf("%d���� �ҵ�, ���� �� ��Ȳ�Դϴ�.\n", selectMonth);
        printf("==============================\n");
        difference[selectMonth - 1] = totalIncome[selectMonth - 1] - totalSpend[selectMonth - 1];
        rateLevel = rate(totalIncome[selectMonth - 1], totalSpend[selectMonth - 1]);

        /* ������ ���� ��� */
        if (difference[selectMonth - 1] > 0){
            printf("�ҵ��� ���⺸�� %d�� �� �����ϴ�.\n", difference[selectMonth - 1]);
            printf("���� ������ �ܰ� 10�ܰ� �� %d�ܰ� �Դϴ�.\n", rateLevel);
            safetySet(rateLevel);
        }

        /* ������ ���� ��� */
        else if (difference[selectMonth - 1] < 0){
            printf("������ �ҵ溸�� %d�� �� �����ϴ�.\n", -difference[selectMonth - 1]);
            printf("���� ���� �ܰ� 10�ܰ� �� %d�ܰ� �Դϴ�.\n", rateLevel);
            dangerSet(rateLevel);
        }

        /* �ҵ� = ������ ���� ��� */
        else{
            printf("�ҵ�� ������ �����մϴ�.\n");
            printf("==============================\n");
        }

        /* ���� ���� ���� */
        printf("�м��� ���� �߰� Ȯ���� ������ 1�� ������ 2�� �Է��ϼ���. : ");
        scanf("%d", &closeSI);
        printf("\n\n");
    }
}
