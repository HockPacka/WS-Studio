// Standalone regression for the production chunk-phase calculation.
#include "WoW/Source/WorldClient/TerrainTextureCoords.h"
#include <cstdio>

static double WrapError(double delta) {
    return std::abs(delta - std::round(delta));
}

int main() {
    const float factors[] = {1, 0.5f, 0.25f, 0.125f, 0.0625f, 0.03125f};
    int checked = 0;
    double worst = 0;
    for (float factor : factors) {
        // All chunks, both outer edges, ADT boundaries, and negative indices.
        for (int i = -16; i < 1040; ++i) {
            float origin = 17066.666f - i * 33.333332f;
            float next = 17066.666f - (i + 1) * 33.333332f;
            float a = TerrainTextureCoords::Phase(origin, factor);
            float b = TerrainTextureCoords::Phase(next, factor);
            // Independent world-coordinate expression used by the shader:
            // (vertex - chunkOrigin) * -geoToTex + phase.
            double edge = (double(next) - origin) * (-8.0 / 33.333332) * factor + a;
            double error = WrapError(edge - b);
            if (error > worst) worst = error;
            if (error > 0.001 || a < 0 || a >= 1 ||
                (factor >= 0.125f && a != 0)) {
                fprintf(stderr, "FAIL factor=%g chunk=%d phase=%g next=%g error=%g\n", factor, i, a, b, error);
                return 1;
            }
            ++checked;
        }
    }
    // Explicitly catch the old half/quarter-repeat restart, including axis order.
    float x = 17066.666f - 33.333332f;
    float y = 17066.666f - 2 * 33.333332f;
    if (TerrainTextureCoords::Phase(x, 0.0625f) != 0.5f ||
        TerrainTextureCoords::Phase(y, 0.0625f) != 0 ||
        TerrainTextureCoords::Phase(x, 0.03125f) != 0.25f ||
        TerrainTextureCoords::Phase(y, 0.03125f) != 0.5f) return 2;
    printf("PASS %d chunk edges; worst UV error %.9g repeats\n", checked, worst);
}
