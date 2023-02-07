#include <stdio.h>

#define DAY_V       31

int lastDay(int month) {
    if (month == 2)
        return DAY_V - 2;
    else if ((month < 8) && (month % 2 == 0))
        return DAY_V - 1;
    else if ((month > 7) && (month % 2 == 1))
        return DAY_V - 1;
    else
        return DAY_V;
}
