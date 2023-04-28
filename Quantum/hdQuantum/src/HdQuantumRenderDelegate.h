#pragma once

#include "pxr/imaging/hd/renderDelegate.h"
#include "pxr/imaging/hd/resourceRegistry.h"
#include "pxr/base/tf/staticTokens.h"

class HdQuantumRenderDelegate : public HdRenderDelegate
{
public:
    HdQuantumRenderDelegate();
    HdQuantumRenderDelegate(HdRenderSettingsMap const& settingsMap);
    virtual ~HdQuantumRenderDelegate();

    /// Supported types
    const TfTokenVector& GetSupportedRprimTypes() const override;
    const TfTokenVector& GetSupportedSprimTypes() const override;
    const TfTokenVector& GetSupportedBprimTypes() const override;

    // Basic value to return from the RD
    HdResourceRegistrySharedPtr GetResourceRegistry() const override;

    // Prims
    HdRenderPassSharedPtr CreateRenderPass(
        HdRenderIndex* index,
        HdRprimCollection const& collection) override;

    HdInstancer* CreateInstancer(HdSceneDelegate* delegate,
        SdfPath const& id) override;
    void DestroyInstancer(HdInstancer* instancer) override;

    HdRprim* CreateRprim(TfToken const& typeId,
        SdfPath const& rprimId) override;
    void DestroyRprim(HdRprim* rPrim) override;

    HdSprim* CreateSprim(TfToken const& typeId,
        SdfPath const& sprimId) override;
    HdSprim* CreateFallbackSprim(TfToken const& typeId) override;
    void DestroySprim(HdSprim* sprim) override;

    HdBprim* CreateBprim(TfToken const& typeId,
        SdfPath const& bprimId) override;
    HdBprim* CreateFallbackBprim(TfToken const& typeId) override;
    void DestroyBprim(HdBprim* bprim) override;

    void CommitResources(HdChangeTracker* tracker) override;

    HdRenderParam* GetRenderParam() const override;

private:
    static const TfTokenVector SUPPORTED_RPRIM_TYPES;
    static const TfTokenVector SUPPORTED_SPRIM_TYPES;
    static const TfTokenVector SUPPORTED_BPRIM_TYPES;

    void _Initialize();

    HdResourceRegistrySharedPtr _resourceRegistry;

    // This class does not support copying.
    HdQuantumRenderDelegate(const HdQuantumRenderDelegate&) = delete;
    HdQuantumRenderDelegate& operator =(const HdQuantumRenderDelegate&) = delete;
};
