#!/usr/bin/env bash
# Run from the repo root after installing the desktop targets into stage/.
set -euo pipefail
platform=${1:?expected platform}
version=${2:?expected version}
[[ $version =~ ^[A-Za-z0-9._+-]+$ ]] || { echo 'Invalid release filename' >&2; exit 1; }
root=$PWD
mkdir -p dist
archive="$root/dist/ddpdoj-$version-$platform"
check=$(mktemp -d)
trap 'rm -rf "$check"' EXIT

instructions() {
    cat > "$1/Start here.txt" <<TEXT
DaiOuJou for $platform
$2
At first launch, select your retail DoDonPachi DaiOuJou PS2 ISO (SLPS-252.33).
The game remembers the disc location for future launches.
Hold Tab to fast-forward. Press F1 to save a state and F2 to load it.
TEXT
}

check_launchers() {
    local dir=$1 suffix=$2 architecture=$3 launcher
    for launcher in ddpdoj ddpdoj-death ddpdoj-gallery; do
        file -b "$dir/$launcher$suffix" | grep -F "$architecture"
        "$dir/$launcher$suffix" --check-install
    done
}

case "$platform" in
windows-x64)
    game=stage/DaiOuJou
    # Walk PE imports recursively. Copy toolchain DLLs beside the launchers.
    binaries=("$game"/*.exe "$game"/*.dll)
    for ((i=0; i<${#binaries[@]}; i++)); do
        imports=$(objdump -p "${binaries[i]}" | awk '/DLL Name:/ {print $3}' | tr -d '\r')
        for dll in $imports; do
            if [[ -f "$MINGW_PREFIX/bin/$dll" && ! -f "$game/$dll" ]]; then
                cp "$MINGW_PREFIX/bin/$dll" "$game/"
                binaries+=("$game/$dll")
                owner=$(pacman -Qqo "$MINGW_PREFIX/bin/$dll")
                licenses="$MINGW_PREFIX/share/licenses/${owner#mingw-w64-ucrt-x86_64-}"
                if [[ -d "$licenses" ]]; then
                    mkdir -p "$game/licenses"
                    cp -R "$licenses" "$game/licenses/"
                fi
            fi
        done
    done
    instructions "$game" 'Extract the entire folder and open ddpdoj.exe.'
    (cd stage && zip -qr "$archive.zip" DaiOuJou)
    unzip -q "$archive.zip" -d "$check"
    cd "$check"
    # Exclude the development toolchain DLL directories from the loader search.
    PATH=/usr/bin:/c/Windows/System32 check_launchers "$check/DaiOuJou" .exe x86-64
    ;;
macos-arm64)
    app=DaiOuJou.app
    instructions stage 'Drag DaiOuJou.app to Applications and open it. This build is not notarized.'
    ditto -c -k --sequesterRsrc stage "$archive.zip"
    ditto -x -k "$archive.zip" "$check"
    cd "$check"
    codesign --verify --deep --strict "$app"
    check_launchers "$check/$app/Contents/MacOS" '' arm64
    ;;
linux-x64)
    appdir="$check/AppDir"
    mkdir -p "$appdir/usr"
    cp -R stage/DaiOuJou "$appdir/usr/bin"
    ln -s usr/bin/ddpdoj "$appdir/AppRun"
    cp pc/linux/ddpdoj.{desktop,svg} "$appdir/"
    instructions "$appdir" 'Mark the AppImage executable and open it.'
    ARCH=x86_64 ./appimagetool --appimage-extract-and-run --runtime-file "$root/runtime" "$appdir" "$archive.AppImage"
    cd "$check"
    "$archive.AppImage" --appimage-extract >/dev/null
    check_launchers "$check/squashfs-root/usr/bin" '' x86-64
    "$archive.AppImage" --appimage-extract-and-run --check-install
    ;;
*) echo "Unknown platform: $platform" >&2; exit 1 ;;
esac
