#ifndef WS_M3_PARSER_H
#define WS_M3_PARSER_H
#include <stddef.h>
#include <stdint.h>
#ifdef _WIN32
#define WS_API __declspec(dllexport)
#else
#define WS_API __attribute__((visibility("default")))
#endif
#ifdef __cplusplus
extern "C" {
#endif
/* ABI v2. Returns 1 on success, 0 on error. On success *json is a UTF-8, NUL-terminated
   JSON document (matching the Model Studio's /api/open response). On error
   *error is an allocated UTF-8 error. Call ws_m3_free on either allocated pointer.
   Input is borrowed during the call; the library does not retain it.
   Supports M3 / LDOM v100; geometry, UVs, tangents, vertex colors, weights,
   bones/tracks, palettes, materials/layers, FX metadata, camera/light/attachments.
   Shader processing and playback are the responsibility of the renderer. */
WS_API int ws_m3_parse_json(const void *bytes, size_t size, const char *filename,
                         char **json, char **error);
WS_API void ws_m3_free(void *pointer);
WS_API uint32_t ws_m3_abi_version(void);
#ifdef __cplusplus
}
#endif
#endif
