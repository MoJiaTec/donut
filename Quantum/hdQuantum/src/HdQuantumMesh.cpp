#include "pch.h"

#include "HdQuantumMesh.h"


HdQuantumMesh::HdQuantumMesh(SdfPath const& id)
    : HdMesh(id)
{
}

HdDirtyBits HdQuantumMesh::GetInitialDirtyBitsMask() const
{
    return HdChangeTracker::Clean
        | HdChangeTracker::DirtyTransform;
}

HdDirtyBits HdQuantumMesh::_PropagateDirtyBits(HdDirtyBits bits) const
{
    return bits;
}

void HdQuantumMesh::_InitRepr(TfToken const &reprToken, HdDirtyBits *dirtyBits)
{

}

void HdQuantumMesh::Sync(HdSceneDelegate *sceneDelegate,
                   HdRenderParam   *renderParam,
                   HdDirtyBits     *dirtyBits,
                   TfToken const   &reprToken)
{
    std::cout << "* (multithreaded) Sync Mesh id=" << GetId() << std::endl;
}

