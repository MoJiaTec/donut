#include "pch.h"

#include "HdQuantumRenderDelegate.h"
#include "HdQuantumRenderPass.h"

HdQuantumRenderPass::HdQuantumRenderPass(HdRenderIndex* index, HdRprimCollection const& collection) :
    HdRenderPass(index, collection)
{
}

HdQuantumRenderPass::~HdQuantumRenderPass()
{
}

bool HdQuantumRenderPass::IsConverged() const
{
    return true;
}

void HdQuantumRenderPass::_Execute(HdRenderPassStateSharedPtr const& renderPassState, TfTokenVector const& /* renderTags */)
{
    std::cout << "=> Execute RenderPass" << std::endl;
}
