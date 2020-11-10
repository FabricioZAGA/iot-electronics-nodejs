var io = require('socket.io')();

var board = [
  0, 0, 0,
  0, 0, 0,
  0, 0, 0];

var playerInTurn = 1;
var connectedClients = -2;

io.sockets.on('connection', (socket) => {
  console.log("New client connected: " + socket.id)
  connectedClients++;

  socket.emit('board-update', [board, playerInTurn]);
  if (connectedClients > 0) {
    socket.broadcast.emit('new-user', `There are ${connectedClients} people watching`)
  }

  socket.on('board-change', (data) => {
    console.log(data);
    board = data[0];
    playerInTurn = data[1];
    socket.broadcast.emit('board-update', [board, playerInTurn]);
  })


  socket.on("winner", (data) => {
    if (data == 1) {
      socket.broadcast.emit('new-user', `Chepe Chepe is the winner`)
      socket.emit('new-user', `Chepe Chepe is the winner`)
    }
    if (data == 2) {
      socket.broadcast.emit('new-user', `Luis Mi is the winner :( )`)
      socket.emit('new-user', `Luis Mi is the winner :( )`)
    }
  });

  socket.on("disconnect", function () {
    connectedClients--;

    if (connectedClients > 0) {
      socket.broadcast.emit('new-user', `There are ${connectedClients} people watching`)
    }
  });
});

module.exports = io;