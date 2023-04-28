#include "pch.h"

#include "HdQuantumRenderDelegate.h"
#include "HdQuantumMesh.h"
#include "HdQuantumRenderPass.h"

const TfTokenVector HdQuantumRenderDelegate::SUPPORTED_RPRIM_TYPES =
{
    HdPrimTypeTokens->mesh,
};

const TfTokenVector HdQuantumRenderDelegate::SUPPORTED_SPRIM_TYPES =
{
};

const TfTokenVector HdQuantumRenderDelegate::SUPPORTED_BPRIM_TYPES =
{
};

HdQuantumRenderDelegate::HdQuantumRenderDelegate()
    : HdRenderDelegate()
{
    _Initialize();
}

HdQuantumRenderDelegate::HdQuantumRenderDelegate(
    HdRenderSettingsMap const& settingsMap)
    : HdRenderDelegate(settingsMap)
{
    _Initialize();
}

void HdQuantumRenderDelegate::_Initialize()
{
    std::cout << "Creating RenderDelegate" << std::endl;
    _resourceRegistry = std::make_shared<HdResourceRegistry>();
}

HdQuantumRenderDelegate::~HdQuantumRenderDelegate()
{
    _resourceRegistry.reset();
    std::cout << "Destroying RenderDelegate" << std::endl;
}

TfTokenVector const& HdQuantumRenderDelegate::GetSupportedRprimTypes() const
{
    return SUPPORTED_RPRIM_TYPES;
}

TfTokenVector const& HdQuantumRenderDelegate::GetSupportedSprimTypes() const
{
    return SUPPORTED_SPRIM_TYPES;
}

TfTokenVector const& HdQuantumRenderDelegate::GetSupportedBprimTypes() const
{
    return SUPPORTED_BPRIM_TYPES;
}

HdResourceRegistrySharedPtr HdQuantumRenderDelegate::GetResourceRegistry() const
{
    return _resourceRegistry;
}

void HdQuantumRenderDelegate::CommitResources(HdChangeTracker* tracker)
{
    std::cout << "=> CommitResources RenderDelegate" << std::endl;
}

HdRenderPassSharedPtr HdQuantumRenderDelegate::CreateRenderPass(
    HdRenderIndex* index,
    HdRprimCollection const& collection)
{
    std::cout << "Create RenderPass with Collection="
        << collection.GetName() << std::endl;

    return HdRenderPassSharedPtr(new HdQuantumRenderPass(index, collection));
}

HdRprim* HdQuantumRenderDelegate::CreateRprim(TfToken const& typeId, SdfPath const& rprimId)
{
    std::cout << "Create Rprim type=" << typeId.GetText()
        << " id=" << rprimId
        << std::endl;

    if (typeId == HdPrimTypeTokens->mesh)
    {
        return new HdQuantumMesh(rprimId);
    }
    else 
    {
        TF_CODING_ERROR("Unknown Rprim type=%s id=%s",
            typeId.GetText(),
            rprimId.GetText());
    }
    return nullptr;
}

void HdQuantumRenderDelegate::DestroyRprim(HdRprim* rPrim)
{
    std::cout << "Destroy Rprim id=" << rPrim->GetId() << std::endl;
    delete rPrim;
}

HdSprim* HdQuantumRenderDelegate::CreateSprim(TfToken const& typeId, SdfPath const& sprimId)
{
    TF_CODING_ERROR("Unknown Sprim type=%s id=%s",
        typeId.GetText(),
        sprimId.GetText());
    return nullptr;
}

HdSprim* HdQuantumRenderDelegate::CreateFallbackSprim(TfToken const& typeId)
{
    TF_CODING_ERROR("Creating unknown fallback sprim type=%s",
        typeId.GetText());
    return nullptr;
}

void HdQuantumRenderDelegate::DestroySprim(HdSprim* sPrim)
{
    TF_CODING_ERROR("Destroy Sprim not supported");
}

HdBprim* HdQuantumRenderDelegate::CreateBprim(TfToken const& typeId, SdfPath const& bprimId)
{
    TF_CODING_ERROR("Unknown Bprim type=%s id=%s",
        typeId.GetText(),
        bprimId.GetText());
    return nullptr;
}

HdBprim* HdQuantumRenderDelegate::CreateFallbackBprim(TfToken const& typeId)
{
    TF_CODING_ERROR("Creating unknown fallback bprim type=%s",
        typeId.GetText());
    return nullptr;
}

void HdQuantumRenderDelegate::DestroyBprim(HdBprim* bPrim)
{
    TF_CODING_ERROR("Destroy Bprim not supported");
}

HdInstancer* HdQuantumRenderDelegate::CreateInstancer(
    HdSceneDelegate* delegate,
    SdfPath const& id)
{
    TF_CODING_ERROR("Creating Instancer not supported id=%s",
        id.GetText());
    return nullptr;
}

void HdQuantumRenderDelegate::DestroyInstancer(HdInstancer* instancer)
{
    TF_CODING_ERROR("Destroy instancer not supported");
}

HdRenderParam* HdQuantumRenderDelegate::GetRenderParam() const
{
    return nullptr;
}
