(define (reciprocal x)
  (/ 1 x)
  )

(define (2b x)
  (+ 3 (* (reciprocal x) 3))

  )


(define z 2)
 (define (fun x)
 
   (lambda (y) (* x y z)
       (write y)
     ))

 (define closure1 (fun 3)   )
    

 

 (define r1 (closure1 5))


  (define closure2 (fun 4))
 (define r2 (closure2 5))

 (let ((l (+ 2 1))(e (/ 16(* 4 4)))(t (length '(5 7)))) (if (< l e) t 0)

 (write l)
 (write e)
 (write t)
   )



