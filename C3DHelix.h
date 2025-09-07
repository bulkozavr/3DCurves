#pragma once

#include "C3DObject.h"

class C3DHelix : public C3DObject {
public:

	C3DHelix(const float xRadius, const float yRadius, const float step) :
		C3DObject(xRadius, yRadius, step) {};

	void PrintCoordsAndDerivative(const float t) const override;

	~C3DHelix() = default;
};

