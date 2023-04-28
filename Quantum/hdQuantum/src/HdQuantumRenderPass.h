
#pragma once

#include "pxr/imaging/hd/renderPass.h"

class HdQuantumRenderDelegate;

class HdQuantumRenderPass final : public HdRenderPass
{
public:
    HdQuantumRenderPass(HdRenderIndex* index, HdRprimCollection const& collection);
    ~HdQuantumRenderPass();

    bool IsConverged() const override;

protected:
    void _Execute(HdRenderPassStateSharedPtr const& renderPassState,
        TfTokenVector const& renderTags) override;

    void _MarkCollectionDirty() override {}

private:
};