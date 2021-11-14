xyu :: [Int] -> Int
xyu [] = 1
xyu (x:xs)
 | x `mod` 2 > 0 = x * xyu xs
 | otherwise = xyu xs