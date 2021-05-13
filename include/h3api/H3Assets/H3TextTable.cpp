//////////////////////////////////////////////////////////////////////
//                                                                  //
//                     Created by RoseKavalier:                     //
//                     rosekavalierhc@gmail.com                     //
//              Created or last updated on: 2021-02-03              //
//        ***You may use or distribute these files freely           //
//            so long as this notice remains present.***            //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#include "h3api/H3Assets/H3TextTable.hpp"

namespace h3
{
    _H3API_ H3Vector<H3Vector<LPCSTR>*>& H3TextTable::GetText()
    {
        return text;
    }
    _H3API_ UINT32 H3TextTable::CountRows() const
    {
        return text.Count();
    }
    _H3API_ H3TextTable* H3TextTable::Load(LPCSTR name)
    {
        return THISCALL_1(H3TextTable*, 0x55C2B0, name);
    }
    _H3API_ VOID H3TextTable::UnLoad()
    {
        vTable->vEraseFromResourceManager(this);
    }
    _H3API_ H3Vector<LPCSTR>& H3TextTable::operator[](UINT row)
    {
        return *text[row];
    }
    _H3API_ H3TextTable::iterator H3TextTable::begin()
    {
        return iterator(text.begin());
    }
    _H3API_ H3TextTable::iterator H3TextTable::end()
    {
        return iterator(text.end());
    }
    _H3API_ H3TextTable::iterator::iterator(H3Vector<LPCSTR>** vec) :
        data(vec)
    {
    }
    _H3API_ H3TextTable::iterator& H3TextTable::iterator::operator++()
    {
        ++data;
        return *this;
    }
    _H3API_ H3TextTable::iterator H3TextTable::iterator::operator++(int)
    {
        iterator it(data);
        ++data;
        return it;
    }
    _H3API_ H3Vector<LPCSTR>& H3TextTable::iterator::operator*()
    {
        return **data;
    }
    _H3API_ H3Vector<LPCSTR>* H3TextTable::iterator::operator->()
    {
        return *data;
    }
    _H3API_ LPCSTR H3TextTable::iterator::operator[](UINT column)
    {
        return (**data)[column];
    }
    _H3API_ BOOL H3TextTable::iterator::operator==(const iterator& other)
    {
        return data == other.data;
    }
    _H3API_ BOOL H3TextTable::iterator::operator!=(const iterator& other)
    {
        return data != other.data;
    }
} /* namespace h3 */
