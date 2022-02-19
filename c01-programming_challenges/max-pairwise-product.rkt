#lang racket

(define (fill-vector v i)
    (define (iter v)
        (printf "enter number: ")
        (vector-set! v i (string->number (read-line)))
        (fill-vector v (+ i 1)))
    (if (<= i (- (vector-length v) 1)) 
        (iter v)
        v))

(define (max-pairwise-product vec)
    (define vec-len (vector-length vec))
    (define first-max-index 1)
    (define second-max-index 2)
    (* (vector-ref vec first-max-index) (vector-ref vec second-max-index)))

(printf "Enter vector length: ")
(define vec-len (read-line))
(define vec (make-vector (string->number vec-len)))
(fill-vector vec 0)
(max-pairwise-product vec)
