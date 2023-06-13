#include "WCT.h"
#include <cstdio>

void ALOHA(const int N, const double LAMBDA, const double DELAY_LAMBDA) {

    Broadcaster* broadcaster = new Broadcaster[N];
    int success = 0;
    int delay = 0;

    // ������
    for (int time = 0; time < 1; time++) {
        for (int index = 0; index < N; index++) {
            broadcaster[index].setInterval(LAMBDA);
        }
    }

    for (int slot = 1; slot < SLOT_NUM; slot++) {
        int fired = 0;	// ���̃X���b�g�ő��M������
        int firstFiredBroadcaster = -1; // �ŏ��ɑ�������
        int firstFiredBroadcasterDelay = 0;	// �ŏ��ɑ������ǂ̒x������
        
        for (int index = 0; index < N; index++) {
            broadcaster[index].advancingTime();

            if (broadcaster[index].isFiring()) {
                fired++;
                if (fired == 1) {
                    firstFiredBroadcaster = index;
                    firstFiredBroadcasterDelay = broadcaster[index].delay;
                    broadcaster[index].setInterval(LAMBDA);
                }
                // �Փ˔������͏��߂ɔ��΂�����ƍ����΂������x���đ�
                if (fired == 2) {
                    // �đ����Ԃ͏㏑�������
                    broadcaster[firstFiredBroadcaster].setDelayInterval(DELAY_LAMBDA);
                }
                if (fired >= 2) {
                    broadcaster[index].setDelayInterval(DELAY_LAMBDA);
                }
            }
        }
        if (fired == 1) {
            // �Փ˂��ĂȂ��̂�OK
            success++;
            delay += firstFiredBroadcasterDelay;
        }
    }

    printf("%lf, %lf, %d\n", LAMBDA, (double)success / SLOT_NUM, delay);
    delete[] broadcaster;
}
