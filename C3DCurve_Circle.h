#pragma once

#include "C3DCurve.h"
#include "C3DCircle.h"

class C3DCurve_Circle : public C3DCurve {
public:
	std::unique_ptr<C3DObject> factoryMethod() override;

	~C3DCurve_Circle() = default;

};
