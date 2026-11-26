# Reset Contract example

[The conformance program](../tests/conformance.cpp) pairs a simulated implementation with assertions at the Contract boundary. The fixture derives from `ReadClear`. It overrides observation and implements take by copying the current mask before clearing it. The program tests a mask containing power-on and watchdog flags, then verifies that the record is empty. A separate request fake records a call instead of terminating the process.

## Implementation excerpt

This class is taken from the program. The linked source contains the test cases and any additional fixtures.

```cpp
#include <reset/reset_info.hpp>
#include <reset/read_clear.hpp>
#include <reset/reset_request.hpp>


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
```

## Build and run

From this repository root, with assertions enabled, compile the full program. A passing run exits with status 0 and prints no output. Use `conformance.exe` on Windows.

```sh
g++ -std=c++11 -Wall -Wextra -Wpedantic -Werror -fno-rtti -fno-exceptions -Iinclude tests/conformance.cpp -o conformance
./conformance
```

To verify enforcement of the abstract interface, compile the two negative sources separately. The first should diagnose an abstract type and the second an incompatible override.

```sh
g++ -std=c++11 -Wall -Wextra -Wpedantic -Werror -fno-rtti -fno-exceptions -Iinclude -fsyntax-only tests/missing_override.cpp
g++ -std=c++11 -Wall -Wextra -Wpedantic -Werror -fno-rtti -fno-exceptions -Iinclude -fsyntax-only tests/wrong_override.cpp
```
