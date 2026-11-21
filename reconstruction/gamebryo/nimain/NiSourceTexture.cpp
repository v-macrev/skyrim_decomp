// Source exposure: mixed (names and declarations from community headers; the listing of the pinned image).
// Code origin: hand-written from the local listing; names and declarations from the community header named in NiSourceTexture.h.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Adapted bodies: none
// 0xef3500 NiSourceTexture::Unk_25
// 0xef3520 NiSourceTexture::Unk_26
// Drafted by v-macrev, assisted by claude-opus-5-5.
#include "NiSourceTexture.h"

// TextureLookupState, g_textureLookupState, LookupRendererTexture, UpdateRendererTexture: STANDIN GUESS(low); names invented
struct TextureLookupState;
extern TextureLookupState g_textureLookupState;
std::uint64_t LookupRendererTexture(TextureLookupState* a_state, BSGraphicsTexture* a_texture);
std::uint64_t UpdateRendererTexture(TextureLookupState* a_state, BSGraphicsTexture* a_texture);

// Unk_25 is the community name; the community header says it returns 0, the listing consults the renderer texture.
std::uint64_t NiSourceTexture::Unk_25()
{
    if (rendererTexture) {
        return LookupRendererTexture(&g_textureLookupState, rendererTexture);
    }
    return 0;
}

// Unk_26 is the community name; same shape as Unk_25 with the neighbouring helper.
std::uint64_t NiSourceTexture::Unk_26()
{
    if (rendererTexture != nullptr) {
        return UpdateRendererTexture(&g_textureLookupState, rendererTexture);
    }
    return 0;
}
