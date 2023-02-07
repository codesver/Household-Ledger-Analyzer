#include <stdio.h>

#include "lastDay.h"

#define MONTH_V     12
#define DAY_V       31
#define SPENDC_V    9

/* ���� �Է� �Լ� */
void spend(int y[MONTH_V][DAY_V][SPENDC_V], char *contentS[SPENDC_V]) {

    /* ���� */
    int selectMonth;                                                // ������ �Է��Ϸ��� ���� �����ϴ� ������ ����
    int selectDay;                                                  // ������ �Է��Ϸ��� ���� �����ϴ� ������ ����
    int spendValue;                                                 // ������ �Է��ϴ� ������ ����
    int selectContent;                                              // ������ �����ϴ� ������ ����

    /* ���� �Է� �ݺ��� */
    printf("< ���� �Է��� �����մϴ� >.\n\n");
    for (int closeSpend = 1; closeSpend != 3;){                     // �ݺ����� 1ȸ �����ϰ� closeSpend = 3�� �Ǹ� �ݺ� ����

        /* ���� �Է��� �Ϸ��� �� �Է� */
        printf("���� �Է� �� �Է� : ");                                  // ���� �Է� �� �Է�
        scanf("%d", &selectMonth);
        if (selectMonth > MONTH_V){                                 // �ùٸ� ���� �Է����� ������ �޴� ȭ������ �ʱ�ȭ
            printf("�ùٸ� �� �Է��� �ƴմϴ�. Menu ȭ������ �Ѿ�ϴ�.\n\n");
            return;
        }
        closeSpend = 1;                                             // ��ø �ݺ����� ��Ȱ�� ������ ���� 1�� �ʱ�ȭ

        /* �ش� ���� ���� �Է� */
        for (; closeSpend != 2 && closeSpend != 3;){
            printf("\n�Է��ϰ��� �ϴ� ��, �ݾ�, ������ �Է�\n");

            /* ��¥ �Է� */
            printf("��¥ : ");
            scanf("%d", &selectDay);
            if (selectDay > lastDay(selectMonth)){                // �ùٸ� ���� �Է����� ������ �޴� ȭ������ �ʱ�ȭ
                printf("�ùٸ� ��¥ �Է��� �ƴմϴ�. Menu ȭ������ �Ѿ�ϴ�.\n\n");
                return;
            }

            /* ���� �Է� */
            printf("�ݾ� : ");
            scanf("%d", &spendValue);
            if (spendValue < 0){                                   // �ùٸ� ������ �ݾ��� �Է����� ������ �޴� ȭ������ �ʱ�ȭ
                printf("�ùٸ� �ݾ� �Է��� �ƴմϴ�. Menu ȭ������ �Ѿ�ϴ�.\n\n");
                return;
            }

            /* ���� �Կ� */
            printf("���� (1. �ĺ� 2. �ĺ�� 3. �ְź� 4. �Ƿ��� 5. ����� 6. ������ 7. �̿�� 8. �Ƿ�� 9. ��Ÿ) : ");
            scanf("%d", &selectContent);
            if (selectContent > 9 || selectContent < 1){           // �ùٸ� ������ ������ �Է����� ������ �޴� ȭ������ �ʱ�ȭ
                printf("�ùٸ� ���� �Է��� �ƴմϴ�. Menu ȭ������ �Ѿ�ϴ�.\n\n");
                return;
            }

            /* ������ ���� */
            printf("%d�� %d�Ͽ� %s(��)������ ���� %d���� �Է��մϴ�.\n",
                   selectMonth, selectDay, contentS[selectContent - 1], spendValue);
            y[selectMonth - 1][selectDay - 1][selectContent - 1] += spendValue;

            /* ���� ���� ���� */
            printf("\n1. %d���� �߰� ���� �Է� 2. �ٸ� ���� ���� �Է� 3. ���� �Է� ����\n", selectMonth);
            printf("���� ��ȣ : ");
            scanf("%d", &closeSpend);
            if (closeSpend > 3 || closeSpend < 1) {
                printf("���� �Է��� �����մϴ�.");
                return;
            }
        }
    }

    printf("���� �Է��� ����Ǿ����ϴ�.\n\n");
}

