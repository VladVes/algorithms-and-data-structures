#lang racket

(define (fibonacci-naive n)
    (if (<= n 1) n
        (+ (fibonacci-naive (- n 1)) (fibonacci-naive (- n 2)))))

(define (fibonacci-fast n)
    (define (calculate)
        (define vec (make-vector (+ n 1)))
        (vector-set! vec 0 0)
        (vector-set! vec 1 1)
        (for ([i (inclusive-range 2 n)])
            (vector-set! vec i (+ (vector-ref vec (- i 1))
                                  (vector-ref vec (- i 2)))))
        (vector-ref vec n))
    (if (< n 2) n
        (calculate)))

(printf "Enter sequence length: \n")
(define seq-len (string->number (read-line)))
(printf "Fibonacci naive: ")
(fibonacci-naive seq-len)
(printf "Fibonacci fast: ")
(fibonacci-fast seq-len)
