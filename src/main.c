#include <stdio.h>
#include <stdlib.h>

#include "aboutProgram.h"
#include "showMenu.h"
#include "performMenu.h"

#define MONTH_V     12
#define DAY_V       31
#define INCOMEC_V   3
#define SPENDC_V    9

/* < 2020�� ����  �ҵ�, ���� �м� ���α׷� > */
int main()
{
    /* ���� ���� */
    int yearIncome[MONTH_V][DAY_V][INCOMEC_V] = {0};                // �ҵ��� �����ϴ� 3���� �迭 [��][��][����]
    int yearSpend[MONTH_V][DAY_V][SPENDC_V] = {0};                  // ������ �����ϴ� 3���� �迭 [��][��][����]
    int selectMenu;                                                 // �޴� ���� ����
    int startProgram;                                               // ���α׷� ���� ����

    /*  �ҵ�, ����� ǥ�Ⱑ ������ ���� */
    char *contentI[INCOMEC_V] = {"����", "�뵷", "��Ÿ"};                 // �ҵ� ������ �ּҷ� �����ϴ� 1���� ������ �迭
    char *contentS[SPENDC_V] = {"  �ĺ�", "�ĺ��", "�ְź�",               // ���� ������ �ּҷ� �����ϴ� 1���� ������ �迭
                                "�Ƿ���", "�����", "������",
                                "�̿��", "�Ƿ��", "  ��Ÿ"};

    /* ���α׷� ���� �� ���� */
    printf("< 2020���� �ҵ�, ������ �ٷ�� ���α׷� >\n\n");
    aboutProgram();

    /* ���α׷� ���� ���ǹ� */
    printf("���α׷��� �����Ͻðڽ���? (1. Yes 2. NO) : ");
    scanf("%d", &startProgram);
    if (startProgram == 1){
        /* �޴� ���� ���� */
        for (; selectMenu != 6;) {
            showMenu();                                         // �޴� ȭ�� ���
            scanf("%d", &selectMenu);                           // �޴� �ɼ� ����
            printf("\n");
            performMenu(selectMenu, yearIncome, yearSpend, contentI, contentS);
        }
    }
    else
        printf("���α׷��� �������� �ʽ��ϴ�.");

    return 0;
}




