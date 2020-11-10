var io = require('socket.io')();

io.sockets.on('connection', (socket) => {
  console.log('USER ID: ' + socket.id);
});

module.exports = io;