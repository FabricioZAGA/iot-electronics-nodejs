var io = require('socket.io')();

io.sockets.on('connection', (socket) => {
  console.log('NUEVO CLIENTE CONECTADO ' + socket.id)
})

module.exports = io;