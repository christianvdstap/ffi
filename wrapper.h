#ifndef WRAPPER_H
#define WRAPPER_H

#include <node.h>
#include <node_object_wrap.h>
#include "structs.h"

namespace wrapper {
	class Wrapper : public node::ObjectWrap {
		public:
			static void Init(v8::Local<v8::Object> exports);

		private:
			explicit Wrapper();
			~Wrapper();

			static void New(const v8::FunctionCallbackInfo<v8::Value>& args);
			static v8::Persistent<v8::Function> constructor;

			static void GetSimple(const v8::FunctionCallbackInfo<v8::Value>& args);
			static struct simple simple_;
	};
} // Namespace wrapper

#endif
