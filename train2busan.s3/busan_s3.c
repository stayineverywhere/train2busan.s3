/*
 * ���α׷�: �λ���(3)
 * ���� ����: 2-1���� 2-4���� ��� �Ϸ�
 * �й�: 20232532
 * �̸�: ���ֿ�
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#include <stdbool.h>

 // 2-2 �Ķ���� ����
#define LEN_MIN 15 // ���� ����
#define LEN_MAX 50  
#define STM_MIN 0  // ������ ü��
#define STM_MAX 5
#define PROB_MIN 10 // Ȯ��
#define PROB_MAX 90 
#define AGGRO_MIN 0 //��׷� ����
#define AGGRO_MAX 5

//������ �̵� ����
#define MOVE_LEFT 1
#define MOVE_STAY 0

//������ ���� ���
#define ATK_NONE 0
#define ATK_CITIZEN 1
#define ATK_DONGSEOK 2
#define ATK_VILLAIN 3

//������ �ൿ
#define ACTION_REST 0
#define ACTION_PROVOKE 1
#define ACTION_PULL 2

void intro()
{
    //��Ʈ��
    printf("  *     *          **       *                **      *    * \n");
    printf("  *******        **  **     *****         ********   *    * \n");
    printf("  *     *      **     ***   *               *****    ****** \n");
    printf("  *******                                 **     **  *    * \n");
    printf("                                          **     **  *    * \n");
    printf("**********       **                         ****     *    * \n");
    printf("     *           **                      !           *    * \n");
    printf("     *           ************          !!!        **        \n");
    printf("     *                                  !!      **  **      \n");
    printf("     *                                  !!      **  **      \n");
    printf("     *                                  !!        **        \n");

}

void intro2()
{
    //��Ʈ��
    printf("  *     *          **       *                **      *    * \n");
    printf("  *******        **  **     *****         ********   *    * \n");
    printf("  *     *      **     ***   *               *****    ****** \n");
    printf("  *******                                 **     **  *    * \n");
    printf("                                          **     **  *    * \n");
    printf("**********       **                         ****     *    * \n");
    printf("     *           **                @@@@@@            *    * \n");
    printf("     *           ************         @@          **        \n");
    printf("     *                              @@          **  **      \n");
    printf("     *                            @@@@@@@@      **  **      \n");
    printf("     *                                            **        \n");
}

void intro3()
{
    //��Ʈ��
    printf("  *     *          **       *                **      *    * \n");
    printf("  *******        **  **     *****         ********   *    * \n");
    printf("  *     *      **     ***   *               *****    ****** \n");
    printf("  *******                                 **     **  *    * \n");
    printf("                                          **     **  *    * \n");
    printf("**********       **                         ****     *    * \n");
    printf("     *           **                ######            *    * \n");
    printf("     *           ************         ##          **        \n");
    printf("     *                             ###          **  **      \n");
    printf("     *                                ##        **  **      \n");
    printf("     *                            #######         **        \n");
}

void intro4()
{
    //��Ʈ��
    printf("  *     *          **       *                **      *    * \n");
    printf("  *******        **  **     *****         ********   *    * \n");
    printf("  *     *      **     ***   *               *****    ****** \n");
    printf("  *******                                 **     **  *    * \n");
    printf("                                          **     **  *    * \n");
    printf("**********       **                         ****     *    * \n");
    printf("     *           **                $$$$              *    * \n");
    printf("     *           ************     $$ $$           **        \n");
    printf("     *                           $$  $$         **  **      \n");
    printf("     *                          $$$$$$$         **  **      \n");
    printf("     *                               $$           **        \n");

}

void print_train(int train_length, int cp, int zp, int mp)
{
    // ������ �ʱ� ���� ���
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
    // ������ �ʱ� ���� ���
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
        // arr[i] > 0 : normal, -4 : dead, -9: ����� ���� �ù�
        if (arr[i] > 0 && arr[i] == v) 
            return TRUE;
    }
    return FALSE;
}

void print_train3(int train_length, int n, int cp[], int zp, int mp)
{
    // ������ �ʱ� ���� ���
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

void print_train4(int train_length, int n, int cp[], int m, int zs[], int zp, int mp)
// n : �ù� ��, cp : �ùε�
// m : ��ȭ �����, zs : ��ȭ �����
// zp, mp : �Ϲ� ����, ������
{
    // ������ �ʱ� ���� ���
    printf("\n");
    for (int i = 0; i < train_length; i++) {
        printf("#");
    }
    printf("\n#");
    for (int i = 1; i < train_length - 1; i++) {
        if (included(n, cp, i))
            printf("C");
        else if (included(m, zs, i) || zp == i)
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


// 2-2: ��ȿ�� ���� �Էµ� ������ �ٽ� �Է� ����
// ������ �������� �Է¹ޱ� ���Ͽ�, ȭ�� ǥ�� ���ڿ��� �ּ�, �ִ� ���� ���� ����
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
    // �ù� ���� ���
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
    // ���� ���� ���
    if (vp <= 0) return; // ������ <= 0�̸�, ������ ���� ����
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
    // ���� ���� ���
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
    // ���� ���� ���
    printf("zombie  : ");
    if (zt == 1) {
        if (ozp == zp)
            printf("stay %d\n", zp);
        else
            printf("%d -> %d\n", ozp, zp);

    }
    else {
        printf("stay %d (cannot move)\n", zp);
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

// 2-3: �ù� �̵�
int move_citizen(int prob, int cp)
{
    if (rand() % 100 < prob) {
        cp--;
    }
    return cp;
}

// 2-3: �̵��� ���� ��׷� ������Ʈ
int update_aggro(int aggro, int old, int current)
{
    // ��ġ�� �����Ǵ� ��� ��׷� ����
    if (old != current)
        aggro++;
    else // ���ڸ��� �ִ� ��� ��׷� ����
        aggro--;
    // ��׷� �ּ�, �ִ� �˻�
    if (aggro > AGGRO_MAX)
        aggro = AGGRO_MAX;
    if (aggro < AGGRO_MIN)
        aggro = AGGRO_MIN;
    return aggro;
}
// 2-3: ���� �̵�
int move_zombie(int prob, int zp)
{
    if (rand() % 100 < prob)
        zp--;
    return zp;
}

// 2-3: ������ �̵�
int move_dongseok(int move, int mp)
{
    if (move == MOVE_LEFT)
        mp--;
    return mp;
}

// 2-2: �Է� ��ó��
int get_dongseok_move(int mp, int zp)
{
    int move;
    //printf("������ �̵� (0. ���, 1. �������� �̵�) >> ");
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

// 2-4: ���� �ൿ �Լ�
int zombie_action(int cp, int mp, int ct_aggro, int ma_aggro, int zp)
{
    int action = ATK_NONE; // ���� ��� �ʱ�ȭ

    // �ΰ��� ������ ���
    if (zp == cp - 1 && zp == mp - 1) {
        // ��׷ΰ� ���� ���� ����
        if (ct_aggro > ma_aggro)
            action = ATK_CITIZEN; // �ù� ����
        else
            action = ATK_DONGSEOK; // ������ ����
    }
    else if (zp == cp - 1) {
        action = ATK_CITIZEN; // �ù� ����
    }
    else if (zp == mp - 1) {
        action = ATK_DONGSEOK; // ������ ����
    }
    return action;
}

// 2-2: �Է� ��ó��
int get_dongseok_action(int mp, int zp)
{
    int action;
    while (1) {
        if (mp == zp + 1)
            //printf("\n������ �ൿ ���� (0. �޽�, 1. ����, 2. �ٵ��) >> ");
            printf("madongseok action (0:rest, 1:provoke, 2:pull) >> ");
        else
            //printf("\n������ �ൿ ���� (0. �޽�, 1. ����) >> ");
            printf("madongseok action (0:rest, 1:provoke) >> ");
        scanf_s("%d", &action);
        if (mp == zp + 1 && action >= 0 && action <= 2) break;
        else if (mp != zp + 1 && action >= 0 && action <= 1) break;
    }
    return action;
}

// 2-4: ������ �ൿ �Լ�
// ma_stamina�� ma_aggro�� ������Ʈ�ϱ� ���Ͽ�, ma_status[2] �迭�� �̿��Ͽ� ������Ʈ��
// �Լ� ȣ������ ma_status�� ma_stamina�� ma_aggro�� �����ϰ�, �Լ� ȣ�� �Ŀ� ������
int dongseok_action(int prob, int mp, int action, int status[2])
{
    int aggro = status[0];
    int stamina = status[1];
    int zombie_hold = 0;

    if (action == ACTION_REST) {
        printf("madongseok rests...\n");
        if (aggro > AGGRO_MIN)
            aggro--;
        if (stamina < STM_MAX)
            stamina++;
        printf("madongseok : %d (aggro: %d -> %d, stamina: %d -> %d)\n", mp,
            status[0], aggro, status[1], stamina);
    }
    else if (action == ACTION_PROVOKE) {
        printf("madongseok provoked zombie...\n");
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
        if (rand() % 100 < prob) {
            printf("\nmadongseok pulled zombie... Next turn, it can't move.\n");
            zombie_hold = 1; // ���� �Ͽ� ���� �̵� �Ұ��� ǥ��
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

// ������ �̵� �Լ�
int move_villain(int prob, int vp, int cp ) {
    // ������ �׻� �ù��� �ٷ� �ڸ� ����ٴϹǷ�, �ù��� ��ġ�� ���� ������ ��ġ�� ������Ʈ�մϴ�.
    // ������ ��ġ�� ������ ������ ����� �ʵ��� ó���մϴ�.
    // ���� ��ġ�� �ùΰ� ��ġ�� �ʾƾ� ��.
    if (rand() % 100 < prob && vp - 1 != cp) 
        vp--;

    // ���� ������ ����� ��� �����մϴ�.
    if (vp < 1)
        vp = 1;

    return vp;
};


// ������ �ൿ �Լ�
int villain_action(int cp, int vp) {
    // ������ �ù��� ������ ��� �߾��� �õ��ϸ�, �׷��� ������ �ƹ� �ൿ�� ���� �ʽ��ϴ�.
    if (cp + 1 == vp) {
        if (rand() % 100 < 30) {
            // ������ �߾� ����
            printf("Villain attempted to trigger but succeeded! Citizen and Villain positions are swapped.\n");
            return TRUE;
        }
        else {
            printf("Villain attempted to trigger but failed!\n");
        }
    }
    return FALSE;
}

//�������� 1 ���� �Լ�
int stage_1(int train_length, int probability, int ma_stamina)
{
    // �ù�, ����, ������ ��ġ ���� ����
    int mp, zp, cp, omp, ozp, ocp;
    int zt = 0;         // ���� �̵� �÷���: 0: �̵�, 1: ����
    int ma_aggro = 1; // ������ ��׷�
    int ct_aggro = 1; // �ù� ��׷�
    int old_ma_aggro, old_ct_aggro; // ��׷� ���� ����� ���� ���� �� ����

    // ������, ����, �ù��� ��ġ �ʱ�ȭ
    mp = train_length - 2;
    zp = train_length - 3;
    cp = train_length - 6;

    // ���� ���� ���
    print_train(train_length, cp, zp, mp);

    while (1) {
        // ���� ��ġ ����
        ocp = cp;
        ozp = zp;
        omp = mp;

        // <�̵�> ������
        // �ù� �̵�
        cp = move_citizen(100 - probability, cp);
        ct_aggro = update_aggro(old_ct_aggro = ct_aggro, ocp, cp);

        // ���� �̵�
        if (zt == 0) {
            zp = move_zombie(probability, zp);
            zt = 1;
        }
        else {
            zt = 0;
        }

        // ���� ���� ���
        print_train(train_length, cp, zp, mp);
        // �ù� ���� ���
        print_citizen(ocp, cp, old_ct_aggro, ct_aggro);
        // ���� ���� ���
        print_zombie(zt, ozp, zp);
        // ���� ���� �˻�
        int game_over = check_gameover(cp, zp);
        if (game_over >= 0)
            return game_over;

        // ������ �̵� �Է� �ޱ�
        int move = get_dongseok_move(mp, zp);
        mp = move_dongseok(move, mp);
        ma_aggro = update_aggro(old_ma_aggro = ma_aggro, omp, mp);
        print_train(train_length, cp, zp, mp);
        print_dongseok(omp, mp, old_ma_aggro, ma_aggro, ma_stamina);

        // <�ൿ> ������
        // ������ �ൿ ó��
        int z_action = zombie_action(cp, mp, ct_aggro, ma_aggro, zp);

        // ������ ���� ��� ���
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

        // ������ �ൿ �Է� �ޱ�
        int action = get_dongseok_action(mp, zp);

        // ������ �ൿ ����
        int ma_status[2] = { ma_aggro, ma_stamina };
        zt = dongseok_action(100-probability, mp, action, ma_status);

        // �迭�� �̿��Ͽ� ����� ���� ����
        ma_aggro = ma_status[0];
        ma_stamina = ma_status[1];
    }
}

int zombie_action2(int cp, int vp, int mp, int ct_aggro, int vl_aggro, int ma_aggro, int zp)
{
    int action = ATK_NONE; // ���� ��� �ʱ�ȭ

    // �ΰ��� ������ ���
    if (zp == cp - 1 && zp == mp - 1) {
        // ��׷ΰ� ���� ���� ����
        if (ct_aggro > ma_aggro)
            action = ATK_CITIZEN; // �ù� ����
        else
            action = ATK_DONGSEOK; // ������ ����
    }
    else if (zp == vp - 1 && zp == mp - 1) {
        // ��׷ΰ� ���� ���� ����
        if (vl_aggro > ma_aggro)
            action = ATK_VILLAIN; // �ù� ����
        else
            action = ATK_DONGSEOK; // ������ ����
    }
    else if (zp == cp - 1) {
        action = ATK_CITIZEN; // �ù� ����
    }
    else if (zp == vp - 1) {
        action = ATK_VILLAIN; // ���� ����
    }
    else if (zp == mp - 1) {
        action = ATK_DONGSEOK; // ������ ����
    }
    return action;
}

// �������� 2 ���� �Լ�
int stage_2(int train_length, int probability, int ma_stamina) {
    // ����, �ù�, ������, ������ ��ġ ���� ����
    int zp, cp, mp, vp;
    int zt = 0;         // ���� �̵� �÷���: 0: �̵�, 1: ����
    int ct_aggro = 1; // �ù� ��׷�
    int ma_aggro = 1; // ������ ��׷�
    int old_ct_aggro, old_ma_aggro; // ��׷� ���� ����� ���� ���� �� ����
    int old_vl_aggro, vl_aggro = 1; // ����

    // �ʱ� ��ġ ����
    mp = train_length - 2;
    zp = train_length - 3;
    cp = train_length - 6;
    vp = cp + 1;  // ������ �ʱ� ��ġ

    intro2();
    // ���� ���� ���
    print_train2(train_length, cp, vp, zp, mp);

    while (1) {
        // ���� ��ġ ����
        int ocp = cp;
        int ozp = zp;
        int omp = mp;
        int ovp = vp;

        // �̵� ������
        // �ù� �̵�
        cp = move_citizen(100 - probability, cp);
        ct_aggro = update_aggro(old_ct_aggro = ct_aggro, ocp, cp);

        // ���� �̵�
        vp = move_villain(100-probability, vp, cp);
        vl_aggro = update_aggro(old_vl_aggro = vl_aggro, ovp, vp);

        // ���� �̵�
        if (zt == 0) {
            zp = move_zombie(probability, zp);
            zt = 1;
        }
        else {
            zt = 0;
        }

        // ���� ���� ���
        print_train2(train_length, cp, vp, zp, mp);
        // �ù� ���� ���
        print_citizen(ocp, cp, old_ct_aggro, ct_aggro);
        // ���� ���� ���
        if (vp > 0)
            print_villain(ovp, vp, old_vl_aggro, vl_aggro);
        // ���� ���� ���
        print_zombie(zt, ozp, zp);

        // ���� ���� �˻�
        int game_over = check_gameover(cp, zp);
        if (game_over >= 0)
            return game_over;

        // ������ �̵�
        int move = get_dongseok_move(mp, zp);
        mp = move_dongseok(move, mp);
        ma_aggro = update_aggro(old_ma_aggro = ma_aggro, omp, mp);
        print_train2(train_length, cp, vp, zp, mp);
        print_dongseok(omp, mp, old_ma_aggro, ma_aggro, ma_stamina);

        // �ൿ ������
        // ���� �߾�
        if (villain_action(cp, vp)) {
            // �ùΰ� ���� ��ġ ����
            int tmp = vp;
            vp = cp;
            cp = tmp;
        }
        // ������ �ൿ ó��
        int z_action = zombie_action2(cp, vp, mp, ct_aggro, vl_aggro, ma_aggro, zp);

        // ������ ���� ��� ���
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

        // �������� �ൿ �Է� �ޱ�
        int action = get_dongseok_action(mp, zp);

        // �������� �ൿ ����
        int ma_status[2] = { ma_aggro, ma_stamina };
        int zombie_hold = dongseok_action(100-probability, mp, action, ma_status);

        // �迭�� �̿��Ͽ� ����� ���� ����
        ma_aggro = ma_status[0];
        ma_stamina = ma_status[1];
    }
}

int init_citizens(int train_length, int citizens[50], int aggros[50]) {
	int num_citizens = train_length / 4 + rand() % (train_length / 2 - train_length / 4);

    // ù ��° �ù��� ������ ������ ���� ��ġ
    citizens[0] = train_length - 6;
    aggros[0] = 1;

    // ������ �ùε��� �������� ��ġ
    for (int i = 1; i < num_citizens; ++i) {
        int position=1;
        // �̹� �ù��� �ִ� ��ġ���� ��ġ���� �ʵ��� �ϱ� ���� while ���� ���
        if (rand() % 100 < 50)
            position += 1;
        citizens[i] = citizens[i - 1] - position;
        aggros[i] = 1;
    }
    return num_citizens;
}

void backup_array(int n, int old[], int cur[]) {
	for (int i = 0; i < n; ++i) {
		old[i] = cur[i];
	}
}

void move_citizens(int prob, int num_citizens, int citizens[50], int ct_aggros[50])
{
    // �ù��� �Ųٷ� ����Ǿ� ����
    for (int i = num_citizens - 1; i >= 0; i--) {
        int cp = citizens[i];
        if (rand() % 100 >= prob && (i == num_citizens-1 || cp - 1 != citizens[i + 1])) {
            if( ct_aggros[i] < AGGRO_MAX)
                ct_aggros[i]++;
            citizens[i]--;
        }
        else {
            if( ct_aggros[i] > AGGRO_MIN)
            ct_aggros[i]--;
        }
    }
}

int check_citizens(int num_citizens, int citizens[50], int ct_aggros[50])
{
    int n = num_citizens;
    if (citizens[n-1] == 0) {
        ct_aggros[n-1] = 0;
        n--;
        printf("\n** One citizen escaped!!.\n");
    }
    return n;
}

void print_citizen3(int no, int ocp, int cp, int oaggro, int aggro) {
    // �ù� ���� ���
    printf("citizen%d : ", no);
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

void print_citizens(int num_citizens, int ct_oldpos[50], int citizens[50], int oct_aggros[50], int ct_aggros[50])
{
    for (int i = 0; i < num_citizens; ++i) {
        print_citizen3(i, ct_oldpos[i], citizens[i], oct_aggros[i], ct_aggros[i]);
    }
}

int check_gameover3(int num_citizens, int citizens[50], int ct_aggros[50], int zp)
{
    int cp = citizens[0];
    if (cp == 1) {
        printf("\nSUCCESS! YOU WIN\n");
        printf("Citizen(s) escaped to the next train\n");
        return TRUE;
    }
    else if (zp == cp + 1) {
        printf("One citizen is dead. Citizen(s) has(have) been attacked by a zombie\n");
        int i;
        for (i = 1; i <  num_citizens; i++) {
            citizens[i-1] = citizens[i];
            ct_aggros[i-1] = ct_aggros[i];
        }
        citizens[num_citizens - 1] = 0;
        ct_aggros[num_citizens - 1] = 0;
        // i == 0�̸� ��� �ùε��� ����
        return (num_citizens == 1 ? FALSE : -1);
    }
    return -1;
}

int stage_3(int train_length, int probability, int ma_stamina) {
    // �ù�, ����, �������� ��ġ�� �����ϴ� �迭�� �ù��� �� ���� ����
    int citizens[50] = { 0 }; // �ִ� ���� ���̴� 50�̹Ƿ�
    int num_citizens;
    int zp, mp, omp , ozp;
    int zt = 0; // ���� �̵� �÷���: 0�� �̵�, 1�� ����
    int ma_aggro = 1; // ������ ��׷�
    int old_ma_aggro; // ��׷� ���� ����� ���� ���� �� ����
    int ct_oldpos[50], ct_aggros[50], oct_aggros[50];

    // ����� ������ �ʱ� ��ġ ����
    zp = train_length - 3;
    mp = train_length - 2;

    // ���� ���̿� ���� �ù� �� ����
    num_citizens = init_citizens(train_length, citizens, ct_aggros);

    intro3();
    // ���� ���� ���
    print_train3(train_length, num_citizens, citizens, zp, mp);

    while (1) {
        omp = mp;
        ozp = zp;
        backup_array(num_citizens, ct_oldpos, citizens);
        backup_array(num_citizens, oct_aggros, ct_aggros);

        // �ù� �̵�
        move_citizens(100-probability, num_citizens, citizens, ct_aggros);

        // Ż���� �ù� ������Ʈ
        num_citizens = check_citizens(num_citizens, citizens, ct_aggros);

        // ���� �̵�
        if (zt == 0) {
            zp = move_zombie(probability, zp);
            zt = 1;
        }
        else {
            zt = 0;
        }

        // ���� ���� ���
        print_train3(train_length, num_citizens, citizens, zp, mp);
        // �ù� ���� ���
        print_citizens(num_citizens, ct_oldpos, citizens, oct_aggros, ct_aggros);
        // ���� ���� ���
        print_zombie(zt, ozp, zp);

        // ���� ���� �˻�
        int game_over = check_gameover3(num_citizens, citizens, ct_aggros, zp);
        if (game_over >= 0)
            return game_over;
        else if (citizens[num_citizens - 1] == 0) {
            num_citizens--;
            printf("%d citizen(s) alive(s).\n", num_citizens);
        }

        // ������ �̵�
        int move = get_dongseok_move(mp, zp);
        mp = move_dongseok(move, mp);
        ma_aggro = update_aggro(old_ma_aggro = ma_aggro, omp, mp);
        print_train3(train_length, num_citizens, citizens, zp, mp);
        print_dongseok(omp, mp, old_ma_aggro, ma_aggro, ma_stamina);

        // �ൿ ������
        // ������ �ൿ ó��
        int z_action = zombie_action(citizens[0], mp, ct_aggros[0], ma_aggro, zp);

        // ������ ���� ��� ���
        printf("Citizen does nothing.\n");
        if (z_action == ATK_CITIZEN) {
            printf("GAME OVER! citizen dead..\n");
            return FALSE;
        }
        else if (z_action == ATK_DONGSEOK) {
            // �ù� ��׷δ� ������ �ù��� ��׷θ� �ǹ�
            printf("Zombie attacked madongseok (aggro: %d vs. %d, madongseok stamina: %d -> %d)\n",
                ct_aggros[0], ma_aggro, ma_stamina, ma_stamina - 1);
            if (--ma_stamina < STM_MIN) {
                printf("GAME OVER! madongseok's stamina(%d) is below than minimum stamina (%d)\n",
                    ma_stamina, STM_MIN);
                return FALSE;
            }
        }
        else { // ATK_NONE
            printf("Zombie attacked nobody.\n");
        }

        // �������� �ൿ �Է� �ޱ�
        int action = get_dongseok_action(mp, zp);

        // �������� �ൿ ����
        int ma_status[2] = { ma_aggro, ma_stamina };
        int zombie_hold = dongseok_action(100-probability, mp, action, ma_status);

        // �迭�� �̿��Ͽ� ����� ���� ����
        ma_aggro = ma_status[0];
        ma_stamina = ma_status[1];
    }
}

void print_zombie4(int i, int ozp, int zp)
{
    // ���� ���� ���
    printf("Reinforced zombie%d  : ",i);
    if (ozp == zp)
        printf("stay %d\n", zp);
    else
        printf("%d -> %d\n", ozp, zp);

}

void print_zombies(int num_zombies, int old_zombies[50], int zombies[50])
{
    for(int i = 0; i < num_zombies; i++)
        print_zombie4(i, old_zombies[i], zombies[i]);
}

void move_zombies(int prob, int num_zombies, int zombies[50])
{
    for (int i = num_zombies - 1; i >= 0; i--) {
        int zp = zombies[i];
        if (rand() % 100 < prob && (i == num_zombies - 1 || zp - 1 != zombies[i + 1])) {
            zombies[i]--;
        }
    }
}

int check_gameover4(int num_citizens, int citizens[50], int ct_aggros[50], int num_zombies, int zombies[50], int zp)
{
    // �׻� ù��° ���� (��ȭ ���� �ִ� ���, ��ȭ������ ������ �ε���)��
    // ������ �ù� (ù��° �ε���)�� ������
    int nz = num_zombies;
    if (nz > 0)
        zp = zombies[nz - 1];

    int cp = citizens[0]; // ������ �ù�
    if (cp == 1) {
        printf("\nSUCCESS! YOU WIN\n");
        printf("Citizen(s) escaped to the next train\n");
        return TRUE;
    }
    else if (zp == cp + 1) {
        printf("One citizen is dead. Citizen(s) has(have) been attacked by a zombie\n");
        int i;
        zombies[nz] = citizens[0];

        for (i = 1; i < num_citizens; i++) {
            citizens[i - 1] = citizens[i];
            ct_aggros[i - 1] = ct_aggros[i];
        }
        citizens[num_citizens - 1] = 0;
        ct_aggros[num_citizens - 1] = 0;
        // i == 0�̸� ��� �ùε��� ����
        return (num_citizens == 1 ? FALSE : -1);
    }
    return -1;
}

int stage_4(int train_length, int probability, int ma_stamina) {
    // �ù�, ����, �������� ��ġ�� �����ϴ� �迭�� �ù��� �� ���� ����
    int citizens[50] = { 0 }; // �ִ� ���� ���̴� 50�̹Ƿ�
    int num_citizens;
    int zombies[50] = { 0 };    // ��ȭ����
    int num_zombies = 0;
    int zp, mp, omp, ozp;
    int zt = 0; // ���� �̵� �÷���: 0�� �̵�, 1�� ����
    int ma_aggro = 1; // ������ ��׷�
    int old_ma_aggro; // ��׷� ���� ����� ���� ���� �� ����
    int ct_oldpos[50], ct_aggros[50], oct_aggros[50];
    int old_zombies[50];

    // ����� ������ �ʱ� ��ġ ����
    zp = train_length - 4;
    mp = train_length - 2;

    // ���� ���̿� ���� �ù� �� ����
    num_citizens = init_citizens(train_length, citizens, ct_aggros);

    intro4();
    // ���� ���� ���
    print_train4(train_length, num_citizens, citizens, num_zombies, zombies, zp, mp);

    while (1) {
        omp = mp;
        ozp = zp;
        backup_array(num_citizens, ct_oldpos, citizens);
        backup_array(num_citizens, oct_aggros, ct_aggros);
        backup_array(num_zombies, old_zombies, zombies);

        // �ù� �̵�
        move_citizens(100 - probability, num_citizens, citizens, ct_aggros);

        // Ż���� �ù� ������Ʈ
        num_citizens = check_citizens(num_citizens, citizens, ct_aggros);

        // ��ȭ ���� �̵�
        move_zombies(probability, num_zombies, zombies);

        // ���� �̵�
        if (zt == 0) {
            zp = move_zombie(probability, zp);
            if (num_zombies > 0 && zombies[num_zombies - 1] == zp) 
                // ��ȭ������ ��ġ�� ������ ��ġ�� ������ ���� �ڸ��� ����
                zp = ozp;
            zt = 1;
        }
        else {
            zt = 0;
        }

        // ���� ���� ���
        print_train4(train_length, num_citizens, citizens, num_zombies, zombies, zp, mp);
        // �ù� ���� ���
        print_citizens(num_citizens, ct_oldpos, citizens, oct_aggros, ct_aggros);
        // ���� ���� ���
        print_zombies(num_zombies, old_zombies, zombies);
        print_zombie(zt, ozp, zp);

        // ���� ���� �˻�
        int game_over = check_gameover4(num_citizens, citizens, ct_aggros, num_zombies, zombies, zp);
        if (game_over >= 0)
            return game_over;
        else {
            if (citizens[num_citizens - 1] == 0) {
                num_citizens--;
                printf("%d citizen(s) alive(s).\n", num_citizens);
                num_zombies++;
            }
        }

        // ������ �̵�
        int move = get_dongseok_move(mp, zp);
        mp = move_dongseok(move, mp);
        ma_aggro = update_aggro(old_ma_aggro = ma_aggro, omp, mp);
        print_train4(train_length, num_citizens, citizens, num_zombies, zombies, zp, mp);
        print_dongseok(omp, mp, old_ma_aggro, ma_aggro, ma_stamina);

        // �ൿ ������
        // ������ �ൿ ó��
        int z_action = zombie_action(citizens[0], mp, ct_aggros[0], ma_aggro, zp);

        // ������ ���� ��� ���
        printf("Citizen does nothing.\n");
        if (z_action == ATK_CITIZEN) {
            printf("GAME OVER! citizen dead..\n");
            return FALSE;
        }
        else if (z_action == ATK_DONGSEOK) {
            // �ù� ��׷δ� ������ �ù��� ��׷θ� �ǹ�
            printf("Zombie attacked madongseok (aggro: %d vs. %d, madongseok stamina: %d -> %d)\n",
                ct_aggros[0], ma_aggro, ma_stamina, ma_stamina - 1);
            if (--ma_stamina < STM_MIN) {
                printf("GAME OVER! madongseok's stamina(%d) is below than minimum stamina (%d)\n",
                    ma_stamina, STM_MIN);
                return FALSE;
            }
        }
        else { // ATK_NONE
            printf("Zombie attacked nobody.\n");
        }

        // �������� �ൿ �Է� �ޱ�
        int action = get_dongseok_action(mp, zp);

        // �������� �ൿ ����
        int ma_status[2] = { ma_aggro, ma_stamina };
        int zombie_hold = dongseok_action(100-probability, mp, action, ma_status);

        // �迭�� �̿��Ͽ� ����� ���� ����
        ma_aggro = ma_status[0];
        ma_stamina = ma_status[1];
    }
}

// �����Լ�
int main(void) {
    // �ù�, ����, ������ ���� �� Ȯ�� ���� ����
    int train_length;
    int probability;
    int ma_stamina; // ������ ü��

    intro();            // ��Ʈ�� ȭ�� ���
    srand(time(NULL));  // ���� �õ� ����

    // ������ ���� �Է� �ޱ�
    train_length = get_value("train length ", LEN_MIN, LEN_MAX);
    // ������ ���¹̳�
    ma_stamina = get_value("madongseok stamina ", STM_MIN, STM_MAX);
    // Ȯ�� �Է� �ޱ�
    probability = get_value("percentile probability 'p' ", PROB_MIN, PROB_MAX);

    if (stage_1(train_length, probability, ma_stamina) && stage_2(train_length, probability, ma_stamina) &&
        stage_3(train_length, probability, ma_stamina) && stage_4(train_length, probability, ma_stamina)){
        printf("WOW, You completed All stages!!!\n");
    }
    else {
        printf("You failed to complete all stages!!\n");
    }
    return 0;
}

