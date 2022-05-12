const ipAddress = '192.168.0.9';

document.querySelector('#topArrow').addEventListener("click", httpRequest('ahead')); // ->  Ahead
document.querySelector('#leftArrow').addEventListener("click", httpRequest('left')); // ->  Left
document.querySelector('#rightArrow').addEventListener("click", httpRequest('right')); // ->  Right
document.querySelector('#backArrow').addEventListener("click", httpRequest('back')); // ->  Back 
document.querySelector('#front-arrow-on').addEventListener("click", httpRequest('frontLightsON')); // -> Front Ligths ON
document.querySelector('#front-arrow-off').addEventListener("click", httpRequest('frontLightsOFF')); //  ->  Front Lights OFF
document.querySelector('#back-arrow-on').addEventListener("click", httpRequest('backLightsON')); //  ->  Back lights ON
document.querySelector('#back-arrow-off').addEventListener("click", httpRequest('backLightsOFF')); //  -> Back Lights OFF  
document.querySelector('.stop').addEventListener("click", httpRequest('stop')); //  ->  Stop


function httpRequest(action) {
    window.fetch(`http://${ipAddress}:5000/${action}`);
}