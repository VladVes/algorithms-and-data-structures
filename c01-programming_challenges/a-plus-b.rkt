#lang racket

(define a (read-line))
(define b (read-line))
(+ (string->number a) (string->number b))
