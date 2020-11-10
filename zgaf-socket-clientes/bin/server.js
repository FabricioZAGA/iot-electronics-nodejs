var io = require('socket.io')();

var clientesTotales = 0;
var contador = 0;

io.sockets.on('connection', function (socket) {
    socket.emit("actualizar_conteo", contador)
    clientesTotales++;

    console.log("un nuevo cliente conectado con id : " + socket.id);
    var nuevo = "un nuevo cliente conectado con ID: " + socket.id
    socket.broadcast.emit("nuevo usuario", nuevo); // mensaje a todo mundo
    socket.emit("bienevido", "bienvenido usuario");
    io.sockets.emit("conexiones", clientesTotales);

    socket.on('disconnect', function () {
        clientesTotales--;
        socket.broadcast.emit("conexiones", clientesTotales);
        socket.broadcast.emit("desconexion", "cliemnte desconectado:   " + socket.id);
    })

    socket.on("contador", function () {
        contador++;
        io.sockets.emit("actualizar_conteo", contador);
    })


})






module.exports = io;