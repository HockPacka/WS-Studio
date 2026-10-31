with open('wowdecomp/Engine/Source/Model3/M3Reader.cpp', 'r', encoding='utf-8') as f:
    text = f.read()

old_block = """        size_t ia = gb + static_cast<size_t>(ido);

        if (ia + static_cast<size_t>(icount) * 2 > size) {
            error = "index data out of bounds";
            return false;
        }

        size_t ma2 = gb + static_cast<size_t>(mso);

        if (msc > size || ma2 + msc * 0x70 > size) {
            error = "mesh table out of bounds";
            return false;
        }

        size_t indexBase = m.indices.size();
        m.indices.resize(indexBase + icount);

        for (uint32_t k = 0; k < icount; k++) {
            uint16_t idx;
            memcpy(&idx, data + ia + static_cast<size_t>(k) * 2, 2);
            m.indices[indexBase + k] = idx;
        }"""

new_block = """        uint64_t idxBytes = 0;
        c.Get(g + 0x70, idxBytes);
        bool isIndex32 = (idxBytes >= static_cast<uint64_t>(icount) * 4);
        size_t indexElemSize = isIndex32 ? 4 : 2;

        size_t ia = gb + static_cast<size_t>(ido);

        if (ia + static_cast<size_t>(icount) * indexElemSize > size) {
            error = "index data out of bounds";
            return false;
        }

        size_t ma2 = gb + static_cast<size_t>(mso);

        if (msc > size || ma2 + msc * 0x70 > size) {
            error = "mesh table out of bounds";
            return false;
        }

        size_t indexBase = m.indices.size();
        m.indices.resize(indexBase + icount);

        if (isIndex32) {
            for (uint32_t k = 0; k < icount; k++) {
                uint32_t idx;
                memcpy(&idx, data + ia + static_cast<size_t>(k) * 4, 4);
                m.indices[indexBase + k] = idx;
            }
        } else {
            for (uint32_t k = 0; k < icount; k++) {
                uint16_t idx;
                memcpy(&idx, data + ia + static_cast<size_t>(k) * 2, 2);
                m.indices[indexBase + k] = idx;
            }
        }"""

assert old_block in text, "old_block not found in M3Reader.cpp"
text = text.replace(old_block, new_block)

with open('wowdecomp/Engine/Source/Model3/M3Reader.cpp', 'w', encoding='utf-8', newline='\r\n') as f:
    f.write(text)

print("Updated M3Reader.cpp with 16/32-bit index support successfully")
