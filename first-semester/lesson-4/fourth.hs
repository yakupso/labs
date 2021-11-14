{--mytake:: Int -> [Int] -> [Int]
mytake y [] = []
mytake 0 x = []
mytake y (x:xs) = x:(mytake (y-1) xs)

mylenght:: [Int] -> Int
mylenght [] = 0
mylenght (x:xs) = 1 + mylenght (xs)


myfindlist:: [Int] -> [Int] -> Bool
myfindlist [] [] = True
myfindlist x [] = False
myfindlist x (y:ys) = if x == (mytake(mylenght x) (y:ys)) then True else myfindlist x ys

-- перемножение и сумма двух матриц  размера 2х2



-- определить упорядочен ли список по возрастанию

lst :: [Int] -> Bool
lst [] = True
lst [_] = True
lst (x:r@(y:_)) = x<y && lst r

-- написать функцию, которая переворачивает 2 функции Cos Sin 3 -> Sin Cos 3
-- дифферинцировать простую функцию

rvs :: (Floating a, Floating (a -> a)) => (a -> a) -> a -> a
rvs x y z = y(x z)--}

qp :: Rational -> Rational -> Rational -> [a]
qp 0 b c = [-c/b]
qp 0 0 c = ["no one"]
qp 0 0 0  = ["infinity"]
qp a b c = [(-b+sqrt(b*b-4*a*c))/(2*a), (-b+sqrt(b*b-4*a*c))/(2*a)]