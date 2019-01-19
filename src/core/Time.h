#ifndef BIRDY_TIME_H
#define BIRDY_TIME_H

#include <chrono>

namespace birdy
{

    class Time 
    {
        public:
            static long timestamp()
            {
                using namespace std::chrono;
                return duration_cast<seconds>(system_clock::now().time_since_epoch()).count();
            }

            static long timestampMillis()
            {
                using namespace std::chrono;
                return duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
            }

            static long timestampNano()
            {
                using namespace std::chrono;
                return duration_cast<nanoseconds>(system_clock::now().time_since_epoch()).count();
            }
    };

}

#endif