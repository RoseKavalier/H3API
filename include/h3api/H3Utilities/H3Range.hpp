//////////////////////////////////////////////////////////////////////
//                                                                  //
//                     Created by RoseKavalier:                     //
//                     rosekavalierhc@gmail.com                     //
//              Created or last updated on: 2021-01-24              //
//        ***You may use or distribute these files freely           //
//            so long as this notice remains present.***            //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#pragma once

#include "h3api/H3Base.hpp"

namespace h3
{
    template<typename Type>	class H3Range;

    /**
     * @brief Lazy-C++11-man's range iterator
     * It only increments by step-size 1.
     */
    template<typename Type>
    class H3Range
    {
    public:
        struct iterator
        {
            iterator(Type value) : m_value(value) {}
            Type operator*() { return m_value; }
            iterator& operator++() { m_value += static_cast<Type>(1); return *this; }
            bool operator!=(const iterator& it) { return m_value < it.m_value; }
        private:
            Type m_value;
        };

        iterator begin() { return m_begin; }
        iterator end() { return m_end; }

        H3Range(Type end) : m_begin(static_cast<Type>(0)), m_end(end) {}
        H3Range(Type begin, Type end) : m_begin(Type(begin)), m_end(end) {}
    private:
        iterator m_begin;
        iterator m_end;
    };

    /**
     * @brief Creates iterable range while automatically deducing type
     * @tparam Type Any integer/float/double
     * @param upper_bound Exclusive bound in the following range: [0, upper_bound)
     * @return Iterable range
     */
    template<typename Type>
    typename H3Range<Type> Range(Type upper_bound)
    {
        return H3Range<Type>(upper_bound);
    }
    /**
     * @brief Creates iterable range while automatically deducing type
     * @tparam Type Any integer/float/double
     * @param lower_bound Inclusive bound in the following range: [lower_bound, upper_bound)
     * @param upper_bound Exclusive bound in the following range: [lower_bound, upper_bound)
     * @return Iterable range
     */
    template<typename Type>
    typename H3Range<Type> Range(Type lower_bound, Type upper_bound)
    {
        return H3Range<Type>(lower_bound, upper_bound);
    }

} /* namespace h3 */
