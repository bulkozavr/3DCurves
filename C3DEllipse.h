#pragma once

#include "C3DObject.h"

class C3DEllipse : public C3DObject {
public:

	C3DEllipse(const float bigRadius, const float smallRadius) :
		C3DObject(bigRadius, smallRadius, 0) {};

	void PrintCoordsAndDerivative(float) const override;

	~C3DEllipse() = default;
};
