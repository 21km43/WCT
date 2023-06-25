#include "WCT.h"
#include <iostream>

int main(int argc, char *argv[])
{
    int mode;

    if (argc < 2) {
        std::cout << "Simulation mode\n" << "  Slotted ALOHA (Normal resend rate): 1\n" << "  Slotted ALOHA (Fixed resend rate): 2\n" << "  TDMA: 3\n" << "Mode: ";
        std::cin >> mode;
    }
    else {
        mode = atoi(argv[1]);
    }

    int N;
    double DELAY_LAMBDA;

    if (argc < 3) {
        std::cout << "Input number of stations: ";
        std::cin >> N;
    }
    else {
        N = atoi(argv[2]);
    }

    std::cout << "Lambda, Throughput, Delay" << std::endl;

    switch (mode) {
    case 1:
        for (double i = 0.0005; i <= 0.03; i += 0.0005) {
            ALOHA(N, i, i);
        }
        break;
    case 2:
        if (argc < 4) {
            std::cout << "Input delay lambda: ";
            std::cin >> DELAY_LAMBDA;
        }
        else {
            DELAY_LAMBDA = atoi(argv[3]);
        }
        
        for (double i = 0.0005; i <= 0.03; i += 0.0005) {
            ALOHA(N, i, DELAY_LAMBDA);
        }
        break;
    case 3:
        for (double i = 0.0005; i <= 0.03; i += 0.0005) {
            TDMA(N, i);
        }
        break;
    }

    return 0;
}
