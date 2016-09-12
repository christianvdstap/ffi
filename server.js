var ref = require('ref');
var ffi = require('ffi');
var struct = require('ref-struct');

// Typedefs
var Simple = struct({
	'number': 'int'
});
var SimplePtr = ref.refType(Simple);
var SimplePtrPtr = ref.refType(SimplePtr);

//var list = ref.types.void;
//var element = ref.types.void;

var lib = ffi.Library('/home/vagrant/ffi/libstructs', {
	"simpleFunc": ['int', [SimplePtr]],
	"simplePointerFunc": ['int', [SimplePtrPtr]]
});

var simple = new Simple();
console.log(simple);
lib.simpleFunc(simple.ref());
console.log(simple);

//var simple2 = ref.alloc(Simple);
//lib.simplePointerFunc(simple2);
//console.log(simple2.deref());
var simple2 = ref.alloc(Simple);
lib.simplePointerFunc(simple2.ref());
console.log(simple2.deref());
