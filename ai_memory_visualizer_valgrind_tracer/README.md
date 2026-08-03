# AI Memory Visualizer + Valgrind Tracer

This repository contains rigorous memory analyses, Valgrind diagnostic evaluations, and deterministic crash investigations for C programs, along with critical critiques of AI-generated explanations.

## Project Structure
* `programs/`: Source files containing memory behaviors, leaks, and crashes.
* `analysis/memory_maps.md`: Detailed stack vs heap memory analysis and lifetime tracking.
* `analysis/valgrind_analysis.md`: Trace breakdowns and categorization of Valgrind diagnostic errors.
* `analysis/crash_report.md`: Causal analysis of segmentation faults and register/address behaviors.

## Peer Review Readiness Checklist
- [x] Memory lifetimes and scopes are explicitly distinguished between stack and heap.
- [x] Pointer aliasing and ownership responsibilities are clearly documented.
- [x] Valgrind findings are interpreted and mapped to code logic rather than just pasted.
- [x] Segmentation faults are explained as deterministic hardware/memory protection faults.
- [x] AI-generated explanations have been critically reviewed, and inaccuracies have been corrected with sound technical reasoning.
