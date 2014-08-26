Script started on Tue 26 Aug 2014 02:08:04 PM PDT
~
kryne001@well $ cd github/rshell/
~/github/rshell
kryne001@well $ make sr[K[Krshell
g++ -Wall -Werror -ansi -pedantic -g --debug src/hw1.cpp -o bin/rshell
~/github/rshell
kryne001@well $ binr[K/rshell
kryne001@well.cs.ucr.edu$ ls > test # io st  redirection
kryne001@well.cs.ucr.edu$ cat test #view contents
bin
homework.sh
LICENSE
makefile
README.md
src
test
tests
kryne001@well.cs.ucr.edu$ rm -rf test #u rm is not in the bin folder, testing if path ow  works
kryne001@well.cs.ucr.edu$ ls l s # test if rm worked      executed
bin  homework.sh  LICENSE  makefile  README.md	src  tests
kryne001@well.cs.ucr.edu$ cd .. # chec    if it uses my cd, should print m used mine
used mine
kryne001@well.cs.ucr.edu$ c ls # check the contents of current directio  ory
rshell	ucr-cs100
kryne001@well.cs.ucr.edu$ ls
rshell	ucr-cs100
kryne001@well.cs.ucr.edu$ cd rshell
used mine
kryne001@well.cs.ucr.edu$ ls  ls
bin  homework.sh  LICENSE  makefile  README.md	src  tests
kryne001@well.cs.ucr.edu$ ls -laksdj          exit
~/github/rshell
kryne001@well $ exit
exit

Script done on Tue 26 Aug 2014 02:09:59 PM PDT
