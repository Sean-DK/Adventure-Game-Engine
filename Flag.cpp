#include "stdafx.h"
#include "Flag.hpp"

void Flag::complete() {
	if (req == nullptr) {}
	else if (req->isComplete()) {
		val = true;
	}
}
