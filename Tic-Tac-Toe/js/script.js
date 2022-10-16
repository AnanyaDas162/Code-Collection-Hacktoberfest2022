console.log("Welcome");
let turnmusic = new Audio("turn.mp3");
let music = new Audio("background.mp3");
let end = new Audio("Over.mp3");
let turn="X";
let over=false;

// Changing the turn
const changeTurn=()=>{
    // if it is X then return O else return X
    return turn==="X"? "O":"X";
}
// Check the winner
const checkWin=()=>{
    let boxtext=document.getElementsByClassName('boxtext');
    let wins=[
        // all 8 winning combinations
        [0,1,2,5,5,0],
        [3,4,5,5,15,0],
        [6,7,8,5,25,0],
        [0,3,6,-5,15,90],
        [1,4,7,5,15,90],
        [2,5,8,15,15,90],
        [0,4,8,5,15,45],
        [2,4,6,5,15,135]
    ]
    wins.forEach(e=>{
        // if all three symbols of the wiining condition array are same and not blank 
        if((boxtext[e[0]].innerText===boxtext[e[1]].innerText) && (boxtext[e[1]].innerText===boxtext[e[2]].innerText) && (boxtext[e[1]].innerText!=="")){
            document.querySelector('.info').innerText=boxtext[e[0]].innerText+" Won";
            over=true;
            end.play();
            music.pause();
            document.querySelector('.image').getElementsByTagName('img')[0].style.width="156px";
            document.querySelector('.line').style.width="20vw";
            document.querySelector('.line').style.transform=`translate(${e[3]}vw,${e[4]}vw)rotate(${e[5]}deg)`
        }
    })
}
// Game Logic

let boxes=document.querySelectorAll('.box');
Array.from(boxes).forEach(element=>{
    let boxtext=element.querySelector('.boxtext');
    element.addEventListener('click',()=>{
        if(boxtext.innerText=== ''){
            boxtext.innerText=turn;
            turn=changeTurn();
            turnmusic.play();
            checkWin();
            if(!over){
                document.getElementsByClassName("info")[0].innerText="Turn for "+turn;
            }
        }
    })
})
// For reset button
reset.addEventListener('click',()=>{
    let boxtext=document.querySelectorAll('.boxtext');
    Array.from(boxtext).forEach(element=>{
        element.innerText=""
    });
    turn="X";
    over=false;
    music.play();
    document.getElementsByClassName("info")[0].innerText="Turn for "+turn;
    document.querySelector('.line').style.width="0vw";
    document.querySelector('.image').getElementsByTagName('img')[0].style.width="0px";
    
})