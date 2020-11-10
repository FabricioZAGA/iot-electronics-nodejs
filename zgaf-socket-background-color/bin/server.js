var io = require('socket.io')();

var rgbColors = {
  red: 255,
  green: 255,
  blue: 255
}

io.sockets.on('connection', (socket) => {
  console.log("New client connected: " + socket.id)

  socket.emit('color-update', rgbColors);

  socket.on('color-change', (data) => {
    console.log(data);
    rgbColors = data;
    socket.broadcast.emit('color-update', rgbColors);
  })
});

module.exports = io;