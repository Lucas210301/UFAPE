const mario = document.querySelector('.mario');
const pipe = document.querySelector('.pipe');

const jump = () => {
  mario.classList.add('jump');

   setTimeout(() => { 
    mario.classList.remove('jump');
  }, 500);      
}

const loop = setInterval(() => {    

  const pipepositon = pipe.offsetLeft; 
  const mariopositon = window.getComputedStyle(mario).bottom.replace;    
  ('px', '');

  if (pipepositon <= 120 && pipepositon > 0 && mariopositon <80) {

    pipe.style.animation = 'none';
    pipe.style.left = `${pipepositon}px`;

    mario.style.animation = 'none';
    mario.style.bottom = `${mariopositon}px`;

    mario.src = './Images/game-over.png';
    mario.style.width = '75px'
    mario.style.marginleft = '50px'
    
    clearInterval(loop);
  
  }
 
}, 10); 

document.addEventListener('keydown', jump);