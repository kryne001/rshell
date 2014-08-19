Script started on Tue 19 Aug 2014 01:40:02 PM PDT
~
kryne001@well $ ls
[0m[01;32maddons.sqlite[0m*           [01;32mcookies.sqlite-wal[0m*         [01;32mhealthreport.sqlite-shm[0m*  [01;32mplaces.sqlite[0m*      [01;34mstartupCache[0m/
[01;32maddons.sqlite-journal[0m*   [01;34mcs100[0m/                      [01;32mhealthreport.sqlite-wal[0m*  [01;32mplaces.sqlite-shm[0m*  [01;34mTemplates[0m/
[01;32ma.out[0m*                   [01;34mDesktop[0m/                    [01;34mhomerepo[0m/                 [01;32mplaces.sqlite-wal[0m*  [01;34mtestgit[0m/
[01;34mAssignment8CS12[0m/         [01;34mDocuments[0m/                  [01;34mindexedDB[0m/                [01;32mpluginreg.dat[0m*      [01;34mthumbnails[0m/
[01;32mblocklist.xml[0m*           [01;34mDownloads[0m/                  [01;34mjetpack[0m/                  [01;32mprefs.js[0m*           [01;32mtimes.json[0m*
[01;34mbookmarkbackups[0m/         [01;32mdownloads.sqlite[0m*           [01;32mkey3.db[0m*                  [01;34mPublic[0m/             [01;32mtree.cpp[0m*
[01;34mCache[0m/                   [01;34mextensions[0m/                 [01;32mlab09.cpp[0m*                [01;32mrebalanceCode.cpp[0m*  [01;32mtree.h[0m*
[01;32m_CACHE_CLEAN_[0m*           [01;32mextensions.ini[0m*             [01;32mlocalstore.rdf[0m*           [01;34mrshell[0m/             [01;32murlclassifierkey3.txt[0m*
[01;32mcert8.db[0m*                [01;32mextensions.sqlite[0m*          [01;32mmain.cpp[0m*                 [01;34msafebrowsing[0m/       [01;34mVideos[0m/
[01;32mcert_override.txt[0m*       [01;32mextensions.sqlite-journal[0m*  [01;32mmarionette.log[0m*           [01;32msearch.json[0m*        [01;34mwebapps[0m/
[01;32mchromeappsstore.sqlite[0m*  [01;32mformhistory.sqlite[0m*         [01;32mmimeTypes.rdf[0m*            [01;32msecmod.db[0m*          [01;32mwebappsstore.sqlite[0m*
[01;32mcompatibility.ini[0m*       [01;34mGeany[0m/                      [01;34mMusic[0m/                    [01;32msessionstore.bak[0m*   [01;32mwebappsstore.sqlite-shm[0m*
[01;32mcontent-prefs.sqlite[0m*    [01;34mgithub[0m/                     [01;32mpercolate.cpp[0m*            [01;32msessionstore.js[0m*    [01;32mwebappsstore.sqlite-wal[0m*
[01;32mcookies.sqlite[0m*          [01;34mhealthreport[0m/               [01;32mpermissions.sqlite[0m*       [01;32msignons.sqlite[0m*     [01;34mWINDOWS[0m/
[01;32mcookies.sqlite-shm[0m*      [01;32mhealthreport.sqlite[0m*        [01;34mPictures[0m/                 [01;32mSortedSet.h[0m*        [01;34mworkspace[0m/
[m~
kryne001@well $ cd github/rshell/
~/github/rshell
kryne001@well $ bin/rshell
kryne001@well.cs.ucr.edu$ ls > test
commands[0]:/bin/ls
kryne001@well.cs.ucr.edu$ ls < test
open at 165 failed: Permission denied
close at 169 failed: Bad file descriptor
dup at 200 failed: Bad file descriptor
commands[0]:/bin/ls
/bin/ls: write error: Bad file descriptor
kryne001@well.cs.ucr.edu$ exit
~/github/rshell
kryne001@well $ bin/rshell
kryne001@well.cs.ucr.edu$ ls
commands[0]:/bin/ls
bin  ets  LICENSE  makefile  README.md	src  test  tests
kryne001@well.cs.ucr.edu$ cat
commands[0]:/bin/cat

~/github/rshell
kryne001@well $ 
~/github/rshell
kryne001@well $ 
~/github/rshell
kryne001@well $ bin/rshell
kryne001@well.cs.ucr.edu$ ls | grep    cat
dup at 200 failed: Bad file descriptor
commands[0]:/bin/ls
/bin/ls: write error: Bad file descriptor
kryne001@well.cs.ucr.edu$ ls    exit
~/github/rshell
kryne001@well $ rm -rf test
~/github/rshell
kryne001@well $ ls > [K[K[K[K[Krm -rf test[1Pbin/rshellcd github/rshell/[7Pbin/rshell
kryne001@well.cs.ucr.edu$ ls > test
commands[0]:/bin/ls
kryne001@well.cs.ucr.edu$ exit
~/github/rshell
kryne001@well $ cat test
bin
ets
LICENSE
makefile
README.md
src
test
tests
~/github/rshell
kryne001@well $ well that works
nxclient: cannot connect to X server 
~/github/rshell
kryne001@well $ exit
exit

Script done on Tue 19 Aug 2014 01:41:42 PM PDT
