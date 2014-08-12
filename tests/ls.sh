Script started on Tue 12 Aug 2014 02:14:00 PM PDT
~
kryne001@well $ cd github/rshell
~/github/rshell
kryne001@well $ bin/ls # [Ktesting regular ls
LICENSE README.md bin makefile src tests ls.sh 
~/github/rshell
kryne001@well $ bin[K[K[Kbin/ls #testing regular ls[C[4h [4l[4h-[4l[4ha[4l[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[K[K[K[K[K[K[K[K[K[K-a flag
. .. .git LICENSE README.md bin makefile src tests ls.sh 
~/github/rshell
kryne001@well $ bin/ls -l #testing -a[Kl flag
lrw------- 1 kryne001 classes 1485 Aug 10 17:17 LICENSE
lrw------- 1 kryne001 classes 1272 Aug 10 17:17 README.md
drwx------ 2 kryne001 classes 4096 Aug 12 14:10 bin
lrw------- 1 kryne001 classes 158 Aug 11 23:46 makefile
drwx------ 2 kryne001 classes 4096 Aug 12 14:02 src
drwx------ 2 kryne001 classes 4096 Aug 12 14:09 tests
lrw------- 1 kryne001 classes 0 Aug 12 14:14 ls.sh
~/github/rshell
kryne001@well $ bin/ls -al #comi[Kbined,[K[K[K[K[K[K[K[K[Kflags combined, a first then l
drwx------ 6 kryne001 classes 4096 Aug 12 14:14 .
drwx------ 4 kryne001 classes 4096 Aug 10 17:17 ..
drwx------ 8 kryne001 classes 4096 Aug 12 14:02 .git
lrw------- 1 kryne001 classes 1485 Aug 10 17:17 LICENSE
lrw------- 1 kryne001 classes 1272 Aug 10 17:17 README.md
drwx------ 2 kryne001 classes 4096 Aug 12 14:10 bin
lrw------- 1 kryne001 classes 158 Aug 11 23:46 makefile
drwx------ 2 kryne001 classes 4096 Aug 12 14:02 src
drwx------ 2 kryne001 classes 4096 Aug 12 14:09 tests
lrw------- 1 kryne001 classes 0 Aug 12 14:14 ls.sh
~/github/rshell
kryne001@well $ bin/ls -al #flags combined, a first then l[C[C[C[C[C[C[C[Ka[1P[4hl[4l[1P[1P[4hl[4l[4ha[4l
drwx------ 6 kryne001 classes 4096 Aug 12 14:14 .
drwx------ 4 kryne001 classes 4096 Aug 10 17:17 ..
drwx------ 8 kryne001 classes 4096 Aug 12 14:02 .git
lrw------- 1 kryne001 classes 1485 Aug 10 17:17 LICENSE
lrw------- 1 kryne001 classes 1272 Aug 10 17:17 README.md
drwx------ 2 kryne001 classes 4096 Aug 12 14:10 bin
lrw------- 1 kryne001 classes 158 Aug 11 23:46 makefile
drwx------ 2 kryne001 classes 4096 Aug 12 14:02 src
drwx------ 2 kryne001 classes 4096 Aug 12 14:09 tests
lrw------- 1 kryne001 classes 0 Aug 12 14:14 ls.sh
~/github/rshell
kryne001@well $ bin[K[K[Kbin/ls -la #flags combined, l first then a
drwx------ 6 kryne001 classes 4096 Aug 12 14:14 .
drwx------ 4 kryne001 classes 4096 Aug 10 17:17 ..
drwx------ 8 kryne001 classes 4096 Aug 12 14:02 .git
lrw------- 1 kryne001 classes 1485 Aug 10 17:17 LICENSE
lrw------- 1 kryne001 classes 1272 Aug 10 17:17 README.md
drwx------ 2 kryne001 classes 4096 Aug 12 14:10 bin
lrw------- 1 kryne001 classes 158 Aug 11 23:46 makefile
drwx------ 2 kryne001 classes 4096 Aug 12 14:02 src
drwx------ 2 kryne001 classes 4096 Aug 12 14:09 tests
lrw------- 1 kryne001 classes 0 Aug 12 14:14 ls.sh
~/github/rshell
kryne001@well $ bin/ls -l -a #flags sepat[Krated, l first h[Kthen a
drwx------ 6 kryne001 classes 4096 Aug 12 14:14 .
drwx------ 4 kryne001 classes 4096 Aug 10 17:17 ..
drwx------ 8 kryne001 classes 4096 Aug 12 14:02 .git
lrw------- 1 kryne001 classes 1485 Aug 10 17:17 LICENSE
lrw------- 1 kryne001 classes 1272 Aug 10 17:17 README.md
drwx------ 2 kryne001 classes 4096 Aug 12 14:10 bin
lrw------- 1 kryne001 classes 158 Aug 11 23:46 makefile
drwx------ 2 kryne001 classes 4096 Aug 12 14:02 src
drwx------ 2 kryne001 classes 4096 Aug 12 14:09 tests
lrw------- 1 kryne001 classes 0 Aug 12 14:14 ls.sh
~/github/rshell
kryne001@well $ bin/ls -l -a #flags separated, l first then a[C[Kl[1P[4ha[4l[1P[4hl[4l[C[1P[4ha[4l
drwx------ 6 kryne001 classes 4096 Aug 12 14:14 .
drwx------ 4 kryne001 classes 4096 Aug 10 17:17 ..
drwx------ 8 kryne001 classes 4096 Aug 12 14:02 .git
lrw------- 1 kryne001 classes 1485 Aug 10 17:17 LICENSE
lrw------- 1 kryne001 classes 1272 Aug 10 17:17 README.md
drwx------ 2 kryne001 classes 4096 Aug 12 14:10 bin
lrw------- 1 kryne001 classes 158 Aug 11 23:46 makefile
drwx------ 2 kryne001 classes 4096 Aug 12 14:02 src
drwx------ 2 kryne001 classes 4096 Aug 12 14:09 tests
lrw------- 1 kryne001 classes 0 Aug 12 14:14 ls.sh
~/github/rshell
kryne001@well $ bin [K/s [K[Kls -a -a - a- [K[K[K[Ka -a #flag a called multiple times
. .. .git LICENSE README.md bin makefile src tests ls.sh 
~/github/rshell
kryne001@well $ bin/ls src #passing in a directory
hw1.cpp ls.cpp 
~/github/rshell
kryne001@well $ bin/ls src #passing in a directory[4h-[4l[4ha[4l[4h [4l[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C with a flag
. .. hw1.cpp ls.cpp 
~/github/rshell
kryne001@well $ bin/ls src -a #passing in a directory with a flag[1P[4hl[4l[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[1P flagl flag
lrw------- 1 kryne001 classes 1868 Aug 11 23:33 hw1.cpp
lrw------- 1 kryne001 classes 9392 Aug 12 14:02 ls.cpp
~/github/rshell
kryne001@well $ bin/ls src -l #passing in a directory with l flag[C[1Pg[1Pg[1Pg[1Pg[1Pg[1Pg[1Pg[1Pg[1Pg[1Pg[1Pg[1Pg[1Pg[1Pg[1Pg[1Pg[1Pg[1Pg[1Pg[1Pg[1Pg[1Pg[C[Kfile[1P[1P[1P[1P[1P[1P[4hR[4l[4hE[4l[4hA[4l[4hD[4l[4hM[4l[4hE[4l[4h.[4l[4hm[4l[4hd[4l
./README.md
~/github/rshell
kryne001@well $ bin/ls README.md #passing in file[4hL[4l[4hI[4l[4hC[4l[4hE[4l[4hN[4l[4hS[4l[4hE[4l[4h [4l[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[K[K[K[Kmil[K[Kultiple files
./README.md
./LICENSE
~/github/rshell
kryne001@well $ bin/ls src/hw1cpp[K[K[K.cpp #passing in file through path
./src/hw1.cpp
~/github/rshell
kryne001@well $ bin/ls README.md -l #passing in file throug[K[K[K[K[K[K[K with l flag
lrw------- 1 kryne001 classes 1272 Aug 10 17:17 ./README.md
~/github/rshell
kryne001@well $ bin/ls README m.[K[K[K.md[K[K[K[K[K[K[K[K[Ksrc/hw1.cpp -l #passing in file with [K[K[K[K[Kthrough path with l flag
lrw------- 1 kryne001 classes 1868 Aug 11 23:33 ./src/hw1.cpp
~/github/rshell
kryne001@well $ bin/ls src bin #passing in myl[K[Kultiple directories
hw1.cpp ls.cpp 
rshell ls 
~/github/rshell
kryne001@well $ bin/ls src bin #passing in multiple directories[K[K[K[K[K[K[K[K[K[K[K[K[K[K[K[K[K[K[K[K[K[K[K[K[K[K[K[K[K[K[K[K-l #passing in multiple directories with -l
./src:
lrw------- 1 kryne001 classes 1868 Aug 11 23:33 hw1.cpp
lrw------- 1 kryne001 classes 9392 Aug 12 14:02 ls.cpp

./bin:
lrwx------ 1 kryne001 classes 14154 Aug 12 14:10 rshell
lrwx------ 1 kryne001 classes 158787 Aug 12 14:10 ls

~/github/rshell
kryne001@well $ bin/ls src bin -l #passing in multiple directories with -l[C[C[C[C[Ca[C[4ha[4l
./src:
drwx------ 2 kryne001 classes 4096 Aug 12 14:02 .
drwx------ 6 kryne001 classes 4096 Aug 12 14:14 ..
lrw------- 1 kryne001 classes 1868 Aug 11 23:33 hw1.cpp
lrw------- 1 kryne001 classes 9392 Aug 12 14:02 ls.cpp

./bin:
drwx------ 2 kryne001 classes 4096 Aug 12 14:10 .
drwx------ 6 kryne001 classes 4096 Aug 12 14:14 ..
lrwx------ 1 kryne001 classes 14154 Aug 12 14:10 rshell
lrwx------ 1 kryne001 classes 158787 Aug 12 14:10 ls

~/github/rshell
kryne001@well $ bin/ls -R #passing in current directory with -R flag
./.git:
	./.git/refs:
	./.git/refs/heads:
	./.git/refs/heads/master:
	./.git/refs/heads/master
~/github/rshell
kryne001@well $ bin/ls src[K[K[K-lR #passing in current directory with -[Kl and r[KR flags
./.git:
	./.git/refs:
	./.git/refs/heads:
	./.git/refs/heads/master:
	lrw------- 1 kryne001 classes 41 Aug 11 23:33 ./.git/refs/heads/master
~/github/rshell
kryne001@well $ bin/ls -Rl [K[K[KaR #passing in current directory with l and R[K[K[K[K[K[K[Ka and R flags
./.git:
	./.git/refs:
	./.git/refs/heads:
	./.git/refs/heads/master:
	./.git/refs/heads/master
~/github/rshell
kryne001@well $ bin/ls -Ra #passing in current[K[K[K[Krent directory with R then a flag[K[K[K[K[K[K'a' flags
./.git:
	./.git/refs:
	./.git/refs/heads:
	./.git/refs/heads/master:
	./.git/refs/heads/master
~/github/rshell
kryne001@well $ bin/ls -Ra #passing in current directory with R then 'a' flags[1P[4hl[4l[C[1P[4hl[4l
./.git:
	./.git/refs:
	./.git/refs/heads:
	./.git/refs/heads/master:
	lrw------- 1 kryne001 classes 41 Aug 11 23:33 ./.git/refs/heads/master
~/github/rshell
kryne001@well $ -l bin [K/ls #passing in flags before executable
bash: -l: command not found
~/github/rshell
kryne001@well $ bin/ls -l -a -r[KR #passing in fla[K[K[K[K all flags separately, l then a then R
./.git:
	./.git/refs:
	./.git/refs/heads:
	./.git/refs/heads/master:
	lrw------- 1 kryne001 classes 41 Aug 11 23:33 ./.git/refs/heads/master
~/github/rshell
kryne001@well $ bin/ls -l -[K[K -R -a #passing in all flags c[Kseparately, l then r[KR then a
./.git:
	./.git/refs:
	./.git/refs/heads:
	./.git/refs/heads/master:
	lrw------- 1 kryne001 classes 41 Aug 11 23:33 ./.git/refs/heads/master
~/github/rshell
kryne001@well $ bin/ls -l -[K[K[KR -l -a #passing in all flags separe[Kately [K, l then R t[K[K[K[K[K[K[K[K[K[KR then l then a
./.git:
	./.git/refs:
	./.git/refs/heads:
	./.git/refs/heads/master:
	lrw------- 1 kryne001 classes 41 Aug 11 23:33 ./.git/refs/heads/master
~/github/rshell
kryne001@well $ bin/ls src -R -l -a # [Kpassing in all flags for a directory
./src/hw1.cpp:
	lrw------- 1 kryne001 classes 1868 Aug 11 23:33 ./src/hw1.cpp
~/github/rshell
kryne001@well $ bin/ls src -R -l -a #passing in all flags for a directory[K[K[K[K[K[K[K[K[K[K[Kmulitiplat[K[Kes[K[Ks [K[Ke directoir[K[Kries[C[4hb[4l[4hi[4l[4hn[4l[4h [4l
./src:
./src/hw1.cpp:
	lrw------- 1 kryne001 classes 1868 Aug 11 23:33 ./src/hw1.cpp

./bin:
./bin/rshell:
	lrwx------ 1 kryne001 classes 14154 Aug 12 14:10 ./bin/rshell

~/github/rshell
kryne001@well $ stop script
bash: stop: command not found
~/github/rshell
kryne001@well $ exit
exit

Script done on Tue 12 Aug 2014 02:27:09 PM PDT
