var express = require('express');
var app = express();

//app.use (express.static ('public'));

app.get ('/', function (req, res) {
	console.log ('client connected')
	res.sendFile (__dirname + "/h1-static.htm");
});

app.listen (3000, function () {
	console.log ('server started on port 3000');
	}) ;

