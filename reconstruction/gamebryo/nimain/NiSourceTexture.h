// Code origin: hand-written class layouts and declarations adapted from the CommonLibSSE-NG headers named below; compared bodies are written from the local listing.
// Source exposure: mixed (community declarations; bases, sizes and slots are community hypotheses).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Adapted bodies: none
// NiSourceTexture, NiTexture and their slots 02, 25-2A: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// NiRefObject, NiObject (self-contained stand-ins of the community classes): STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// NiTexture, FormatPrefs, BSFixedString and all data members: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
#pragma once

#include <cstdint>
#include <cstddef>

class NiRTTI;
class NiNode;
class NiSwitchNode;
class BSFadeNode;
class BSMultiBoundNode;
class BSGeometry;
class NiTriStrips;
class BSTriShape;
class BSSegmentedTriShape;
class BSSubIndexTriShape;
class BSDynamicTriShape;
class NiGeometry;
class NiTriBasedGeom;
class NiTriShape;
class NiParticles;
class BSLines;
class bhkNiCollisionObject;
class bhkBlendCollisionObject;
class bhkAttachmentCollisionObject;
class bhkRigidBody;
class bhkLimitedHingeConstraint;
class NiCloningProcess;
class NiStream;
class NiObjectGroup;
class NiControllerManager;
class BSResourceStream;
class BSGraphicsTexture;

class NiRefObject
{
public:
    virtual ~NiRefObject();  // 00
    virtual void DeleteThis();  // 01

    std::uint32_t refCount;  // 08
    std::uint32_t pad0C;  // 0C
};
static_assert(sizeof(NiRefObject) == 0x10, "NiRefObject size");

class NiObject : public NiRefObject
{
public:
    ~NiObject() override;  // 00
    virtual const NiRTTI* GetRTTI() const;  // 02
    virtual NiNode* AsNode();  // 03
    virtual NiSwitchNode* AsSwitchNode();  // 04
    virtual BSFadeNode* AsFadeNode();  // 05
    virtual BSMultiBoundNode* AsMultiBoundNode();  // 06
    virtual BSGeometry* AsGeometry();  // 07
    virtual NiTriStrips* AsTriStrips();  // 08
    virtual BSTriShape* AsTriShape();  // 09
    virtual BSSegmentedTriShape* AsSegmentedTriShape();  // 0A
    virtual BSSubIndexTriShape* AsSubIndexTriShape();  // 0B
    virtual BSDynamicTriShape* AsDynamicTriShape();  // 0C
    virtual NiGeometry* AsNiGeometry();  // 0D
    virtual NiTriBasedGeom* AsNiTriBasedGeom();  // 0E
    virtual NiTriShape* AsNiTriShape();  // 0F
    virtual NiParticles* AsParticlesGeom();  // 10
    virtual BSLines* AsLinesGeom();  // 11
    virtual bhkNiCollisionObject* AsBhkNiCollisionObject();  // 12
    virtual bhkBlendCollisionObject* AsBhkBlendCollisionObject();  // 13
    virtual bhkAttachmentCollisionObject* AsBhkAttachmentCollisionObject();  // 14
    virtual bhkRigidBody* AsBhkRigidBody();  // 15
    virtual bhkLimitedHingeConstraint* AsBhkLimitedHingeConstraint();  // 16
    virtual NiObject* CreateClone(NiCloningProcess& a_cloning);  // 17
    virtual void LoadBinary(NiStream& a_stream);  // 18
    virtual void LinkObject(NiStream& a_stream);  // 19
    virtual bool RegisterStreamables(NiStream& a_stream);  // 1A
    virtual void SaveBinary(NiStream& a_stream);  // 1B
    virtual bool IsEqual(NiObject* a_object);  // 1C
    virtual void ProcessClone(NiCloningProcess& a_cloning);  // 1D
    virtual void PostLinkObject(NiStream& a_stream);  // 1E
    virtual bool StreamCanSkip();  // 1F
    virtual const NiRTTI* GetStreamableRTTI() const;  // 20
    virtual std::uint32_t GetBlockAllocationSize() const;  // 21
    virtual NiObjectGroup* GetGroup() const;  // 22
    virtual void SetGroup(NiObjectGroup* a_group);  // 23
    virtual NiControllerManager* AsNiControllerManager();  // 24
};
static_assert(sizeof(NiObject) == 0x10, "NiObject size");

struct NiTextureFormatPrefs
{
    std::uint32_t pixelLayout;  // 00
    std::uint32_t alphaFormat;  // 04
    std::uint32_t mipMapped;  // 08
    std::uint32_t pad0C;  // 0C
};
static_assert(sizeof(NiTextureFormatPrefs) == 0x10, "FormatPrefs size");

struct BSFixedString
{
    const char* data;  // 00
};

class NiTexture : public NiObject
{
public:
    const NiRTTI* GetRTTI() const override;  // 02
    virtual std::uint64_t Unk_25(void);  // 25 (result type is a low-confidence guess)
    virtual std::uint64_t Unk_26(void);  // 26 (result type is a low-confidence guess)
    virtual void Unk_27(void);  // 27
    virtual void Unk_28(void);  // 28
    virtual void Unk_29(void);  // 29
    virtual void Unk_2A(void);  // 2A

    NiTextureFormatPrefs formatPrefs;  // 10
    BSFixedString name;  // 20
    std::uint32_t unk28;  // 28
    std::uint32_t unk2C;  // 2C
    NiTexture* prev;  // 30
    NiTexture* next;  // 38
};
static_assert(sizeof(NiTexture) == 0x40, "NiTexture size");

class NiSourceTexture : public NiTexture
{
public:
    ~NiSourceTexture() override;  // 00
    const NiRTTI* GetRTTI() const override;  // 02
    std::uint64_t Unk_25() override;  // compared: 0xef3500  // slot 25
    std::uint64_t Unk_26() override;  // compared: 0xef3520  // slot 26
    void Unk_27(void) override;  // 27
    void Unk_28(void) override;  // 28
    void Unk_29(void) override;  // 29
    void Unk_2A(void) override;  // 2A

    BSResourceStream* unk40;  // 40
    BSGraphicsTexture* rendererTexture;  // 48
    std::uint8_t flags;  // 50
    std::uint8_t pad51;  // 51
    std::uint16_t pad52;  // 52
    std::uint32_t pad54;  // 54
};
static_assert(sizeof(NiSourceTexture) == 0x58, "NiSourceTexture size");
static_assert(offsetof(NiSourceTexture, rendererTexture) == 0x48, "NiSourceTexture members");
