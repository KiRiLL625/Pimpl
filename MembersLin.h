//
// Created by Admin on 10.10.2023.
//

#ifndef TIMEMETER_MEMBERSLIN_H
#define TIMEMETER_MEMBERSLIN_H

#include <memory>

class Members{
public:
    unsigned count;
    double start;
    std::unique_ptr<double[]> timeStamps;
    explicit Members(unsigned count){
        struct timespec ts;
        clock_gettime(CLOCK_REALTIME, &ts);
        this->count = count;
        this->start = ts.tv_sec + (ts.tv_nsec / 1000000) * 0.001;
        this->timeStamps = std::unique_ptr<double[]>(new double[count]);
    }
};

#endif //TIMEMETER_MEMBERSLIN_H
