let music=new Audio("Alarm.wav");
setInterval(() => {
    // generating hours,minutes,seconds
    date = new Date();
    hour = date.getHours();
    minute = date.getMinutes();
    second = date.getSeconds();

    // for displayTime
    h.innerHTML=hour;
    m.innerHTML=minute;
    s.innerHTML=second;

    // rotaion calculation
    hrotate = 30 * hour + minute / 2;
    mrotate = 6 * minute;
    srotate = 6 * second;
    
    // rotate hands
    hours.style.transform = `rotate(${hrotate}deg)`
    minutes.style.transform = `rotate(${mrotate}deg)`
    seconds.style.transform = `rotate(${srotate}deg)`
}, 1000)
function addZero(time) {

    return (time < 10) ? "0" + time : time;

}
set.addEventListener('click',()=>{
    var hr=document.getElementById('ho');
    var mi=document.getElementById('min');
    var selectedhour=hr.innerHTML;
    var selectedmin=mi.innerHTML;
    var alarmTime = addZero(selectedhour) + ":" + addZero(selectedmin);
    console.log('alarmTime:' + alarmTime);

    document.getElementById('ho').disabled = true;
	document.getElementById('min').disabled = true;
    setInterval(()=>{
        var d=new Date();
        var hou=d.getHours();
        var min=d.getMinutes();
        var currentTime = addZero(hou) + ":" + addZero(min);
        if (alarmTime == currentTime) {
            music.play();
        }
    },1000)
})
Stop.addEventListener('click',()=>{
    document.getElementById('ho').disabled = false;
	document.getElementById('min').disabled = false;
    music.pause();
})