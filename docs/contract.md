# Reset contract

## Observe or take the record

[ResetInfo](../include/reset/reset_info.hpp) reads a `Causes` mask without acknowledging it. Several flags can coexist. Zero is an empty record, and `Cause::Other` represents a reported cause with no portable mapping.

[ReadClear](../include/reset/read_clear.hpp) extends the same source. `take_causes()` observes and acknowledges its flags. This couples both operations to one source but does not promise a hardware-atomic read and clear.

## Request reset

[ResetRequest](../include/reset/reset_request.hpp) is independently optional. Return false on rejection. An accepted request can terminate execution before the call returns. State the affected domain in the Adapter integration.

## Implementation boundary

The Adapter owns resource state. The caller must keep the implementation alive during each call and arrange access from other execution contexts. Document the contexts and concurrency guarantees of the actual implementation. Shared public types are in [`reset/types.hpp`](../include/reset/types.hpp).
