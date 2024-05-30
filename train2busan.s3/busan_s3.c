/*
 * 프로그램: 부산헹(3)
 * 구현 내용: 2-1부터 2-4까지 모두 완료
 * 학번: 20232532
 * 이름: 윤주영
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#include <stdbool.h>

 // 2-2 파라미터 선언
#define LEN_MIN 15 // 기차 길이
#define LEN_MAX 50  
#define STM_MIN 0  // 마동석 체력
#define STM_MAX 5
#define PROB_MIN 10 // 확률
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
#define ATK_VILLAIN 3

//마동석 행동
#define ACTION_REST 0
#define ACTION_PROVOKE 1
#define ACTION_PULL 2

void intro()
{
    //인트로
    printf("  *     *          **       *                **      *    * \n");
    printf("  *******        **  **     *****         ********   *    * \n");
    printf("  *     *      **     ***   *               *****    ****** \n");
    printf("  *******                                 **     **  *    * \n");
    printf("                                          **     **  *    * \n");
    printf("**********       **                         ****     *    * \n");
    printf("     *           **                                  *    * \n");
    printf("     *           ************                     **        \n");
    printf("     *                                          **  **      \n");
    printf("     *                                          **  **      \n");
    printf("     *                                            **        \n");

}


void print_train(int train_length, int cp, int zp, int mp)
{
    // 열차의 초기 상태 출력
    printf("\n");
    for (int i = 0; i < train_length; i++) {
        printf("#");
    }
    printf("\n#");
    for (int i = 1; i < train_length - 1; i++) {
        if (i == cp)
            printf("C");
        else if (i == zp)
            printf("Z");
        else if (i == mp)
            printf("M");
        else
            printf(" ");
    }
    printf("#\n");
    for (int i = 0; i < train_length; i++) {
        printf("#");
    }
    printf("\n\n");
}

void print_train2(int train_length, int cp, int vp, int zp, int mp)
{
    // 열차의 초기 상태 출력
    printf("\n");
    for (int i = 0; i < train_length; i++) {
        printf("#");
    }
    printf("\n#");
    for (int i = 1; i < train_length - 1; i++) {
        if (i == cp)
            printf("C");
        else if (i == vp)
            printf("V");
        else if (i == zp)
            printf("Z");
        else if (i == mp)
            printf("M");
        else
            printf(" ");
    }
    printf("#\n");
    for (int i = 0; i < train_length; i++) {
        printf("#");
    }
    printf("\n\n");
}



int included(int n, int arr[], int v)
{
    for (int i = 0; i < n; i++) {
        if (arr[i] == v)
            return TRUE;
    }
    return FALSE;
}

void print_train3(int train_length, int n, int cp[], int zp, int mp)
{
    // 열차의 초기 상태 출력
    printf("\n");
    for (int i = 0; i < train_length; i++) {
        printf("#");
    }
    printf("\n#");
    for (int i = 1; i < train_length - 1; i++) {
        if (included(n, cp, i))
            printf("C");
        else if (i == zp)
            printf("Z");
        else if (i == mp)
            printf("M");
        else
            printf(" ");
    }
    printf("#\n");
    for (int i = 0; i < train_length; i++) {
        printf("#");
    }
    printf("\n\n");
}

void print_train4(int train_length, int n, int cp[], int m, int zp[], int mp)
{
    // 열차의 초기 상태 출력
    printf("\n");
    for (int i = 0; i < train_length; i++) {
        printf("#");
    }
    printf("\n#");
    for (int i = 1; i < train_length - 1; i++) {
        if (included(n, cp, i))
            printf("C");
        else if (included(m, zp, i))
            printf("Z");
        else if (i == mp)
            printf("M");
        else
            printf(" ");
    }
    printf("#\n");
    for (int i = 0; i < train_length; i++) {
        printf("#");
    }
    printf("\n\n");
}


// 2-2: 유효한 값이 입력될 때까지 다시 입력 받음
// 동일한 형식으로 입력받기 위하여, 화면 표시 문자열과 최소, 최대 값을 전달 받음
int get_value(char prompt[], int min_val, int max_val)
{
    int value;
    printf("%s(%d ~ %d)>> ", prompt, min_val, max_val);
    scanf_s("%d", &value);
    while (value < min_val || value > max_val) {
        printf("%s(%d ~ %d)>> ", prompt, min_val, max_val);
        scanf_s("%d", &value);
    }
    return value;
}


void print_citizen(int ocp, int cp, int oaggro, int aggro)
{
    // 시민 상태 출력
    printf("citizen : ");
    if (ocp == cp) {
        printf("stay %d ", cp);
    }
    else {
        printf("%d -> %d ", ocp, cp);
    }

    printf("(aggro: ");
    if (oaggro == aggro)
        printf("%d", aggro);
    else
        printf("%d -> %d", oaggro, aggro);
    printf(")\n");
}

void print_villain(int ovp, int vp, int oaggro, int aggro)
{
    // 시민 상태 출력
    printf("villain : ");
    if (ovp == vp) {
        printf("stay %d ", vp);
    }
    else {
        printf("%d -> %d ", ovp, vp);
    }

    printf("(aggro: ");
    if (oaggro == aggro)
        printf("%d", aggro);
    else
        printf("%d -> %d", oaggro, aggro);
    printf(")\n");
}

void print_dongseok(int omp, int mp, int oaggro, int aggro, int stamina)
{
    // 동석 상태 출력
    printf("madongseok : ");
    if (omp == mp) {
        printf("stay %d", mp);
    }
    else {
        printf("%d -> %d", omp, mp);
    }

    printf("(aggro: ");
    if (oaggro == aggro)
        printf("%d, ", aggro);
    else
        printf("%d -> %d, ", oaggro, aggro);
    printf("stamina: %d)\n\n", stamina);
}

void print_zombie(int zt, int ozp, int zp)
{
    // 좀비 상태 출력
    printf("zombie  : ");
    if (zt == 1) {
        if (ozp == zp)
            printf("stay %d\n\n", zp);
        else
            printf("%d -> %d\n\n", ozp, zp);

    }
    else {
        printf("stay %d (cannot move)\n\n", zp);
    }

}

int check_gameover(int cp, int zp)
{
    if (cp == 1) {
        printf("\nSUCCESS! YOU WIN\n");
        printf("Citizen(s) escaped to the next train\n");
        return TRUE;
    }
    else if (zp == cp + 1) {
        printf("\nGAME OVER!\n");
        printf("Citizen(s) has(have) been attacked by a zombie\n");
        return FALSE;
    }
    return -1;
}

// 2-3: 시민 이동
int move_citizen(int prob, int cp)
{
    if (rand() % 100 >= prob) {
        cp--;
    }
    return cp;
}

// 2-3: 이동에 따른 어그로 업데이트
int update_aggro(int aggro, int old, int current)
{
    // 위치가 변동되는 경우 어그로 증가
    if (old != current)
        aggro++;
    else // 제자리에 있는 경우 어그로 감소
        aggro--;
    // 어그로 최소, 최대 검사
    if (aggro > AGGRO_MAX)
        aggro = AGGRO_MAX;
    if (aggro < AGGRO_MIN)
        aggro = AGGRO_MIN;
    return aggro;
}
// 2-3: 좀비 이동
int move_zombie(int prob, int zp)
{
    if (rand() % 100 < prob)
        zp--;
    return zp;
}

// 2-3: 마동석 이동
int move_dongseok(int move, int mp)
{
    if (move == MOVE_LEFT)
        mp--;
    return mp;
}

// 2-2: 입력 값처리
int get_dongseok_move(int mp, int zp)
{
    int move;
    //printf("마동석 이동 (0. 대기, 1. 왼쪽으로 이동) >> ");
    while (1) {
        if (mp != zp + 1)
            printf("madongseok move (0:stay, 1:left) >> ");
        else
            printf("madongseok move (0:stay) >> ");
        scanf_s("%d", &move);
        if (mp == zp + 1 && move == 0) break;
        else if (mp != zp + 1 && (move == 0 || move == 1)) break;
    }
    return move;
}

// 2-4: 좀비 행동 함수
int zombie_action(int cp, int mp, int ct_aggro, int ma_aggro, int zp)
{
    int action = ATK_NONE; // 공격 대상 초기화

    // 인간과 인접한 경우
    if (zp == cp - 1 && zp == mp - 1) {
        // 어그로가 높은 쪽을 공격
        if (ct_aggro > ma_aggro)
            action = ATK_CITIZEN; // 시민 공격
        else
            action = ATK_DONGSEOK; // 마동석 공격
    }
    else if (zp == cp - 1) {
        action = ATK_CITIZEN; // 시민 공격
    }
    else if (zp == mp - 1) {
        action = ATK_DONGSEOK; // 마동석 공격
    }
    return action;
}

// 2-2: 입력 값처리
int get_dongseok_action(int mp, int zp)
{
    int action;
    while (1) {
        if (mp == zp + 1)
            //printf("\n마동석 행동 선택 (0. 휴식, 1. 도발, 2. 붙들기) >> ");
            printf("madongseok action (0:rest, 1:provoke, 2:pull) >> ");
        else
            //printf("\n마동석 행동 선택 (0. 휴식, 1. 도발) >> ");
            printf("madongseok action (0:rest, 1:provoke) >> ");
        scanf_s("%d", &action);
        if (mp == zp + 1 && action >= 0 && action <= 2) break;
        else if (mp != zp + 1 && action >= 0 && action <= 1) break;
    }
    return action;
}

// 2-4: 마동석 행동 함수
// ma_stamina와 ma_aggro를 업데이트하기 위하여, ma_status[2] 배열을 이용하여 업데이트함
// 함수 호출전에 ma_status에 ma_stamina와 ma_aggro를 복사하고, 함수 호출 후에 복원함
int dongseok_action(int prob, int mp, int action, int status[2])
{
    int aggro = status[0];
    int stamina = status[1];
    int zombie_hold = 0;

    if (action == ACTION_REST) {
        printf("\nmadongseok rests...\n");
        if (aggro > AGGRO_MIN)
            aggro--;
        if (stamina < STM_MAX)
            stamina++;
        printf("madongseok : %d (aggro: %d -> %d, stamina: %d -> %d)\n", mp,
            status[0], aggro, status[1], stamina);
    }
    else if (action == ACTION_PROVOKE) {
        printf("\nmadongseok provoked zombie...\n");
        aggro = AGGRO_MAX;
        printf("madongseok : %d (aggro: %d -> %d, stamina: %d)\n", mp,
            status[0], aggro, stamina);
    }
    else if (action == ACTION_PULL) {
        aggro += 2;
        if (aggro > AGGRO_MAX)
            aggro = AGGRO_MAX;
        if (stamina > STM_MIN)
            stamina--;
        if (rand() % 100 >= prob) {
            printf("\nmadongseok pulled zombie... Next turn, it can't move.\n");
            zombie_hold = 1; // 다음 턴에 좀비 이동 불가능 표시
        }
        else {
            printf("\nmadongseok failed to pull zombie.\n");
        }
        printf("madongseok : %d (aggro: %d -> %d, stamina: %d -> %d)\n", mp,
            status[0], aggro, status[1], stamina);
    }
    status[0] = aggro;
    status[1] = stamina;
    return zombie_hold;
}

int stage_1(int train_length, int probability, int ma_stamina);
int stage_2(int train_length, int probability, int ma_stamina);
int stage_3(int train_length, int probability, int ma_stamina);
int stage_4(int train_length, int probability, int ma_stamina);

// 빌런의 이동 함수
int move_villain(int vp , int prob) {
    // 빌런은 항상 시민의 바로 뒤를 따라다니므로, 시민의 위치에 따라 빌런의 위치를 업데이트합니다.
    // 빌런의 위치가 열차의 범위를 벗어나지 않도록 처리합니다.
    if (rand() % 100 < prob)
        vp--;

    // 열차 범위를 벗어나는 경우 보정합니다.
    if (vp < 1)
        vp = 1;

    return vp;
};


// 빌런의 행동 함수
int villain_action(int cp, int vp) {
    // 빌런은 시민이 인접한 경우 발암을 시도하며, 그렇지 않으면 아무 행동도 하지 않습니다.
    if (cp + 1 == vp && rand() % 100 < 30) {
        // 빌런의 발암 성공
        printf("Villain attempted to trigger but succeeded! Citizen and Villain positions are swapped.\n");
        return TRUE;
    }
    else {
        printf("Villain attempted to trigger but failed!\n");
        return FALSE;
    }
}

// 메인함수
int main(void) {
    // 시민, 좀비, 열차의 길이 및 확률 변수 선언
    int train_length;
    int probability;
    int ma_stamina; // 마동석 체력

    intro();            // 인트로 화면 출력
    srand(time(NULL));  // 난수 시드 설정

    // 열차의 길이 입력 받기
    train_length = get_value("train length ", LEN_MIN, LEN_MAX);
    // 마동석 스태미나
    ma_stamina = get_value("madongseok stamina ", STM_MIN, STM_MAX);
    // 확률 입력 받기
    probability = get_value("percentile probability 'p' ", PROB_MIN, PROB_MAX);

    /*stage_2(train_length, probability, ma_stamina);*/
    /*
    //스테이지 1 실행
    if (stage_1(train_length, probability, ma_stamina) && stage_2(train_length, probability, ma_stamina) &&
        stage_3(train_length, probability, ma_stamina) && statge_4(train_length, probability, ma_stamina)){
        printf("WOW, You completed All stages!!!\n");
    }
    else {
        printf("You failed to complete all stages!!\n");
    }
    */
    stage_3(train_length,probability, ma_stamina);
    return 0;
}

//스테이지 1 실행 함수
int stage_1(int train_length, int probability, int ma_stamina)
{
    // 시민, 좀비, 열차의 위치 변수 선언
    int mp, zp, cp, omp, ozp, ocp;
    int zt = 0;         // 좀비 이동 플래그: 0: 이동, 1: 멈춤
    int ma_aggro = 1; // 마동석 어그로
    int ct_aggro = 1; // 시민 어그로
    int old_ma_aggro, old_ct_aggro; // 어그로 변동 출력을 위해 이전 값 저장

    // 마동석, 좀비, 시민의 위치 초기화
    mp = train_length - 2;
    zp = train_length - 3;
    cp = train_length - 6;

    // 열차 상태 출력
    print_train(train_length, cp, zp, mp);

    while (1) {
        // 현재 위치 보관
        ocp = cp;
        ozp = zp;
        omp = mp;

        // <이동> 페이즈
        // 시민 이동
        cp = move_citizen(100 - probability, cp);
        ct_aggro = update_aggro(old_ct_aggro = ct_aggro, ocp, cp);

        // 좀비 이동
        if (zt == 0) {
            zp = move_zombie(probability, zp);
            zt = 1;
        }
        else {
            zt = 0;
        }

        // 열차 상태 출력
        print_train(train_length, cp, zp, mp);
        // 시민 상태 출력
        print_citizen(ocp, cp, old_ct_aggro, ct_aggro);
        // 좀비 상태 출력
        print_zombie(zt, ozp, zp);
        // 게임 종료 검사
        int game_over = check_gameover(cp, zp);
        if (game_over >= 0)
            return game_over;

        // 마동석 이동 입력 받기
        int move = get_dongseok_move(mp, zp);
        mp = move_dongseok(move, mp);
        ma_aggro = update_aggro(old_ma_aggro = ma_aggro, omp, mp);
        print_train(train_length, cp, zp, mp);
        print_dongseok(omp, mp, old_ma_aggro, ma_aggro, ma_stamina);

        // <행동> 페이즈
        // 좀비의 행동 처리
        int z_action = zombie_action(cp, mp, ct_aggro, ma_aggro, zp);

        // 좀비의 공격 대상 출력
        printf("Citizen does nothing.\n");
        if (z_action == ATK_CITIZEN) {
            printf("GAME OVER! citizen dead..\n");
            return FALSE;
        }
        else if (z_action == ATK_DONGSEOK) {
            printf("Zombie attacked madongseok (aggro: %d vs. %d, madongseok stamina: %d -> %d)\n",
                ct_aggro, ma_aggro, ma_stamina, ma_stamina - 1);
            if (--ma_stamina < STM_MIN) {
                printf("GAME OVER! madongseok's stamina(%d) is below than minimum stamina (%d)\n",
                    ma_stamina, STM_MIN);
                return FALSE;
            }

        }
        else { // ATK_NONE
            printf("Zombie attacked nobody.\n");
        }

        // 마동석 행동 입력 받기
        int action = get_dongseok_action(mp, zp);

        // 마동석 행동 수행
        int ma_status[2] = { ma_aggro, ma_stamina };
        zt = dongseok_action(probability, mp, action, ma_status);

        // 배열을 이용하여 변경된 값을 복원
        ma_aggro = ma_status[0];
        ma_stamina = ma_status[1];
    }
}

int zombie_action2(int cp, int vp, int mp, int ct_aggro, int vl_aggro, int ma_aggro, int zp)
{
    int action = ATK_NONE; // 공격 대상 초기화

    // 인간과 인접한 경우
    if (zp == cp - 1 && zp == mp - 1) {
        // 어그로가 높은 쪽을 공격
        if (ct_aggro > ma_aggro)
            action = ATK_CITIZEN; // 시민 공격
        else
            action = ATK_DONGSEOK; // 마동석 공격
    }
    else if (zp == vp - 1 && zp == mp - 1) {
        // 어그로가 높은 쪽을 공격
        if (vl_aggro > ma_aggro)
            action = ATK_VILLAIN; // 시민 공격
        else
            action = ATK_DONGSEOK; // 마동석 공격
    }
    else if (zp == cp - 1) {
        action = ATK_CITIZEN; // 시민 공격
    }
    else if (zp == vp - 1) {
        action = ATK_VILLAIN; // 빌런 공격
    }
    else if (zp == mp - 1) {
        action = ATK_DONGSEOK; // 마동석 공격
    }
    return action;
}

// 스테이지 2 실행 함수
int stage_2(int train_length, int probability, int ma_stamina) {
    // 좀비, 시민, 마동석, 빌런의 위치 변수 선언
    int zp, cp, mp, vp;
    int zt = 0;         // 좀비 이동 플래그: 0: 이동, 1: 멈춤
    int ct_aggro = 1; // 시민 어그로
    int ma_aggro = 1; // 마동석 어그로
    int old_ct_aggro, old_ma_aggro; // 어그로 변동 출력을 위해 이전 값 저장
    int old_vl_aggro, vl_aggro = 1; // 빌런

    // 초기 위치 설정
    mp = train_length - 2;
    zp = train_length - 3;
    cp = train_length - 6;
    vp = cp + 1;  // 빌런의 초기 위치

    // 열차 상태 출력
    print_train2(train_length, cp, vp, zp, mp);

    while (1) {
        // 현재 위치 저장
        int ocp = cp;
        int ozp = zp;
        int omp = mp;
        int ovp = vp;

        // 이동 페이즈
        // 시민 이동
        cp = move_citizen(100 - probability, cp);
        ct_aggro = update_aggro(old_ct_aggro = ct_aggro, ocp, cp);

        // 빌런 이동
        vp = move_villain(ocp, cp, vp);
        vl_aggro = update_aggro(old_vl_aggro = vl_aggro, ovp, vp);

        // 좀비 이동
        if (zt == 0) {
            zp = move_zombie(probability, zp);
            zt = 1;
        }
        else {
            zt = 0;
        }
        // 마동석 이동
        int move = get_dongseok_move(mp, zp);
        mp = move_dongseok(move, mp);
        ma_aggro = update_aggro(old_ma_aggro = ma_aggro, omp, mp);

        // 열차 상태 출력
        print_train2(train_length, cp, vp, zp, mp);
        // 시민 상태 출력
        print_citizen(ocp, cp, old_ct_aggro, ct_aggro);
        // 빌런 상태 출력
        if (vp != -1)
            print_villain(ovp, vp, old_vl_aggro, vl_aggro);
        // 좀비 상태 출력
        print_zombie(zt, ozp, zp);
        // 마동석 상태 출력
        print_dongseok(omp, mp, old_ma_aggro, ma_aggro, ma_stamina);

        // 게임 종료 검사
        int game_over = check_gameover(cp, zp);
        if (game_over >= 0)
            return game_over;

        // 행동 페이즈

        // 빌런 발암
        if (villain_action(cp, vp)) {
            // 시민과 빌런 위치 변경
            int tmp = vp;
            vp = cp;
            cp = tmp;
        }
        // 좀비의 행동 처리
        int z_action = zombie_action2(cp, vp, mp, ct_aggro, vl_aggro, ma_aggro, zp);

        // 좀비의 공격 대상 출력
        printf("Citizen does nothing.\n");
        if (z_action == ATK_CITIZEN) {
            printf("GAME OVER! citizen dead..\n");
            return FALSE;
        }
        else if (z_action == ATK_VILLAIN) {
            printf("Villain is dead.. but continue game\n");
            vp = -1;
        }
        else if (z_action == ATK_DONGSEOK) {
            printf("Zombie attacked madongseok (aggro: %d vs. %d, madongseok stamina: %d -> %d)\n",
                ct_aggro, ma_aggro, ma_stamina, ma_stamina - 1);
            if (--ma_stamina < STM_MIN) {
                printf("GAME OVER! madongseok's stamina(%d) is below than minimum stamina (%d)\n",
                    ma_stamina, STM_MIN);
                return FALSE;
            }

        }
        else { // ATK_NONE
            printf("Zombie attacked nobody.\n");
        }

        // 마동석의 행동 입력 받기
        int action = get_dongseok_action(mp, zp);

        // 마동석의 행동 수행
        int ma_status[2] = { ma_aggro, ma_stamina };
        int zombie_hold = dongseok_action(probability, mp, action, ma_status);

        // 배열을 이용하여 변경된 값을 복원
        ma_aggro = ma_status[0];
        ma_stamina = ma_status[1];
    }
}

int stage_3(int train_length, int probability, int ma_stamina) {
    // 시민, 좀비, 마동석의 위치를 저장하는 배열과 시민의 수 변수 선언
    int citizens[50] = { 0 }; // 최대 열차 길이는 50이므로
    int num_citizens;
    int zp, mp,omp , ozp;
    int zt = 0; // 좀비 이동 플래그: 0은 이동, 1은 멈춤
    int ma_aggro = 1; // 마동석 어그로
    int old_ma_aggro; // 어그로 변동 출력을 위해 이전 값 저장

    // 열차 길이에 따라 시민 수 설정
    num_citizens = train_length / 4 + rand() % (train_length / 4 + 1);
    // 첫 번째 시민은 열차의 오른쪽 끝에 배치
    citizens[0] = train_length - 2;
    // 나머지 시민들은 무작위로 배치
    for (int i = 1; i < num_citizens; ++i) {
        int position;
        // 이미 시민이 있는 위치에는 배치하지 않도록 하기 위해 while 루프 사용
        while (1) {
            position = rand() % (train_length - 2) + 1;
            if (citizens[position] == 0) {
                break; // 이미 시민이 없는 위치에 도달했을 때 루프 종료
            }
        }
        citizens[position] = 1;
    }

    // 좀비와 마동석 초기 위치 설정
    zp = train_length - 3;
    mp = train_length - 2;

    // 열차 상태 출력
    print_train3(train_length, num_citizens, citizens, zp, mp);

    while (1) {
        omp = mp;
        ozp = zp;

        // 좀비 이동
        if (zt == 0) {
            zp = move_zombie(probability, zp);
            zt = 1;
        }
        else {
            zt = 0;
        }

        // 마동석 이동
        int move = get_dongseok_move(mp, zp);
        mp = move_dongseok(move, mp);
        ma_aggro = update_aggro(old_ma_aggro = ma_aggro, mp - move, mp);

        // 열차 상태 출력
        print_train3(train_length, num_citizens, citizens, zp, mp);

        // 시민 탈출 검사
        int escaped = 0;
        for (int i = 0; i < train_length - 2; ++i) {
            if (citizens[i] == 1 && i > zp + 1) {
                escaped = 1; // 좀비 뒤에 있는 시민이 탈출한 경우
                break;
            }
        }

        if (escaped) {
            printf("\nSUCCESS! All citizens escaped!\n");
            return TRUE;
        }

        // 생존한 시민이 없는지 검사
        int num_survivors = 0;
        for (int i = 0; i < train_length - 2; ++i) {
            if (citizens[i] == 1) {
                ++num_survivors;
            }
        }

        if (num_survivors == 0) {
            printf("\nGAME OVER! All citizens are dead.\n");
            return FALSE;
        }

        // 시민 이동 및 생존 여부 검사
        for (int i = 0; i < train_length - 2; ++i) {
            if (citizens[i] == 1) {
                citizens[i] = move_citizen(100 - probability, i);
                if (citizens[i] <= zp + 1) {
                    printf("A citizen has been attacked by a zombie!\n");
                    citizens[i] = 0; // 좀비에게 물린 시민 삭제
                }
            }
        }

        // 마동석 상태 출력
        print_dongseok(mp - move, mp, old_ma_aggro, ma_aggro, ma_stamina);
    }
}

int stage_4(int train_length, int probability, int ma_stamina) {
    // 좀비, 시민, 마동석, 빌런의 위치 변수 선언
    int zp, cp, mp, vp;
    int zt = 0;         // 좀비 이동 플래그: 0: 이동, 1: 멈춤

    int ct_aggro = 1; // 시민 어그로
    int ma_aggro = 1; // 마동석 어그로
    int old_ct_aggro, old_ma_aggro; // 어그로 변동 출력을 위해 이전 값 저장
    int old_vl_aggro, vl_aggro = 1; // 빌런

    // 초기 위치 설정
    mp = train_length - 2;
    zp = train_length - 3;
    cp = train_length - 6;
    vp = cp + 1;  // 빌런의 초기 위치

    // 열차 상태 출력
    print_train2(train_length, cp, vp, zp, mp);

    while (1) {
        // 현재 위치 저장
        int ocp = cp;
        int ozp = zp;
        int omp = mp;
        int ovp = vp;

        // 이동 페이즈
        // 시민 이동
        cp = move_citizen(100 - probability, cp);
        ct_aggro = update_aggro(old_ct_aggro = ct_aggro, ocp, cp);

        // 빌런 이동
        vp = move_villain(ocp, cp, vp);
        vl_aggro = update_aggro(old_vl_aggro = vl_aggro, ovp, vp);

        // 좀비 이동
        if (zt == 0) {
            zp = move_zombie(probability, zp);
            zt = 1;
        }
        else {
            zt = 0;
        }

        // 마동석 이동
        int move = get_dongseok_move(mp, zp);
        mp = move_dongseok(move, mp);
        ma_aggro = update_aggro(old_ma_aggro = ma_aggro, omp, mp);

        // 열차 상태 출력
        print_train2(train_length, cp, vp, zp, mp);
        // 시민 상태 출력
        print_citizen(ocp, cp, old_ct_aggro, ct_aggro);
        // 빌런 상태 출력
        if (vp != -1)
            print_villain(ovp, vp, old_vl_aggro, vl_aggro);
        // 좀비 상태 출력
        print_zombie(zt, ozp, zp);
        // 마동석 상태 출력
        print_dongseok(omp, mp, old_ma_aggro, ma_aggro, ma_stamina);

        // 게임 종료 검사
        int game_over = check_gameover(cp, zp);
        if (game_over >= 0)
            return game_over;

        // 행동 페이즈

        // 빌런 발암
        if (villain_action(cp, vp)) {
            // 시민과 빌런 위치 변경
            int tmp = vp;
            vp = cp;
            cp = tmp;
        }
        // 좀비의 행동 처리
        int z_action = zombie_action2(cp, vp, mp, ct_aggro, vl_aggro, ma_aggro, zp);

        // 좀비의 공격 대상 출력
        printf("Citizen does nothing.\n");
        if (z_action == ATK_CITIZEN) {
            printf("GAME OVER! citizen dead..\n");
            return FALSE;
        }
        else if (z_action == ATK_VILLAIN) {
            printf("Villain is dead.. but continue game\n");
            vp = -1;
        }
        else if (z_action == ATK_DONGSEOK) {
            printf("Zombie attacked madongseok (aggro: %d vs. %d, madongseok stamina: %d -> %d)\n",
                ct_aggro, ma_aggro, ma_stamina, ma_stamina - 1);
            if (--ma_stamina < STM_MIN) {
                printf("GAME OVER! madongseok's stamina(%d) is below than minimum stamina (%d)\n",
                    ma_stamina, STM_MIN);
                return FALSE;
            }

        }
        else { // ATK_NONE
            printf("Zombie attacked nobody.\n");
        }

        // 마동석의 행동 입력 받기
        int action = get_dongseok_action(mp, zp);

        // 마동석의 행동 수행
        int ma_status[2] = { ma_aggro, ma_stamina };
        int zombie_hold = dongseok_action(probability, mp, action, ma_status);

        // 배열을 이용하여 변경된 값을 복원
        ma_aggro = ma_status[0];
        ma_stamina = ma_status[1];
    }
}