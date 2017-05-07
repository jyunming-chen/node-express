var shelljs = require('shelljs');

// Sync call to exec()
//var version = exec('node --version', {silent:true}).output;

var argv = "5";

// Async call to exec()
shelljs.exec('./a.out ' + argv, function(status, output) {
  console.log('Exit status: ' + status);
  console.log(5 + '! = ', output);
});
