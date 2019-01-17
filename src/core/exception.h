#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <exception>

namespace birdy 
{

    class OccupiedTileException : public std::exception 
    {
        const char* what()
        {
            return "All tiles are occupied, cannot occupy any more tiles";
        }
    };

}

#endif