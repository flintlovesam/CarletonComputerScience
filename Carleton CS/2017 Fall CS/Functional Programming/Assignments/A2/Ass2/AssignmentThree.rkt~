(#%require (only racket/base random))

; Question 1A


(define (f n)
  (if (< n 4)
      n          ; base case
      ( + (f (- n 1)) (* 2 (f(- n 2))) (* 3 (f(- n 3))) (* 4 (f(- n 4))))  ;recursive loop
      ))
;SUBSTITUTION MODEL
(f 6)
( + (f 5) (* 2 (f 4)) (* 3 (f 3)) (* 4 (f 2)))  
( + (f 5) (* 2 (f(- 6 2))) (* 3 (f(- 6 3))) (* 4 (f(- 6 4))))
( + (f 5) (* 2 (f 4)) (* 3 (f 3)) (* 4 (f 2)))
( + ( + (f (- 5 1)) (* 2 (f(- 5 2))) (* 3 (f(- 5 3))) (* 4 (f(- 5 4)))) (* 2 ( + (f (- 4 1)) (* 2 (f(- 4 2))) (* 3 (f(- 4 3))) (* 4 (f(- 4 4))))) (* 3 (f 3)) (* 4 (f 2)))
( + ( + (f 4) 6 6 4) (* 2 ( + 3 4 3 0)) 9 8)
( + ( + ( + (f (- 4 1)) (* 2 (f(- 4 2))) (* 3 (f(- 4 3))) (* 4 (f(- 4 4)))) 6 6 4) (* 2 ( + 3 4 3 0)) 9 8)
( + ( + ( + (f 3) (* 2 (f 2)) (* 3 (f 1)) (* 4 (f 0))) 6 6 4) (* 2 ( + 3 4 3 0)) 9 8)
( + ( + ( + 3 (* 2 2) (* 3 1) (* 4 0)) 6 6 4) (* 2 ( + 3 4 3 0)) 9 8)
    

; Question 1B

(define (fun n)
    (define (fun-iteration n1 n2 n3 n4 count)   
        (if (= count (- n 2))        ; set the stop condition to when count is = n-2, then we return n1 which represents the sum of the values
            n1                        
            (fun-iteration (+ n1 (* 2 n2) (* 3 n3) (* 4 n4)) n1 n2 n3 (+ count 1))  ; set n1 to be the sum of all the previous values w algorithm included
            ))
    (if (< n 4)     ; stop condition is when n<4, returning n as a result  
        n    
        (fun-iteration 3 2 1 0 1)))  ; start the iterative loop where count is set to 1


; SUBSTITUTION MODEL
#|fib 6-->
(fun-iteration 3 2 1 0 1)
(fun-iteration (+ 3 (* 2 2) (* 3 1) (* 4 0)) 3 2 1 (+ 1 1))
(fun-iteration (10 3 2 1 2)
(fun-iteration (+ 10 (* 2 3) (* 3 2) (* 4 1)) 10 3 2 (+ 2 1))
(fun-iteration (+ 10 6 6 4) 10 3 2 3)
(fun-iteration 26 10 3 2 3)
(fun-iteration (+ 26 (* 2 10) (* 3 3) (* 4 2)) 26 10 3 (+ 3 1))
(fun-iteration (+ 26 20 9 8) 26 10 3 (+ 3 1))
(fun-iteration 63 26 10 3 (+ 3 1))
;BECAUSE (= count (- n 2)) is now true ..... count(3) = (5-2)... 4=4, the function breaks returning n1, which is 63 ( which is shown as the value n1 in the line above
|#


; QUESTION TWO

(define (pTri row col)
  (cond((= row col) 1)    ; When the row is the same as the column the value directly above it is always a 1
       ((= col 0) 1)    ;  we are on a the wall of the pyramid where the value is always a 1
       ((= row 0) 0)    
       (else(+(pTri(- row 1)(- col 1))   ; recursive loop that summs of the value of the parents of the (row col) pair, 
              (pTri(- row 1) col) ) )))  ; where one parent is the found at the coordinate row-1 and col-1, and the other and the row-1 and the same col #



; QUESTION THREE A (recursive version)

(define (numCounter n)
  (if (< n 0) (numCounter (* -1 n))        ; takes negative input and converts it to a positive value to handle normally
  (if (< n 10)     ; set less than 10 as the base case in order to handle user input of 0, and still return 1
      1
      ( + 1 (numCount (floor(/ n 10)))))               ; uses division by 10 recursively to determine the number of digits in a number
  )
  )
; QUESTION THREE B (iterative case)

(define (numCount n)  
(define (numCountIter num counter)
         (if (< num 10)
             counter
             (numCountIter (floor(/ num 10)) (+ counter 1))))         ;iteratively divides by 10, and each time this is done, the counter is added to
                                                                    ; and menawhile the num is continually reduced until it fails the base case and counter is returned
 (if (< n 0)                    
     (numCountIter (* -1 n) 1)           ; if condition where negative numbers are handled
     (numCountIter n 1)))       ; starts the iterative call at a begining counter value of 1




; QUESTION FOUR

(define (rps)
  (game 0) ; call game with a value set to zero as the initial score
  )

(define (game theScore)

  ; HELPER FUNCTIONS
  (define Prompt "\nPlease enter a selection, 0=Rock, 1=Paper, 2=scissors\n")

  (define (statusPrint Hmove Cmove)   ; the function that prints out the status of the moves
    (display "\nThe Human Move is: ")
    (display Hmove)
    (display "\nThe Computer Move is: ")
    (display Cmove)
    
    )
  (define (scorePrint theScore)  ; prints out the current score
    (display "\nThe Score is: ")
    (display theScore)
    )
  

  (define (battle Hmove theScore)    ; game logic that based on who wins, a value is added or subtracted to the overall score. No matter the battle outcome, program is recursively called with the new score as the parameter
    (let ((Cmove (random 3)))
      (if (> Hmove 2) (game theScore))  ; if the entered number is greater than 0,1 or 2, reprompt user
      (if (< Hmove 0) (game theScore))  ; if the entered number is less than 0,1 or 2, reprompt user
      (statusPrint Hmove Cmove) 
      (cond
        ((and (equal? Hmove 1) (equal? Cmove 0)) ( game (+ 1 theScore)) )       ; if human wins, add one       // game (+ 1 theScore)    
        ((and (equal? Hmove 1) (equal? Cmove 1)) (game theScore))    ; if tie, do nothing
        ((and (equal? Hmove 1) (equal? Cmove 2)) (game (+ -1 theScore)))    ; if computer wins, remove one
        ((and (equal? Hmove 0) (equal? Cmove 0)) (game theScore))
        ((and (equal? Hmove 0) (equal? Cmove 1)) (game (+ -1 theScore)))
        ((and (equal? Hmove 0) (equal? Cmove 2)) (game (+ 1 theScore)))
        ((and (equal? Hmove 2) (equal? Cmove 0)) (game (+ -1 theScore)))
        ((and (equal? Hmove 2) (equal? Cmove 1)) (game (+ 1 theScore)))
        ((and (equal? Hmove 2) (equal? Cmove 2)) (game theScore))
         
        ) 
           
       ))      ; recursively call game and loop until the user clicks EOF

     
  ; GAME LOGIC
  (scorePrint theScore) 
  (display Prompt) ; Prompt user for input
  (let ((Hmove (read)))     ; read inout
    (if(not(eof-object? Hmove))    ; if human has not quit by pressing EOF button, pass the human move ( rock,paper or scissor) to the battle function which recursively loops until quit
       (begin
         (newline)
         (battle Hmove Thescore)  ; The first call to battle which sets of the recursive loop that follows
         )))
	
	
  )


; Question Five

(define (range a b )     ; input of the values from a->b that we want to sum up

  (define (next x) (+ x 1))     ; helper function that increases the value by 1
  (define (term x) x)           ; helper function that keeps value the same
  
  (define (Iterange term a next b total )     ;   term a next b total
    (if (> a b)
     total             ; return the total that has been being accumulated once A is bigger than B
     (Iterange term (next a) next b (+ (term a) total))))     ; the iterative loop which includes total as the sum of itself + the first term
  (Iterange term a next b 0)                                   ; the starting point where user input is take from range and total is set to zero

  )


; Question Six A
(define (square x) (* x x))   ; a function that gives the cube of a number
(define (cube x) (* x x x))    ; a function that gives the square of a number

(define (good-enough? guess x)
    (< (abs (- (cube guess)        ; take the cube of the guess
               x))
       0.001))

(define (average x y)      ; gives the average of two values  
    (/ (+ x y) 2))
       
	
(define (improve guess x)     ; the altered function that allows us to determine the cube root, adapted from ((x/y2+2y)/3)
      (/ (+ (/ x (square guess))
            (* 2 guess))
         3))
	 
(define (cube-iteration guess x)    ; the iterative loop that passes a predefined guess 
    (if (good-enough? guess x)
        guess
        (cube-iteration (improve guess x)
                        x)))
		
(define (cubrt x)       ; the main function that is called with a value we want to get the cube root of, that then triggers the cube-iteration function
    (cube-iteration 1.0 x))   


; Question 6b (unfortunately didnt have the time to do, but was able to at minimum test my code against the "if" provided in the assignment, leading to my answer for 6c below

; Question 6c
#|The new if procedure does not work because this new if is a special case...never evaluates the actual if expression.
 if a special case procedure that always gives a true or false depending on
 the value of the predicate. the new if abides by normal order which will not satisfy the if condition being met |#



; Question Seven


#|TESTING









|#

















