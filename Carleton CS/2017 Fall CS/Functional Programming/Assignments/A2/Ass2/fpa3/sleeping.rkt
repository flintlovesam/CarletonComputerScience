; NOTE to TA - to end the game, click EOF
; GAME LOGIC
#|
 create a recursive loop:
; print the Prompt
; call "statusPrint" to show player options and prompt to get the input. Pass the input into battle
; call the battle helper function - this passes the Human Move(Hmove) and generates the Computer Move (Cmove) and resets the score according to who wins
  ; battle has a call to a function that prints the new moves and prints the new score
;  game calls itself, entering the loop, sending it the updated score
|#


(#%require (only racket/base random))
(define (rps)
  (game 0) ; call game with a value set to zero as the initial score
  )



(define (game theScore)


  ; HELPER FUNCTIONS
  (define Prompt "\nPlease enter a selection, 0=Rock, 1=Paper, 2=scissors\n")

  (define (statusPrint theScore Hmove Cmove)
    (display "\nThe Human Move is: ")
    (display Hmove)
    (display "\nThe Computer Move is: ")
    (display Cmove)
    (display "\nThe new Score is: ")
    (display theScore)
    )
  
; 2 functions for adding or removing from score
  (define (add1 x)
    (+ x 1))
  (define (sub1 x)
    (- x 1))

  

  (define (battle Hmove theScore)
    (let ((Cmove (random 3)))
      (if (> Hmove 2) (game theScore))  ; if the entered number is greater than 0,1 or 2, reprompt user
      (if (< Hmove 0) (game theScore))  ; if the entered number is less than 0,1 or 2, reprompt user
      
      (cond
        ((and (equal? Hmove 1) (equal? Cmove 0)) (set! theScore (add1 theScore)) )       ; if human wins, add one       // game (+ 1 theScore)    
        ((and (equal? Hmove 1) (equal? Cmove 1)) (+ 0 theScore))    ; if tie, do nothing
        ((and (equal? Hmove 1) (equal? Cmove 2)) (set! theScore (sub1 theScore)))    ; if computer wins, remove one
        ((and (equal? Hmove 0) (equal? Cmove 0)) (+ 0 theScore))
        ((and (equal? Hmove 0) (equal? Cmove 1)) (set! theScore (sub1 theScore)))
        ((and (equal? Hmove 0) (equal? Cmove 2)) (set! theScore (add1 theScore)))
        ((and (equal? Hmove 2) (equal? Cmove 0)) (set! theScore (sub1 theScore)))
        ((and (equal? Hmove 2) (equal? Cmove 1)) (set! theScore (add1 theScore)))
        ((and (equal? Hmove 2) (equal? Cmove 2)) (+ 0 theScore))) 
      (statusPrint theScore Hmove Cmove)      ; throw this to the top: print the human, computer moves and the new score that has been set by the result of the battle
      (game theScore) ))      ; recursively call game and loop until the user clicks EOF

     
  ; GAME LOGIC
  (display Prompt) ; Prompt user for input
  (let ((Hmove (read)))     ; read inout
    (if(not(eof-object? Hmove))    ; if human has not quit by pressing EOF button, pass the human move ( rock,paper or scissor) to the battle function which recursively loops until quit
       (begin
         (newline)
         (battle Hmove Thescore)
         )))
	
	
  )
	
