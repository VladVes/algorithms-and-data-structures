#lang racket

(define (fibonacci-naive n)
    (if (<= n 1) n
        (+ (fibonacci-naive (- n 1)) (fibonacci-naive (- n 2)))))

(printf "Enter sequence length: \n")
(define seq-len (string->number (read-line)))
(fibonacci-naive seq-len)
