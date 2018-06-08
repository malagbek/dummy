#ifndef BASE_TIMERANGEVALUE_H
#define BASE_TIMERANGEVALUE_H

template<typename T, typename V>
class time_range_value
{
public:
    typedef T time_type;
    typedef V value_type;
    
    time_type from;
    time_type to;
    value_type value;
    
    time_range_value()
        : from(type_helper<time_type>::zero())
        , to(type_helper<time_type>::zero())
        , value(type_helper<value_type>::zero())
    {
    }
    
    time_range_value(const time_type & f,
                     const time_type & t,
                     const value_type & v)
        : from(f)
        , to(t)
        , value(v)
    {
    }
    
    time_range_value(const time_range_value & trv)
        : from(trv.from)
        , to(trv.to)
        , value(trv.value)
    {
    }
    
    time_range_value & operator=(const time_range_value & trv)
    {
        if (this != &trv)
        {
            from = trv.from;
            to = trv.to;
            value = trv.value;
        }
        return *this;
    }
    
    bool is_valid() const
    {
        return type_helper<time_type>::is_valid(from) &&
               type_helper<time_type>::is_valid(to);
    }
    
    bool contains(const time_type & t) const
    {
        if (!type_helper<time_type>::is_valid(t))
        {
            return false;
        }
        return (t >= from && t < to);
    }
    
    bool contains(const time_range_value & trv) const
    {
        if (!is_valid() || !trv.is_valid())
        {
            return false;
        }
        return (from <= trv.from && trv.to <= to);
    }
    
    bool overlaps(const time_range_value & trv) const
    {
        if (!is_valid() || !trv.is_valid())
        {
            return false;
        }
        
        return (from <= trv.from && to > trv.from) ||
               (from < trv.to && to >= trv.to);
    }
};

#endif
