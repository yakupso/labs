invmatrix :: [[Float]] -> [[Float]]
invmatrix x
 |dety x /= 0 && mod (mcount x) 2 /= 0 = mfunc ((1 / dety x)) $mtransp (algmatrixo (mcount x) x)
 |dety x /= 0 && mod (mcount x) 2 == 0 = mfunc ((1 / dety x)) $mtransp (algmatrixe (mcount x) x)
 |otherwise = error "Determinant is equal to zero"

mfunc :: (Float -> Float) -> [[Float]] -> [[Float]]
mfunc  [] = []
mfunc f (m:ms) = map1 f m : mfunc f ms

mcount :: [[Float]] -> Int
mcount [] = 0
mcount (x:xs) = 1 + mcount xs

mtransp :: [[Float]] -> [[Float]]
mtransp ([]:) = []
mtransp x = (map1 head1 x) : mtransp (map1 tail1 x)

algmatrixe :: Int -> [[Float]] -> [[Float]]
algmatrixe 0  = []
algmatrixe i (x:xs)
 |mod i 2 /= 0 = [map1 ((-1)*) [(-1)^(j+1) * dety(deletesty j xs) | j <-[1..(length x)]]] ++ algmatrixe (i-1) (xs ++ [x])
 |otherwise = [[(-1)^(j+1) * dety(deletesty j xs) | j <-[1..(length x)]]] ++ algmatrixe (i-1) (xs ++ [x])

algmatrixo :: Int -> [[Float]] -> [[Float]]
algmatrixo 0  = []
algmatrixo i (x:xs) = [[(-1)^(j+1) * dety(deletesty j xs) | j <-[1..(length x)]]]++ algmatrixo (i-1) (xs ++ [x])



-- Вычисление определителя квадратной матрицы
-- посчитать обратную матрицу

