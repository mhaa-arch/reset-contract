#include <reset/reset_info.hpp>

using namespace mhaa::reset;

class WrongOverride final : public ResetInfo
{
public:
    Causes causes() override;
};
