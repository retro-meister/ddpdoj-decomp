# DoDonPachi DaiOuJou PS2 Decompilation & PC Port

Byte-matching decompilation of **DoDonPachi DaiOuJou** (PS2), covering all three disc executables: the main game (`SLPS_252.33`), Death Label (`DEATH.ELF`), and the Gallery (`GALLERY.ELF`). Also builds a native PC port for Windows, macOS and Linux. Supply your own retail ISO to build the PS2 version or play the PC port.

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

## Native PC port
**Repo setup**

```sh
git clone https://github.com/retro-meister/ddpdoj-decomp.git
cd ddpdoj-decomp
git submodule update --init
```

**macOS Terminal Build**

```sh
brew install cmake python
cmake -S pc -B build/pc -DCMAKE_BUILD_TYPE=Release
cmake --build build/pc --parallel
./build/pc/ddpdoj
```

Select your retail ISO on first launch. The port remembers its path.

**Windows PowerShell Build**

Install the build tools once, then reopen PowerShell in the repository root:

```powershell
winget install --exact --id BrechtSanders.WinLibs.POSIX.UCRT --architecture x64
winget install --exact --id Python.Python.3.12
```

```powershell
cmake -S pc -B build/pc -G "MinGW Makefiles" -DCMAKE_BUILD_TYPE=Release
cmake --build build/pc --parallel
.\build\pc\ddpdoj.exe
```


**Linux Terminal Build**

Install GCC, Make, CMake, Python 3 and [SDL’s build dependencies for your distribution](https://wiki.libsdl.org/SDL3/README-linux#build-dependencies).

```sh
cmake -S pc -B build/pc -DCMAKE_BUILD_TYPE=Release
cmake --build build/pc --parallel
./build/pc/ddpdoj
```