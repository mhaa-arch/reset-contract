#ifndef MHAA_RESET_TYPES_HPP
#define MHAA_RESET_TYPES_HPP

#include <stdint.h>

namespace mhaa
{
    namespace reset
    {
        enum class Cause : uint32_t
        {
            PowerOn = 1u,
            External = 2u,
            BrownOut = 4u,
            Watchdog = 8u,
            Software = 16u,
            Lockup = 32u,
            Other = 64u
        };
        using Causes = uint32_t;
    }
}

#endif
