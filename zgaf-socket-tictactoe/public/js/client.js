var socket = io("http://192.168.100.11:5000");

var whoWon = null;
var someoneWon = false;
var newGame = true;

var playerInTurn = 1;

var board = [
  0, 0, 0,
  0, 0, 0,
  0, 0, 0];


var positionChange = (position) => {

  if (board[position] == 0) {
    board[position] = playerInTurn;
    validate(playerInTurn);

    if (playerInTurn == 1) {
      document.getElementById(`img${position}`).src = "./img/josejose.png"
      playerInTurn = 2
    } else if (playerInTurn == 2) {
      document.getElementById(`img${position}`).src = "./img/luismi.png"
      playerInTurn = 1
    }
    socket.emit('board-change', [board, playerInTurn]);
  }

  if (someoneWon) {
    resetGame();
  }
}

var validate = (player) => {
  for (let i = 0; i < 9; i += 3) {
    if (board[i] == player && board[i + 1] == player && board[i + 2] == player) {
      someoneWon = true;
      whoWon = player;
      break

    }
  }

  for (let i = 0; i < 9; i++) {
    if (board[i] == player && board[i + 3] == player && board[i + 6] == player) {
      someoneWon = true;
      whoWon = player;
      break
    }
  }
  if (board[0] == player && board[4] == player && board[8] == player) {
    someoneWon = true;
    whoWon = player;
  }
  if (board[6] == player && board[4] == player && board[2] == player) {
    someoneWon = true;
    whoWon = player;
  }
  if (someoneWon == true) {
    socket.emit('winner', whoWon);
  }
}

var resetGame = () => {
  whoWon = null;
  someoneWon = false;
  newGame = true;

  playerInTurn = 1;

  board = [
    0, 0, 0,
    0, 0, 0,
    0, 0, 0];

  socket.emit('board-change', [board, playerInTurn]);
  debugger

  for (let i = 0; i < 9; i++) {
    document.getElementById(`img${i}`).src = "./img/question.png"
  }
}

socket.on('board-update', (data) => {
  playerInTurn = data[1];

  console.log(data);

  for (let i = 0; i < 9; i++) {
    if (data[0][i] == 1) {
      document.getElementById(`img${i}`).src = "./img/josejose.png"
    }
    if (data[0][i] == 2) {
      document.getElementById(`img${i}`).src = "./img/luismi.png"
    }
    if (data[0][i] == 0) {
      document.getElementById(`img${i}`).src = "./img/question.png"
    }
  }
  board = data[0];
});

socket.on("new-user", (data) => {
  console.log(data);

  $.gritter.add({
    title: "Notificacion",
    text: data,
    sticky: false,
    time: "3000",
    image: '',
  });
});