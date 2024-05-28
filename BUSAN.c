#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>

//파라미터
#define LEN_MIN 15 //기차 길이
#define LEN_MAX 50
#define STM_MIN 0 //마동석 체력
#define STM_MAX 5
#define PROB_MIN 10 //확률
#define PROB_MAX 90
#define AGGRO_MIN 0 //어그로 범위
#define AGGRO_MAX 5

//마동석 이동 방향
#define MOVE_LEFT 1
#define MOVE_STAY 0

//좀비의 공격 대상
#define ATK_NONE 0
#define ATK_CITIZEN 1
#define ATK_DONGSEOK 2

//마동석 행동
#define ACTION_REST 0
#define ACTION_PROVOKE 1
#define ACTION_PULL 2

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

    //변수들
    int LEN, PROB, STM, MDS; // 길이, 확률, 스테미너, 마동석
    int Caggro = 1, Maggro = 1; // 시민 어그로, 마동석 어그로
    int action, stun = 999; // 스턴
    int z = 0;

    //입력값 처리
    while (1) {
        printf("train length(15~50)>> ");
        scanf_s("%d", &LEN);
        if (LEN <= LEN_MAX && LEN >= LEN_MIN)
            break;
    }
    while (1) {
        printf("madongseok stamina(0~5)>> ");
        scanf_s("%d", &STM);
        if (STM <= STM_MAX && STM >= STM_MIN)
            break;
    }
    while (1) {
        printf("percentile probability 'p'(10~90)>> ");
        scanf_s("%d", &PROB);
        if (PROB <= PROB_MAX && PROB >= PROB_MIN)
            break;
    }

    int Z = LEN - 3, C = LEN - 6, M = LEN - 2; //좀비, 시민, 마동석
    int Zturn = 1;

    printf("---------------\n");

    //기차
    for (int i = 0; i < LEN; i++)
        printf("#");
    printf("\n#");
    for (int i = 0; i < C - 1; i++)
        printf(" ");
    printf("C");
    for (int i = C; i < Z - 1; i++)
        printf(" ");
    printf("Z");
    for (int i = Z; i < M - 1; i++)
        printf(" ");
    printf("M");
    for (int i = 0; i <= LEN - M - 3; i++)
        printf(" ");
    printf("#\n");
    for (int i = 0; i < LEN; i++)
        printf("#");
    printf("\n---------------\n\n\n");

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


        //Zturn 홀수번째
        Zturn = !Zturn;

        //C상태
        if (PROB < r1)
            C--;

        //Z상태
        if (PROB > r2 && Zturn)
            Z--;
        printf("\n");

        //기차
        for (int i = 0; i < LEN; i++)
            printf("#");
        printf("\n#");
        for (int i = 0; i < C - 1; i++)
            printf(" ");
        printf("C");
        for (int i = C; i < Z - 1; i++)
            printf(" ");
        printf("Z");
        for (int i = Z; i < M - 1; i++)
            printf(" ");
        printf("M");
        for (int i = 0; i <= LEN - M - 3; i++)
            printf(" ");
        printf("#\n");
        for (int i = 0; i < LEN; i++)
            printf("#");
        prinf("\n\n");

        //C상태
        if (PROB < r1)
            printf("citizen: %d -> %d\n", C + 1, C);
        else
            printf("citizen: stay %d\n", C);

        //Z상태
        if (PROB > r2 && Zturn)
            printf("zombie: %d -> %d", Z + 1, Z);
        else
            printf("zombie: stay %d", Z);

        //Z쿨타임
        if (!Zturn)
            printf(" (cannot move)\n");
        else
            printf("\n");
        printf("\n");
        printf("---------------\n");
        printf("\n");

        //Citizen won
        if (C == 1) {
            //기차
            for (int i = 0; i < LEN; i++)
                printf("#");
            printf("\n#");
            for (int i = 0; i < C - 1; i++)
                printf(" ");
            printf("C");
            for (int i = C; i < Z - 1; i++)
                printf(" ");
            printf("Z");
            for (int i = Z; i < M - 1; i++)
                printf(" ");
            printf("M");
            for (int i = 0; i <= LEN - M - 3; i++)
                printf(" ");
            printf("#\n");
            for (int i = 0; i < LEN; i++)
                printf("#");


            printf("\n");
            printf("SUCCESS!\n");
            printf("citizen(s) escaped to the next train\n");
            break;
        }
        //Zombie won
        if (C + 1 == Z) {
            //기차
            for (int i = 0; i < LEN; i++)
                printf("#");
            printf("\n#");
            for (int i = 0; i < C - 1; i++)
                printf(" ");
            printf("C");
            for (int i = C; i < Z - 1; i++)
                printf(" ");
            printf("Z");
            for (int i = Z; i < M - 1; i++)
                printf(" ");
            printf("M");
            for (int i = 0; i <= LEN - M - 3; i++)
                printf(" ");
            printf("#\n");
            for (int i = 0; i < LEN; i++)
                printf("#");
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