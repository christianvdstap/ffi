#include "structs.h"
#include "test.h"
#include <stdio.h>

namespace test {
	struct simple Test::simple_;

	Test::Test() {
		struct simple s = {1};
		simpleFunc(&s);
		this->simple_ = s;
	}

	Test::~Test() {
	}

	Test* Test::Init() {
		return new Test();
	}

	void Test::Print() {
		printf("%d\n", simple_.number);
	}

	int main() {
		Test *t = Test::Init();
		t->Print();
	}
}

int main() {
	test::main();
}
