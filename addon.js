const addon = require('./build/Release/addon');

var obj = new addon.Wrapper();
console.log(addon.getSimple());
//console.log(addon.hello()); // 'world'
