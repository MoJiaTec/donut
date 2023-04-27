
#include "pch.h"

#include "rendererPlugin.h"

#include "pxr/imaging/hdSt/renderDelegate.h"

HdRenderDelegate* HdQuantumRendererPlugin::CreateRenderDelegate()
{
    return new HdStRenderDelegate();
}

HdRenderDelegate* HdQuantumRendererPlugin::CreateRenderDelegate(
    HdRenderSettingsMap const& settingsMap)
{
    return new HdStRenderDelegate(settingsMap);
}

void HdQuantumRendererPlugin::DeleteRenderDelegate(HdRenderDelegate *renderDelegate)
{
    delete renderDelegate;
}

bool HdQuantumRendererPlugin::IsSupported() const
{
    return HdStRenderDelegate::IsSupported();
}

