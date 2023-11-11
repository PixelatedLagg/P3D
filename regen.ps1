Remove-Item -path cmake_install.cmake;
Remove-Item -path CMakeCache.txt;
Remove-Item -path Makefile;
Remove-Item -path CMakeFiles -Recurse;
cmake . -G "MinGW Makefiles"