        
        let score = JSON.parse(localStorage.getItem('score'));
        //parse ley chai string ma convert gareko kyra paila ko ma convert garcha.
                   if(score === null)
                   {
                    score={
                        wins:0,
                        loss: 0,
                        tie: 0
                    };
                   };

                   let isAutoPlaying = false;
                   let intervalId ;
        function autoPlay(){
            
            if(!isAutoPlaying)
            {
                document.querySelector('.auto-play-button').innerText = 'Stop Auto play';
              intervalId =  setInterval(function(){
                const playerMove = computerMove();
                const computerMove1 = computerMove();
                play(playerMove,computerMove1);
                },1000)
                isAutoPlaying = true;
            } else {
                document.querySelector('.auto-play-button').innerText ='Auto Play';
                clearInterval(intervalId); 
                isAutoPlaying = false;
            }
    }
                  
                  
                function computerMove() {
                    const setValues = Math.random();
                    let computerMove = '';
                    
                    if (setValues >= 0 && setValues <= 1/3) {
                        computerMove = 'Rock';
                    } else if (setValues > 1/3 && setValues <= 2/3) {
                        computerMove = 'paper';
                    } else if (setValues > 2/3 && setValues <= 1) {
                        computerMove = 'Scissor';
                    }
                       
                    return computerMove;
                }
        
                // . ${result} {{inner html pachi halney}}
                function updateScoreElement()
                    {
                    document.querySelector('.js-score')
                    .innerHTML = `
                    Wins:${score.wins}, Loss:${score.loss},Tie:${score.tie}`;
                }
        
        
                function play(playerMove,computerMove)
                 {
                    
                    let result ='';
               
                    if (playerMove === 'Rock') {
                        if (computerMove === 'Rock') {
                            result = 'Tie';
                        } else if (computerMove === 'paper') {
                            result = 'loose';
                        } else if (computerMove === 'Scissor') {
                            result = 'win';
                        }
                    } else if (playerMove === 'paper') {
                        if (computerMove === 'Rock') {
                            result = 'win';
                        } else if (computerMove === 'paper') {
                            result = 'Tie';
                        } else if (computerMove === 'Scissor') {
                            result = 'loose';
                        }
                    } else if (playerMove === 'Scissor') {
                        if (computerMove === 'Rock') {
                            result = 'loose';
                        } else if (computerMove === 'paper') {
                            result = 'win';
                        } else if (computerMove === 'Scissor') {
                            result = 'Tie';
                        } 
                    }  
        
                    if (result === 'win'){
                        score.wins += 1
                    }
                      else if (result === 'loose'){
                        score.loss += 1; 
                    }
                     else if (result === 'Tie'){
                        score.tie +=1; 
                    }
        
                    localStorage.setItem('score',JSON.stringify(score)); //line 96 ko object store ra yo lineko 'score' chuttai chuttai object ho.
        //set item vitra score vanne object create gareko ho ani tesvitra chai mathi ko
        //score ko value haleko ho string ma convert garera.
        
                    updateScoreElement();
        
        
                document.querySelector('.js-result')
                .innerHTML = result;
        
                document.querySelector('.js-moves').innerHTML=
                ` You
            <img src="RPM image/${playerMove}-emoji.png" class="move-icon">
            Computer
            <img src="RPM image/${computerMove}-emoji.png" class="move-icon">`;
                
                 }    
            
        
                 