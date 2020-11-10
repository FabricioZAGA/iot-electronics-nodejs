var io = require('socket.io')();
var Timer = require("easytimer.js").Timer;
var temporizador = new Timer();

io.sockets.on("connection", function (socket) {
    console.log("nuevo cliente : " + socket.id);
    socket.on("startTimer", function (data) {
        console.log("NEW TIMER START", data);
        temporizador.start({
            countdown: true,
            startValues: {
                hours: Number(data.horas),
                minutes: Number(data.minutos),
                seconds: Number(data.segundos)
            }
        })
    })

    socket.on("ResetTimer", function (data) {
        console.log("RESET TIMER ", data);
        temporizador.reset({
            countdown: true,
            startValues: {
                hours: Number(data.horas),
                minutes: Number(data.minutos),
                seconds: Number(data.segundos)

            }
        })
    })

    socket.on("stopTimer", function (data) {
        console.log("STOP TIMER", data);
        temporizador.stop({
            startValues: {
                hours: Number(data.horas),
                minutes: Number(data.minutos),
                seconds: Number(data.segundos)

            }
        })
        io.sockets.emit('stopTimer1');
    })

    socket.on("PauseTimer", function (data) {
        console.log("PAUSE TIMER ", data);
        temporizador.pause({
            startValues: {
                hours: Number(data.horas),
                minutes: Number(data.minutos),
                seconds: Number(data.segundos)
            }
        })
    })
})

temporizador.addEventListener('secondsUpdated', function () {
    console.log(temporizador.getTimeValues().toString())
    var tiempo = temporizador.getTimeValues().toString()

    io.sockets.emit('focoOn', tiempo)

})

temporizador.addEventListener('targetAchieved', function () {
    console.log("TIMER OFF")
    io.sockets.emit('focoOff')
})

module.exports = io;