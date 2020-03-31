#lang scheme
(define lst1 '(1 2 3 4))
(define lst2 (cons 'a '(b c d)))
(define lst3 (list 'w 'x 'y 'z))
(define lst4 (append '(7 8) '(9 10)))
lst1
lst2
lst3
lst4

(cons 0 lst1)

(define sum-list
  (lambda (lst)
    (if (null? lst)
        0
        (+ (car lst) (sum-list (cdr lst))))))
(sum-list lst1)
(sum-list lst4)

(define remove-odds
  (lambda (lst)
    (if (null? lst)
        '()
        (if (= 0 (remainder (car lst) 2))
            (cons (car lst) (remove-odds (cdr lst)))
            (remove-odds (cdr lst))))))
(remove-odds lst1)
(remove-odds lst4)

"list?"
(list? lst1)
(list? '())
(list? (cons 'x '()))

"pair?"
(pair? lst1)
(pair? '())
(pair? (cons 'x '()))

"Create pairs using cons"
(cons 'a 'b)
(cons lst1 lst2)
(cons 1 2)
(cons '() 'a)
'(1 . 2)
'((1 2 3) . (a . (b . c)))
'(3 . ())

(newline)
"Compare two lists"
(define list-equal?
  (lambda (lst1 lst2)
    (cond
      ((and (null? lst1) (null? lst2)) #t)
      ((and (null? lst1) (not (null? lst2))) #f)
      ((and (null? lst2) (not (null? lst1))) #f)
      ((eq? (car lst1) (car lst2)) (list-equal? (cdr lst1) (cdr lst2)))
      (else #f))))
lst1
lst2
(list-equal? lst1 lst2)
(list-equal? lst1 '(1 2 3 4))
(list-equal? (cons 10 '(20 30)) (cons 10 (cons 20 (cons 30 '()))))
(list-equal? (cons 'a '(b c)) (list 'a 'b 'c))
(list-equal? (cons 'a '(b c d)) (list 'a 'b 'c))



      
      

    