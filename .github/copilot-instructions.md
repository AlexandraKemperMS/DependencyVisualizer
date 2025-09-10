
# C++ Coding Preferences 

**General**
- Target **C++23** where available; otherwise **C++20**. Prefer standard library features over third‑party deps. 
- **No raw `new`/`delete`**. Use RAII and smart pointers (`std::unique_ptr` first; `std::shared_ptr` only when shared ownership is required).
- **Do not** write `using namespace std;`. Qualify names or use selective `using`.
- Favor **`const` correctness**, **`constexpr`**, **`noexcept`** where appropriate.
- Prefer **`enum class`** over unscoped enums.
- Prefer **`std::string_view`** for non‑owning text and **`std::span<T>`** for non‑owning buffers.
- Prefer **range‑based for** and **`std::ranges`** algorithms when it improves clarity.

**Error handling**
- Use **exceptions** for non‑recoverable errors and API contracts. Use **`std::optional<T>`** for “missing value” cases.
- For recoverable errors with payloads, prefer **`std::expected<T, E>`** (if toolchain supports it); otherwise use a struct return type with status + value.

**API & Style**
- **Naming**: `PascalCase` for types; `snake_case` for functions/variables; `kCamelCase` for constants; macros in `ALL_CAPS`.
- **Headers**: keep light; use `#pragma once`. Separate interface (.hpp) from implementation (.cpp). Forward‑declare when reasonable.
- Avoid macros; use `constexpr`, templates, or inline functions instead.
- Keep functions small and **single‑purpose**. Prefer **value semantics** with move/copy as needed.

**Performance & Safety**
- Avoid unnecessary copies; pass by `const&` or use moves.
- Prefer **`std::chrono`** for time, **`std::filesystem`** for paths.
- For concurrency, prefer **`std::jthread`** with `std::stop_token`.

**Build & Tooling (for generated scaffolding)**
- Use **CMake** with out‑of‑source builds. Default to:
  - C++ standard set to **23** (fallback to 20).
  - Debug builds enable sanitizers (`address,undefined`) when supported.