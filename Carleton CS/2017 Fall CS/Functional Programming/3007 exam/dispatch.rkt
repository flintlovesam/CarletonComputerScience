(define (make-account balance)
    (define (withdraw amount)
        (if (>= balance amount)
            (begin
                (set! balance (- balance amount))
                balance)
            "Insufficient funds"))

    (define (deposit amount)
        (set! balance (+ balance amount))
        balance)

    (define (dispatch method)
        (cond ((eq? method 'withdraw) withdraw)
              ((eq? method 'deposit) deposit)
              (else (lambda() (display "Unknown Request: ")(display method)(newline)))))

    dispatch)

(define account (make-account 100))
((account 'withdraw) 60) → 40
((account 'withdraw) 60) → "Insufficient funds"
((account 'deposit) 50) → 90
((account 'clear)) → Unknown Request: clear