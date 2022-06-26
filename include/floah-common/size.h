#pragma once

////////////////////////////////////////////////////////////////
// Current target includes.
////////////////////////////////////////////////////////////////

#include "floah-common/length.h"

namespace floah
{
    class Size
    {
    public:
        ////////////////////////////////////////////////////////////////
        // Constructors.
        ////////////////////////////////////////////////////////////////

        constexpr Size() = default;

        constexpr Size(const Length w, const Length h) : width(w), height(h) {}

        constexpr Size(const int32_t w, const int32_t h) : width(w), height(h) {}

        constexpr Size(const float w, const float h) : width(w), height(h) {}

        constexpr Size(const Size&) = default;

        constexpr Size(Size&&) noexcept = default;

        constexpr ~Size() noexcept = default;

        constexpr Size& operator=(const Size&) = default;

        constexpr Size& operator=(Size&&) noexcept = default;

        ////////////////////////////////////////////////////////////////
        // Getters.
        ////////////////////////////////////////////////////////////////

        /**
         * \brief Get width.
         * \return Width.
         */
        [[nodiscard]] constexpr Length& getWidth() noexcept { return width; }

        /**
         * \brief Get width.
         * \return Width.
         */
        [[nodiscard]] constexpr const Length& getWidth() const noexcept { return width; }

        /**
         * \brief Get height.
         * \return Height.
         */
        [[nodiscard]] constexpr Length& getHeight() noexcept { return height; }

        /**
         * \brief Get height.
         * \return Height.
         */
        [[nodiscard]] constexpr const Length& getHeight() const noexcept { return height; }

        ////////////////////////////////////////////////////////////////
        // Setters.
        ////////////////////////////////////////////////////////////////

        constexpr void setWidth(const Length v) { width = v; }

        constexpr void setHeight(const Length v) { height = v; }

    private:
        ////////////////////////////////////////////////////////////////
        // Member variables.
        ////////////////////////////////////////////////////////////////

        /**
         * \brief Width.
         */
        Length width;

        /**
         * \brief Height.
         */
        Length height;
    };
}  // namespace floah