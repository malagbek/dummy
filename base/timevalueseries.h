#ifndef BASE_TIMEVALUESERIES_H
#define BASE_TIMEVALUESERIES_H

#include <vector>
#include "timevalue.h"

namespace rz
{
namespace base
{
    template<typename T, typename V>
    class TimeValueSeries
    {
        T valid_from;
        T valid_until;
        bool first_valid_to_ninf;
        bool last_valid_to_pinf;
        std::vector<TimeValue<T, V> > events;
    public:
        TimeValueSeries()
        {}
        
        TimeValueSeries(const T &t, const V &v)
        {
        }
        
        TimeValueSeries(const TimeValueSeries &tvs)
        {
            valid_from = tvs.valid_from;
            valid_until = tvs.valid_until;
            first_valid_to_ninf = tvs.first_valid_to_ninf;
            last_valid_to_pinf = tvs.last_valid_to_pinf;
            events = tvs.events;
        }
        
        
        const V& Get(const T& t) const
        {
        }
        
        bool TryGet(const T& t, V& v) const
        {
        }
    };
}
}
#endif
