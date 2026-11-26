#ifndef MHAA_RESET_RESET_REQUEST_HPP
#define MHAA_RESET_RESET_REQUEST_HPP

#include <reset/types.hpp>

namespace mhaa
{
    namespace reset
    {
        /** @brief Requests a system reset when supported. */
        class ResetRequest
        {
        public:
            virtual ~ResetRequest() = default;

            /** @brief An accepted reset may terminate execution before this call returns. */
            virtual bool request_reset() = 0;
        };
    }
}

#endif
