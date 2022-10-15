//creating text for input
let string="";
//selecting all elements with class button
let buttons=document.querySelectorAll('.button');

//creating array of button
Array.from(buttons).forEach((button)=>{
    button.addEventListener('click',(e)=>{
        //if button is = then evaluate the value
        if(e.target.innerHTML== '='){
            string=eval(string);
            document.querySelector('input').value=string;
        }
        //if button is AC then then clear all value
        else if(e.target.innerHTML== 'AC'){
            string="";
            document.querySelector('input').value=string;
        }
        //if button is X then clear the last input
        else if(e.target.innerHTML== 'DEL'){
            string=string.substring(0, string.length - 1);;
            document.querySelector('input').value=string;
        }
        //if button is other then print that on text bar
        else{
            console.log(e.target);
            string=string+e.target.innerHTML;
            document.querySelector('input').value=string;
        }
        
    })
})