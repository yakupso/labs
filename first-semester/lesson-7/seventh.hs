rmv_agn :: (Eq a) => [a]->[a] -- удаляет элементы, имеющие повторы
rmv_agn [] = []
rmv_agn (x:xs)
    | [k | k <- xs, k == x] == [] = x : (rmv_agn xs)
    | otherwise =  rmv_agn [k | k <- xs, k/= x]


remove_agained :: Int -> Int -> [Int] 
remove_agained a b | a > b = []
remove_agained a b = a : remove_agained (a+1) b


mylo :: [a] -> [a]       -- меняет местами первый с последним
mylo [] = []
mylo [x]=[x]
mylo (x:xs) = let (f, g) = swap x xs in f:g
    where swap k [y] = (y, [k])
          swap k (y:ys) = let (n, m) = swap k ys in (n, y:m)


-- разрезать список пополам и реверснуть половинки
-- [1,2,3,4,5,6] - [3,2,1,6,5,4]

perevorot :: [Int] -> [Int]
perevorot [] = []
perevorot [x] = [x]
perevorot (x:xs) = perevorot xs ++ [x]

swaps :: [Int] -> [[Int]]
swaps [] = []
swaps [x] = [[x]]
swaps x = let (f,g) = razb x (length x `div` 2) in f:[g]
 where razb :: [Int] -> Int -> ([Int],[Int])
       razb (y:ys) 1 = ([y],perevorot ys)
       razb (y:ys) z = let (n,m) = razb ys (z-1) in (n++[y],m)

middleSplitThenFlip :: [a] -> [a]
middleSplitThenFlip [] = []
middleSplitThenFlip zs = list
    where
        list = (rev beg) ++ mid ++ (rev end)

        (beg, mid, end) = go zs zs
        go (x:xs) (_:_:ys) = 
            let 
                (beg, mid, end) = go xs ys 
            in 
                (x:beg, mid, end)
        go (x:xs) [_] = ([], [x], xs)
        go (x:xs) []  = ([], [], x:xs)

        rev [] = []
        rev [x] = [x]
        rev (x:xs) = rev xs ++ [x]



-- вывести все возможные подсписки списка
-- например, [1,2] -> [[],[1],[2],[1,2]]



all_sublists :: [a] -> [[a]]
all_sublists [] = [[]]
all_sublists (x:xs) = sublists_without_x ++ sublists_appender x sublists_without_x
    where sublists_without_x = all_sublists xs
          sublists_appender a [] = []
          sublists_appender a (b:bs) = (a:b):(sublists_appender a bs)


--Берет первые n элементов из списка
frstn :: [Int] -> Int -> [Int]
frstn _ 0 = []
frstn (x:xs) n = x : frstn xs (n-1)

--Матрица из списков frstn
podspisok :: [Int] ->[[Int]]
podspisok []  = [[]]
podspisok (x:xs) = [frstn (x:xs) n | n <- [1..length (x:xs)]] ++ podspisok xs




mycut :: (Eq a, Num a) => [a] -> [a] -> [a]
mycut [] y = y
mycut x [] = []
mycut x (y:ys)
    | isbeginning x (y:ys) = mycut x (myerase (mylistlength x) (y:ys))
    | otherwise = y:(mycut x ys)

    where isbeginning x [] = False
          isbeginning [x] (y:ys) = x == y
          isbeginning (x:xs) (y:ys)
              | x == y = isbeginning xs ys
              | otherwise = False

          mylistlength [] = 0
          mylistlength [x] = 1
          mylistlength (x:xs) = mylistlength(xs) + 1

          myerase _ [] = error "dummy"
          myerase 1 (x:xs) = xs
          myerase n (x:xs) = myerase (n-1) xs 