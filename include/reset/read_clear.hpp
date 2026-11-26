#ifndef MHAA_RESET_READ_CLEAR_HPP
#define MHAA_RESET_READ_CLEAR_HPP

#include <reset/reset_info.hpp>
#include <reset/types.hpp>

namespace mhaa
{
    namespace reset
    {
        /** @brief Reads and clears causes on the same reset source. */
        class ReadClear : public ResetInfo
        {
        public:
            /** @brief Obtains the observed causes and acknowledges their flags. */
            virtual Causes take_causes() = 0;
        };
    }
}

#endif
