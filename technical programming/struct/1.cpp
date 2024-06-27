/**
 * Description:
 *          CSC10001 Struct homework
 *          chương trình tính toán khoảng thời gian giữa 2 mốc thời gian (h/m/s)
 *
 * Original Author:    H.T.Phong
 * Created:   Dec 1, 2023
 *
 **/

#include <cmath>
#include <iomanip>
#include <iostream>

struct Time
{
    int hours;
    int minutes;
    int seconds;
};

void printTime(Time input)
{
    char prevFill;
    prevFill = std::cout.fill('0');
    std::cout << std::setw(2) << input.hours << ":" << std::setw(2)
              << input.minutes << ":" << std::setw(2) << input.seconds;
    std::cout.fill(prevFill);
}

int toSeconds(Time input)
{
    return input.hours * 3600 + input.minutes * 60 + input.seconds;
}

Time calTimeBetween(Time start, Time end)
{
    Time timeBetween;
    int startSecond = toSeconds(start);
    int endSecond = toSeconds(end);
    int midSecond = (endSecond - startSecond + 86400) % 86400;
    timeBetween.hours = midSecond / 3600;
    timeBetween.minutes = midSecond % 3600 / 60;
    timeBetween.seconds = midSecond % 3600 % 60;
    return timeBetween;
}

int main()
{
    Time time1 = {.hours = 1, .minutes = 56, .seconds = 12};
    Time time2 = {.hours = 13, .minutes = 8, .seconds = 37};
    printTime(calTimeBetween(time1, time2));
    return 0;
}