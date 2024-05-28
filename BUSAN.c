#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#define LEN_MIN 15
#define LEN_MAX 50
#define PROB_MIN 10
#define PROB_MAX 90

int main() {
    //인트로
    printf("□□■■□□□□□■■□□□□■■□□□□■□□□□□■■□□□□■□□■□□\n");
    printf("□□■■□□□□□■■□□□□■■□□□□■□□□■■■■■■□□■□□■□□\n");
    printf("□□■■■■■■■■■□□□□■■□□□□■□□□□■■■■□□□■□□■□□\n");
    printf("□□■■□□□□□■■□□□□■■□□□□■■■□■■□□■■□■■□□■□□\n");
    printf("□□■■■■■■■■■□□□■■■■■□□■□□□■□□□□■□□■□□■□□\n");
    printf("□□□□□□□□□□□□□■■□□■■■□■□□□■■□□■■□□■□□■□□\n");
    printf("□□□□□□□□□□□□■■□□□□■■□■□□□□■■■■□□□■□□■□□\n");
    printf("□■■■■■■■■■■■□□□■□□□□□■□□□□□□□□■■■■■■□□□\n");
    printf("□□□□□□■□□□□□□□□■□□□□□■□□□□□□□■■□□□□■■□□\n");
    printf("□□□□□□■□□□□□□□□■□□□□□□□□□□□□□■□□□□□□■□□\n");
    printf("□□□□□□■□□□□□□□□■□□□□□□□□□□□□□■■□□□□■■□□\n");
    printf("□□□□□□■□□□□□□□□■■■■■■■■□□□□□□□■■■■■■□□□\n");


    int LEN, PROB; //기차 길이, 설정


    printf("train length(15~50) >> ");
    scanf_s("%d", &LEN);
    printf("percentile 'p' (10~90) >> ");
    scanf_s("%d", &PROB);

    int Z = LEN - 3, C = LEN - 6, M = LEN - 2; //좀비, 시민, 마동석
    int Zturn = 1;

    printf("---------------\n");

    //기차 상단
    for (int i = 0; i < LEN; i++) {
        printf("#");
    }
    printf("\n");

    //기차 중단
    printf("#");

    //C위치
    for (int i = 0; i < C - 1; i++) {
        printf(" ");
    }
    printf("C");

    //Z위치
    for (int i = C; i < Z - 1; i++) {
        printf(" ");
    }
    printf("Z");

    //M위치
    for (int i = Z; i < M - 1; i++) {
        printf(" ");
    }
    printf("M");


    //우측#위치
    for (int i = 0; i <= LEN - M - 4; i++) {
        printf(" ");
    }
    printf("#\n");

    //기차 하단
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


        //Zturn 홀수번째
        Zturn = !Zturn;

        //C상태
        if (PROB < r1) {
            C--;
        }

        //Z상태
        if (PROB > r2 && Zturn) {
            Z--;
        }
        printf("\n");

        //기차 상단
        for (int i = 0; i < LEN; i++) {
            printf("#");
        }
        printf("\n");

        //기차 중단
        printf("#");

        //C위치
        for (int i = 0; i < C - 1; i++) {
            printf(" ");
        }
        printf("C");

        //Z위치
        for (int i = C; i < Z - 1; i++) {
            printf(" ");
        }
        printf("Z");

        //M위치
        for (int i = Z; i < M - 1; i++) {
            printf(" ");
        }
        printf("M");


        //우측#위치
        for (int i = 0; i <= LEN - M - 4; i++) {
            printf(" ");
        }
        printf("#\n");

        //기차 하단
        for (int i = 0; i < LEN; i++) {
            printf("#");
        }
        printf("\n");
        printf("\n");
        //C상태
        if (PROB < r1) {
            printf("citizen: %d -> %d\n", C + 1, C);
        }
        else {
            printf("citizen: stay %d\n", C);
        }

        //Z상태
        if (PROB > r2 && Zturn) {
            printf("zombie: %d -> %d", Z + 1, Z);
        }
        else {
            printf("zombie: stay %d", Z);
        }

        //Z쿨타임
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
            //기차 상단
            for (int i = 0; i < LEN; i++) {
                printf("#");
            }
            printf("\n");

            //기차 중단
            printf("#");

            //C위치
            for (int i = 0; i < C - 1; i++) {
                printf(" ");
            }
            printf("C");

            //Z위치
            for (int i = C; i < Z - 1; i++) {
                printf(" ");
            }
            printf("Z");

            //M위치
            for (int i = Z; i < M - 1; i++) {
                printf(" ");
            }
            printf("M");


            //우측#위치
            for (int i = 0; i <= LEN - M - 4; i++) {
                printf(" ");
            }
            printf("#\n");

            //기차 하단
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
            //기차 상단
            for (int i = 0; i < LEN; i++) {
                printf("#");
            }
            printf("\n");

            //기차 중단
            printf("#");

            //C위치
            for (int i = 0; i < C - 1; i++) {
                printf(" ");
            }
            printf("C");

            //Z위치
            for (int i = C; i < Z - 1; i++) {
                printf(" ");
            }
            printf("Z");

            //M위치
            for (int i = Z; i < M - 1; i++) {
                printf(" ");
            }
            printf("M");


            //우측#위치
            for (int i = 0; i <= LEN - M - 4; i++) {
                printf(" ");
            }
            printf("#\n");

            //기차 하단
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
    printf("게임이 종료되었습니다.\n");
    return 0;
}