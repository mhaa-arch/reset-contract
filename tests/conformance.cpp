#include <reset/reset_info.hpp>
#include <reset/read_clear.hpp>
#include <reset/reset_request.hpp>

#include <cassert>

using namespace mhaa::reset;

class Fake final : public ReadClear
{
public:
    Causes causes() const override { return flags; }
    Causes take_causes() override
    {
        const Causes observed = flags;
        flags = 0;
        return observed;
    }

    Causes flags = static_cast<Causes>(Cause::Watchdog) | static_cast<Causes>(Cause::PowerOn);
};

class Request final : public ResetRequest
{
public:
    bool request_reset() override
    {
        requested = true;
        return true;
    }
    bool requested = false;
};

int main()
{
    Fake fake;
    ReadClear &monitor = fake;
    const Causes expected = static_cast<Causes>(Cause::PowerOn) |
                            static_cast<Causes>(Cause::Watchdog);
    assert(monitor.causes() == expected && monitor.take_causes() == expected);
    assert(monitor.causes() == 0);
    Request request;
    ResetRequest &reset = request;
    assert(reset.request_reset() && request.requested);
}
