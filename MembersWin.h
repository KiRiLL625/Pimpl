//
// Created by Admin on 10.10.2023.
//

#ifndef TIMEMETER_MEMBERSWIN_H
#define TIMEMETER_MEMBERSWIN_H

#include <memory>

class Members{
public:
    unsigned count;
    std::unique_ptr<double[]> timeStamps;
    explicit Members(unsigned count){
        this->count = count;
        this->timeStamps = std::unique_ptr<double[]>(new double[count]);
    }
};

#endif //TIMEMETER_MEMBERSWIN_H
