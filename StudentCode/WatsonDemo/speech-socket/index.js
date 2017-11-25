require('dotenv').config({ silent: true }); 
const SpeechToTextV1 = require('watson-developer-cloud/speech-to-text/v1');
var NaturalLanguageUnderstandingV1 = require('watson-developer-cloud/natural-language-understanding/v1');
const util = require('util');
var EventEmitter = require('events').EventEmitter;
const spawn = require('child_process').spawn;
var which = require('which');


// Find the "rec" program (it comes with sox)
var rec = "rec";
which('rec', function (err, resolvedPath) {
	if(err) throw err;
 	rec = resolvedPath;
});


// Open a socketio server on port 3000
var io = require('socket.io')(3000);
io.on('connection', function (socket) {
	socket.on('message', function () { });
	socket.on('disconnect', function () { });
});


// Create a SpeechToText object
// NOTE: This depends on SPEECH_TO_TEXT_USERNAME and SPEECH_TO_TEXT_PASSWORD in .env file
const stt = new SpeechToTextV1();


// Create a NaturalLanguageUnderstanding object
// NOTE: This depends on NATURAL_LANGUAGE_UNDERSTANDING_USERNAME and NATURAL_LANGUAGE_UNDERSTANDING_PASSWORD in .env file
var nlu = new NaturalLanguageUnderstandingV1({
	version_date: NaturalLanguageUnderstandingV1.VERSION_DATE_2017_02_27
});


// Create a "recognizeStream"
var recognizeStream = stt.createRecognizeStream({content_type: 'audio/mp3'});
recognizeStream.setEncoding('utf8');
recognizeStream.on('listening', data => {
	console.log("listening");
});

recognizeStream.on('data', data => {
	console.log("on data", data);
	data = data.replace("%HESITATION", "");

	io.emit("sentence", data);

	if(data.split(" ").length > 3) {
		// features to fetch from Watson NLU
		// https://github.com/watson-developer-cloud/node-sdk/blob/master/natural-language-understanding/v1.js
		var features = { concepts: {}, emotion: {}, entities: {}, keywords: {}, sentiment: {} };
		var options = { text: data, features: features };
		nlu.analyze(options, function(err, res) {
			if(err) return console.log(err);
			console.log("nlu results", util.inspect(res, {depth: 10, colors: true}));

			io.emit("concepts", res.concepts);
			io.emit("emotion", res.emotion.document.emotion);
			io.emit("entities", res.entities);
			io.emit("keywords", res.keywords);
			io.emit("sentiment", res.sentiment.document);
		});
	}
});

recognizeStream.on('results', data => {
	if(data.results && data.results.length) {
		console.log("on results", util.inspect(data, {depth: 10, colors: true}) );

		var transcript = data.results[0].alternatives[0].transcript;
		var final = data.results[0].final;

		io.emit("transcript", transcript, final);
	}
});

recognizeStream.on('error', err => {
	console.log("on error", err);
});

recognizeStream.on('close', () => {
	console.log("on close");
});




// Spawn a process that just dumps an MP3 stream of the audio coming into the microphone to stdout
var recProc = null;
recProc = spawn(rec, ['--endian', 'little', '-t', 'mp3', '-C', '128', '-']);
recProc.on('exit', (code, sig) => {
	debug(`recProc has exited with code = ${code}`);
});

// Pipe the MP3 data directly to the recognizeStream
recProc.stdout.pipe(recognizeStream);


