#pragma once

#include "pxr/imaging/hd/rendererPlugin.h"

class HdQuantumRendererPlugin final : public HdRendererPlugin 
{
public:
    HdQuantumRendererPlugin()          = default;
    virtual ~HdQuantumRendererPlugin() = default;

    virtual HdRenderDelegate *CreateRenderDelegate() override;
    virtual HdRenderDelegate *CreateRenderDelegate(
        HdRenderSettingsMap const& settingsMap) override;

    virtual void DeleteRenderDelegate(HdRenderDelegate *renderDelegate) 
        override;

    virtual bool IsSupported() const override;

private:
    HdQuantumRendererPlugin(const HdQuantumRendererPlugin &)             = delete;
    HdQuantumRendererPlugin &operator =(const HdQuantumRendererPlugin &) = delete;
};
