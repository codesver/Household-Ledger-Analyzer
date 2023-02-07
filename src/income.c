#include <stdio.h>

#include "lastDay.h"

#define MONTH_V     12
#define DAY_V       31
#define INCOMEC_V   3

/* �ҵ� �Է� �Լ� */
void income(int y[MONTH_V][DAY_V][INCOMEC_V], char *contentI[INCOMEC_V]) {

    /* ���� */
    int selectMonth;                                               // �ҵ��� �Է��Ϸ��� ���� �����ϴ� ������ ����
    int selectDay;                                                 // �ҵ��� �Է��Ͽ��� ���� �����ϴ� ������ ����
    int incomeValue;                                               // �ҵ��� �Է��ϴ� ������ ����
    int selectContent;                                             // ������ �����ϴ� ������ ����

    /* �ҵ� �Է� �ݺ��� */
    printf("< �ҵ� �Է��� �����մϴ� >.\n\n");
    for (int closeIncome = 1; closeIncome != 3;){                  // �ݺ����� 1ȸ �����ϰ� closeIncome = 3�� �Ǹ� �ݺ� ����

        /* �ҵ� �Է��� �Ϸ��� �� �Է� */
        printf("�ҵ� �Է� �� �Է� : ");                                 // �ҵ� �Է� �� �Է�
        scanf("%d", &selectMonth);
        if (selectMonth > MONTH_V){                                // �ùٸ� ���� �Է����� ������ �޴� ȭ������ �ʱ�ȭ
            printf("�ùٸ� �� �Է��� �ƴմϴ�. Menu ȭ������ �Ѿ�ϴ�.\n\n");
            return;
        }
        closeIncome = 1;                                           // ��ø �ݺ����� ��Ȱ�� ������ ���� 1�� �ʱ�ȭ

        /* �ش� ���� �ҵ� �Է� */
        for (; closeIncome != 2 && closeIncome != 3;){
            printf("\n�Է��ϰ��� �ϴ� ��, �ݾ�, ������ �Է�\n");

            /* ��¥ �Է� */
            printf("��¥ : ");
            scanf("%d", &selectDay);
            if (selectDay > lastDay(selectMonth)){                // �ùٸ� ���� �Է����� ������ �޴� ȭ������ �ʱ�ȭ
                printf("�ùٸ� ��¥ �Է��� �ƴմϴ�. Menu ȭ������ �Ѿ�ϴ�.\n\n");
                return;
            }

            /* �ҵ� �Է� */
            printf("�ݾ� : ");
            scanf("%d", &incomeValue);
            if (incomeValue < 0){                                   // �ùٸ� ������ �ݾ��� �Է����� ������ �޴� ȭ������ �ʱ�ȭ
                printf("�ùٸ� �ݾ� �Է��� �ƴմϴ�. Menu ȭ������ �Ѿ�ϴ�.\n\n");
                return;
            }

            /* ���� �Է� */
            printf("���� (1. ���� 2. �뵷 3. ��Ÿ) : ");
            scanf("%d", &selectContent);
            if (selectContent > 3 || selectContent < 1){           // �ùٸ� ������ ������ �Է����� ������ �޴� ȭ������ �ʱ�ȭ
                printf("�ùٸ� ���� �Է��� �ƴմϴ�. Menu ȭ������ �Ѿ�ϴ�.\n\n");
                return;
            }

            /* ������ ���� */
            printf("%d�� %d�Ͽ� %s(��)������ �ҵ� %d���� �Է��մϴ�.\n",
                   selectMonth, selectDay, contentI[selectContent - 1], incomeValue);
            y[selectMonth - 1][selectDay - 1][selectContent - 1] += incomeValue;

            /* ���� ���� ���� */
            printf("\n1. %d���� �߰� �ҵ� �Է� 2. �ٸ� ���� �ҵ� �Է� 3. �ҵ� �Է� ����\n", selectMonth);
            printf("���� ��ȣ : ");
            scanf("%d", &closeIncome);
            if (closeIncome > 3 || closeIncome < 1) {
                printf("�ҵ� �Է��� �����մϴ�.");
                return;
            }
        }
    }

    printf("�ҵ� �Է��� ����Ǿ����ϴ�.\n\n");
}
