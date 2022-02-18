#lang racket

(define (fill-vector v i)
  ((define vecLen (vector-length v))
   (cond 
     [(<= i (- vecLen 1)) 
      ((printf "Enter number: ") 
       (vector-set! v i (string->number (read-line)))
       (fill-vector v (+ i 1)))]
     [(> i (- vecLen 1)) (v)]
     [else v]
    )
))

(printf "Enter array length: ")
(define vecLength (read-line))
(define vec (make-vector (string->number vecLength)))
(fill-vector vec 0)
