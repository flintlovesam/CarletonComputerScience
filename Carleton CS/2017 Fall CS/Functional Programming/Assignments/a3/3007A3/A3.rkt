(#%require (only racket/base random))

; Question 1

(define (make-interval a b)
  (cons a b))

(define (lower-bound i)   ; lower-bound accesses the X value (x,y)
  (car i))

(define (upper-bound i)   ; upper-bound accesses the Y value (x,y)
  (cdr i))


; Addition: [a,b] + [c,d] = [a+c,b+d]

(define (add-interval x y)
  (make-interval (+ (lower-bound x) (lower-bound y))    ; creates a interval used in the addition of two intervals
                 (+ (upper-bound x) (upper-bound y))))


(define (sub-interval x y)     ; creates a interval used in the substraction of two intervals relies on helper functions above
  (make-interval (- (lower-bound x) (lower-bound y))
                 (- (upper-bound x) (upper-bound y))))


(define (mul-interval x y)
  (let ((p1 (* (lower-bound x) (lower-bound y))) ; ; creates a interval used in the multiplication of two intervals relies on helper functions above
        (p2 (* (lower-bound x) (upper-bound y)))
        (p3 (* (upper-bound x) (lower-bound y)))
        (p4 (* (upper-bound x) (upper-bound y))))
    (make-interval (min p1 p2 p3 p4) ; takes the min of the intervals
                   (max p1 p2 p3 p4)))) ; takes the max of the intervals
; makes an interval of the max and the min



; Division

(define (width i)
  (/ (- (upper-bound i) (lower-bound i)) 2))

(define (div-interval x y)
  (if (= (width y ) 0) 
      (error "division of interval by width of 0")
      (mul-interval x
                    (make-interval (/ 1.0 (upper-bound y))
                                   (/ 1.0 (lower-bound y))))))


;Question 2

;; provided
(define (special-cons x y)
  (lambda (m) (m x y)))

;2a  
(define (special-car special-pair)
  (special-pair (lambda (p1 p2) p1))) ; allows us to achieve getting the right element by having the lambda function return it without using car 

(define (special-cdr special-pair)
  (special-pair (lambda (p1 p2) p2))) ; ; allows us to achieve getting the left element by having the lambda function return it without using cdr 

; 2 b

(define (triple x y z)
  (lambda (choice)
    (cond ((eq? 'x choice) x)
          ((eq? 'y choice) y)
          (else z))))

(define (first trpl)
  (trpl 'x))

(define (second trpl)
  (trpl 'y))

(define (third trpl)
  (trpl 'z))




; 3a
(define (after L n)
  (cond
    ((null? L) L)
    ( (= n 0) (cons (car L)(cdr L)))
    (else (after (cdr L)(- n 1)))))



;3b
(define (before L n)
  (cond
    ((null? L) L)
    (rev(rev (after (rev L) (+ n 1)))
  )))

(define (rev lis)
   (if (null? lis)
       '()
       (append (rev (cdr lis))
               (list (car lis)))))


(define (append2 lis1 lis2)
  (cond ((null? lis1)
         lis2)
        (else
         (cons (car lis1)
               (append2 (cdr lis1) lis2)))))


(define (splice L n A)
(if (= n 0)  (append2
  (append2
   (before L n)
   A)
  (after L n)))
  
 (append2
  (append2
   (before L n)
   A)
  (after L n))
  )





;3c   works for first example : (multiDelete '(1 2 3 4 5) 2 1 '(a b c))

(define (delete-n l n)
  (if (= n 0) (cdr l)
      (append (list (car l)) (delete-n (cdr l) (- n 1)))))

(define (multiDelete l index num l2)
 (if (= num 0) (splice l index l2)
  (multiDelete (delete-n l index) index (- 1 num) l2)
)
  )


(define (splice2 L i n A)            ; i i
 (append2 (append2 (before L (+ n 1)) A) (after L (+ n 2)))
  
  )





;4a
(define (add1 x)
  (+ x 1))

(define (depth lst)
  (if (not (pair? lst))
      0
      (max (add1 (depth (car lst)))
           (depth (cdr lst)))))

;4b: 
(define (treemap proc tree)
   (cond ((null? tree) tree)
          ((not (pair? tree)) (proc tree))
          (else (cons (treemap proc (car tree))
                      (treemap proc (cdr tree))))))

(define (sqr x)
   (* x x))





(define (flattenList tree)
  (cond ((null? tree) tree)
        ((not (pair? tree)) (list tree))
        (else (append (flattenList (car tree))
                      (flattenList (cdr tree))))))
;5;

(define-syntax cons-stream
    (syntax-rules ()
        ((cons-stream a b)(cons a (delay b)))))

(define (stream-car s) (car s))

(define (stream-cdr s) (force (cdr s)))


;5ai:


(define (integers-start-from n)
  (cons-stream n (integers-start-from(+ n 1))))

(define integers (integers-start-from 1))

(define(stream-first n str)
  (cond ((null? str) str)
        ((= n 0) (cons(stream-car str) (delay str)))
        (else (stream-first (- n 1)(stream-cdr str)))))

;(display(stream-first 10 integers))
        

;5aii:

(define (lis->stream lis)
(cond ((null? lis) lis)
      (else (cons-stream(car lis)
                        (lis->stream(cdr lis)))))) 
(define aList '(1 2 3 4 5))


;5aiii  

(define(stream->list str)
  (cond ((null? str) str)
        (else (cons (stream-car str)
                    (stream->list(stream-cdr str))))))

;5bi


(define (toInfinitynumbers n)
  (cons-stream n (toInfinitynumbers n)))

 (define toInfinity1 (toInfinitynumbers 1))

 ;(stream-first 10 toInfinity1)

  ;5bii

(define (toInfinitynumbersOdd n)
  (cons-stream n (toInfinitynumbersOdd (+ n 2))))

 (define toInfinityO (toInfinitynumbersOdd 1))
;(stream-first 10 toInfinityO)
 

  ;5biii
 (define (toInfinitynumbersRand n)
  (cons-stream n (toInfinitynumbersRand (random 1 101))))

 (define toInfinityR (toInfinitynumbersRand (random 1 101)))

;(stream-first 10 toInfinityR)

 
  ;5biv


(define (f n)
  (if (< n 4)
      n          ; base case
      ( + (f (- n 1)) (* 2 (f(- n 2))) (* 3 (f(- n 3))))  ;recursive loop
      ))

 
  (define (fibLoop n)
  (cons-stream (f n) (fibLoop (f (+ n 1)))))

 (define fibLoopStarter (fibLoop -4))

 
;5c 


 #| TESTING


1.
(addition)

Normal: (add-interval (make-interval 0 6) (make-interval 0 5))
expected (0 . 11)
actual (0 . 11)

Edge: (add-interval (make-interval 0 0) (make-interval 0 0))
expected (0 . 0)
actual (0 . 0) 

(substraction)
Normal: (sub-interval (make-interval 0 6) (make-interval 0 5))
expected (0 . 1)
actual (0 . 1)

Edge: (sub-interval (make-interval 0 1) (make-interval 10 0))
expected (-10 . 1)
actual (-10 . 1)

(multiplication)
Normal: (mul-interval (make-interval 0 6) (make-interval 0 5))
expected (0 . 30)
actual (0 . 30)

Edge: (mul-interval (make-interval -1 0) (make-interval -1 0))
expected (0 . 0)
actual (1 . 0) 


(division)
Normal: (div-interval (make-interval 5 10) (make-interval 5 100))
expected (0.05 . 2.0)
actual (0.05 . 2.0)

Edge: (div-interval (make-interval 0 6) (make-interval 0 5))
expected : division by zero
actual division by zero


; 2

; test them

(define a (triple 1 2 3))

(first a)
expected: 1
actual:  1

(second a)
expected: 2
actual:  2

(third a)
expected: 3
actual:  3


;3a
(after '(a b c d e f g h) 3)
expected: (d e f g h)
actual: (d e f g h)

(after '(a b c d e f g h) 0)
actual: (a b c d e f g h)
expected: (a b c d e f g h)


3b
(splice '(1 2 3 4 5) 2 '(a b c))

expected: (1 2 a b c 3 4 5)
actual: (1 2 a b c 3 4 5)


(splice '(1 2 3 4 5) 0 '(a b c))

expected: (a b c 1 2 3 4 5)
actual: expected: (a b c 1 2 3 4 5)



3c
(splice2 '(1 2 3 4 5) 2 1 '(a b c))
actual: (1 2 a b c 4 5)
expected: (1 2 a b c 4 5)


4a: (depth 'a)
Expected: 0
Actual:0

(depth 'a) → 0
Expected: 
Actual:

(depth '(a))
Expected: 1
Actual:1

(depth '(a (b) c))
Expected:  2
Actual: 2

(depth '(((((a(((b)))))))))
Expected: 8
Actual: 8 


4b: (treemap sqr '(1 (2 3) ((4 5) (6 7)) (((8 (9))))))

Expected: (1 (4 9) ((16 25) (36 49)) (((64 (81)))))
Actual: (1 (4 9) ((16 25) (36 49)) (((64 (81)))))


4c: (flattenList '(1 (2 3) ((4 5 6 (7)))(((8 (9))))))
Expected: (1 2 3 4 5 6 7 8 9)
Actual: (1 2 3 4 5 6 7 8 9)



5ai (display(stream-first 10 integers))
Expected: (11 . #<promise>)
Actual: (11 . #<promise>)


5aii : (lis->stream aList) where (define aList '(1 2 3 4 5))
Expected:  (1 . #<promise>)
Actual: (1 . #<promise>)

5aiii
Expected: 
Actual:

5bi: (stream-first 10 toInfinity1)
Expected: (1 . #<promise>)
Actual: (1 . #<promise>)

5bii: (stream-first 10 toInfinityO)
Expected:  (21 . #<promise>)
Actual: (21 . #<promise>)




5bii: (stream-first 10 toInfinityR)
Expected: (63 . #<promise>)
Actual: (63 . #<promise>)


5biv: (stream-first 5 fibLoopStarter)
Expected:  (1 . #<promise>)
Actual:  (1 . #<promise>)

5c



|#

