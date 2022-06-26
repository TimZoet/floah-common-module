#pragma once

////////////////////////////////////////////////////////////////
// Standard includes.
////////////////////////////////////////////////////////////////

#include <cmath>
#include <cstdint>

namespace floah
{
    class Length
    {
    public:
        ////////////////////////////////////////////////////////////////
        // Constructors.
        ////////////////////////////////////////////////////////////////

        /**
         * \brief Construct an absolute length.
         */
        constexpr Length() = default;

        /**
         * \brief Construct an absolute length.
         * \param v Absolute length.
         */
        constexpr explicit Length(const int32_t v) : absLength(v) {}

        /**
         * \brief Construct a relative length.
         * \param v Relative length.
         */
        constexpr explicit Length(const float v) : relative(true), relLength(v) {}

        constexpr Length(const Length&) = default;

        constexpr Length(Length&&) noexcept = default;

        constexpr ~Length() noexcept = default;

        constexpr Length& operator=(const Length&) = default;

        constexpr Length& operator=(Length&&) noexcept = default;

        ////////////////////////////////////////////////////////////////
        // Getters.
        ////////////////////////////////////////////////////////////////

        /**
         * \brief Get absolute length.
         * \return Absolute length.
         */
        [[nodiscard]] constexpr int32_t get() const noexcept { return absLength; }

        /**
         * \brief Get relative length.
         * \return Relative length.
         */
        [[nodiscard]] constexpr float getRelative() const noexcept { return relLength; }

        /**
         * \brief Get absolute length. If this object contains a relative length, convert it to an absolute length relative to base.
         * \param base Base length to multiply relative length with.
         * \return Absolute length.
         */
        [[nodiscard]] constexpr int32_t get(int32_t base) const noexcept
        {
            return isRelative() ? static_cast<int32_t>(std::round(relLength * static_cast<float>(base))) : absLength;
        }

        /**
         * \brief Returns whether this length is absolute.
         * \return True if absolute.
         */
        [[nodiscard]] constexpr bool isAbsolute() const noexcept { return !relative; }

        /**
         * \brief Returns whether this length is relative.
         * \return True if relative.
         */
        [[nodiscard]] constexpr bool isRelative() const noexcept { return relative; }

        ////////////////////////////////////////////////////////////////
        // Setters.
        ////////////////////////////////////////////////////////////////

        /**
         * \brief Set absolute length.
         * \param v Absolute length.
         */
        constexpr void set(int32_t v) noexcept
        {
            absLength = v;
            relative  = false;
        }

        /**
         * \brief Set relative length.
         * \param v Relative length.
         */
        constexpr void setRelative(float v) noexcept
        {
            relLength = v;
            relative  = true;
        }

        /**
         * \brief Use absolute length value.
         */
        constexpr void makeAbsolute() noexcept { relative = false; }

        /**
         * \brief Use relative length value.
         */
        constexpr void makeRelative() noexcept { relative = true; }

    private:
        ////////////////////////////////////////////////////////////////
        // Member variables.
        ////////////////////////////////////////////////////////////////

        /**
         * \brief Whether absLength or relLength is used.
         */
        bool relative = false;

        /**
         * \brief Absolute length.
         */
        int32_t absLength = 0;

        /**
         * \brief Relative length.
         */
        float relLength = 0;
    };
}  // namespace floah