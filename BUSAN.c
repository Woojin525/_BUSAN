#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#define LEN_MIN 15
#define LEN_MAX 50
#define PROB_MIN 10
#define PROB_MAX 90

int main() {
    //��Ʈ��
    printf("����������������������������������������\n");
    printf("����������������������������������������\n");
    printf("����������������������������������������\n");
    printf("����������������������������������������\n");
    printf("����������������������������������������\n");
    printf("����������������������������������������\n");
    printf("����������������������������������������\n");
    printf("����������������������������������������\n");
    printf("����������������������������������������\n");
    printf("����������������������������������������\n");
    printf("����������������������������������������\n");
    printf("����������������������������������������\n");


    int LEN, PROB; //���� ����, ����


    printf("train length(15~50) >> ");
    scanf_s("%d", &LEN);
    printf("percentile 'p' (10~90) >> ");
    scanf_s("%d", &PROB);

    int Z = LEN - 3, C = LEN - 6, M = LEN - 2; //����, �ù�, ������
    int Zturn = 1;

    printf("---------------\n");

    //���� ���
    for (int i = 0; i < LEN; i++) {
        printf("#");
    }
    printf("\n");

    //���� �ߴ�
    printf("#");

    //C��ġ
    for (int i = 0; i < C - 1; i++) {
        printf(" ");
    }
    printf("C");

    //Z��ġ
    for (int i = C; i < Z - 1; i++) {
        printf(" ");
    }
    printf("Z");

    //M��ġ
    for (int i = Z; i < M - 1; i++) {
        printf(" ");
    }
    printf("M");


    //����#��ġ
    for (int i = 0; i <= LEN - M - 4; i++) {
        printf(" ");
    }
    printf("#\n");

    //���� �ϴ�
    for (int i = 0; i < LEN; i++) {
        printf("#");
    }
    printf("\n");
    printf("---------------\n");
    printf("\n\n");

    if (LEN < LEN_MIN || LEN > LEN_MAX || PROB < PROB_MIN || PROB > PROB_MAX) {
        return 0;
    }

    while (1) {

        srand((unsigned int)time(NULL));

        for (int i = 0; i < 30; i++)
            int temp = rand();

        int r1 = rand() % 101;
        int r2 = rand() % 101;
        printf("\n");
        //printf("%d ", r1);
        //printf("%d", r2);


        //Zturn Ȧ����°
        Zturn = !Zturn;

        //C����
        if (PROB < r1) {
            C--;
        }

        //Z����
        if (PROB > r2 && Zturn) {
            Z--;
        }
        printf("\n");

        //���� ���
        for (int i = 0; i < LEN; i++) {
            printf("#");
        }
        printf("\n");

        //���� �ߴ�
        printf("#");

        //C��ġ
        for (int i = 0; i < C - 1; i++) {
            printf(" ");
        }
        printf("C");

        //Z��ġ
        for (int i = C; i < Z - 1; i++) {
            printf(" ");
        }
        printf("Z");

        //M��ġ
        for (int i = Z; i < M - 1; i++) {
            printf(" ");
        }
        printf("M");


        //����#��ġ
        for (int i = 0; i <= LEN - M - 4; i++) {
            printf(" ");
        }
        printf("#\n");

        //���� �ϴ�
        for (int i = 0; i < LEN; i++) {
            printf("#");
        }
        printf("\n");
        printf("\n");
        //C����
        if (PROB < r1) {
            printf("citizen: %d -> %d\n", C + 1, C);
        }
        else {
            printf("citizen: stay %d\n", C);
        }

        //Z����
        if (PROB > r2 && Zturn) {
            printf("zombie: %d -> %d", Z + 1, Z);
        }
        else {
            printf("zombie: stay %d", Z);
        }

        //Z��Ÿ��
        if (!Zturn) {
            printf(" (cannot move)\n");
        }
        else {
            printf("\n");
        }
        printf("\n");
        printf("---------------\n");
        printf("\n");

        //Citizen won
        if (C == 1) {
            //���� ���
            for (int i = 0; i < LEN; i++) {
                printf("#");
            }
            printf("\n");

            //���� �ߴ�
            printf("#");

            //C��ġ
            for (int i = 0; i < C - 1; i++) {
                printf(" ");
            }
            printf("C");

            //Z��ġ
            for (int i = C; i < Z - 1; i++) {
                printf(" ");
            }
            printf("Z");

            //M��ġ
            for (int i = Z; i < M - 1; i++) {
                printf(" ");
            }
            printf("M");


            //����#��ġ
            for (int i = 0; i <= LEN - M - 4; i++) {
                printf(" ");
            }
            printf("#\n");

            //���� �ϴ�
            for (int i = 0; i < LEN; i++) {
                printf("#");
            }


            printf("\n");
            printf("SUCCESS!\n");
            printf("citizen(s) escaped to the next train\n");
            break;
        }
        //Zombie won
        if (C + 1 == Z) {
            //���� ���
            for (int i = 0; i < LEN; i++) {
                printf("#");
            }
            printf("\n");

            //���� �ߴ�
            printf("#");

            //C��ġ
            for (int i = 0; i < C - 1; i++) {
                printf(" ");
            }
            printf("C");

            //Z��ġ
            for (int i = C; i < Z - 1; i++) {
                printf(" ");
            }
            printf("Z");

            //M��ġ
            for (int i = Z; i < M - 1; i++) {
                printf(" ");
            }
            printf("M");


            //����#��ġ
            for (int i = 0; i <= LEN - M - 4; i++) {
                printf(" ");
            }
            printf("#\n");

            //���� �ϴ�
            for (int i = 0; i < LEN; i++) {
                printf("#");
            }
            printf("\n");
            printf("GAME OVER!\n");
            printf("Citizen(s) has(have) been attacked by a zombie\n");

            break;
        }


        Sleep(4000);
    }
    printf("������ ����Ǿ����ϴ�.\n");
    return 0;
}