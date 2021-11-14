{- 
Модули и функции в Haskell:
	Data.List:
		partition (условие)[список] разбивает список на несколько в зависимости
			от условия
		find (условие)[список] находит первый элемент удовл. условию
		filter (условие)[список] находит все элемент удовл. условию
		any(условие)[список] выводит True, если элементы, удовл. условию есть
			или False, если их нет
		all(условие)[список] выводит True, если все элементы удовл. условию
		union[список1][список1] дополнение списка 1 списком 2
		intersect[список1][список2] пересечение списков 1 и 2
		elem элемент [список] True, если элемент есть в спике
		sort [список] сортирует элементы по возрастанию
-}

--  сделать сортировку
{-
{-Препод-}
mySort :: (Ord a)=> [a]->[a]
mySort [] = []
mySort (x:xs) =
    let leftSort = mySort [a|a<-xs,a<=x]
        rightSort = mySort [a|a<-xs,a>x] 
    in leftSort++[x]++rightSort 
-}

{-Препод-}
sort2 :: Ord a => [a]->[a]
sort2 [] = []
sort2 [x] = [x]
sort2 (x1 : x2 : xs)
   | (x1<x2) = let (a:as) = sort2 (x1:xs) in a: sort2 (x2:as)   
   | otherwise = let (a:as) = sort2 (x2:xs) in a: sort2 (x1:as) 


{-Препод-}
sort1 :: (Ord a)=> [a]->[a]
sort1 [] = []
sort1 (x:xs) = sort1 (filter (<x) xs)++[x]++sort1 (filter (>=x) xs)


{-Саша-Вор-}
mysort:: (Ord a) => [a] -> [a]
mysort [] = []
mysort [x] = [x]
mysort r@(x:y:xs)
 |issorted r = r
 |x > y = mysort (y:(mysort (x:xs)))
 |otherwise = mysort (x:(mysort (y:xs)))

issorted:: (Ord a) => [a] -> Bool
issorted [x, y] = (x <= y)
issorted (x:y:xs) =  (x <= y) && (issorted (y:xs))

{-Сортировка пузырьком от препода-}
bubble1 :: (Ord a) => [a] -> [a]
bubble1(x:y:xs) =
     if x > y then y:bubble1 (x:xs)
     else x:bubble1 (y:xs)
bubble1 xs = xs

bubble :: (Ord a) => [a] -> [a]
bubble [] = []
bubble lst = 
  let t1 = bubble1 lst
  in bubble(init t1) ++ [last t1] 


{-
Стоит изучить ассемблрер. Лит-ра и документация на сайте Microsoft и Habr;
http://osinavi.ru/index.php?param2=18
https://m.habr.com/ru/post/131971/

перемножение матрицы 2х2

-}

umnoj :: Num a => [[a]] -> [[a]]
umnoj 


main :: IO ()
main = do
	putStrLn "Input your name please:"
	lineFromUser <- getLine
	putStrLn $ "Hello " ++ lineFromUser
