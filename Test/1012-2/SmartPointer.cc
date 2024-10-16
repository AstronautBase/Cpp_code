#include "SmartPointer.h"

SmartPointer::SmartPointer(const SmartPointer &sptr)
{
    if (this == &sptr)
        return;
    pointer = sptr.pointer;
    ref_cnt = sptr.ref_cnt;
    if (ref_cnt)
    {
        (*ref_cnt)++;
    }
}

void SmartPointer::assign(const SmartPointer &sptr)
{
    if (this == &sptr)
        return;
    if (ref_cnt && --(*ref_cnt) == 0)
    {
        delete pointer;
        delete ref_cnt;
    }
    pointer = sptr.pointer;
    ref_cnt = sptr.ref_cnt;
    if (ref_cnt)
    {
        (*ref_cnt)++;
    }
}

SmartPointer::~SmartPointer()
{
    if (ref_cnt && --(*ref_cnt) == 0)
    {
        delete pointer;
        delete ref_cnt;
    }
}