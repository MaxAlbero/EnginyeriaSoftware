#pragma once
#include "Administrator.h"
#include "Teacher.h"

class AdminTeach : public Administrator, public Teacher {
	void DoSomething() {
		Administrate();
		Teach();
		Administrator::Update();
		Teacher::Update();
	}
};