#include "WCT.h"
#include <cstdio>

void ALOHA(const int N, const double LAMBDA, const double DELAY_LAMBDA) {

    Broadcaster* broadcaster = new Broadcaster[N];
    int success = 0;
    int delay = 0;

    // 初期化
    for (int time = 0; time < 1; time++) {
        for (int index = 0; index < N; index++) {
            broadcaster[index].setInterval(LAMBDA);
        }
    }

    for (int slot = 1; slot < SLOT_NUM; slot++) {
        int fired = 0;	// このスロットで送信した数
        int firstFiredBroadcaster = -1; // 最初に送った局
        int firstFiredBroadcasterDelay = 0;	// 最初に送った局の遅延時間
        
        for (int index = 0; index < N; index++) {
            broadcaster[index].advancingTime();

            if (broadcaster[index].isFiring()) {
                fired++;
                if (fired == 1) {
                    firstFiredBroadcaster = index;
                    firstFiredBroadcasterDelay = broadcaster[index].delay;
                    broadcaster[index].setInterval(LAMBDA);
                }
                // 衝突発生時は初めに発火したやつと今発火したやつを遅延再送
                if (fired == 2) {
                    // 再送時間は上書きされる
                    broadcaster[firstFiredBroadcaster].setDelayInterval(DELAY_LAMBDA);
                }
                if (fired >= 2) {
                    broadcaster[index].setDelayInterval(DELAY_LAMBDA);
                }
            }
        }
        if (fired == 1) {
            // 衝突してないのでOK
            success++;
            delay += firstFiredBroadcasterDelay;
        }
    }

    printf("%lf, %lf, %d\n", LAMBDA, (double)success / SLOT_NUM, delay);
    delete[] broadcaster;
}
