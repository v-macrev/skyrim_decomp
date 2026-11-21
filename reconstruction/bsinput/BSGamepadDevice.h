// Source exposure: mixed (names and declarations from community headers; base classes, sizes and
// the compared functions from the pinned image).
// Code origin: Written for this reconstruction from the listing; names from the header.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BSGamepadDevice: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) EXE_RTTI
// BSIInputDevice, BSInputDevice: STANDIN EXE_RTTI
// BSGamepadDevice::Unk_0E, BSGamepadDevice::Unk_0C, BSGamepadDevice::ResetLEDColor: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// BSIInputDevice::~BSIInputDevice, unknown08, unknown70, unknownC8, enabledCC: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

class BSIInputDevice
{
public:
    virtual ~BSIInputDevice() = default;
};
static_assert(sizeof(BSIInputDevice) == 0x8, "BSIInputDevice size");

class BSInputDevice : public BSIInputDevice
{
public:
    std::uint8_t unknown08[0x68];  // 08
};
static_assert(sizeof(BSInputDevice) == 0x70, "BSInputDevice size");

class BSGamepadDevice : public BSInputDevice
{
public:
    virtual void Unk_0E();  // compared: 0xcfbde0
    virtual bool Unk_0C();  // compared: 0xcfc180
    virtual void ResetLEDColor();  // compared: 0xcfc1a0

    bool IsEnabled();  // compared: 0xcfc150

    std::uint8_t unknown70[0x58];  // 70
    std::int32_t unknownC8;        // C8: compared against -1 by IsEnabled
    bool enabledCC;                // CC: checked by IsEnabled
    std::uint8_t unknownCD[0x3];   // CD
};
static_assert(sizeof(BSGamepadDevice) == 0xD0, "BSGamepadDevice size");
