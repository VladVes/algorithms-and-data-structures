#lang racket

(require readline/readline)
(define a "")
(define b "")
(write "Enter value for A")
(readline a)
(readline b)
(write (+ a b))


