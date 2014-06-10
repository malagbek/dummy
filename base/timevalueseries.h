#ifndef BASE_TIMEVALUESERIES_H
#define BASE_TIMEVALUESERIES_H

#include <vector>
#include <algorithm>
#include "base/tassert.h"
#include "base/timevalue.h"

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
        bool is_integral;
        std::vector<TimeValue<T, V> > events;
    public:
        TimeValueSeries()
            : first_valid_to_ninf(false)
            , last_valid_to_pinf(false)
            , is_integral(false)
        {}
        
        TimeValueSeries(const T &t, const V &v, bool integral=false)
            : valid_from(t)
            , valid_until(t)
            , first_valid_to_ninf(true)
            , last_valid_to_pinf(true)
            , is_integral(integral)
        {
            events.push_back(TimeValue(t, v));
        }
        
        TimeValueSeries(const TimeValueSeries &tvs)
        {
            valid_from = tvs.valid_from;
            valid_until = tvs.valid_until;
            first_valid_to_ninf = tvs.first_valid_to_ninf;
            last_valid_to_pinf = tvs.last_valid_to_pinf;
            is_integral = tvs.is_integral;
            events = tvs.events;
        }
        
        TimeValueSeries(const std::vector<T> &times, const std::vector<V> &values)
        {
            TASSERT(times.size() == values.size(), "number of time periods != number of values");
            TASSERT(times.size() > 0, "number of events is zero");
            
            first_valid_to_ninf = true;
            last_valid_to_pinf = true;
            for (size_t i = 0; i < times.size(); ++i)
            {
                events.push_back(times[i], values[i]);
            }
            std::sort(events.begin(), events.end());
            valid_from = events.front().time;
            valid_until = events.back().time;
            Compress();
        }
        
        const V& Get(const T& t) const
        {
        }
        
        bool TryGet(const T& t, V& v) const
        {
        }
        
        
        T ValidFrom() const
        {
            return valid_from;
        }
        
        T ValidUntil() const
        {
            return valid_until;
        }
        
        bool FirstValidToNinf() const
        {
            return first_valid_to_ninf;
        }
        
        void FirstValidToNinf(bool flag)
        {
            first_valid_to_ninf = flag;
        }
        
        bool LastValidToPinf() const
        {
            return last_valid_to_pinf;
        }
        
        void LastValidToPinf(bool flag)
        {
            last_valid_to_pinf = flag;
        }
        
        bool IsIntegral() const
        {
            return is_integral;
        }
        
        void IsIntegral(bool flag)
        {
            is_integral = flag;
        }
        
        const std::vector<TimeValue<T, V> > Events() const
        {
            return events;
        }
        
        void AddEvent(const T &t, const V &v)
        {
            events.push_back(TimeValue(t,v));
            std::sort(events.begin(), events.end());
            Compress();
        }
    private:
        void Compress()
        {
            if (events.size() < 2)
                return;
            std::vector<TimeValue<T, V> > tmp;
            tmp.push_back(events.front());
            for (size_t i = 1; i < events.size(); ++i)
            {
                if (events[i].value != tmp.back().value)
                    tmp.push_back(events[i]);
            }
            
            events = tmp;
        }
    };
}
}
#endif
