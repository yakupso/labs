mysum :: [Int] -> Int
mysum [ ] = 0
mysum (x:xs) = x + mysum xs

{-mylast :: [a] -> a
mylast [] = error "dummy"
mylast [x] = x
mylast (x:xs) = mylast xs-}

mybody :: [a] -> [a]
mybody [] = error "dummy"
mybody (x:xs) = xs

mydelete3 :: [a] -> [a]
mydelete3 [] = error "dummy"
mydelete3 [x] = []
mydelete3 (x:xs) = x:mydelete3 xs

mydelete4 :: [a] -> [a]
mydelete4 [] = error "dummy"
mydelete4 [x, y] = []
mydelete4 (x:xs) = x:mydelete4 xs


-- посчитать сумму (первый элемент с последним,
-- второй с предпоследним и т.д.)
-- посчитать сумму справа 

delete5 :: [a] -> [a]
delete5 (x:y:z:w:q:xs) = (x:y:z:w:xs)

fac :: Int -> Int
fac 0 = 1
fac x = x*fac(x-1)

sum_ :: Int -> Int
sum_ 0 = 0
sum_ x = x + sum_(x-1)

fib :: Int -> Int
fib 0 = 0
fib 1 = 1
fib x = fib(x-1)+fib(x-2)

rev :: [Int] -> Int
rev [] = 0
rev [x] = x
rev (x:xs) = x + last xs

mylast :: [Int] -> Int
mylast [] = 0
mylast [x] = x
mylast (x:xs) = mylast xs


