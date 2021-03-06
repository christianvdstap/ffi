#include <node.h>
#include "wrapper.h"

namespace wrapper {

using v8::Local;
using v8::Object;

void InitAll(Local<Object> exports) {
  Wrapper::Init(exports);
}

NODE_MODULE(addon, InitAll)

}  // namespace wrapper
