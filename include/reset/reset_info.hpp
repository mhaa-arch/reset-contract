#ifndef MHAA_RESET_RESET_INFO_HPP
#define MHAA_RESET_RESET_INFO_HPP

#include <reset/types.hpp>

namespace mhaa
{
    namespace reset
    {
        /** @brief Exposes the reset flags recorded by one reset source. */
        class ResetInfo
        {
        public:
            virtual ~ResetInfo() = default;
            virtual Causes causes() const = 0;
        };
    }
}

#endif
