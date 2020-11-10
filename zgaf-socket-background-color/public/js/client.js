var socket = io("http://192.168.100.11:3000");


var colorChange = () => {
  lblRed.innerHTML = `RED: ${sldRed.value}`
  lblGreen.innerHTML = `GREEN: ${sldGreen.value}`
  lblBlue.innerHTML = `BLUE: ${sldBlue.value}`

  backbody.style = `background-color : rgb(${sldRed.value}, ${sldGreen.value}, ${sldBlue.value});`

  var rgbColors = {
    red: sldRed.value,
    green: sldGreen.value,
    blue: sldBlue.value
  }
  socket.emit('color-change', rgbColors);
}

socket.on('color-update', (data) => {
  console.log(data);
  lblRed.innerHTML = `RED: ${data.red}`
  lblGreen.innerHTML = `GREEN: ${data.green}`
  lblBlue.innerHTML = `BLUE: ${data.blue}`

  sldRed.value = data.red;
  sldGreen.value = data.green;
  sldBlue.value = data.blue;

  backbody.style = `background-color : rgb(${sldRed.value}, ${sldGreen.value}, ${sldBlue.value});`
})