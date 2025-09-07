#pragma once

#include "C3DCurve.h"
#include "C3DEllipse.h"

class C3DCurve_Ellipse : public C3DCurve {
public:
	std::unique_ptr<C3DObject> factoryMethod() override;

	~C3DCurve_Ellipse() = default;

};
