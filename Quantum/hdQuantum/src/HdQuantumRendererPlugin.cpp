
#include "pch.h"

#include "HdQuantumRenderDelegate.h"
#include "HdQuantumRendererPlugin.h"

HdRenderDelegate* HdQuantumRendererPlugin::CreateRenderDelegate()
{
    return new HdQuantumRenderDelegate();
}

HdRenderDelegate* HdQuantumRendererPlugin::CreateRenderDelegate(HdRenderSettingsMap const& settingsMap)
{
    return new HdQuantumRenderDelegate(settingsMap);
}

void HdQuantumRendererPlugin::DeleteRenderDelegate(HdRenderDelegate *renderDelegate)
{
    delete renderDelegate;
}

bool HdQuantumRendererPlugin::IsSupported() const
{
    return true;
}

