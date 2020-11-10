const socket = io('http://localhost:3000');


var status = 'on';
const lightBulbCard = () => { return (
  '<div class="d-flex justify-content-center">'+
  '<img id="imgLight" src = "img/lampOff.gif">'+'</div>'+
  //'<span class="input-group-text" id="basic-addon1">Web</span>' +
  '<input type="hidden" class="form-control" placeholder="Password" aria-label="Password" id="inPassword">' +
  '<span class="input-group-text" id="basic-addon1">CONTRASEÑA PRIMOROSA</span>' +
  '<input type="text" class="form-control" placeholder="Password" aria- label="Password" id="inPasswordC">'  +
  '<button onclick="lightbulbOnClick()" id="btnSwitch" class=" w-100 btn btn-outline-success">PRENDER</Button>' +
  '<h3 align=center id="lblTimer">STATUS</h3>'+  '</div>'
  ); };

socket.on('focoOn',function(data1){
  document.getElementById('imgLight').src = 'img/lampOn.gif';
  lblTimer.innerHTML="PUERTA ABIERTA POR " + data1;
})

socket.on('focoOff',function(){
  imgLight.src="./img/lampOff.gif";
  lblTimer.innerHTML="PUERTA CERRADA";
  inPassword.value="";
  inPasswordC.value="";
})


const ContraIncorrecta=()=>{
lblTimer.innerHTML="CONTRASEÑA INCORRECTA";
inPassword.value="";
inPasswordC.value="";


}
 
const lightbulbOnClick = () => {

if (inPassword.value === '1234' || inPasswordC.value === '1234') {

  var tiempo={
    horas:0,
    minutos:0,
    segundos:10
    
}

socket.emit("startTimer",tiempo)
  
inPassword.value = ''; inPasswordC.value = '';
    if (status === 'on') 
    {
      status = 'off';
document.getElementById('imgLight').src = 'img/lampOff.gif';
//document.getElementById('btnSwitch').innerHTML = 'on'; 
} 
else 
{
status = 'on';
document.getElementById('imgLight').src = 'img/lampOn.gif';
//document.getElementById('btnSwitch').innerHTML = 'off'; 
}
socket.emit('statusChange', status); } 
else 
{
//alert('Incorrect password'); 
ContraIncorrecta();


}
};

socket.on("ContraIncorrecta",()=>{

  ContraIncorrecta();
})


socket.on('serialData', (data) => { 
var aux = data;
inPasswordC.value = aux;

});
const strMain =

'<div class="container-fluid">' +'<div class="row row-cols-1 row-cols-md-4" >' +'<div class="col">' + lightBulbCard() +'</div>' +'</div>' +'</div>';

document.body.innerHTML = document.body.innerHTML + strMain;