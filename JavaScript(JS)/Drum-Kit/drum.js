function playSound(e) {
    const audio= this.document.querySelector(`audio[data-key="${e.keyCode}"]`);
    const key= this.document.querySelector(`.key[data-key="${e.keyCode}"]`);
    if(!audio) return;
    audio.currentTime=0;
    audio.play();
    key.classList.add('playing');  
}

    function removetransition(e){
        this.classList.remove('playing');
    }
    const keys=document.querySelectorAll('.key');  
    keys.forEach(key => key.addEventListener('transitionend',removetransition));
    window.addEventListener('keydown', playSound);