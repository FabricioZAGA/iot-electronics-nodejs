var socket = io("http://192.168.100.11:3000")

var startTimer = () => {

    var tiempo = {
        horas: txtHoras.value,
        minutos: txtMinutos.value,
        segundos: txtsegundos.value

    }

    socket.emit("startTimer", tiempo)
}

var ResetTimer = () => {
    imgFoco.src = "./img/lampOff.gif";
    var tiempo = {
        horas: txtHoras.value = null,
        minutos: txtMinutos.value = null,
        segundos: txtsegundos.value = null,

    }
    socket.emit("ResetTimer", tiempo)
}

var stopTimer = () => {
    var tiempo = {
        horas: txtHoras.value = null,
        minutos: txtMinutos.value = null,
        segundos: txtsegundos.value = null
    }
    socket.emit("stopTimer", tiempo)
}

socket.on('stopTimer1', function () {
    imgFoco.src = "./img/lampOff.gif";
    lblTimer.innerHTML = '00:00:00';
})

var PauseTimer = () => {

    var tiempo = {
        horas: txtHoras.value,
        minutos: txtMinutos.value,
        segundos: txtsegundos.value

    }

    socket.emit("PauseTimer", tiempo)
}

socket.on('focoOn', function (data) {

    imgFoco.src = "./img/lampOn.gif";
    lblTimer.innerHTML = data;
})

socket.on('focoOff', function () {
    imgFoco.src = "./img/lampOff.gif";
    btnStart.disabled = false;
    txtHoras.value = null;
    txtMinutos.value = null;
    txtsegundos.value = null
})
