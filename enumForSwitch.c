#include<stdio.h>

enum TrafficLight {RED, YELLOW, GREEN};

int main()
{
    enum TrafficLight cur = YELLOW;
     switch (cur) {
        case RED:
            printf("Stop!\n");
            break;
        case YELLOW:
            printf("Slow Down!\n");
            break;
        case GREEN:
            printf("Go!\n");
            break;
        default:
            printf("Invalid light!\n");
    }
}