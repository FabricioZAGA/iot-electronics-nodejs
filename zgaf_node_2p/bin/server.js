const io = require('socket.io')();
var SerialPort = require('serialport');
var ReadLine = SerialPort.parsers.Readline;
var parser = new ReadLine();
var password = '';
var status = 'turnOFF';
var serial_interface = "COM3";
var Timer = require("easytimer.js").Timer;
var timer = new Timer();

var port = new SerialPort(serial_interface, {
  baudRate: 9600
});
port.on('open', (err) => {
  if (err) {
    console.log('Error when trying to connect', err);
  }
  else {
    console.log('ARDUINO OK');
    port.pipe(parser);
  }
});

io.sockets.on('connection', (socket) => {
  socket.on("startTimer", function (data) {
    timer.start({
      countdown: true,
      startValues: {
        hours: Number(data.horas),
        minutes: Number(data.minutos),
        seconds: Number(data.segundos)
      }
    })
  })

  console.log(`ID USER: ${socket.id}`);
  socket.emit('updateStatuts', status);

  socket.on('statusChange', (data) => {
    status = data;
    port.write(status, (err) => {
      if (err) {
        console.log('Error when trying to send info', err);
      }
      else {
        console.log('Info sent: ', status);
      }
    });
  });
});

parser.on('data', (serialData) => {
  if (serialData == 'ok') {
    if (password == '1234') {
      if (status === 'on') {
        status = 'turnOFF';
      }
      else {
        timer.start({
          countdown: true,
          startValues: {
            hours: Number(0),
            minutes: Number(0),
            seconds: Number(10)
          }
        })
        status = 'ON';
      }
      port.write(status, (err) => {
        if (err) {
          console.log('Error when trying to send info', err);
        }
        else {
          io.sockets.emit('updateStatuts', status);
        }
      });
    } else {
      console.log('WRONG PASSWORD');
      io.sockets.emit("badEntry");

    }
  }
  else {
    password = serialData;
    io.sockets.emit('serialData', password);
  }
  console.log(status);
});

timer.addEventListener('secondsUpdated', function () {
  console.log(timer.getTimeValues().toString())
  var tiempo = timer.getTimeValues().toString()

  io.sockets.emit('turnON', tiempo)
})

timer.addEventListener('targetAchieved', function () {
  port.write("turnOFF", function (err) {

    if (err)

      console.log("ERROR", err)

  })
  io.sockets.emit('focoturnOFF')
})

module.exports = io;