// pch.h: This is a precompiled header file.
// Files listed below are compiled only once, improving build performance for future builds.
// This also affects IntelliSense performance, including code completion and many code browsing features.
// However, files listed here are ALL re-compiled if any one of them is updated between builds.
// Do not add files here that you will be updating frequently as this negates the performance advantage.

#pragma once

#pragma warning(push)
#pragma warning(disable : 4244) // disabling type conversion warnings in USD
#pragma warning(disable : 4305) // disabling type truncation warnings in USD
#pragma warning(disable : 4127) // disabling const comparison warnings in USD
#pragma warning(disable : 4201) // disabling nameless struct warnings in USD
#pragma warning(disable : 4100) // disabling unreferenced parameter warnings in USD
#pragma warning(disable : 4275) // disabling non dll-interface class used as base for dll-interface class in USD

#include "pxr/pxr.h"
#include "pxr/base/arch/defines.h"

#pragma warning(pop)

PXR_NAMESPACE_USING_DIRECTIVE
