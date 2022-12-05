var shelljs = require('shelljs');
var express = require('express');
var app = express();

// or simply
// app.listen (1337); 
// will do

var server = app.listen (1337, function() {
	var host = server.address().address;
	var port = server.address().port;
	console.log ('server started on http://' + host + ':' + port);
});

app.get ('/api', function (req, res) {
	//res.send ('request received');
	console.log ('url:' + req.url);
console.log (req.query);

	var argv = req.query.argv; // ("argv");
	console.log (argv);
		
	shelljs.exec('./a.out ' + argv, function(code, stdout, stderr) {
	  console.log('Exit code: ' + code);
		  
	  var outputStr = argv + '! = ' + stdout;

	  console.log(outputStr);

	  res.writeHead(200, {"Content-Type": "text/plain"});
	  res.write(outputStr);
	  res.end();   
	 	
	});
});
