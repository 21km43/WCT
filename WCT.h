#pragma once
#include <cmath>
#include <random>

static std::random_device rndmm;
static std::mt19937 mt(rndmm());
static std::uniform_real_distribution<double> rnd(0, 1); // 0~1の実数の乱数

void ALOHA(const int N, const double LAMBDA, const double DELAY_LAMBDA);
void TDMA(const int N, const double LAMBDA);

static const int SLOT_NUM = 100000; // スロットの数

struct Broadcaster {
    int delay;		// 遅延時間(スロット単位なので整数値で良い)
    int fireTime;		// 発火までの残り時間(スロット単位なので整数値で良い)
    bool isDelaying;	// 現在、遅延状態か

    Broadcaster() {
        delay = 0;
        fireTime = 0;
        isDelaying = false;
    }

    // インターバル計算
    inline double interval(double random, double lambda) {
        return((-1.0 / lambda) * log(random)) + 1.0;
    }

    // 通常時のインターバル計算
    inline void setInterval(const double LAMBDA) {
        fireTime = (int)interval(rnd(mt), LAMBDA);
        isDelaying = false;
    }

    // 遅延時のインターバル計算
    inline void setDelayInterval(const double DELAY_LAMBDA) {
        fireTime = (int)interval(rnd(mt), DELAY_LAMBDA);
        isDelaying = true;
    }

    // 送信するかどうか
    inline bool isFiring() {
        return fireTime == 0;
    }

    // 時間を進ませる
    inline void advancingTime() {
        if (fireTime >= 1) fireTime--;
        // 遅延状態かどうかで遅延時間をかえる
        if (isDelaying) delay++;
        else delay = 0;
    }
};
