var querystring = require('querystring');
var http = require('http');
var serialport = require('serialport');

var nomeporta = 'COM11';

var portaSeriale = new serialport.SerialPort(nomeporta, {
    baudRate: 9600,
    parser: serialport.parsers.readline("\n")
});

function PostCode(codestring) {
	console.log(codestring);	
  // costruisce il corpo del messaggio
  var dati = querystring.stringify({
      'temperatura' : codestring
  });

  // definisce un oggetto con le opzioni per l'invio della richiesta
  var opzioni = {
      host: 'localhost',
      port: '80',
      path: '/iot/aggiornaDati.php',
      method: 'POST',
      headers: {
          'Content-Type': 'application/x-www-form-urlencoded',
          'Content-Length': Buffer.byteLength(dati)
      }
  };

  // prepara la richiesta
  var post = http.request(opzioni, function(res) {
      res.setEncoding('utf8');
      res.on('data', function (chunk) {
          console.log('Response: ' + chunk);
      });
  });

  // invia i dati
  post.write(dati);
  post.end();
}

portaSeriale.on('data', function(input) {
	PostCode(input);
});