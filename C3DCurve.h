#pragma once

#include "C3DObject.h"
#include <memory>

class C3DCurve {
public:
	virtual std::unique_ptr<C3DObject> factoryMethod() = 0;

	virtual ~C3DCurve() = default;
};