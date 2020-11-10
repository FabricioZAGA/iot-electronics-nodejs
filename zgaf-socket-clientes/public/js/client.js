var socket = io("localhost:3000")

var lblCliente = document.getElementById("lblCliente");
var lblContador = document.getElementById("lblContador");

var cuenta = () => {

    socket.emit("contador")

}

socket.on("actualizar_conteo", function (data) {
    lblContador.innerHTML = data;
})

socket.on("nuevo usuario", function (data) {
    console.log(data);
})

socket.on("bienevido", function (data) {
    console.log(data);
})

socket.on("conexiones", function (data) {

    console.log("clientes conectados: " + data);
    lblCliente.innerHTML = "clientes conectados    " + data;
})

socket.on("desconexion", function (data) {

    console.log(data);
})