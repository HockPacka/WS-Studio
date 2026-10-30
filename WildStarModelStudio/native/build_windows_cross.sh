#!/usr/bin/env bash
set -euo pipefail
cd "$(dirname "$0")"
: "${CLANG:=clang}"
: "${LLD_LINK:=lld-link}"
"$CLANG" -target x86_64-pc-windows-msvc -std=c11 -ffreestanding -fno-builtin -fno-stack-protector -O2 -c ws_m3_parser.c -o ws_m3_parser.obj
"$LLD_LINK" /machine:x64 /dll /noentry /nodefaultlib /def:kernel32_exports.def /out:kernel32_stub.dll /implib:kernel32_stub.lib
"$LLD_LINK" /machine:x64 /dll /noentry /nodefaultlib /out:ws_m3_parser.dll /implib:ws_m3_parser.lib /export:ws_m3_parse_json /export:ws_m3_free /export:ws_m3_abi_version ws_m3_parser.obj kernel32_stub.lib
rm -f ws_m3_parser.obj kernel32_stub.dll kernel32_stub.lib
printf 'Windows-x64 M3-Parser gebaut: %s\n' "$(pwd)/ws_m3_parser.dll"
