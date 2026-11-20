#wc -l < test.txt
wc -l < data.dat
grep -oi "dolor" data.dat|wc -l
#`-E` 扩展正则，`|` 代表或；搭配 `-o` 才能**逐个匹配计数**
grep -Eo "dolor|dolar" data.dat|wc -l
wc -w < data.dat
#大小写不敏感加 `-i`,加 `-w` 整词：
grep -o "mol" data.dat|wc -l