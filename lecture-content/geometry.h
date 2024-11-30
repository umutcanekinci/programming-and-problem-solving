//
// Created by dindar.oz on 11/27/2024.
//

#ifndef __GEOMETRY
#define __GEOMETRY



#include "stdio.h"

#define PI 3.145

double areaCircle(double radius)
{
    return PI * radius * radius;
}

double perimeterCircle(double radius)
{
    return PI * 2 * radius;
}

double volumeOfSphere(double radius)
{
    return 4/3.0 * PI * radius*radius*radius;
}

#endif