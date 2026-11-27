# DoDonPachi DaiOuJou Decompilation (PS2)

Byte-matching decompilation of **DoDonPachi DaiOuJou** (PS2), covering all three disc executables: the main game (`SLPS_252.33`), Death Label (`DEATH.ELF`), and the Gallery (`GALLERY.ELF`). No game assets or binaries are included; supply your own retail ISO to build.

All functions have been 100% matched and all data has been moved into C. The build is also shiftable allowing for mods. However many parts of the code still need cleaning up.

[![Main game C-match map](docs/progress-map-main.svg)](docs/progress-map-main.svg)

[![Death Label C-match map](docs/progress-map-death.svg)](docs/progress-map-death.svg)

[![Gallery C-match map](docs/progress-map-gallery.svg)](docs/progress-map-gallery.svg)

![Decompilation progress](docs/progress.svg)

## Building

Requires [uv](https://docs.astral.sh/uv/) and a retail ISO of **DoDonPachi DaiOuJou** (`SLPS-252.33`). Setup automatically downloads and verifies the compilers, PS2 binutils, and runner.

### macOS

```sh
brew install uv zstd
uv run tools/setup.py --iso /path/to/ddpdoj.iso --build
```

*(Apple Silicon uses Rosetta 2 for `wibo`, or a local x86 QEMU guest if `qemu-system-x86_64` is installed.)*

### Windows

```powershell
winget install astral-sh.uv
uv run tools/setup.py --iso C:\path\to\ddpdoj.iso --build
```

*(CodeWarrior runs natively on Windows.)*

### Linux (x86-64)

Requires `glibc >= 2.38` and `libzstd` (e.g. `sudo apt install libzstd1`).

```sh
curl -LsSf https://astral.sh/uv/install.sh | sh
uv run tools/setup.py --iso /path/to/ddpdoj.iso --build
```

### Subsequent builds

```sh
# Rebuild and SHA-256 verify all three ELFs (SLPS_252.33, DEATH.ELF, GALLERY.ELF)
uv run tools/build.py

# Build a single target
uv run tools/build.py --target SLPS_252.33

# Build shiftable mod ELFs and repack build/mod/ddpdoj.iso
uv run tools/build.py --mod --iso
```

## Native desktop port

Main, Death Label and Gallery run natively on macOS and 64-bit Windows. Open DaiOuJou and choose your retail ISO. The original Main menu launches the other two modes. They also accept an ISO path on the command line.

Use an SDL gamepad or the keyboard. The arrow keys move, Enter is Start, and X confirms in the menus. Z, X, C and V map to Cross, Circle, Square and Triangle. Q and E map to L1 and R1. The game stores virtual memory cards in the per-user SDL preference directory.

### Build and run

Use CMake, Python 3 and the SDL3 development package with Clang on macOS or 64-bit MinGW-w64 GCC on Windows. On macOS, Homebrew provides the dependencies with `brew install cmake python sdl3`. On Windows, run the following in an MSYS2 UCRT64 shell with the UCRT64 GCC, CMake, Ninja, Python and SDL3 packages installed.

```sh
cmake -S pc -B build/pc -DCMAKE_BUILD_TYPE=Release
cmake --build build/pc --config Release --parallel
cmake --install build/pc --config Release --prefix build/desktop
```

On macOS open `build/desktop/DaiOuJou.app`. On Windows open `build/desktop/DaiOuJou/ddpdoj.exe`. Move the whole app or Windows folder together to keep all three modes and the SDL runtime available. The desktop port reads assets directly from the ISO at runtime.

### Desktop checks

```sh
ctest --test-dir build/pc -C Release --output-on-failure
```

Configure with `-DDDPDOJ_TEST_ISO=/path/to/ddpdoj.iso` to enable retail integration tests. The disc comparison also uses the three executables extracted to `baserom/` during PS2 setup. The Super Replay tests use the game's menu and check the final input count and score for each recording. Run those ten tests with `ctest --test-dir build/pc -C Release -L super-replay --output-on-failure`.
