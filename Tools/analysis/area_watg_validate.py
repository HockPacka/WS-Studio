"""Validate the self-contained WATG surface mesh across many .area cells."""
from collections import Counter
import math
import sys
from area_water_decode import water_cells, decode_watg


def main():
    layers = Counter()
    flags = Counter()
    types = Counter()
    strides = Counter()
    cells = 0
    vertices_total = 0
    for name, cell, raw, _ in water_cells(500):
        water = decode_watg(raw)
        layers[water["layer"]] += 1
        flags[water["flags"]] += 1
        types[water["water_type"]] += 1
        cells += 1
        vertices_total += len(water["vertices"])
        for vertex in water["vertices"]:
            if not all(math.isfinite(value) for value in vertex):
                raise ValueError(f"non-finite WATG vertex: {name} {cell}")
        if cells <= 3:
            print("CELL", name, cell, "type", water["water_type"], "layer", water["layer"],
                  "indices", len(water["indices"]), "vertices", len(water["vertices"]))
            for index, vertex in enumerate(water["vertices"][:5]):
                print(" VERTEX", index, ["%.7g" % value for value in vertex])
    print("VALIDATED", cells, "cells", vertices_total, "vertices")
    print("TYPES", types, "FLAGS", flags, "LAYERS", layers)


if __name__ == "__main__":
    main()
