#pragma once

////////////////////////////////////////////////////////////////
// Current target includes.
////////////////////////////////////////////////////////////////

#include "floah-common/length.h"

namespace floah
{
    class Margin
    {
    public:
        ////////////////////////////////////////////////////////////////
        // Constructors.
        ////////////////////////////////////////////////////////////////

        constexpr Margin() = default;

        constexpr Margin(const Margin&) = default;

        constexpr Margin(Margin&&) noexcept = default;

        constexpr ~Margin() noexcept = default;

        constexpr Margin& operator=(const Margin&) = default;

        constexpr Margin& operator=(Margin&&) noexcept = default;

        ////////////////////////////////////////////////////////////////
        // Getters.
        ////////////////////////////////////////////////////////////////

        /**
         * \brief Get left margin.
         * \return Left margin.
         */
        [[nodiscard]] constexpr Length& getLeft() noexcept { return left; }

        /**
         * \brief Get left margin.
         * \return Left margin.
         */
        [[nodiscard]] constexpr const Length& getLeft() const noexcept { return left; }

        /**
         * \brief Get top margin.
         * \return Top margin.
         */
        [[nodiscard]] constexpr Length& getTop() noexcept { return top; }

        /**
         * \brief Get top margin.
         * \return Top margin.
         */
        [[nodiscard]] constexpr const Length& getTop() const noexcept { return top; }

        /**
         * \brief Get right margin.
         * \return Right margin.
         */
        [[nodiscard]] constexpr Length& getRight() noexcept { return right; }

        /**
         * \brief Get right margin.
         * \return Right margin.
         */
        [[nodiscard]] constexpr const Length& getRight() const noexcept { return right; }

        /**
         * \brief Get bottom margin.
         * \return Bottom margin.
         */
        [[nodiscard]] constexpr Length& getBottom() noexcept { return bottom; }

        /**
         * \brief Get bottom margin.
         * \return Bottom margin.
         */
        [[nodiscard]] constexpr const Length& getBottom() const noexcept { return bottom; }

        ////////////////////////////////////////////////////////////////
        // Setters.
        ////////////////////////////////////////////////////////////////

        /**
         * \brief Set all margins.
         * \param l Left.
         * \param t Top.
         * \param r Right.
         * \param b Bottom.
         */
        constexpr void set(const int32_t l, const int32_t t, const int32_t r, const int32_t b) noexcept
        {
            left.set(l);
            top.set(t);
            right.set(r);
            bottom.set(b);
        }

    private:
        ////////////////////////////////////////////////////////////////
        // Member variables.
        ////////////////////////////////////////////////////////////////

        Length left;

        Length top;

        Length right;

        Length bottom;
    };
}  // namespace floah
