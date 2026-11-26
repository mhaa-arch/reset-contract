# Porting the Reset Contract

Hardware Definitions can describe reset flag sources, persistence and supported reset mechanisms. The Adapter maps simultaneous native flags into the common mask and can preserve an unmapped reported condition as `Other`. Some targets clear flags during early boot or omit certain causes. The portable interface cannot recover information the implementation no longer has.

This repository's host simulations and shared API compile/link checks provide source-level evidence. Target timing and physical behavior require hardware validation.
