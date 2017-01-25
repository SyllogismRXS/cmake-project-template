#include "SylloLib.h"

SylloLib::SylloLib()
{
    count_ = 0;
}

void SylloLib::increment()
{
    count_++;
}

int SylloLib::count()
{
    return count_;
}
