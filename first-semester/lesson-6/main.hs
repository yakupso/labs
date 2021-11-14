inc :: Integer -> Integer
inc n = n + 1

add :: Integer -> Integer -> Integer
add x y = x + y

lenght :: [a] -> Integer
lenght [] = 0
lenght (x:xs) = 1 + lenght xs

mmap :: (a -> b) -> [a] -> [b]
mmap f [] = []
mmap f (x:xs) = f x : mmap f xs