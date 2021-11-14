test1 :: Float -> Float
test1 x = x + x

test2 :: Float -> Float -> Float
test2 x y = test1 x + test1 y

test3 :: Int -> String
test3 1 = "one"
test3 2 = "two"
test3 3 = "three"
test3 x = "hi"

max1 :: (Ord) a => a -> a -> a
max1 x y
    | x >= y = x
    | otherwise = y

max2 :: (Ord) a => a -> a -> a -> a
max2 x y z
    | (x <= y) && (z <= y) = y
    | (x <= z) && (y <= z) = z
    | otherwise = x


 --последний элемент на первую позицию

max4 :: (Ord) a => a -> a -> a -> a -> a
max4 x y z q
    | (x <= y),(z <= y),(q <= y) = y
    | (x <= z),(y <= z),(q <= z) = z
    | (x <= q),(y <= q),(z <= q) = q
    | otherwise = x



sex :: Int -> Int
sex a 
    | a > 0 = sex(a-1) + 2*a - 1
    | otherwise = 0
