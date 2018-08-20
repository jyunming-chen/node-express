var shelljs = require('shelljs');

// Sync call to exec()
//var version = exec('node --version', {silent:true}).output;

// Async call to exec()
var lsout = shelljs.ls("*.js");
//var myfiles = lsout.split('\n');
var res = lsout.stdout.split("\n")

//console.log (lsout.stdout.split("\n"));

for (var i = 0; i < res.length; i++) 
	console.log (res[i])
