#ifndef __moving__
#define __moving__

namespace util
{

enum class moving
{

    MOVING,                 
    NOT_MOVING,             
    IMMOBILE,               
    STARTED             //STARTED behaves as a `flag` to initiate certain behaviors.
};
}
#endif