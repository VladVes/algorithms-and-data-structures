#lang racket

(define (fill-vector v)
    (define (put-at-i i)
        (printf "enter number: ")
        (vector-set! v i (string->number (read-line)))
        (iter (+ i 1)))
    (define (iter next-i)
        (if (< next-i (vector-length v)) 
            (put-at-i next-i)
            v))
    (iter 0))

(define (get-biggest-i vec)
    (define (iter next-i biggest-at-i)
        (if (= next-i (vector-length vec)) biggest-at-i 
            (compare next-i biggest-at-i)))
    (define (compare i j)
        (if (> (vector-ref vec i) (vector-ref vec j))
            (iter (+ i 1) i)
            (iter (+ i 1) j)))
    (compare 0 0))
    
(define (max-pairwise-product vec)
    (define first-max-index (get-biggest-i vec))
    (define second-vec 
        (if (> (vector-length vec) 1)
            (list->vector
                (remove (vector-ref vec first-max-index) (vector->list vec)))
            vec))
    (define second-max-index (get-biggest-i second-vec))
    (* (vector-ref vec first-max-index) (vector-ref second-vec second-max-index)))

(printf "Enter vector length: ")
(define vec (make-vector (string->number (read-line))))
(fill-vector vec)
(max-pairwise-product vec)

