#lang racket

(printf "Enter number for A:")
(define a (read-line))
(printf "Enter number for B:")
(define b (read-line))
(printf "A + B = ")
(+ (string->number a) (string->number b))
