//
// Created by Admin on 03.10.2023.
//


#include "TimeMeter.h"
#include "MembersLin.h"

TimeMeter::TimeMeter(unsigned count) : members(new Members(count)) {}

TimeMeter::~TimeMeter() = default;

double TimeMeter::setTimeStamp(unsigned num) {
    struct timespec ts;
    clock_gettime(CLOCK_REALTIME, &ts);
    members->timeStamps[num] = (ts.tv_sec + (ts.tv_nsec / 1000000) * 0.001 - this->members->start);
    return members->timeStamps[num];
}

double TimeMeter::getSTimeStamp(unsigned num) {
    return members->timeStamps[num];
}

int64_t TimeMeter::getMSTimeStamp(unsigned num) {
    return members->timeStamps[num] * 1000;
}

double TimeMeter::getSDiff(unsigned first, unsigned second) {
    return (members->timeStamps[second] - members->timeStamps[first]);
}

int64_t TimeMeter::getMSDiff(unsigned first, unsigned second) {
    return (members->timeStamps[second] - members->timeStamps[first]) * 1000;
}

bool TimeMeter::isLess(unsigned first, unsigned second, int64_t expected) {
    return getMSTimeStamp(second) - getMSTimeStamp(first) < expected;
}

bool TimeMeter::isLess(unsigned num, int64_t expected) {
    return getMSTimeStamp(num) < expected;
}