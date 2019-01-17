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
    };

}