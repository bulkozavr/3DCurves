#pragma once

#include "C3DCurve.h"
#include "C3DHelix.h"

class C3DCurve_Helix : public C3DCurve {
public:
	std::unique_ptr<C3DObject> factoryMethod() override;

	~C3DCurve_Helix() = default;
};
