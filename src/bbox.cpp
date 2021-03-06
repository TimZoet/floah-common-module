#include "floah-common/bbox.h"

////////////////////////////////////////////////////////////////
// Standard includes.
////////////////////////////////////////////////////////////////

#include <algorithm>

namespace floah
{
    int32_t BBox::width() const noexcept { return x1 - x0; }

    int32_t BBox::height() const noexcept { return y1 - y0; }

    std::array<int32_t, 2> BBox::center() const noexcept { return {(x0 + x1) / 2, (y0 + y1) / 2}; }

    BBox& BBox::operator+=(const BBox& rhs) noexcept
    {
        x0 = std::min(x0, rhs.x0);
        y0 = std::min(y0, rhs.y0);

        x1 = std::max(x1, rhs.x1);
        y1 = std::max(y1, rhs.y1);

        return *this;
    }
}  // namespace floah
