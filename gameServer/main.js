var localStorage = require('localStorage');
var express = require('express');
var app = express();

// for testing purpuse: 
// clear stats for each server starts	
//
localStorage.clear();
console.log ('LS: ' + localStorage.length);

app.get('/', function(req, res){
  res.sendFile(__dirname + '/game.html');
});

// routing
app.get ('/api', function (req, res) {

	console.log ('url:' + req.url);   // /api?wins:5

	var wins = req.query.wins;
		
	// compute running average ...
	var aveStr = localStorage.getItem ('runAve');
	var average;
	if (aveStr === null) 
		average = {n: 0, ave: 0};
	else
		average = JSON.parse (aveStr);

	// gotcha!
	average.ave = (Number(average.ave * average.n) + Number(wins))/(Number(average.n)+10);
	average.n += 10;
	localStorage.setItem ('runAve', JSON.stringify (average) );
	
	// response
	var outputObj = {
		status: 1,
		output: average.n +', ' + average.ave
	};

	res.writeHead(200, {
		"Content-Type": "application/json",
		"Access-Control-Allow-Origin": "*",
		"Access-Control-Allow-Headers": "Content-Type"
	});

	res.write(JSON.stringify(outputObj));
	res.end();
 		
});

// simply
// app.listen (1337); 
// will do

var server = app.listen (1337, function() {
	var host = server.address().address;
	var port = server.address().port;
	console.log ('server started on http://' + host + ':' + port);
});

