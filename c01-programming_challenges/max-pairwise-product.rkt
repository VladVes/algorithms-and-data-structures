#lang racket

(printf "Enter array length: ")
(define vecLength (read-line))
(define vec (make-vector (string->number vecLength)))
(vector-set! vec 0 5)
(vector-set! vec 1 4)
(vector-set! vec 2 3)
(printf (number->string (vector-ref vec 0)))

