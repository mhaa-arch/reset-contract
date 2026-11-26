#include <reset/reset_info.hpp>

using namespace mhaa::reset;

class Incomplete final : public ResetInfo
{
public:
};

int main()
{
    Incomplete implementation;
    (void)implementation;
}
