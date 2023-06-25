#include "WCT.h"
#include <cstdio>

void TDMA(const int N, const double LAMBDA) {
    
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
        for (int index = 0; index < N; index++) {
            broadcaster[index].advancingTime();

            if (broadcaster[index].isFiring()) {
                if (slot % N != index) {
                    broadcaster[index].isDelaying = true;
                } else {
                    success++;	// �Փ˂͋N���肦�Ȃ�
                    delay += broadcaster[index].delay;
                    broadcaster[index].setInterval(LAMBDA);	// �x����ԂłȂ��Ȃ�
                }
            }
        }
    }

    printf("%lf, %lf, %d\n", LAMBDA, (double)success / SLOT_NUM, delay);
    delete[] broadcaster;
}
