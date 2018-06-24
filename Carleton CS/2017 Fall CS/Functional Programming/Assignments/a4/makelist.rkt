


  (define (make-list)
    ;Make an empty list
    
  (define lst '())

    
  ;Getter ( to add/set/remove, we must use the get method)... to do so, get location in li

    
  ;(get i) - returns the element stored at index i in the list
    (define (get i)
      ; first check if spot is valid
      (if (valid-index i)
          (list-ref lst i )   ; get uses the list-ref function to return the value in the lst at i
          #f
          ))

    
  ;Setter
  ;(set i x) - modifies index i in the list to hold item x
  (define (set i x)
    (cond ((valid-index? i)
           (set! lst (delete i lst))      ; first delete the item in that place
           (set! lst (insert i x lst)))  ; then insert the value desired into that spot
          (else #f)))


  ; Mutator
    
  ;(add i x) - adds item x at index i in the list
(define (add i x)
  (if (valid-index i)(set! lst (insert i x lst))  ; add checks if valid index using the helper function
     (display "Please enter a valid index")
      ))
    
; insert function: abstracted out of add to be used in set as well
 (define (insert index value lst)    ; insert helper check if at end of list, 
    (cond ((null? lst) (list value)) ;  if zero, we are at the correct place to perform the addition, in which case add it in
          ((zero? index) (cons value lst))
          (else
           (cons (car lst)   ; take the current element and build up a stack composed of the recent added element
                 (insert (- index 1) value (cdr lst)))
           ))
   
   )

    
  ;(remove i) - removes the item at index i from the list
(define (remove i)
  (if (valid-index i)(set! lst (delete i lst))     ; checks valid index for remove operaton, if valid use delete helper
     (display "Please enter a valid index")
      ))

 (define (delete index lst)    ; in order to delete , a check is done to see if it is null,
  (cond ((null? lst) '())
        ((zero? index) (cdr lst))  ;if zero, we are at the correct place to perform the removal using cdr
        (else 
         (cons (car lst)  ; cons everything from before the element to be deleted with everything after the item to be deleted, do so by calling recursive
         (delete (- index 1) (cdr lst))
         ))))


  ; helper
    
  ; (print) - displays the list
  (define (print) 
    lst)

  ; (size) - returns an integer equal to the number of items in the list
  (define (size)
    (length lst))
    
  ; (valid-index) - returns a true or false value depending on whether the position in the list valid..ie exists
    (define (valid-index i)
    (if (and (integer? i) (<= i (size)) (>= i 0))
        #t
        #f))

    (define (dispatch method)
    (cond ((eq? method 'init) init)
          ((eq? method 'size) size)
          ((eq? method 'get) get)
          ((eq? method 'set) set)
          ((eq? method 'add) add)
          ((eq? method 'remove) remove)
          ((eq? method 'print) print)
          (else (lambda() (display "Unknown Request: ")(display method)(newline)))))

 

   ; (display #\x)
   dispatch )

#|
Testing

(define L1 (make-list))
(define L2 (make-list))
(display "L1: ")((L1 'print))		; prints → L1: ()
(display "L2: ")((L2 'print))		; prints → L2: ()
((L1 'add) 0 'a)
((L1 'add) 1 'b)
((L1 'add) 2 'c)
((L1 'add) 3 'd)
(display "L1: ")((L1 'print))		; prints → L1: (a b c d)
((L2 'add) 0 ((L1 'get) 2))
((L1 'set) 2 'x)
((L2 'add) 1 'z)
((L1 'remove) 1)
((L2 'add) 1 'y)
((L1 'add) 0 1)
(display "L1: ")((L1 'print))		; prints → L1: (1 a x d)
(display "L2: ")((L2 'print))		; prints → L2: (c y z)
(display "size of L1: ")(display ((L1 'size)))(newline) ; prints → size of L1: 4
(display "size of L2: ")(display ((L2 'size)))(newline) ; prints → size of L2: 3  

|#















