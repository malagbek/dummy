#ifndef BASE_TYPEHELPER_H
#define BASE_TYPEHELPER_H

#include <limits>

template<typename T>
class type_helper
{
public:
    inline static T min()
    {
        return -std::numeric_limits<T>::min();
    }
    
    inline static T max()
    {
        return std::numeric_limits<T>::max();
    }
    
    inline static T zero()
    {
        return T();
    }
    
    inline static bool is_valid(const T & t)
    {
        (void)t;
        return true;
    }
};

#endif
