; WAY 1

(define (sum term a next b)
  (if (> a b)
    0
    (+ (term a)
       (sum term (next a) next b))
    ))


; way NUMBER 2 

     (define (inc x) (+ x 1))

     (define (identity x) x)


    (define (sum-integers a b)
	(sum identity a inc b))



  (sum-integers 0 10)
  (sum identity 0 inc 10)
  (sum identity 0 inc 10)                                                   ;identity 0 .... 0   &&  inc 10.....11
  ; a is not greater than b...so   (+ (term a)(sum term (next a) next b))

  (sum term a next b)
  (+ (identity 0)(sum identity (next a) next b))       ;next a = 1 in this case
  (+ (identity 0)(sum identity (next 0) next 10))


(sum-integers 0 2)


