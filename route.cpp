#include "route.h"

bool operator<(const route &x, const route &y)
{
    return x.distance < y.distance;
}
