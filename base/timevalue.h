#ifndef BASE_TIMEVALUE_H
#define BASE_TIMEVALUE_H

namespace rz
{
namespace base
{
    template<typename T, typename V>
    struct TimeValue
    {
        T time;
        V value;
        
        TimeValue()
        {}
        
        TimeValue(const T &t, const V &v) : time(t), value(v)
        {}
        
        TimeValue(const TimeValue &tv) : time(tv.time), value(tv.value)
        {}
        
        bool operator<(const TimeValue &tv) const
        {
            return time < tv.time;
        }
    };
    
    template<typename T, typename V>
    struct TimeRangeValue
    {
        T from;
        T to;
        V value;
        
        TimeRangeValue()
        {}
        
        TimeRangeValue(const T& f, const T& &t, const V& v)
            : from(f), to(t), value(v)
        {}
        
        TimeRangeValue(const TimeRangeValue &trv)
            : from(trv.from), to(trv.to), value(trv.value)
        {}
        
        bool operator<(const TimeRange &trv) const
        {
            return from < trv.from;
        }
    };
}
}
#endif
