#pragma once
#include <cmath>
#include <random>

static std::random_device rndmm;
static std::mt19937 mt(rndmm());
static std::uniform_real_distribution<double> rnd(0, 1); // 0~1�̎����̗���

void ALOHA(const int N, const double LAMBDA, const double DELAY_LAMBDA);
void TDMA(const int N, const double LAMBDA);

static const int SLOT_NUM = 100000; // �X���b�g�̐�

struct Broadcaster {
    int delay;		// �x������(�X���b�g�P�ʂȂ̂Ő����l�ŗǂ�)
    int fireTime;		// ���΂܂ł̎c�莞��(�X���b�g�P�ʂȂ̂Ő����l�ŗǂ�)
    bool isDelaying;	// ���݁A�x����Ԃ�

    Broadcaster() {
        delay = 0;
        fireTime = 0;
        isDelaying = false;
    }

    // �C���^�[�o���v�Z
    inline double interval(double random, double lambda) {
        return((-1.0 / lambda) * log(random)) + 1.0;
    }

    // �ʏ펞�̃C���^�[�o���v�Z
    inline void setInterval(const double LAMBDA) {
        fireTime = (int)interval(rnd(mt), LAMBDA);
        isDelaying = false;
    }

    // �x�����̃C���^�[�o���v�Z
    inline void setDelayInterval(const double DELAY_LAMBDA) {
        fireTime = (int)interval(rnd(mt), DELAY_LAMBDA);
        isDelaying = true;
    }

    // ���M���邩�ǂ���
    inline bool isFiring() {
        return fireTime == 0;
    }

    // ���Ԃ�i�܂���
    inline void advancingTime() {
        if (fireTime >= 1) fireTime--;
        // �x����Ԃ��ǂ����Œx�����Ԃ�������
        if (isDelaying) delay++;
        else delay = 0;
    }
};
