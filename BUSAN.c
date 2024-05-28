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
    srand((unsigned int)time(NULL));
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

    if (LEN < LEN_MIN || LEN > LEN_MAX || PROB < PROB_MIN || PROB > PROB_MAX)
        return 0;

    while (1) {
        //난수
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
        if (Zturn) {
            if (Caggro >= Maggro && C + 1 != Z && z != stun)
                Z--;
            else if (Caggro < Maggro && M - 1 != Z && z != stun)
                Z++;
            else if (z == stun) {
                printf("madongseok pulled zombie. ");
            }
        }
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
        printf("\n\n");

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
        printf("\n---------------\n\n");

        //M입력
        while (1) {
            printf("madongseok move(0:stay, 1:left)>> ");
            scanf_s("%d", &MDS);
            if (MDS == MOVE_STAY || MDS == MOVE_LEFT && M - 1 != Z)
                break;
            else
                printf("제자리 대기만 가능합니다.\n");
        }
        if (MDS == MOVE_LEFT) {
            M--;
            if (Maggro != AGGRO_MAX)
                Maggro++;
        }
        if (MDS == MOVE_STAY)
            if (Maggro != AGGRO_MIN)
                Maggro--;

        //페이즈 2
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
        printf("\n\n");

        //페이즈 2 M상태
        if (MDS == MOVE_LEFT)
            printf("\n\nmadongseok:  %d -> %d(aggro: %d -> %d, stamina: %d)\n\n", M + 1, M, Maggro - 1, Maggro, STM);
        if (MDS == MOVE_STAY)
            printf("\n\nmadongseok: stay %d(aggro: %d -> %d, stamina: %d)\n\n", M, Maggro + 1, Maggro, STM);

        //C
        if (C != Z - 1)
            printf("citizen does nothing.\n");
        //Z
        if (Z != C + 1 || Z != M - 1)
            printf("zonbie attacked nobody.\n");
        //M action
        while (1) {
            z = 0;
            if (M == Z + 1)
                printf("madongseok action(0.rest, 1.provoke, 2.pull)>> ");
            else
                printf("madongseok action(0.rest, 1.provoke)>> ");
            scanf_s("%d", &action);
            if (action == ACTION_REST) {
                if (Maggro != AGGRO_MIN)
                    Maggro--;
                if (STM != STM_MAX)
                    STM++;
                printf("madongseok rests...\n\n");
                if (Maggro != AGGRO_MIN && STM != STM_MAX)
                    printf("madongseok: %d (aggro: %d -> %d, stamina: %d -> %d)\n", M, Maggro + 1, Maggro, STM - 1, STM);
                else if (Maggro == AGGRO_MIN && STM != STM_MAX)
                    printf("madongseok: %d (aggro: %d -> %d, stamina: %d -> %d)\n", M, Maggro, Maggro, STM - 1, STM);
                else if (Maggro != AGGRO_MIN && STM == STM_MAX)
                    printf("madongseok: %d (aggro: %d -> %d, stamina: %d -> %d)\n", M, Maggro + 1, Maggro, STM, STM);
                else if (Maggro == AGGRO_MIN && STM == STM_MAX)
                    printf("madongseok: %d (aggro: %d -> %d, stamina: %d -> %d)\n", M, Maggro, Maggro, STM, STM);
                break;
            }
            else if (action == ACTION_PROVOKE) {
                int maggro = Maggro;
                Maggro = AGGRO_MAX;
                printf("madongseok provoked zombie...\n\n");
                printf("madongesok: %d, (aggro: %d -> %d, stamina: %d)\n", M, maggro, Maggro, STM);
                break;
            }
            else if (action == ACTION_PULL) {
                if (PROB < r2) {
                    if (Maggro + 1 != AGGRO_MAX || Maggro != AGGRO_MAX)
                        Maggro += 2;
                    STM--;
                    z = stun;
                    printf("madongseok pulled zombie... Next turn, it can't move\n\n");
                    break;
                }
                else {
                    z = 0;
                    printf("madongseok failed to pull zombie.\n\n");
                    break;
                }
            }
            else
                printf("잘못된 입력입니다.\n");
        }

        //zomnie attacked
        if (C == Z - 1 && M != Z + 1) {
            printf("GAME OVER! citizen dead...\n");
            break;
        }
        else if (C != Z - 1 && M == Z + 1) {
            STM--;
            printf("zombie attacked madongseok. madongseok stamina: %d -> %d\n", STM + 1, STM);
            if (STM == STM_MIN)
                break;
        }
        else if (C == Z - 1 && M == Z + 1) {
            if (Caggro > Maggro) {
                printf("zombie attacked Citizen (aggro: %d vs %d)\n", Caggro, Maggro);
                printf("GAME OVER! citizen dead\n");
                break;
            }
            if (Caggro <= Maggro) {
                printf("zombie attacked madongseok (aggro: %d vs %d, madongseok stamina: %d -> %d)\n", Caggro, Maggro, STM - 1, STM);
                if (STM == STM_MIN)
                    break;
            }
        }

        //Citizen won
        if (C == 1) {
            printf("\n");
            printf("SUCCESS!\n");
            printf("citizen(s) escaped to the next train\n");
            break;
        }
        //madongseok dead
        if (STM == STM_MIN) {
            printf("madongseok dead...\n");
            break;
        }
    }
    printf("게임이 종료되었습니다.\n");
    return 0;
}