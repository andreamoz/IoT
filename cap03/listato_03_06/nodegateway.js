var serialport = require('serialport');
var nomeporta = 'COM11';

var portaSeriale = new serialport.SerialPort(nomeporta, {
    baudRate: 9600,
    parser: serialport.parsers.readline("\n")
});

portaSeriale.on('data', function(input) {
    console.log(input);
});