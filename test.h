#ifndef TEST_H
#define TEST_H

#include "structs.h"


namespace test{
	class Test {
		public:
			static Test* Init();
			static void Print();
		
		private:
			explicit Test();
			~Test();

			static struct simple simple_;
	};
}

#endif
