myfirst :: [Int] -> Int
myfirst [] = error "chainik_myfirst"
myfirst (x:xs) = x

mylast :: [Int] -> Int
mylast [] = error "chainik_mylast"
mylast [x] = x
mylast (x:xs) = mylast xs

mysum :: [Int] -> Int
mysum [] = 0
mysum [x] = x
mysum (x:xs) = x + mylast xs + mysum(k xs)

k :: [Int] -> [Int]
k (x:xs) 
 |xs == [] = []
 |otherwise = x:k (xs)

mydelete3 :: [a] -> [a]
mydelete3 [] = error "dummy"
mydelete3 [x] = []
mydelete3 (x:xs) = x:mydelete3 xs

rightsum :: [Int] -> Int
rightsum [] = 0
rightsum x = rightsum(mydelete3 x) + mylast x

