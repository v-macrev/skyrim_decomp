// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: written for this reconstruction from the listing; names from the header.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0xcfc150 BSGamepadDevice::IsEnabled
// Adapted bodies: none
// 0xcfbde0 Unk_0E
// 0xcfc180 BSGamepadDevice::Unk_0C
// 0xcfc1a0 ResetLEDColor
// Drafted by v-macrev, assisted by claude-haiku-5-5.
#include "BSGamepadDevice.h"

// RVA 0xcfc150, 24 bytes
bool BSGamepadDevice::IsEnabled()
{
    return enabledCC && unknownC8 != -1;
}

// RVA 0xcfbde0, 3 bytes
void BSGamepadDevice::Unk_0E()
{
}

// RVA 0xcfc180, 3 bytes
bool BSGamepadDevice::Unk_0C()
{
    return false;
}

// RVA 0xcfc1a0, 3 bytes
void BSGamepadDevice::ResetLEDColor()
{
}
