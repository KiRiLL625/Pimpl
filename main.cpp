#include <iostream>
#include "TimeMeter.h"
#include <unistd.h>
int main() {
    TimeMeter timeMeter(2);
    timeMeter.setTimeStamp(0);
    sleep(2);
    timeMeter.setTimeStamp(1);
    std::cout << timeMeter.getSDiff(0, 1) << std::endl;
    std::cout << timeMeter.getMSDiff(0, 1) << std::endl;
    std::cout << timeMeter.isLess(0, 1, 1000) << std::endl;
    std::cout << timeMeter.isLess(0, 1000) << std::endl;
    return 0;
}
