#include <stdio.h>
#include <math.h>

struct Punkt
{
    double x;
    double y;
};

struct Rechteck
{
    struct Punkt obenLinks;
    struct Punkt untenRechts;
};

double berechneFlaeche(struct Rechteck *rechteck)
{
    double xLength = abs(rechteck->obenLinks.x - rechteck->untenRechts.x);
    double yLength = abs(rechteck->obenLinks.y - rechteck->untenRechts.y);

    return xLength * yLength;
}

int main()
{

    struct Rechteck rechteck1;
    rechteck1.obenLinks.x = -1;
    rechteck1.obenLinks.y = 1;
    rechteck1.untenRechts.x = 1;
    rechteck1.untenRechts.y = -1;

    printf("%lf", berechneFlaeche(&rechteck1));

    return 0;
}