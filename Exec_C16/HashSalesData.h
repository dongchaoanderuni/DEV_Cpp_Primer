#ifndef __HASHSALESDATA_H__
#define __HASHSALESDATA_H__

#include "Sales_data.h"

class Sales_data;

namespace std
{
    template <>
    struct hash<Sales_data>
    {
        typedef size_t result_type;
        typedef Sales_data argument_type;
        size_t  operator() (const Sales_data& s) const
        {
            return hash<string>()(s.bookNo)
                    ^hash<unsigned>()(s.units_sold)
                    ^hash<double>()(s.revenue);
        }
    };
}


#endif