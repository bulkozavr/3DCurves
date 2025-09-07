#pragma once

#include "C3DObject.h"

class C3DCircle : public C3DObject {
public:
	C3DCircle(const float radius) : C3DObject(radius, radius, 0) {};

	void PrintCoordsAndDerivative(const float t) const override;

	~C3DCircle() = default;
};
