-- Вычисление определителя матрицы

dety :: [[Rational]] -> Rational
dety [] = error "Empty Error"
dety [[x]] = x
dety (x:xs) = sum [(-1)^(j+1) * (head [x])!!(j-1) * dety(deletesty j xs) | j <-[1..(length x) ]]

dely :: Int-> [a] -> [a]
dely 1 (x:xs) = xs
dely k (x:xs) = [x] ++ dely (k-1) xs


deletesty::(Num a) => Int -> [[a]] -> [[a]]
deletesty k x = [c|c<- [ dely k q | q<-x ]]

-- разделить список на два списка в кортеже. Один список с "+", другой с "-"
-- найти обратную матрицу