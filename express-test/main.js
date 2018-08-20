var express = require('express');
var app = express();

app.get ('/', function (req, res) {
	console.log ('client connected')
	res.send ('hello world');
});

app.listen (3000, function () {
	console.log ('server started on port 3000');
	}) ;

