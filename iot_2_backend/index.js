const { SerialPort, ReadlineParser } = require('serialport');       //serial port eingebunden, also die library

const port = new SerialPort({
    'path': "COM6",
    'baudRate': 9600
})

const mqtt = require('mqtt');                                       //mqtt einbinden nach installation
let client = mqtt.connect("mqtt://mqtt.hfg.design:1883");                        //adresse

client.on('connect', function() {                       //connecten auf client und dann in funktion
    client.subscribe('iot2/projektX');                  //jeweilige projekte eigene topics, sonst jeder mit jedem; wenn subscribe, dann nachricht 
    console.log("Client connected");
});

client.on('message', getMessage);           //event für wenn nachricht reinkommt

function getMessage(topic, message) {
    port.write(message.toString() + "E");                            //nicht nur lesen sondern auch schreiben
}

const readline = new ReadlineParser({ delimiter: '\r\n' });
const parser = port.pipe(readline);

//Callback-Funktion
// parser.on('data', value => {
//     console.log(value);
// });

// parser.on('data', function (value) {
//     console.log(value);
// });

// Funktionsaufruf
parser.on('data', getData);

function getData(value){
    console.log(value.toString());
    client.publish('iot2/projektX', value);
}